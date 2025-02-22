#pragma once
#include <cstdint>
#include "../Utils/MemUtils.h"
namespace Sigs {
	static const uintptr_t keymap = SigScan("48 83 ec ? 0f b6 c1 4c 8d 05"); //Keyboard::feed
	static const uintptr_t hurtcolor = SigScan("48 8B C4 48 89 58 20 55 56 57 41 54 41 55 41 56 41 57 48 8D 68 A1 48 81 EC A0"); //RenderController::getHurtColor
}