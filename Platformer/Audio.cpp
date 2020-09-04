#include "Audio.h"

void AudioClass::loadSounds()
{
	walkSB.loadFromFile("Audio/Walking.wav");
	deathSB.loadFromFile("Audio/Death.wav");
	coinSB.loadFromFile("Audio/Coin.wav");
	pDeathSB.loadFromFile("Audio/playerDeath.wav");
}