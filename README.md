#  SplashMol
> A simple &amp; straight forward molecular mass calculator, written in Qt 5.
> Chiefly designed for high school students. Uses a (possibly buggy) simple bruteforce algorithm.

## Usage
Simply type in chemical formulas in their natural form, with subscripts replaced by normal numbers, then press Enter or click "Calculate". 

For formulas involving water of hydration (water of crystallization), use `-` as separator.

Please note that all elements are case sensitive.

**Examples:**
`Ca(OH)2`
`Cu2(OH)2CO3`
`NH4OH`
`CCl4`
`AgCl`
`CuSO4-5H2O`

`KAl(SO4)2-12H2O`

## Screenshot
![v1.2 Screenshot](screenshot.png)
## Known Limitations
- Multiple (>1) layers of parentheses are currently not supported. This will be implemented later down the road.
- Only supports a small set of elements that are commonly used in high school chemistry. 

  - They are: `C H O N P S K I Ba Au Ca Cl Na Mg Al Si Mn Fe Cu Zn Ag Hg`
- The above elements' atomic weight are stored in their rounded form, also intended for use in high school chemistry calculations. 
- Only `-` instead of `·` is supported in formulas involving water of hydration due to issues with `utf-8` in code; ~~Both separators would be supported in the future.~~ *due to limitations of `QString` and `QChar`, this should be a wontfix for a period of time.*

Please note that all of those problems won't cause runtime errors; they'll be automatically ignored though the result might be wrong.  
## TODO
- [ ] Rewrite frontend using QML and adapt Material Design
- [ ] Improve algorithm & solve the problems listed above.
- [ ] Design a new icon & adapt them in macOS
- [ ] Publish prebuilt binaries for Windows, macOS and Linux.
- [ ] Port the app to Android 
- [ ] ...more?

## Changelog

See [Releases](https://github.com/CRH6F-A-0464/splashmol/releases).

