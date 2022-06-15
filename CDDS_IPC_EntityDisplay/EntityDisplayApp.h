#pragma once
#include <vector>
#include "raylib.h"
#include "WinInc.h"
#include <windows.h>

struct Entity {
	float x = 0, y = 0;
	float rotation = 0;
	float speed = 0;
	unsigned char r = 0, g = 0, b = 0;
	float size = 1;
};

class EntityDisplayApp  {
public:
	EntityDisplayApp(int screenWidth = 800, int screenHeight = 450);
	~EntityDisplayApp();

	bool Startup();
	void Shutdown();

	void Update(float deltaTime);
	void Draw();

	// IN APPLICATION 2 – A user of the named shared memory 
	// gain access to a named shared memory block that already exists 
	HANDLE fileHandle;

	struct MyData {
		float x = 0, y = 0;
		float rotation = 0;
		float speed = 0;
		unsigned char r = 0, g = 0, b = 0;
		float size = 1;
	};

	MyData* data;

	HANDLE aOpenFileMapping();

protected:
	int m_screenWidth;
	int m_screenHeight;

	// an array of an unknown number of entities
	std::vector<Entity> m_entities;
};