#ifndef _SCMANAGER_H_
#define _SCMANAGER_H_


#include <openGLESv2.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <vector>

#include "Rect.h"
#include "Cir.h"
#include "Plain.h"
#include "videoDriver.h"
#include "matrix.h"
#include "Object.h"

class SceneManager 
{
private:
	static SceneManager* s_Instance;
	std::vector<Object*> m_objList;
	bool is_touch;

public:
	//bool isClicked = false;

	float r_x;
	float r_y;
	float c_x;
	float c_y;
	float c_radius;

	bool isCollision = false;

	SceneManager(void);
	~SceneManager(void);

	
	void Init();
	void Render();
	void Update(float frametime);
	void AddObject(Object * object);
	void CheckTouchDown(float x, float y);
	void ActionMove(float x, float y);

	void collistionXToX();


	bool checkObject(Object* obj1, Object* obj2);

	bool checkRectToRect(Rect* obj1, Rect* obj2);
	bool checkRectToCir(Rect* obj1, Cir* obj2);

	bool checkCirToRect(Cir* obj1, Rect* obj2);
	bool checkCirToCir(Cir* obj1, Cir* obj2);

	bool checkRectToPlane(Rect* obj1, Plain *obj2);
	bool checkCirToPlane(Cir* obj1, Plain *obj2);

	static SceneManager* GetInstance();

};
#endif

