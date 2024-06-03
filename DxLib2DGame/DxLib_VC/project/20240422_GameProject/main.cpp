#include "DxLib.h"//Dxlibをンクルード

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//windowsをメインで動かす
{

    //基本設計
    ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
    DxLib_Init();//DxLibの初期化
    SetDrawScreen(DX_SCREEN_BACK);//画面の色
    SetGraphMode(800, 600, 32);//画面の大きさ

    if (DxLib_Init() == -1)
    {
        return -1;//もしもエラーが起きたら、速やかに終了する
    }

    int circleX = 150;//円の初期位置
    int circleY = 200;

    int stringX = 10;//文字の位置
    int stringY = 15;

    int stringX1 = 10;//Hit!の文字の位置
    int stringY1 = 60;
    
    int mouseX = 0;//マウスの座標
    int mouseY = 0;

    int circleColor = GetColor(0, 0, 225);//円の色指定

    int StringColor = GetColor(255, 255, 255);//文字の色指定
    int StringColor1 = GetColor(255, 0, 0);//Hit!の文字の色

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)//ゲームループ
    {
        ClearDrawScreen();//画面の初期化

        DrawCircle(circleX, circleY, 30, circleColor, TRUE);//円をスクリーンに表示する

        GetMousePoint(&mouseX, &mouseY);//マウスカーソルの位置を取得

        if (GetMouseInput() & (MOUSE_INPUT_LEFT))//マウスの左クリックを押したとき
        {
            SetFontSize(30);//文字の大きさ
            DrawString(stringX1, stringY1, "Hit!", StringColor1);//Hit!と表示する
        }

        if (CheckHitKey(KEY_INPUT_W))
        {
            if (circleY <= 40)//円のY座標が40より小さくなったら
            {
                circleY += 3;
            }
            else {
                circleY -= 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_S))
        {
            if (circleY >= 560)//円のY座標が560(画面は600)より大きくなったら
            {
                circleY -= 3;
            }
            else {
                circleY += 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_A))
        {
            if (circleX <= 40)//円のX座標が40より小さくなったら
            {
                circleX += 3;
            }
            else {
                circleX -= 3;
            }
        }
        if (CheckHitKey(KEY_INPUT_D))
        {
            if (circleX >= 760)//円のX座標が760(画面は800)より大きくなったら
            {
                circleX -= 3;
            }
            else {
                circleX += 3;
            }
        }

        SetFontSize(32);//文字の大きさ指定
        //DrawString(10, 15, "HelloWorld", StringColor);
        DrawFormatString(stringX, stringY, StringColor, "Circle X:%d Y:%d Mouse X:%d Y:%d",circleX, circleY, mouseX, mouseY);//円とマウスの座標表示

        ScreenFlip();//裏画面の内容を表画面に反映させる
    }

    DxLib_End();//DxLibを終了する 

    return 0;//ソースの終わり
}