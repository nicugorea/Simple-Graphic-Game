#pragma once

#include "../../includes.h"



class Level
{
public:
	Level();
	~Level();
	
public:
	void generate();
	void load(const char* name);
	void save(const char* name);
	void draw();
	void getPlayerPos(int *x, int *y);

public:
	Uint8 data[8][16];

private:
	Uint16 pX, pY;//player coordonates
};

