#include "Plain.h"
#include "videoDriver.h"



Plain::Plain()
{
}

Plain::Plain(int id, float x1, float y1, int velocity, float x2, float y2)
	: Object(id ,x1, y1, velocity), p_x2(x2), p_y2(y2)
{

}

void Plain::Render()
{
	VideoDriver::GetInstance()->DrawLine(m_x, m_y, p_x2, p_y2);
}

void Plain::Update(float frametime)
{
}

bool Plain::checkTouch(float x, float y)
{
	return false;
}


Plain::~Plain()
{
}

