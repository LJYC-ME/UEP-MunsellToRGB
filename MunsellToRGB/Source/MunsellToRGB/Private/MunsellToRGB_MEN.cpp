// Fill out your copyright notice in the Description page of Project Settings.
#include "MunsellToRGB_MEN.h"
#define LOCTEXT_NAMESPACE "UMunsellToRGB_MEN"

#if WITH_EDITOR
#include "MaterialCompiler.h"
#endif

UMunsellToRGB_MEN::
UMunsellToRGB_MEN()
{
    bCollapsed = false;
}

#if WITH_EDITOR
/*Compiling the material. Called when the material is being compiled.
Compiler - the object responsible for material compilation.
OutputIndex - the index of the output being compiled.
Returns the index of the compiled expression in the material graph.*/
int32 UMunsellToRGB_MEN::
Compile(FMaterialCompiler* Compiler, int32 OutputIndex)
{
    if (OutputIndex != 0)
    {
        return Compiler->Errorf(TEXT("Invalid output index for UMunsellToRGB_MEN %d"), OutputIndex);
    }

    const FVector3f* Color = FMunsellToRGB_LUT::Find(Hue, Value, Chroma);
    if (Color)
    {
        UE_LOG(LogTemp, Warning, TEXT("Color = (%f, %f, %f)"), Color->X, Color->Y, Color->Z);
        return Compiler->Constant3(Color->X, Color->Y, Color->Z);
    }
    
    for(uint8 ChromaIdx = static_cast<uint8>(Chroma); ChromaIdx > 0; --ChromaIdx)
    {
        Color = FMunsellToRGB_LUT::Find(Hue, Value, static_cast<EMunsellChroma>(ChromaIdx));
        if (Color)
        {
            Compiler->Errorf(TEXT("The maximum chroma is %d!"), 2 * ChromaIdx);
            return Compiler->Constant3(0, 0, 0);
        }
    }

    Compiler->Errorf(TEXT("Invalid Munsell Color!"));
    return Compiler->Constant3(0, 0, 0);
}

TArray<FExpressionOutput>& UMunsellToRGB_MEN::
GetOutputs()
{
    Outputs.Reset();
    Outputs.Add(FExpressionOutput(TEXT("RGB"), 0x7, 1, 1, 1, 0));
    
    return Outputs;
}

uint32 UMunsellToRGB_MEN::
GetOutputType(int32 OutputIndex)
{
    switch (OutputIndex)
    {
        case 0:  return MCT_Float3; // RGB
        default:
        {
            UE_LOG(LogTemp, Error, TEXT("Unkown Output Type!"));
            return MCT_Unknown;
        }
    }
}

/*Retrieving the node's caption, which is displayed in the material editor.
OutCaptions - an array of strings to which the node's caption is added.*/
void UMunsellToRGB_MEN::
GetCaption(TArray<FString>& OutCaptions) const
{
    const UEnum* HueType    = StaticEnum<EMunsellHue>();
    const UEnum* ValueType  = StaticEnum<EMunsellValue>();
    const UEnum* ChromaType = StaticEnum<EMunsellChroma>();

    FString Caption = FString::Format(TEXT("Munsell To RGB\n({0}, {1}, {2})"),
    {
        HueType->GetNameStringByValue(static_cast<int64>(Hue)),
        ValueType->GetNameStringByValue(static_cast<int64>(Value)),
        ChromaType->GetNameStringByValue(static_cast<int64>(Chroma))
    });

    OutCaptions.Add(Caption);
}

/*Retrieving the list of inputs for the node.
Returns a view (TArrayView) of an array of pointers to input expressions (FExpressionInput*).*/
TArrayView<FExpressionInput*> UMunsellToRGB_MEN::
GetInputsView()
{
    CachedInputs.Empty();
    
    //CachedInputs.Add(&Hue);

    return CachedInputs;
}

/*Retrieving a specific input by its index.
InputIndex - the index of the input parameter.
Returns a pointer to the input expression (FExpressionInput*) or nullptr if the index is invalid.*/
FExpressionInput* UMunsellToRGB_MEN::
GetInput(int32 InputIndex)
{
    /*switch (InputIndex)
    {
        default: return nullptr;
    }*/
    return nullptr;
}

/*Retrieving the name of an input parameter by its index.
InputIndex - the index of the input parameter.
Returns the name of the input parameter (FName) or NAME_None if the index is invalid.*/
FName UMunsellToRGB_MEN::
GetInputName(int32 InputIndex) const
{
    /*switch (InputIndex)
    {
        default: return EName::None;
    }*/
    return EName::None;
}

/** Get a single line description of the material expression (used for lists) */
FString UMunsellToRGB_MEN::
GetDescription() const
{
    return "Munsell to RGB.";
}

#endif // WITH_EDITOR