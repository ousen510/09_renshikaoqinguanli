
#pragma comment(lib, "SkinLib.lib")
//安装钩子
extern "C" _declspec(dllexport) BOOL  RunHook( HMODULE hModule, DWORD dwThreadID);
//卸载钩子
extern "C" _declspec(dllexport) BOOL  StopHook();

void LoadSkin()
{
	RunHook(GetModuleHandle( NULL ),GetCurrentThreadId());
}