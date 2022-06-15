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

class EntityEditorApp {
public:
	EntityEditorApp(int screenWidth = 800, int screenHeight = 450);
	~EntityEditorApp();

	bool Startup();
	void Shutdown();

	void Update(float deltaTime);
	void Draw();

	// IN APPLICATION 1 – The host of the named shared memory 
	// open a named shared memory block 
	HANDLE fileHandle;

	struct MyData {
		float x = 1, y = 1;
		float rotation = 2;
		float speed = 10;
		unsigned char r = 0, g = 0, b = 255;
		float size = 100;
	};

	HANDLE aCreateFileMapping();

protected:
	int m_screenWidth;
	int m_screenHeight;

	// define a block of entities that should be shared
	enum { ENTITY_COUNT = 10 };
	Entity m_entities[ENTITY_COUNT];

	MyData* data;

	HANDLE h = aCreateFileMapping();
};