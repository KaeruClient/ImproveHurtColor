#include "RenderControllerHook.h"

mce::Color* RenderControllerHook::getHurtColor::handle(__int64 a1, mce::Color* color, __int64 renderParams)
{
	static auto oFunc = funcPtr->GetOrigFunc<mce::Color*, __int64, mce::Color*, __int64>();
	__int64 actor = *(__int64*)(renderParams + 0x38);
	if (actor && (*(DWORD*)(actor + 0x210) & 2) != 0)
	{
		int* damageTime = *(int**)(actor + 0x418);
		bool onFire = (*(unsigned __int8(__fastcall**)(__int64))(*(__int64*)actor + 0x180i64))(actor);
		if (*damageTime > 0 || onFire) {
			color->r = onFire ? 1.f : 0.75f;
			color->g = onFire ? 0.25f : 0.f;
			color->b = 0.f;
			color->a = 0.6f;
			color->a *= (*damageTime / 10.f);
			return color;
		}
	}
	return oFunc(a1, color, renderParams);
}
