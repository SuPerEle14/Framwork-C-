#include "Object.h"
//#include "videoDriver.h"


Object::Object() {

}

Object::Object(int id, float x, float y, int velocity) : m_id(id), m_x(x), m_y(y), m_velocity(velocity)
{
}

void Object::Render()
{
}

void Object::Update(float frametime)
{
//	m_y+=2;
	
}


bool Object::checkTouch(float x, float y)
{
	return false;
}

void Object::actionMove(float x, float y)
{
	//moveX = x - m_x;
	//moveY = y - m_y;
	if (checkTouch(x, y))
	{
		//m_x += moveX;
		//m_y += moveY;
		m_x = x;
		m_y = y;
	}

}


Object::~Object()
{
}



