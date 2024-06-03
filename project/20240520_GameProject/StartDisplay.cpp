#include "DxLib.h"
#include <math.h>
#include <stdio.h>

//定数
#define SCREEN_X 800
#define SCREEN_Y 600
#define START_STRING_X 230
#define START_STRING_Y 520

//フレームカウント
double frameCount = 0;
//デルタ関数
int prevCount, nowCount;

//画像ハンドル変数
int startScreenImage;
//アルファ値
int alpha;

//メイン関数
int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevlnstance, LPSTR lpCmdLine, int nCmdShow)//Windowsのメインで動かす
{
	//--------------------------//
	//基本設定
	//--------------------------//
	ChangeWindowMode(TRUE);//Windowsの画面をアクティブにする
	DxLib_Init();//DxLibの初期化
	SetMainWindowText("タイミングゲーム");
	SetDrawScreen(DX_SCREEN_BACK);//画面の背景は黒
	SetGraphMode(SCREEN_X, SCREEN_Y, 32);//画面の大きさ

	//DsLibの初期化処理
	if (DxLib_Init() == -1)
	{
		//エラーが起きたら直ちに終了
		return -1;
	}
	//画像をメモリに追加
	startScreenImage = LoadGraph("img/tittle01.png");

	//文字の色
	int stringColor = GetColor(255, 99, 71);

	prevCount = GetNowCount();
	//--------------------------//
	//ゲームループ
	//--------------------------//

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
	{
		//時間を獲得
		nowCount = GetNowCount();
		//デルタタイム
		double deltaTime = (nowCount - prevCount) / 1000.0f;

		//フレームカウントに追加
		frameCount += deltaTime * 1000;
		//画像の追加
		DrawExtendGraph(0,0,SCREEN_X, SCREEN_Y,startScreenImage,TRUE);
		//アルファ値を計算
		alpha = (int)(255 * (0.5 * (1 + sin(frameCount * 0.003))));

		//描画モードをブレンドモードに設定
		SetDrawBlendMode(DX_BLENDMODE_ALPHA,alpha);
		SetFontSize(30);
		DrawFormatString(START_STRING_X, START_STRING_Y, stringColor, "Press Enter to Start");
		//描画モードを戻す
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);

		prevCount = nowCount;
	}


	//DsLib終了処理
	DxLib_End();

	return 0;
}
