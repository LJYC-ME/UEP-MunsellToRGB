# MunsellToSRGB
**Munsell To sRGB (Unreal Engine Plug-in)**
![](/MunsellToRGB/Resources/Icon128.png)

## Features
- **Munsell HVC to Linear RGB Conversion**
  - Custom Material Expression node for easy integration in materials.
  - Lightweight LUT implementation (< 200 kB of dynamic memory usage).

- **Plugin Modules**
  - `MunsellToRGB`: Integrated with the Unreal Engine Plugin Manager.
  - `MunsellToRGB_MEN`: Material Expression Node class for color conversion.
  - `MunsellToRGB_LUT`: Munsell Color Lookup Table with optimized access.

## Installation
1. Copy the `MunsellToRGB` folder into your Unreal Engine project's `Plugins` directory.
2. Close the Unreal Engine Editor and rebuild your project in your IDE (e.g., Visual Studio).
3. Reopen the Unreal Engine Editor and enable the plugin via **Edit > Plugins**.

## Example
Here's how to use the **"Munsell To RGB"** node in the Material Editor:

1. Enable the Plug-in in Unreal Engine (Edit > Plugins).
![](/Data/0.MunsellToRGB_Plugin.jpg)

2. Open the Material Editor and find "Munsell To RGB".
![](/Data/1.MunsellToRGB_MEN.jpg)

3. Adjust Munsell HVC parameters in the details panel.
![](/Data/2.MunsellColor.jpg)

## References

[1] D. Nikolaev, O. Basova, G. Usaev, M. Tchobanou, and V. Bozhkova, “Detection and Correction of Errors in Psychophysical Color Difference Munsell Re-renotation Dataset,” lim, vol. 4, no. 1, pp. 40–44, Jun. 2023, doi: 10.2352/lim.2023.4.1.10.

[2] A. H. Munsell, “A Pigment Color System and Notation,” The American Journal of Psychology, vol. 23, no. 2, p. 236, Apr. 1912, doi: 10.2307/1412843.

## Acknowledgments

This project uses color reference data from the **Munsell Color Science Laboratory**.  
- [RIT - Munsell Renotation Data](https://www.rit.edu/science/munsell-color-science-lab-educational-resources#munsell-renotation-data)

@[pe7yu](https://github.com/pe7yu). Thanks so much for sharing this amazing template!
- [pe7yu - CustomMaterialNodeTemplate](https://github.com/pe7yu/CustomMaterialNodeTemplate)

## License
This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.
