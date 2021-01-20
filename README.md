# SplashMol
> A simple &amp; straight forward molecular mass calculator, written in Qt 5.
> Chiefly designed for high school students. Uses a (possibly buggy) simple bruteforce algorithm.

## Usage
Simply type in chemical formulas in their natural form, with subscripts replaced by normal numbers, then press Enter or click "Calculate". 

**Examples:**
`Ca(OH)2`
`Cu2(OH)2CO3`
`NH4OH`
`CCl4`
`AgCl`
`KClO3`

## Known Limitations
- Some special forms of formulas, including *multiple (>1) layers of parentheses* and *water of hydration* are not supported. Support for these formats will be added in future versions.
- Only supports a small set of elements that are commonly used in high school chemistry. 

  - They are: `C H O N P S K I Ba Au Ca Cl Na Mg Al Si Mn Fe Cu Zn Ag Hg`
- The above elements' atomic weight are stored in their rounded form, also intended for use in high school chemistry calculations. Those two problems will be solved in future versions.

## TODO
- [] Rewrite frontend using QML and adapt Material Design
- [] Improve algorithm & solve the problems listed above.
- [] Design a new icon & adapt them in macOS
- [] Publish prebuilt binaries for Windows, macOS and Linux.
- [] Port the app to Android 
- [] ...more?

## Changelog
v1.0 - First working version.
