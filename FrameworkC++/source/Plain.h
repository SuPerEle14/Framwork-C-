#pragma once
#include <Object.h>

class Plain : public Object
{
public:
	int p_x2;
	int p_y2;

	Plain();
	Plain(int id, float x1, float y1, int velocity, float x2, float y2);
	~Plain();

	void Render();
	void Update(float frametime);
	bool checkTouch(float x, float y);
};

