#include "Level.h"
#include "../../TextureManager.h"
#include "../../Window.h"
#include "../Object/GameObject.h"
#include <fstream>

GameObject *tile;

Level::Level()
{
	tile = new GameObject("res/img/blocks_256x.png");
	tile->setObjectRect(0, 0, BLOCK_RES, BLOCK_RES);
}


Level::~Level()
{
}


void Level::load(const char *name) {
	std::ifstream file{name};
	file >> pX; file >> pY;
	for (size_t i = 0; i < 8; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			file >> data[i][j];
			data[i][j] -= 48;
		}
	}


}

void Level::draw() {
	
	for (size_t i = 0; i < 8; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			tile->setPos(j * BLOCK_RES, i * BLOCK_RES);
			tile->setTextureRect(data[i][j] * BLOCK_TEX_RES, 0, BLOCK_TEX_RES, BLOCK_TEX_RES);
			tile->draw();
		}
	}
	

}


void Level::getPlayerPos(int *x, int *y) {
	*x = pX;
	*y = pY;
}