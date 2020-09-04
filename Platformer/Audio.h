#pragma once
#include <SFML/Audio.hpp>


class AudioClass
{
public:
	void Audio();
	void loadSounds();
	sf::SoundBuffer walkSB;
	sf::SoundBuffer deathSB;
	sf::SoundBuffer coinSB;
	sf::SoundBuffer pDeathSB;
	sf::Sound sound;
};