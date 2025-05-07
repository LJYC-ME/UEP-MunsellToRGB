// MIT License - Copyright (c) 2025 LJYC (ljyc.me)
// See LICENSE file in the root of the repository for more details.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EMunsellHue : uint8
{
    None = 0 UMETA(Hidden),

    R25      UMETA(DisplayName = "Red 2.5"),
    R50      UMETA(DisplayName = "Red 5.0"),
    R75      UMETA(DisplayName = "Red 7.5"),
    R100     UMETA(DisplayName = "Red 10.0"),

    YR25     UMETA(DisplayName = "Yellow-Red 2.5"),
    YR50     UMETA(DisplayName = "Yellow-Red 5.0"),
    YR75     UMETA(DisplayName = "Yellow-Red 7.5"),
    YR100    UMETA(DisplayName = "Yellow-Red 10.0"),

    Y25      UMETA(DisplayName = "Yellow 2.5"),
    Y50      UMETA(DisplayName = "Yellow 5.0"),
    Y75      UMETA(DisplayName = "Yellow 7.5"),
    Y100     UMETA(DisplayName = "Yellow 10.0"),

    GY25     UMETA(DisplayName = "Green-Yellow 2.5"),
    GY50     UMETA(DisplayName = "Green-Yellow 5.0"),
    GY75     UMETA(DisplayName = "Green-Yellow 7.5"),
    GY100    UMETA(DisplayName = "Green-Yellow 10.0"),

    G25      UMETA(DisplayName = "Green 2.5"),
    G50      UMETA(DisplayName = "Green 5.0"),
    G75      UMETA(DisplayName = "Green 7.5"),
    G100     UMETA(DisplayName = "Green 10.0"),

    BG25     UMETA(DisplayName = "Blue-Green 2.5"),
    BG50     UMETA(DisplayName = "Blue-Green 5.0"),
    BG75     UMETA(DisplayName = "Blue-Green 7.5"),
    BG100    UMETA(DisplayName = "Blue-Green 10.0"),

    B25      UMETA(DisplayName = "Blue 2.5"),
    B50      UMETA(DisplayName = "Blue 5.0"),
    B75      UMETA(DisplayName = "Blue 7.5"),
    B100     UMETA(DisplayName = "Blue 10.0"),

    PB25     UMETA(DisplayName = "Purple-Blue 2.5"),
    PB50     UMETA(DisplayName = "Purple-Blue 5.0"),
    PB75     UMETA(DisplayName = "Purple-Blue 7.5"),
    PB100    UMETA(DisplayName = "Purple-Blue 10.0"),

    P25      UMETA(DisplayName = "Purple 2.5"),
    P50      UMETA(DisplayName = "Purple 5.0"),
    P75      UMETA(DisplayName = "Purple 7.5"),
    P100     UMETA(DisplayName = "Purple 10.0"),

    RP25     UMETA(DisplayName = "Red-Purple 2.5"),
    RP50     UMETA(DisplayName = "Red-Purple 5.0"),
    RP75     UMETA(DisplayName = "Red-Purple 7.5"),
    RP100    UMETA(DisplayName = "Red-Purple 10.0"),

    Max      UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EMunsellValue : uint8
{
    None = 0 UMETA(Hidden),

    V1       UMETA(DisplayName = "Value 1"),
    V2       UMETA(DisplayName = "Value 2"),
    V3       UMETA(DisplayName = "Value 3"),
    V4       UMETA(DisplayName = "Value 4"),
    V5       UMETA(DisplayName = "Value 5"),
    V6       UMETA(DisplayName = "Value 6"),
    V7       UMETA(DisplayName = "Value 7"),
    V8       UMETA(DisplayName = "Value 8"),
    V9       UMETA(DisplayName = "Value 9"),
    
    Max      UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EMunsellChroma : uint8
{
    None = 0 UMETA(Hidden),

    C2       UMETA(DisplayName = "Chroma 2"),
    C4       UMETA(DisplayName = "Chroma 4"),
    C6       UMETA(DisplayName = "Chroma 6"),
    C8       UMETA(DisplayName = "Chroma 8"),
    C10      UMETA(DisplayName = "Chroma 10"),
    C12      UMETA(DisplayName = "Chroma 12"),
    C14      UMETA(DisplayName = "Chroma 14"),
    C16      UMETA(DisplayName = "Chroma 16"),
    C18      UMETA(DisplayName = "Chroma 18"),
    C20      UMETA(DisplayName = "Chroma 20"),
    C22      UMETA(DisplayName = "Chroma 22"),
    C24      UMETA(DisplayName = "Chroma 24"),
    C26      UMETA(DisplayName = "Chroma 26"),

    Max      UMETA(Hidden),
};

class FMunsellToRGB_LUT
{
public:
    static const FVector3f*
    Find(EMunsellHue InHue, EMunsellValue InValue, EMunsellChroma InChroma)
    {
        static FMunsellToRGB_LUT Instance{};

        const auto& Entry = Instance.LUT[static_cast<uint32>(InHue)][static_cast<uint32>(InValue)];
        if (Entry.Contains(InChroma))
        {
            return &Entry[InChroma];
        }
        else return nullptr;
    }

private:
    using FColorLUT = TStaticArray<TStaticArray<TMap<EMunsellChroma, FVector3f>,
                                   static_cast<uint32>(EMunsellValue::Max)>,
                                   static_cast<uint32>(EMunsellHue::Max)>;
    FColorLUT LUT;

    FMunsellToRGB_LUT()
    {
        LoadDataToLUT_1();
        LoadDataToLUT_2();
        LoadDataToLUT_3();
    }
    
    void LoadDataToLUT_1();
    void LoadDataToLUT_2();
    void LoadDataToLUT_3();
};
