#include "RenderControllerHook.h"

mce::Color* RenderControllerHook::getHurtColor::handle(__int64 a1, mce::Color* color, __int64 renderParams)
{
	static auto oFunc = funcPtr->GetOrigFunc<mce::Color*, __int64, mce::Color*, __int64>();
	__int64 actor = *(__int64*)(renderParams + 0x38);
	int* damageTime = *(int**)(actor + 0x478);
	color->r = 1.f;
	color->g = 0.f;
	color->b = 0.f;
	color->a = 0.6f;
	int deathTime = (*(int(__fastcall**)(__int64))(*(__int64*)actor + 0x360i64))(actor);
	if (deathTime > 0) color->a *= fminf((deathTime / 10.f), 1.f);
	else color->a *= (*damageTime / 10.f);
	return color;
}
