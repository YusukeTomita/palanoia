#include "DxLib.h"//Dxlibをインクルード

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

    int circleX = 320;//円の初期位置
    int circleY = 240;


    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)//ゲームをエンドレスにさせる
    {
        ClearDrawScreen();//画面の初期化

        DrawCircle(circleX, circleY, 30, GetColor(0, 0, 225), TRUE);//円をスクリーンに表示する

        circleX += 4;//円のX軸方向
        circleY += 3;//円のY軸方向
        if (circleX >= 800)
        {
            circleX = 0;
            circleY = 0;
        }

        ScreenFlip();//裏画面の内容を表画面に反映させる
    }

    DrawPixel(320, 240, GetColor(255, 0, 0));//画面の点の色をRGB値で表示する

    WaitKey();//エンターキーを待つ

    return 0;//ソースの終わり
}