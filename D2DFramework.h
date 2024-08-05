#pragma once
#include<d2d1.h>
#include<wrl/client.h>
#include<exception>
#include<stdio.h>
class com_exception : public std::exception
{
public:
	com_exception(HRESULT hr) : result(hr) {}
	virtual const char* what() const override
	{
		static char str[64]{};

		sprintf_s(str, "Fail with HRESULT code : %X", (unsigned int)result);
		return str;
	}
private:
	HRESULT result;
};

inline void ThowIfFailed(HRESULT hr)
{
	if (FAILED(hr))
	{
		throw com_exception(hr);
	}
}

class D2DFramework
{
protected:
	Microsoft::WRL::ComPtr<ID2D1Factory> gpD2DFactory{};
	Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget> gpRenderTarget{};

public:
	virtual HRESULT Init(HWND hwnd);
	virtual void Release();
	virtual void Render();
};

