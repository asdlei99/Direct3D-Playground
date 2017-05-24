#include "AppUtil.h"
#include "WinApp.h"

//����һ�����࣬�̳п�����ࣺWinApp
class Basic : public WinApp
{
public:
	Basic(HINSTANCE hInst, std::wstring title = L"D3D11ѧϰ������", int width = 640, int height = 480) :
		WinApp(hInst, title, width, height)
	{}

	//��������Ա����������д
	bool Update(float delta);
	bool Render();

private:
	//�����ﶨ���������������س�Ա����
};

//�������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cmdLine, int cmdShow)
{
	//�����������
	Basic app(hInstance);

	//��ʼ��
	if (!app.Init())
		return -1;

	//�����������ʼ����صĳ�Ա�������������������

	//��ʼ����
	return app.Run();
}

bool Basic::Update(float delta)
{
	//����

	return true;
}

bool Basic::Render()
{
	m_deviceContext->ClearDepthStencilView(m_depthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.f, 0);
	m_deviceContext->ClearRenderTargetView(m_renderTargetView, reinterpret_cast<const float*>(&Colors::Green));

	//��Ⱦ����

	m_swapChain->Present(0, 0);

	return true;
}