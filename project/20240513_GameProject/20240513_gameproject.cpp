#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>

//�萔
#define SCREEN_X 800
#define SCREEN_Y 600
#define CIRCLE_POS_X 400
#define CIRCLE_POS_Y 300
#define CIRCLE_RADIUS_START 10
#define CIRCLE_RADIUS_MAX 200

//�ϐ�
typedef struct circle
{
    int posX;
    int posY;
    int radius;
    int area;
}circle;

//�Q�[���t���O
bool enterPressedLastFrame = false;//�G���^�[�L�[�������ꂽ���ǂ����̃t���O
bool gameStartFlag = false;//�Q�[���J�n�t���O
bool circleGenerationsFlag = true;//�~�̐����t���O
bool gameEndFlag = true;//�Q�[���̏I���t���O

//�Q�[���J�E���g
int enterPreesCount;
//�\���̂�ϐ��ɂ���
circle Circle;
//�~�̍ő�ʐ�
double circleAreaMax = M_PI * CIRCLE_RADIUS_MAX * CIRCLE_RADIUS_MAX;

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

	//�~�̐F�w��
	int CircleColor = GetColor(128, 128, 128);
	//�~�̑傫���w��
	Circle.posX = CIRCLE_POS_X;
	Circle.posY = CIRCLE_POS_Y;
	Circle.radius = CIRCLE_RADIUS_START;

	//--------------------------//
	//�Q�[�����[�v
	//--------------------------//

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
	{
		//��ʂ̏�����
		ClearDrawScreen();

		//�G���^�[�L�[�������ăQ�[�����X�^�[�g
		if (CheckHitKey(KEY_INPUT_RETURN) && !enterPressedLastFrame)
		{
			//�Q�[���̊J�n
			gameStartFlag = !gameStartFlag;
		}
		//�G���^�[�L�[�������ꂽ�����L��������
		enterPressedLastFrame = CheckHitKey(KEY_INPUT_RETURN);
		//�~�̕ω�������
		if (gameStartFlag)
		{
			//�傫������
			if (circleGenerationsFlag)
			{
				//���a��5�����₷
				Circle.radius += 5;
				//���a���ő�l�ɂȂ�����t���O��ϊ�
				if (Circle.radius >= CIRCLE_RADIUS_MAX)
				{
					circleGenerationsFlag = false;
				}
			}
				//���a���T�����炷
			else
			{
				Circle.radius -= 5;
				//���a���ŏ��l�ɂȂ�����t���O��ϊ�
				if (Circle.radius <= CIRCLE_RADIUS_START)
				{
					circleGenerationsFlag = true;
				}
			}
			
		}

		//�~�̕`��
		DrawCircle(Circle.posX, Circle.posY, Circle.radius, CircleColor);

		//����ʂ̓��e��\��ʂɕ`�ʂ�����
		ScreenFlip();
		WaitTimer(1000 / 60);
	}

	//DsLib�I������
	DxLib_End();

	return 0;
}
