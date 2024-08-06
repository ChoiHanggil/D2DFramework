#include<Windows.h>
#include "D2DFramework.h"


D2DFramework myFramework;

int WINAPI WinMain(
	_In_ HINSTANCE hInstacne,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	int ret;
	try
	{
		myFramework.Init(hInstacne);

		ret = myFramework.GameLoop();
		// 4. «ÿ¡¶
		myFramework.Release();
	}
	catch (const com_exception& e)
	{
		OutputDebugStringA(e.what());
	}

	return ret;
}


