#pragma once
#include "../Hook.h"

class FreeLibraryAndExitThreadHook final : public Hook {
private:
	static inline std::unique_ptr<HookClass> funcPtr;
public:
	FreeLibraryAndExitThreadHook() : Hook("FreeLibraryAndExitThread") {};
	static void handle(HMODULE hLibModule, DWORD dwExitCode);
	bool Initialize() override {
		return CreateHook(funcPtr, (uintptr_t)&FreeLibraryAndExitThread, handle);
	}
};