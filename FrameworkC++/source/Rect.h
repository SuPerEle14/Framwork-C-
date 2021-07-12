#ifndef __RECT_H__
#define __RECT_H__

#include "Object.h"


class Rect : public Object
{	

public:
	int r_width;
	int r_height;
	int r_mass;

	Rect();
	Rect(int id, float x, float y, int width, int height, int velocity);
	~Rect();

	void Render();
	void Update(float frametime);
	bool checkTouch(float x, float y);
};
#endif
