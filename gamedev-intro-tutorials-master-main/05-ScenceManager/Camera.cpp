#include "Camera.h"

Camera::Camera()
{
	this->position = VECTOR_0;
}
 
Camera::Camera(Vec2 pos, Vec2 size)
{
	this->position = Vec2(pos.x, pos.y);
	this->size = Vec2(size.x, size.y);
}

Camera::~Camera()
{}

Vec2 Camera::GetCameraSize()
{
	return this->size;
}

void Camera::SetCameraSize(float x, float y)
{
	this->size.x = x;
	this->size.y = y;
}

Vec2 Camera::GetCameraPosition()
{
	return position;
}

void Camera::SetCameraPosition(float x, float y)
{
	this->position.x = x; 
	this->position.y = y;
}

void Camera::Update(DWORD dt)
{
	if (this->position.x < this->boundaryleft)
		this->position.x = this->boundaryleft;
	if (this->position.x + this->size.x > this->boundaryright)
		this->position.x = this->size.x=this->boundaryright;
	if (this->position.y < this->boundarytop)
		this->position.y = this->boundarytop;
	if (this->position.y + this->size.y > this->boundarybottom)
		this->position.y = this->size.y = this->boundarybottom;
	
}

