#pragma once
#include<Windows.h>
#include <stdio.h>
HHOOK g_hHook = NULL;
extern "C" _declspec(dllexport) BOOL InstallHook();
extern "C" _declspec(dllexport) BOOL UninstallHook();
//����extern"C"{
// _declspec(dllexport) BOOL InstallHook();
// _declspec(dllexport) BOOL UninstallHook();
// }
//���Ӵ�����
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);