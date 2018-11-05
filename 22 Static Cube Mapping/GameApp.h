#ifndef GAMEAPP_H
#define GAMEAPP_H

#include "d3dApp.h"
#include "Camera.h"
#include "GameObject.h"
#include "SkyRender.h"
#include "ObjReader.h"
#include "Collision.h"
class GameApp : public D3DApp
{
public:
	// �����ģʽ
	enum class CameraMode { FirstPerson, ThirdPerson, Free };
	// ��պ�ģʽ
	enum class SkyBoxMode { Daylight, Sunset, Desert };

public:
	GameApp(HINSTANCE hInstance);
	~GameApp();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();

private:
	bool InitResource();
	
private:
	
	ComPtr<ID2D1SolidColorBrush> mColorBrush;				// ��ɫ��ˢ
	ComPtr<IDWriteFont> mFont;								// ����
	ComPtr<IDWriteTextFormat> mTextFormat;					// �ı���ʽ

	GameObject mSphere;										// ��
	GameObject mGround;										// ����
	GameObject mCylinder;									// Բ��

	BasicEffect mBasicEffect;								// ������Ⱦ��Ч����
	
	SkyEffect mSkyEffect;									// ��պ���Ч����
	std::unique_ptr<SkyRender> mDaylight;					// ��պ�(����)
	std::unique_ptr<SkyRender> mSunset;						// ��պ�(����)
	std::unique_ptr<SkyRender> mDesert;						// ��պ�(ɳĮ)
	SkyBoxMode mSkyBoxMode;									// ��պ�ģʽ

	std::shared_ptr<Camera> mCamera;						// �����
	CameraMode mCameraMode;									// �����ģʽ

	ObjReader mObjReader;									// ģ�Ͷ�ȡ����
};


#endif