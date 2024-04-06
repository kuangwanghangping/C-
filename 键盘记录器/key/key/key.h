#pragma once
#include<Windows.h>
#include <stdio.h>
HHOOK g_hHook = NULL;
extern "C" _declspec(dllexport) BOOL InstallHook();
extern "C" _declspec(dllexport) BOOL UninstallHook();
//或者extern"C"{
// _declspec(dllexport) BOOL InstallHook();
// _declspec(dllexport) BOOL UninstallHook();
// }
//钩子处理函数
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);