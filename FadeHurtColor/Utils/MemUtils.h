#pragma once
#include <Windows.h>
#include <chrono>
#include <cstdint>
#include <psapi.h>
#include <string>
#include <vector>
#include <string_view>
#include <unordered_map>

#include <memory>
#include <libloaderapi.h>
#include <processthreadsapi.h>

#include <libhat.hpp>

class MemUtils {
public:
    static uintptr_t getBase() {
        static uintptr_t mc = reinterpret_cast<uintptr_t>(GetModuleHandleA("Minecraft.Windows.exe"));
        return mc;
    }
private:
    static unsigned long GetMinecraftSize() {
        MODULEINFO moduleInfo;
        if (!GetModuleInformation(GetCurrentProcess(), (HMODULE)getBase(), &moduleInfo, sizeof(MODULEINFO))) return 0;
        return moduleInfo.SizeOfImage;
    }

    static std::optional<uintptr_t> SigScanSafe(std::string_view signature) {
        const auto parsed = hat::parse_signature(signature);

        const auto begin = reinterpret_cast<std::byte*>(getBase());
        const auto end = begin + GetMinecraftSize();
        const auto result = hat::find_pattern(begin, end, parsed.value());

        if (!result.has_result()) return std::nullopt;
        return reinterpret_cast<uintptr_t>(result.get());
    }
    static inline std::unordered_map<std::string, uintptr_t> sig_data = {};
public:
    static uintptr_t SigScan(std::string_view signature) {
        if (auto check = sig_data.find(std::string(signature)); check != sig_data.end()) return check->second;
        auto result = SigScanSafe(signature);
        return sig_data[std::string(signature)] = result.value();
    }
};
#define SigScan(signature) MemUtils::SigScan(signature)