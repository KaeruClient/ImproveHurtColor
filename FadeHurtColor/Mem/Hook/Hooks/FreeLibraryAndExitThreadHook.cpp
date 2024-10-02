#include "FreeLibraryAndExitThreadHook.h"
#include "../../../dllmain.h"
void FreeLibraryAndExitThreadHook::handle(HMODULE hLibModule, DWORD dwExitCode)
{
	static auto oFunc = funcPtr->GetOrigFunc<void, HMODULE, DWORD>();
	if (hLibModule == dllmain::module && dllmain::isRunning) {
		dllmain::isRunning = false;
		return;
	}
	return oFunc(hLibModule, dwExitCode);
}
