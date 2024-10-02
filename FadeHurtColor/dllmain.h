#pragma once
#include <windows.h>
#include <map>
class dllmain {
public:
	static bool isRunning;
	static std::map<unsigned char, bool> keymap;
	static HMODULE module;
};
