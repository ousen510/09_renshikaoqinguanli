
#pragma comment(lib, "SkinLib.lib")
//��װ����
extern "C" _declspec(dllexport) BOOL  RunHook( HMODULE hModule, DWORD dwThreadID);
//ж�ع���
extern "C" _declspec(dllexport) BOOL  StopHook();

void LoadSkin()
{
	RunHook(GetModuleHandle( NULL ),GetCurrentThreadId());
}