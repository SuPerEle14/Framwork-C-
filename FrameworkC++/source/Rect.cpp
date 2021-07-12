#include "videoDriver.h"
#include "Rect.h"
//#include "matrix.h"


Rect::Rect() {

}


Rect::Rect(int id, float x, float y, int width, int height, int velocity) 
	: Object(id, x, y, velocity) , r_width(width), r_height(height), r_mass(1)
{	

}


void Rect::Render() {
	VideoDriver::GetInstance()->DrawRect(m_x - r_width / 2, m_y - r_height / 2, r_width, r_height, 1);
}

void Rect::Update(float frametime) {
	if (m_y < SCREEN_H - r_height/2 - 1 )
	{
		m_y += m_velocity * frametime;
	}
//	std::cout << m_velocity << std::endl;
}

bool Rect::checkTouch(float x, float y)
{
	if ((m_x + r_width / 2) > x && (m_y + r_height / 2) > y && m_x - r_width / 2 < x && m_y - r_height / 2 < y)
	{
		return true;
	}
	else 
		return false;
		
}


Rect::~Rect()
{
}

