#include "D2DFramework.h"
#pragma comment (lib,"d2d1.lib")

using namespace Microsoft::WRL;

HRESULT D2DFramework::Init(HWND hwnd)
{
	// 1. Factory 생성
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, gpD2DFactory.GetAddressOf());

	// if(SUCCEEDED(hr))	//성공
	if (FAILED(hr))			//실패
	{
		OutputDebugString(L"Failed to Create Factory\n");
		return hr;
	}
	// 2. 렌더타겟 생성
	//D2D1_RENDER_TARGET_PROPERTIES rtp;
	//ZeroMemory();
	//rtp.dpiX;...
	RECT wr;
	GetClientRect(hwnd, &wr);

	hr = gpD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(wr.right - wr.left, wr.bottom - wr.top)),
		&gpRenderTarget);

	if (FAILED(hr))
	{
		OutputDebugString(L"Failed to Create Hwnd Render Target!\n");
		return hr;
	}

	return S_OK;
}

void D2DFramework::Release()
{
	gpRenderTarget.Reset();
	gpD2DFactory.Reset();
}

void D2DFramework::Render()
{
	// 3. 그리기
	gpRenderTarget->BeginDraw();

	gpRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

	gpRenderTarget->EndDraw();
}
