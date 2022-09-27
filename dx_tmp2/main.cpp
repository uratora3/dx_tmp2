#include "DxLib.h"

namespace
{
	constexpr bool kWindowMode = true;
	const char* const kTitleText = "�Q�[����";
	constexpr int kScreenWidth = 1280;
	constexpr int kScreenHeight = 720;
	constexpr int kColorDepth = 32;
}
// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// window���[�h�ɂ���
	ChangeWindowMode(kWindowMode);
	SetMainWindowText(kTitleText);
	SetGraphMode(kScreenWidth, kScreenHeight, kColorDepth);

	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);


	while (ProcessMessage() == 0)
	{
		LONGLONG  time = GetNowHiPerformanceCount();

		ClearDrawScreen();

		DrawString(160, 160, "a1aa2aaa3", GetColor(255, 255, 255));
		
		//����ʂ�\��ʂ����ւ���
		ScreenFlip();

		// esc�L�[����������I������
		if (CheckHitKey(KEY_INPUT_ESCAPE))	break;

		// fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{
		}
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}