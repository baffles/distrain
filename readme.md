# Distrain

In the context of this game, distrain carries not the traditional definition of the word, but
rather is meant to be my own word, built by adding the dis- prefix to 'train.' This refers to the
concept in the game that as you train and level up, you're applying stats to the enemy as well,
which is sort of the opposite of training.

This name reflects on some old game ideas that fell out of use here.

## SpeedHack Rules

Unfortunately, some plans I was assuming would be canceled for Sunday ended up working out (weather cleared up). This left me with a fair chunk less time than anticipated, which prevented me from finishing the entry.

In its current state, the main player can be customized, and there is a minimal map to run around in. Not much to actually do though.

### Genre Requirements

#### Traveling Salesman
The idea here evolved to exploring the map, looking for and gathering keys. This idea is not fully fleshed out nor fully implemented.

### Technical Requirements

#### Character Development
The idea here was to have the player gain experience/stat points by battling enemies, giving the player more power and special abilities. Again, this idea is not fully fleshed out nor implemented.

#### Easter Egg
There was no idea in place for this yet therefore not implemented.

### Artistic Requirements

#### Player Customization
The skin for the main character can be fully customized. This is fully implemented.

#### Soviet Russia
The idea here was to have enemies in the game, and the relationship with the player flipped around. Enemies begin killing themselves when they're within a certain range of the player. The player must heal the enemy before it dies in order to gain experience points. This idea is not implemented.

### Bonus Rules

#### Act of Efficiency
I was considering invoking this act to remove various rules at various stages of developing the game idea. I'm not invoking it at the present time.

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