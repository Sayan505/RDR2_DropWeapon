#include "../inc/main.h"

#include "../inc/script.h"
#include "../inc/keyboard.h"


BOOL APIENTRY DllMain(
	_In_ HMODULE hDllHandle,
	_In_ DWORD fdwReason,
	_In_ LPVOID lpReserved) {

	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		scriptRegister(hDllHandle, ScriptMain);
		keyboardHandlerRegister(OnKeyboardMessage);
		break;
	case DLL_PROCESS_DETACH:
		scriptUnregister(hDllHandle);
		keyboardHandlerUnregister(OnKeyboardMessage);
		break;
	}

	return TRUE;
}