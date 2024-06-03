#include "DxLib.h"//Dxlib�����N���[�h

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

    int circleX = 150;//�~�̏����ʒu
    int circleY = 200;

    int stringX = 10;//�����̈ʒu
    int stringY = 15;

    int stringX1 = 10;//Hit!�̕����̈ʒu
    int stringY1 = 60;
    
    int mouseX = 0;//�}�E�X�̍��W
    int mouseY = 0;

    int circleColor = GetColor(0, 0, 225);//�~�̐F�w��

    int StringColor = GetColor(255, 255, 255);//�����̐F�w��
    int StringColor1 = GetColor(255, 0, 0);//Hit!�̕����̐F

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)//�Q�[�����[�v
    {
        ClearDrawScreen();//��ʂ̏�����

        DrawCircle(circleX, circleY, 30, circleColor, TRUE);//�~���X�N���[���ɕ\������

        GetMousePoint(&mouseX, &mouseY);//�}�E�X�J�[�\���̈ʒu���擾

        if (GetMouseInput() & (MOUSE_INPUT_LEFT))//�}�E�X�̍��N���b�N���������Ƃ�
        {
            SetFontSize(30);//�����̑傫��
            DrawString(stringX1, stringY1, "Hit!", StringColor1);//Hit!�ƕ\������
        }

        if (CheckHitKey(KEY_INPUT_W))
        {
            if (circleY <= 40)//�~��Y���W��40��菬�����Ȃ�����
            {
                circleY += 3;
            }
            else {
                circleY -= 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_S))
        {
            if (circleY >= 560)//�~��Y���W��560(��ʂ�600)���傫���Ȃ�����
            {
                circleY -= 3;
            }
            else {
                circleY += 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_A))
        {
            if (circleX <= 40)//�~��X���W��40��菬�����Ȃ�����
            {
                circleX += 3;
            }
            else {
                circleX -= 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_D))
        {
            if (circleX >= 760)//�~��X���W��760(��ʂ�800)���傫���Ȃ�����
            {
                circleX -= 3;
            }
            else {
                circleX += 3;
            }
        }

        SetFontSize(32);//�����̑傫���w��
        //DrawString(10, 15, "HelloWorld", StringColor);
        DrawFormatString(stringX, stringY, StringColor, "Circle X:%d Y:%d Mouse X:%d Y:%d",circleX, circleY, mouseX, mouseY);//�~�ƃ}�E�X�̍��W�\��

        ScreenFlip();//����ʂ̓��e��\��ʂɔ��f������
    }

    DxLib_End();//DxLib���I������ 

    return 0;//�\�[�X�̏I���
}