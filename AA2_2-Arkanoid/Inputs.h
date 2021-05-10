#pragma once
#include <Windows.h>
enum class InputKey {LEFT, RIGHT, ESCAPE, COUNT};

struct InputData {
	//Array IK values
	bool Keyboard[(int)InputKey::COUNT] = {};

	//Updates the array with current value of the input by windows.h
	void Update() {
		Keyboard[(int)InputKey::LEFT] = GetAsyncKeyState(VK_LEFT);
		Keyboard[(int)InputKey::RIGHT] = GetAsyncKeyState(VK_RIGHT);
		Keyboard[(int)InputKey::ESCAPE] = GetAsyncKeyState(VK_ESCAPE);
	}
};

/*

- A vegades les col·lisions experimenten rebots no esperats contra la 
plataforma. 

- Per ser més correcte la lògica del moviment de la plataforma 
s’ha de calcular dins de la classe plataforma i no al main.
*/