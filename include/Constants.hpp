#ifndef __CONSTANTS_HPP
#define __CONSTANTS_HPP

namespace Constants
{
	const int ResolutionX = 640, ResolutionY = 480;
	const float FPS = 30.0f;

	const int TileWidth = 32, TileHeight = 32;
	const int CharacterWidth = 32, CharacterHeight = 48;

	const float WalkVelocity = 3.4f;
	const float RunVelocity = 7.2f;

	enum Direction {
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3
	};
}

#endif