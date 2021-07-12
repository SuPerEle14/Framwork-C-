#pragma once
#include <Object.h>

class Cir : public Object
{
private:
	
public:
	float c_radius;

	Cir();
	Cir(int id, float x, float y , int velocity, float radius);
	~Cir();

	void Render();
	void Update(float frametime);
	bool checkTouch(float x, float y);
};

