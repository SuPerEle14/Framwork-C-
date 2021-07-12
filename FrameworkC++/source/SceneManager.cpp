#include "SceneManager.h"


using namespace std;

SceneManager* SceneManager::s_Instance = NULL;

SceneManager::SceneManager(void)
{
	this->Init();
//	this->Render();

//	VideoDriver::GetInstance()->DrawLine(0,0,500,500);
}

SceneManager::~SceneManager()
{
}


SceneManager* SceneManager::GetInstance()
{
	if (!s_Instance)
		s_Instance = new SceneManager();
	return s_Instance;
}

void SceneManager::Init()
{
	FILE *t;
	t = fopen("SceneManager.txt","r");
	if (t == NULL)
	{
		 printf("Can't read File!");
	}
	
	else 
	{
		int objCount;
		fscanf(t, "#OBJECT_NUM %d\n", &objCount);
		while(objCount--)
		{
			int id;
			fscanf(t, "#ID %d\n",&id);
			char str[10];
			fscanf(t, "TYPE: %s\n", str);
			if (strcmp(str, "RECT") == 0) 
			{
				float x, y;
				int width, height, velocity;
				fscanf(t, "POSITION: %f, %f, %d, %d\n", &x, &y, &width, &height);
				fscanf(t, "VELOCITY: %d\n", &velocity);
				Object* object = new Rect(id, x, y, width, height, velocity);
				AddObject((Object*)object);
			}

			if (strcmp(str, "CIRCLE") == 0)
			{
				float x, y, radius;
				int velocity;
				fscanf(t, "POSITION: %f, %f, %f\n", &x, &y, &radius);
				fscanf(t, "VELOCITY: %d\n", &velocity);
				Object* object = new Cir(id, x, y, velocity, radius);
				AddObject((Object*)object);
			}

			if (strcmp(str, "PLANE") == 0)
			{
				float x1, y1, x2, y2;
				fscanf(t, "POSITION: %f, %f, %f, %f\n", &x1, &y1, &x2, &y2);
				Object* object = new Plain(id,x1, y1, 1, x2, y2);
				AddObject((Object*)object);
			}
		}
	}

	fclose(t);
}

void SceneManager::Render() {
	for (auto& obj : m_objList) {
		obj->Render();
	}
}

void SceneManager::Update(float frametime) {
//	collistionXToX();

	for (auto& obj : m_objList) {
		obj->Update(frametime);
	}
}

void SceneManager::AddObject(Object *object) {
	m_objList.push_back(object);
}

void SceneManager::CheckTouchDown(float x, float y)
{
	for (auto& obj : m_objList) 
	{
		if (obj->checkTouch(x,y))
		{
			obj->isClicked = true;
		}
		else
		{
			obj->isClicked = false;
		}
	}
}

void SceneManager::ActionMove(float x, float y)
{
	for (auto& obj : m_objList)
	{
		if (obj->isClicked)
		{
			obj->actionMove(x, y);
		}
	}
}

void SceneManager::collistionXToX()
{
	for (int i = 0;i < m_objList.size(); i++) 
		for (int j = i+1; j < m_objList.size(); j++)
		{
			if(checkObject(m_objList[i], m_objList[j])) printf("Collision!\n");
		} 
}

bool SceneManager::checkObject(Object *obj1, Object *obj2)
{
	if (auto* typeObject = dynamic_cast<Rect*> (obj1))
	{
		if (auto* typeObject = dynamic_cast<Rect*> (obj2))
			return checkRectToRect((Rect*) obj1, (Rect*) obj2);
		else if (auto* typeObject = dynamic_cast<Cir*> (obj2))
			return checkRectToCir((Rect*) obj1, (Cir*) obj2) ;
//		else if (auto* typeObject = dynamic_cast<Plain*> (obj2))
//			return checkRectToPlane((Rect*)obj1, (Plain*)obj2);
	}

	if (auto* typeObject = dynamic_cast<Cir*> (obj1))
	{
		if (auto* typeObject2 = dynamic_cast<Rect*> (obj2))
			return checkCirToRect((Cir*) obj1, (Rect*) obj2);
		else if (auto* typeObject2 = dynamic_cast<Cir*> (obj2))
			return checkCirToCir((Cir*) obj1, (Cir*) obj2);
//		else if (auto* typeObject2 = dynamic_cast<Plain*> (obj2))
//			return checkCirToPlane((Cir*) obj1, (Plain*) obj2);
	}
}

bool SceneManager::checkRectToRect(Rect* obj1, Rect* obj2)
{
	if (obj1->m_x < obj2->m_x + obj2->r_width &&
		obj1->m_x + obj1->r_width > obj2->m_x &&
		obj1->m_y < obj2->m_y + obj1->r_height &&
		obj1->m_y + obj1->r_height > obj1->m_y)
	{
		return true;
	}
	else 
		return false;
}

bool SceneManager::checkRectToCir(Rect* obj1, Cir* obj2)
{	
	float testX = obj2->m_x;
	float testY = obj2->m_y;

	if (obj2->m_x < obj1->m_x) testX = obj1->m_x;
	else if (obj2->m_x > obj1->m_x + obj1->r_width) testX = obj1->m_x + obj1->r_width;
	if (obj2->m_y < obj1->m_y)         testY = obj1->m_y;
	else if (obj2->m_y > obj1->m_y + obj1->r_height) testY = obj1->m_y + obj1->r_height;

									
	float distX = obj2->m_x - testX;
	float distY = obj2->m_y - testY;

	float distance = sqrt((distX*distX) + (distY*distY));
	if (distance <= obj2->c_radius) {
		return true;
	}
	else 
		return false;
}

bool SceneManager::checkCirToRect(Cir* obj1, Rect* obj2)
{
	float testX = obj1->m_x;
	float testY = obj1->m_y;

	if (obj1->m_x < obj2->m_x) testX = obj2->m_x;
	else if (obj1->m_x > obj2->m_x + obj2->r_width) testX = obj2->m_x + obj2->r_width;
	if (obj1->m_y < obj2->m_y)         testY = obj2->m_y;
	else if (obj1->m_y > obj2->m_y + obj2->r_height) testY = obj2->m_y + obj2->r_height;


	float distX = obj1->m_x - testX;
	float distY = obj1->m_y - testY;

	float distance = sqrt((distX*distX) + (distY*distY));
	if (distance <= obj1->c_radius) {
		return true;
	}
	else
		return false;
}

bool SceneManager::checkCirToCir(Cir * obj1, Cir * obj2)
{
	float d_X = obj1->m_x - obj2->m_x;
	float d_Y = obj1->m_y - obj2->m_y;
	float R = obj1->c_radius + obj2->c_radius;

	if (R*R > d_X*d_X + d_Y*d_Y) 
		return true;
	else 
		return false;
}

bool SceneManager::checkRectToPlane(Rect * obj1, Plain * obj2)
{
	if (obj1->m_y + obj1->r_height > 800) 
		return true;
	else 
		return false; 
}

bool SceneManager::checkCirToPlane(Cir* obj1, Plain* obj2)
{
	if (obj1->m_y + obj1->c_radius > 800)
		return true;
	else
		return false;

}








