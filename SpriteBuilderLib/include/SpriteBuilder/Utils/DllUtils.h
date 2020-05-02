#pragma once

#ifdef _WIN32

	// SPRITEBUILDERDLL_EXPORTS
	#ifdef SpriteBuilder_EXPORTS 
		#define libSpriteBuilder __declspec(dllexport)
	#else
		#define libSpriteBuilder __declspec(dllimport)
	#endif
	#ifdef debugDefines
		#ifdef SpriteBuilder_EXPORTS 
			#define libPvtSpriteBuilder __declspec(dllexport)
		#else
			#define libPvtSpriteBuilder __declspec(dllimport)
		#endif
	#else
		#define libPvtSpriteBuilder
	#endif
#else
	#define libSpriteBuilder
	#define libPvtSpriteBuilder
#endif
