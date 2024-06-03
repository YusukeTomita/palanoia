#include "DxLib.h"//Dxlib���C���N���[�h

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//windows�����C���œ�����
{

    //��{�݌v
    ChangeWindowMode(TRUE);//Windows�̉�ʂ��A�N�e�B�u�ɂ���
    DxLib_Init();//DxLib�̏�����
    SetDrawScreen(DX_SCREEN_BACK);//��ʂ̐F
    SetGraphMode(800, 600, 32);//��ʂ̑傫��

    if (DxLib_Init() == -1)
    {
        return -1;//�������G���[���N������A���₩�ɏI������
    }

    int circleX = 320;//�~�̏����ʒu
    int circleY = 240;


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)//�Q�[�����G���h���X�ɂ�����
    {
        ClearDrawScreen();//��ʂ̏�����

        DrawCircle(circleX, circleY, 30, GetColor(0, 0, 225), TRUE);//�~���X�N���[���ɕ\������

        circleX += 4;//�~��X������
        circleY += 3;//�~��Y������
        if (circleX >= 800)
        {
            circleX = 0;
            circleY = 0;
        }

        ScreenFlip();//����ʂ̓��e��\��ʂɔ��f������
    }

    DrawPixel(320, 240, GetColor(255, 0, 0));//��ʂ̓_�̐F��RGB�l�ŕ\������

    WaitKey();//�G���^�[�L�[��҂�

    return 0;//�\�[�X�̏I���
}