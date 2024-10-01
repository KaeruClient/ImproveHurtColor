#pragma once

#include "../Hook.h"

namespace KeyboardHook {
	class Feed final : public Hook {
	private:
		static inline std::unique_ptr<HookClass> funcPtr;
	public:
		Feed() : Hook("Keyboard::feed") {};
		static void handle(unsigned char key, bool isDown);
		bool Initialize() override {
			return CreateHook(funcPtr, Sigs::keymap, handle);
		}
	};
}