#include "dllmain.h"
#include <windows.h>
#include <iostream>
#include <string>

#include <winrt/Windows.UI.Notifications.h>
#include <winrt/Windows.Data.Xml.Dom.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.UI.Core.h>

#include <MinHook.h>

#include "Mem/HookHandler.h"

using namespace winrt;
using namespace Windows::Data::Xml::Dom;
using namespace Windows::UI::Notifications;

#define PluginName std::wstring(L"FadingHurtColor")

bool dllmain::isRunning = true;
std::map<unsigned char, bool> dllmain::keymap;

void CreateToast(std::wstring title, std::wstring message) {
    XmlDocument toastXml = ToastNotificationManager::GetTemplateContent(ToastTemplateType::ToastText02);
    XmlNodeList textElements = toastXml.GetElementsByTagName(L"text");
    textElements.Item(0).InnerText(title);
    textElements.Item(1).InnerText(message);
    ToastNotification toast(toastXml);
    ToastNotificationManager::CreateToastNotifier().Show(toast);
}

DWORD WINAPI InitializeClient(LPVOID lpParam) {
    MH_Initialize();
    HookHandler::Initialize();
    while (dllmain::isRunning) {
        if (dllmain::keymap['L'] && dllmain::keymap[VK_CONTROL]) {
            break;
        }
        Sleep(100);
    }
    return 1;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)InitializeClient, hModule, NULL, NULL);
        DisableThreadLibraryCalls(hModule);
        CreateToast(L"Plugin", std::wstring(L"Actived " + PluginName + L".\nDeactive to [Ctrl+L]."));
    }
    if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        HookHandler::Uninitialize();
        CreateToast(L"Plugin", std::wstring(L"Deactived " + PluginName));
    }
    return TRUE;
}

