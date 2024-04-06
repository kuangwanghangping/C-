#include<Windows.h>
#pragma comment (lib,"key.lib")
extern "C" _declspec(dllimport) BOOL InstallHook();
extern "C" _declspec(dllimport) BOOL UninstallHook();
LRESULT CALLBACK WindowProc(HWND hWnd ,UINT uMsg ,WPARAM wParam ,LPARAM iParam );
//·�ں�������·�ں���
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreinstance, LPSTR lpCmdLine, int nCmdShow)
{
	//���̼�¼��
	// һ����һ������
	// 1��ƴ�����
	TCHAR szAppClassName[] = TEXT("��¼��");
	WNDCLASS wc = { 0 };
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//���ذ�ɫˢ��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//���ع��
	wc.hIcon = NULL;//ͼ����
	wc.hInstance = hInstance;//��ǰӦ�ó���ʵ�����
	wc.lpfnWndProc = WindowProc;//���ڴ�����
	wc.lpszClassName = szAppClassName;//����������
	wc.style = CS_HREDRAW | CS_VREDRAW;//��������
	// 2ע�ᴰ����
	RegisterClass(&wc);
	// 3��������
	HWND hwnd = CreateWindow(szAppClassName, TEXT("С͵"), WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX, 300, 200, 600, 400, NULL, NULL, hInstance, NULL);
	// 4��ʾ���ں͸��´���
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	// 5��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		//�������ת��Ϊ�ַ���Ϣ
		TranslateMessage(&msg);
		//����Ϣ�ַ������ڴ���������
		DispatchMessageW(&msg);
		//������������У������ϵķŴ���С�ر��϶���������


	}
	//��װ���ӣ�hook����
	//����
	//
	return 0;
}
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM iParam)
{
	switch (uMsg) {
	case WM_CREATE:
		InstallHook();
		break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		UninstallHook();
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, iParam);
}