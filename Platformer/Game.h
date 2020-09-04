#pragma once
#include "Editor.h"
#include "Audio.h"

struct Collision
{
	bool hit;
	sf::Vector2f dir;
};

class Player : public Actor
{
public:
	Player();
	int lives;
	int coins;
	bool isDead;

	//Collision hitbox, check next loc for collision
	sf::FloatRect nextRect;
	//if we can move, this is ther position to move to
	sf::Vector2f nextPos;
	//this is to create smooth physics 
	sf::Vector2f velocity;
	//Jump stuff
	bool isGrounded;
	float jumpSpeed;
	float speed;

	Collision CollisionCheck(sf::FloatRect other);

	void Refresh();
	void Respawn();
	bool isAnyKeyPressed();
	sf::Vector2f startPos;

	virtual sf::Vector2f getPosition();
	virtual void setPosition(sf::Vector2f p);
};

class Enemy : public Actor
{
public:
	Enemy();
	bool isDead;
	void Killed();
};

class GameClass
{
public:
	GameClass();
	bool Start(MainRenderWindow& mainWindow);
	void Update(MainRenderWindow& mainWindow);
	bool gameActive = false;
	static const int x = 30;
	static const int y = 20;

	AudioClass myAudio;

	Player player;
	//std::Vector<Enemy> enemies;

	void SaveScore();
	void ResetLevel();
	void GameOver();

	Tile** tile = new Tile * [x];
	void LoadLevel(std::string levelName, Tile** incTile);
	//delta time stuff
	sf::Clock clock;
	float deltaTime;
	//physics numbers 
	float gravity;
	float friction;
	int coins;
	int lives;
	sf::Text coinCounter;
	sf::Text liveCounter;
	sf::Font font;
	int textSize = 30;
};

class Counter : public sf::Drawable, public sf::Transformable
{
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(rect, states);
		target.draw(text, states);
	}
public:
	int textSize = 30;
	float rectOutline = 1;
	sf::RectangleShape rect;
	sf::Font font;
	sf::Text text;
	sf::FloatRect rBounds;

	Counter()
	{
		font.loadFromFile("arial.ttf");
		text.setFont(font);
		text.setCharacterSize(textSize);
		text.setFillColor(sf::Color::Black);
		text.setStyle(sf::Text::Regular);
		rect.setFillColor(sf::Color::White);
		rect.setOutlineColor(sf::Color::Black);
		rect.setOutlineThickness(rectOutline);
	}
	
	
};


int sign(int x);
int sign(float x);