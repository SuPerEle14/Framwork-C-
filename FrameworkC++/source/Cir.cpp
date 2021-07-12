#include "Cir.h"
#include "videoDriver.h"


Cir::Cir()
{
}

Cir::Cir(int id, float x, float y, int velocity, float radius )
	: Object(id, x, y, velocity) , c_radius(radius)
{
}


void Cir::Render()
{
	VideoDriver::GetInstance()->DrawCircle(m_x, m_y, c_radius);
}

void Cir::Update(float frametime)
{
	if (m_y < SCREEN_H - c_radius - 2) 
	{
		m_y += m_velocity * frametime;
	}

//	m_y +=1;
}

bool Cir::checkTouch(float x, float y)
{
	if ((m_x - x) * (m_x - x) + (m_y - y) * (m_y - y) <= c_radius*c_radius)
	{
		return true;
	}
	else 
		return false;

}


Cir::~Cir()
{
}







