# Distrain

In the context of this game, distrain carries not the traditional definition of the word, but
rather is meant to be my own word, built by adding the dis- prefix to 'train.' This refers to the
concept in the game that as you train and level up, you're applying stats to the enemy as well,
which is sort of the opposite of training.

## Building

### Makefile

Just run `make`. I haven't tested this makefile extensively at all; it's largely the one included
in the SpeedHack 2011 template.

### Visual Studio Project

Some configuration is necessary for the Visual Studio project file. Be sure to add a user macro to
point at the Allegro install folder. e.g., View -> Other Windows -> Property Manager, double click
`Microsoft.Cpp.Win32.User`, and add macro `AllegroDir` pointing at
`c:\some\path\to\allegro-5.0.10-msvc-11.0`.

You may also need to edit the project properties. In `Configuration Properties -> Debugging`, set
`Environment` to `PATH=$(AllegroDir)\bin;%PATH%`

## Credits

* Character assets and map tileset from https://github.com/silveira/openpixels
* Image assets were optimized using https://tinypng.com/