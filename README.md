# FT-817/857/897 CAT library

This is a CAT library to interface with a Yaesu FT-817/857/897 radio, with a lot of STAMINA via direct EEPROM access.

## Inspiration
- [stdevPavelmc ft817 library](https://github.com/stdevPavelmc/ft817)
- [James Buck, VE3BUX FT-857D library](http://www.ve3bux.com)
- [KA7OEI FT-817 pages](http://www.ka7oei.com/ft817pg.shtml)
- [Andy Webster FT-817_Buddy project](https://github.com/g7uhn/ft817_buddy)
- [Jordan Rubin (KJ4TLB) Perl Module for FT-817](https://metacpan.org/pod/Ham::Device::FT817COMM)

In fact this library was born due to my interest in the [Andy Webster FT-817_Buddy project](https://github.com/g7uhn/ft817_buddy), he twitted about it and I offered to help him out, he reach me and this is the result.

You want to see this lib in action in a real product? Go check [Andy Webster FT-817_Buddy project](https://github.com/g7uhn/ft817_buddy)!

## Main goal

To control a FT-817 via CAT to make a external display with buttons, mainly to help Andy on his project but now it's open to every ham that want to use it.

## WARNING!

This library uses **DIRECT EEPROM ACCESS** that means that you radio eeprom may wear out as per [KA7OEI instructions](http://www.ka7oei.com/ft817_meow.html) so use it wisely.

Tip: Almost all toggleXYZ() functions are a **WRITE** to the eeprom memory where XYZ is the item to toggle.

## Examples?

Se the example once you install your lib, it covers almost all functions we have implemented.

## Contributions & Thanks

Thanks to [Andy Webster](https://github.com/g7uhn) that tested the code on a live radio, Yes, I coded all this blindly as I don't have a FT-817 radio, one of my dream radios.

You have a question/bug/improvement/etc, please reach me via Telegram as @pavelmc o via Twitter as @co7wt.

If you are a dev, don't hesitate to rise a issue or fire a PR to improve the code, the documentation or simply fix a typo.

This is Free/Libre Software, Free as in freedom, if you are happy enough with my lib and want to make a donation please contact me in the above for instructions.
