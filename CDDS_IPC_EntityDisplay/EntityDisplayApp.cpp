#include "EntityDisplayApp.h"

EntityDisplayApp::EntityDisplayApp(int screenWidth, int screenHeight) : m_screenWidth(screenWidth), m_screenHeight(screenHeight) {

}

EntityDisplayApp::~EntityDisplayApp() {

}

bool EntityDisplayApp::Startup() {

	InitWindow(m_screenWidth, m_screenHeight, "EntityDisplayApp");
	SetTargetFPS(60);

	return true;
}

void EntityDisplayApp::Shutdown() {

	CloseWindow();        // Close window and OpenGL context
}

void EntityDisplayApp::Update(float deltaTime) {
	fileHandle = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");

	Entity* data = (Entity*)MapViewOfFile(fileHandle, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(Entity));

	// close the shared file 
	CloseHandle(fileHandle);
	// unmap the memory block since we're done with it 
	UnmapViewOfFile(data);
}

void EntityDisplayApp::Draw() {
	BeginDrawing();

	ClearBackground(RAYWHITE);

	// draw entities
	for (auto& entity : m_entities) {
		DrawRectanglePro(
			Rectangle{ entity.x, entity.y, entity.size, entity.size }, // rectangle
			Vector2{ entity.size / 2, entity.size / 2 }, // origin
			entity.rotation,
			Color{ entity.r, entity.g, entity.b, 255 });
	}

	// output some text, uses the last used colour
	DrawText("Press ESC to quit", 630, 15, 12, LIGHTGRAY);

	EndDrawing();
}

HANDLE EntityDisplayApp::aOpenFileMapping()
{
	return OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"MySharedMemory");
}
