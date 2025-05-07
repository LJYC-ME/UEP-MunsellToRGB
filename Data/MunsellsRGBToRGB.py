import csv
import re

def convert_hue_format(hue: str) -> str:
    # Regular expression to match patterns like '2.5R', '10.0PR', etc.
    match = re.match(r"(\d*\.?\d+)([A-Za-z]+)", hue)
    
    if match:
        number = match.group(1)
        suffix = match.group(2)

        # Remove the decimal point and construct the new string
        # Remove the decimal part and construct new format
        number = number.replace('.', '')  # Remove decimal to get whole number
        if(number == "10"): number = "100"
        elif(number == "5"): number = "50"
        return f"{suffix}{number}"  # Combine the suffix and number

    # If no match, return the input unchanged
    return hue

munsell_hue_enum_indices = {
    name: idx + 1 for idx, name in enumerate([
        "R25", "R50", "R75", "R100",
        "YR25", "YR50", "YR75", "YR100",
        "Y25", "Y50", "Y75", "Y100",
        "GY25", "GY50", "GY75", "GY100",
        "G25", "G50", "G75", "G100",
        "BG25", "BG50", "BG75", "BG100",
        "B25", "B50", "B75", "B100",
        "PB25", "PB50", "PB75", "PB100",
        "P25", "P50", "P75", "P100",
        "RP25", "RP50", "RP75", "RP100"
    ])
}

# Initialize the LUT dictionary
LUT = {}
cnt = 0
def srgb_to_linear(c):
    """Convert a single sRGB channel to linear RGB"""
    if c <= 0.04045:
        return c / 12.92
    else:
        return ((c + 0.055) / 1.055) ** 2.4
# Read the CSV file
with open('real_sRGB.csv', mode='r') as file:
    reader = csv.DictReader(file)
    
    # Loop through each row in the CSV file

    for row in reader:
        cnt += 1
        # Extract relevant fields
        hue = convert_hue_format(row['h'])
        value = row['V']
        chroma = f"C{row['C']}"
        r = srgb_to_linear(float(row['R']))
        g = srgb_to_linear(float(row['G']))
        b = srgb_to_linear(float(row['B']))
        
        # Store the RGB values under the corresponding hue and value
        if(hue not in LUT):        LUT[hue] = dict()
        if(value not in LUT[hue]): LUT[hue][value] = dict()
        if(chroma in LUT[hue][value]): raise("?")
        LUT[hue][value][chroma] = (r, g, b)

# Print the result to verify

print(cnt)
# Accessing specific values:
# LUT["10RP"][1][2] would give the RGB values for that specific combination
#print(LUT[0][9]["C10"])

cnt2 = 0
with open("lut.generated", "w") as f:
    for Hue, VandC in LUT.items():
        p = 0
        for Value, CandSRGB in VandC.items():
            p +=1 
            for Chroma, SRGB in CandSRGB.items():
                cnt2 += 1
                line = f"LUT[{munsell_hue_enum_indices[Hue]}][{Value}].Add(EMunsellChroma::{Chroma},\t{{{SRGB[0]},{SRGB[1]},{SRGB[2]}}});\n"
                f.write(line)
        if p != 9: print("????")
assert(cnt == cnt2)