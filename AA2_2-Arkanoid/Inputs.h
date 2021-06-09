#pragma once
#include <Windows.h>
enum class InputKey {LEFT, RIGHT, ESCAPE, GAME, RANK, LEAVE, COUNT};

struct InputData {
	//Array IK values
	bool Keyboard[(int)InputKey::COUNT] = {};

	//Updates the array with current value of the input by windows.h
	void Update() {
		Keyboard[(int)InputKey::LEFT] = GetAsyncKeyState(VK_LEFT);
		Keyboard[(int)InputKey::RIGHT] = GetAsyncKeyState(VK_RIGHT);
		Keyboard[(int)InputKey::ESCAPE] = GetAsyncKeyState(VK_ESCAPE);
		Keyboard[(int)InputKey::GAME] = GetAsyncKeyState(0x31);
		Keyboard[(int)InputKey::RANK] = GetAsyncKeyState(0x32);
		Keyboard[(int)InputKey::LEAVE] = GetAsyncKeyState(0x30);
	}
};

/*

- A vegades les col�lisions experimenten rebots no esperats contra la 
plataforma. 

*/