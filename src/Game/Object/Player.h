#pragma once

#include "GameObject.h"

class Player: public GameObject
{
public:
	Player(const char* path);
	~Player();

public:
	void Update(Uint8 data[LEVEL_H][LEVEL_W]);
	int deltaT();
private:
	Uint32 lastFrame;
	int dx, dy; //delta x and y
	float ax, ay;

private:
	void colide(Uint8 data[LEVEL_H][LEVEL_W], bool *right, bool *left, bool *up, bool *down);
	bool onGround(Uint8 data[LEVEL_H][LEVEL_W]);



};

