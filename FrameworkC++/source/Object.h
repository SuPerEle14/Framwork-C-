#ifndef __OBJ_H__
#define __OBJ_H__
#include <iostream>

class Object
{
protected:
	

public:
	int m_id;
	float m_x;
	float m_y;
	int m_velocity;
	bool isClicked;

	int moveX;
	int moveY;

	Object();
	Object(int id, float x, float y, int velocity);
	~Object();


	virtual void Render() = 0;
	virtual void Update(float frametime) = 0;
	virtual bool checkTouch(float x, float y);
	void actionMove(float x, float y);
};
#endif
