#include "DxLib.h"
#include <math.h>
#include <stdio.h>

//�萔
#define SCREEN_X 800
#define SCREEN_Y 600
#define START_STRING_X 230
#define START_STRING_Y 520

//�t���[���J�E���g
double frameCount = 0;
//�f���^�֐�
int prevCount, nowCount;

//�摜�n���h���ϐ�
int startScreenImage;
//�A���t�@�l
int alpha;

//���C���֐�
int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevlnstance, LPSTR lpCmdLine, int nCmdShow)//Windows�̃��C���œ�����
{
	//--------------------------//
	//��{�ݒ�
	//--------------------------//
	ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
	DxLib_Init();//DxLib�̏�����
	SetMainWindowText("�^�C�~���O�Q�[��");
	SetDrawScreen(DX_SCREEN_BACK);//��ʂ̔w�i�͍�
	SetGraphMode(SCREEN_X, SCREEN_Y, 32);//��ʂ̑傫��

	//DsLib�̏���������
	if (DxLib_Init() == -1)
	{
		//�G���[���N�����璼���ɏI��
		return -1;
	}
	//�摜���������ɒǉ�
	startScreenImage = LoadGraph("img/tittle01.png");

	//�����̐F
	int stringColor = GetColor(255, 99, 71);

	prevCount = GetNowCount();
	//--------------------------//
	//�Q�[�����[�v
	//--------------------------//

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
	{
		//���Ԃ��l��
		nowCount = GetNowCount();
		//�f���^�^�C��
		double deltaTime = (nowCount - prevCount) / 1000.0f;

		//�t���[���J�E���g�ɒǉ�
		frameCount += deltaTime * 1000;
		//�摜�̒ǉ�
		DrawExtendGraph(0,0,SCREEN_X, SCREEN_Y,startScreenImage,TRUE);
		//�A���t�@�l���v�Z
		alpha = (int)(255 * (0.5 * (1 + sin(frameCount * 0.003))));

		//�`�惂�[�h���u�����h���[�h�ɐݒ�
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,alpha);
		SetFontSize(30);
		DrawFormatString(START_STRING_X, START_STRING_Y, stringColor, "Press Enter to Start");
		//�`�惂�[�h��߂�
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);

		prevCount = nowCount;
	}


	//DsLib�I������
	DxLib_End();

	return 0;
}
