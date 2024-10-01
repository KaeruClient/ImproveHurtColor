#pragma once
#include "../Hook.h"

namespace RenderControllerHook {
	class getHurtColor final : public Hook {
	private:
		static inline std::unique_ptr<HookClass> funcPtr;
	public:
		getHurtColor() : Hook("RenderController::getHurtColor") {};
		static mce::Color* handle(__int64 a1, mce::Color* color, __int64 a3);
		bool Initialize() override {
			return CreateHook(funcPtr, Sigs::hurtcolor, handle);
		}
	};
}