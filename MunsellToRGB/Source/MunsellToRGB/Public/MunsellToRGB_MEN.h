// MIT License - Copyright (c) 2025 LJYC (ljyc.me)
// See LICENSE file in the root of the repository for more details.

#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialExpression.h"

#include "MunsellToRGB_LUT.h"

#include "MunsellToRGB_MEN.generated.h"
/**
 * 
 */
UCLASS(hidecategories = Object, meta = (DisplayName = "Munsell To sRGB"))
class MUNSELLTORGB_API
UMunsellToRGB_MEN : public UMaterialExpression
{
	GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Category = "Munsell")
    EMunsellHue    Hue    = EMunsellHue::None;
    UPROPERTY(EditAnywhere, Category = "Munsell")
    EMunsellValue  Value  = EMunsellValue::None;
    UPROPERTY(EditAnywhere, Category = "Munsell")
    EMunsellChroma Chroma = EMunsellChroma::None;
    
#if WITH_EDITOR
    virtual int32
    Compile(class FMaterialCompiler* Compiler, int32 OutputIndex) override;
    virtual void
    GetCaption(TArray<FString>& OutCaptions) const override;
    virtual TArrayView<FExpressionInput*>
    GetInputsView() override;
    virtual FExpressionInput*
    GetInput(int32 InputIndex) override;
    virtual FName
    GetInputName(int32 InputIndex) const override;
    virtual TArray<FExpressionOutput>&
    GetOutputs() override;
    
    virtual uint32
    GetOutputType(int32 OutputIndex) override;
    virtual FString
    GetDescription() const override;
#endif // WITH_EDITOR

public:
	UMunsellToRGB_MEN();
	~UMunsellToRGB_MEN() = default;
};
