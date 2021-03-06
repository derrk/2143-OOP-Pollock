#pragma once

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Splash Background.png"
#define MAIN_MENU_BACKGROUND_FILEPATH	"Resources/res/sky.png"
#define GAME_BACKGROUND_FILEPATH	"Resources/res/sky.png"
#define GAME_OVER_BACKGROUND_FILEPATH	"Resources/res/sky.png"

#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"

#define DEBRIS_UP_FILEPATH "Resources/res/PipeUp.png"
#define DEBRIS_DOWN_FILEPATH "Resources/res/PipeDown.png"
#define SCORING_DEBRIS_FILEPATH "Resources/res/InvisibleScoringPipe.png"

#define LAND_FILEPATH "Resources/res/Land.png"

#define DOGE_FRAME_1_FILEPATH "Resources/res/bird-01.png"
#define DOGE_FRAME_2_FILEPATH "Resources/res/bird-02.png"
#define DOGE_FRAME_3_FILEPATH "Resources/res/bird-03.png"
#define DOGE_FRAME_4_FILEPATH "Resources/res/bird-04.png"


#define DEBRIS_MOVEMENT_SPEED 200.0f
#define DEBRIS_SPAWN_FREQUENCY 2.5f

//animation

#define DOGE_STATE_STILL 1
#define DOGE_STATE_FALLING 2
#define DOGE_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f

#define FLYING_DURATION 0.25f

enum	GameStates
{
	eReady,
	ePlaying,
	eGameOver
};
