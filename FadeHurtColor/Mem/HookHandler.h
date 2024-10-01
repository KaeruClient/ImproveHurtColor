#pragma once

#include <vector>
#include "Hook/Hook.h"
#include "Hook/Hooks/KeyboardHook.h"
#include "Hook/Hooks/RenderControllerHook.h"

class HookHandler {
private:
	static inline std::vector<Hook*> hookList;
	static inline bool Initialized = false;

	template <typename T>
	static void add() {
		static_assert(std::is_base_of<Hook, T>::value, "It isn't Hook!");
		T* newHook = new T();
		hookList.push_back(newHook);
		newHook->Initialize();
	};
public:
	static bool isInitialized() { return Initialized; }
	static void Initialize() {
		{
			add<KeyboardHook::Feed>();
			add<RenderControllerHook::getHurtColor>();
		}
		MH_EnableHook(MH_ALL_HOOKS);
		Initialized = true;
	}
	static void Uninitialize() {
		hookList.clear();
		MH_DisableHook(MH_ALL_HOOKS);
		MH_RemoveHook(MH_ALL_HOOKS);
	}
};
