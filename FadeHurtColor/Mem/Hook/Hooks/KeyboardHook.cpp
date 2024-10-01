#include "KeyboardHook.h"
#include "../../../dllmain.h"

void KeyboardHook::Feed::handle(unsigned char key, bool isDown)
{
	static auto oFunc = funcPtr->GetOrigFunc<void, unsigned char, bool>();
	dllmain::keymap[key] = isDown;
	return oFunc(key, isDown);
}
