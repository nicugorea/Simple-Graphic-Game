#include "GameObject.h"
#include "../../TextureManager.h"


GameObject::GameObject(const char* path)
{
	mTexture = TextureManager::loadTexture(path);
}

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}


void GameObject::draw() {
	TextureManager::draw(mTexture, &textureRect, &objectRect);
}


void GameObject::move(int x, int y) {
	objectRect.x += x;
	objectRect.y += y;
}


void GameObject::setPos(int x = 0, int y = 0) {
	objectRect.x = x;
	objectRect.y = y;
}


void GameObject::setTextureRect(int x = 0, int y = 0, int w = 100, int h = 100) {
	textureRect.x = x;
	textureRect.y = y;
	textureRect.w = w;
	textureRect.h = h;

}

void GameObject::setObjectRect(int x = 0, int y = 0, int w = 100, int h = 100) {
	objectRect.x = x;
	objectRect.y = y;
	objectRect.w = w;
	objectRect.h = h;


}