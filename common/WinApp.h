#ifndef _WIN_APP_H_
#define _WIN_APP_H_

#include <Windows.h>
#include <string>
#include <D3D11.h>

#include "Timer.h"

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

class WinApp
{
public:
	WinApp(HINSTANCE hInst, std::wstring title = L"D3D11ѧϰ������", int width = 640, int height = 480);
	~WinApp();

	//����������Ա����
	HINSTANCE	AppInstance()	const				{ return m_hInstance;		}
	HWND		Window()		const				{ return m_hWnd;			}
	int			Width()			const				{ return m_clientWidth;		}
	int			Height()		const				{ return m_clientHeight;	}
	void		SetWindowTitle(std::wstring title)	{ SetWindowText(m_hWnd,title.c_str()); }

	/*
	  ����������д��Щ������ʵ���Զ���Ĺ���
	  ���ڸ�����������дʱ��Ҫ�ȵ��ø���ĺ�����������Զ���Ĺ��ܣ�
	  ���磺Init(),������Init()�У���Ҫ�ȵ���WinApp::Init()��
	  ͬ��Ҳ�ʺ���OnResize()��
	 */
	virtual bool	Init();							//�����ʼ��
	virtual bool	OnResize();						//�����ڴ�С�ı�ʱ����
	virtual bool	Update(float timeDelt) = 0;		//ÿ֡����
	virtual bool	Render() = 0;					//��Ⱦ

	virtual LRESULT CALLBACK WinProc(HWND,UINT,WPARAM,LPARAM);
	
	int		Run();		//��ѭ��

protected:
	bool	InitWindow();		//��ʼ��Win32����
	bool	InitD3D();			//��ʼ��D3D11
	
	void	CalculateFPS();		//����֡��

protected:
	HINSTANCE	m_hInstance;		//Ӧ�ó���ʵ�����
	HWND		m_hWnd;				//���ھ��

	int			m_clientWidth;		//���ڴ�С
	int			m_clientHeight;

	bool		m_isMinimized;		//�Ƿ���С��
	bool		m_isMaximized;		//�Ƿ����
	bool		m_isPaused;			//�Ƿ���ͣ����
	bool		m_isResizing;		//��������ڸı䴰�ڳߴ�ʱ

	ID3D11Device			*m_d3dDevice;				//D3D11�豸
	ID3D11DeviceContext		*m_deviceContext;			//�豸������
	IDXGISwapChain			*m_swapChain;				//������
	ID3D11Texture2D			*m_depthStencilBuffer;		//���/ģ�建����
	ID3D11RenderTargetView	*m_renderTargetView;		//��Ⱦ������ͼ
	ID3D11DepthStencilView	*m_depthStencilView;		//���/ģ����ͼ
	
	std::wstring	m_winTitle;			//��������
	Timer			m_timer;			//Ӧ�ó���ʱ��

private:
	//���⸴��
	WinApp(const WinApp&);
	WinApp& operator = (const WinApp&);
};

#endif	//_WIN_APP_H_