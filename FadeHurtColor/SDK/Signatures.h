#pragma once
#include <cstdint>
#include "../Utils/MemUtils.h"
namespace Sigs {
	static const uintptr_t keymap = SigScan("48 83 ec ? 0f b6 c1 4c 8d 05"); //Keyboard::feed
	static const uintptr_t hurtcolor = SigScan("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 56 48 83 EC 50 0F 10 05 ?? ?? ?? ?? 45 33 F6 49 8B F8 0F 29 70 E8 48 8B DA 0F 29 78 D8 48 8B E9 F3 0F 10 3D ?? ?? ?? ?? 0F 57 F6 44 0F 29 40 C8 F3 44 0F 10 05 ?? ?? ?? ?? 4D 89 B0 30 01 00 00 0F 11 02 8B 02 41 89 80 30 01 00 00 45 89 B0 28 01 00 00 66 83 B9 50"); //RenderController::getHurtColor
}