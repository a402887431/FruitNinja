#include"stdafx.h"
#include"EasyXPng.h"
#include<graphics.h>
#include <conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<mmsystem.h>
#include "Definition.h"
#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)

#pragma comment(lib,"Winmm.lib")
#define Width 640
#define High 480

void loadimage_x()
{
	loadimage(&img_flash, ".\\source\\images\\flash.jpg");
	loadimage(&img_bk, ".\\source\\images\\background.jpg");
	loadimage(&img_apple1, ".\\source\\images\\fruit\\apple.png");
	loadimage(&img_banana1, ".\\source\\images\\fruit\\banana.png");
	loadimage(&img_basaha1, ".\\source\\images\\fruit\\basaha.png");
	loadimage(&img_peach1, ".\\source\\images\\fruit\\peach.png");
	loadimage(&img_sandia1, ".\\source\\images\\fruit\\sandia.png");
	loadimage(&img_boom1, ".\\source\\images\\fruit\\boom.png");

	loadimage(&img_apple_L1, ".\\source\\images\\fruit\\apple-1.bmp");
	loadimage(&img_apple_L2, ".\\source\\images\\fruit\\apple-1_mask.bmp");
	loadimage(&img_banana_L1, ".\\source\\images\\fruit\\banana-1bmp");
	loadimage(&img_banana_L2, ".\\source\\images\\fruit\\banana-1_mask.bmp");
	loadimage(&img_basaha_L1, ".\\source\\images\\fruit\\basaha-1.bmp");
	loadimage(&img_basaha_L2, ".\\source\\images\\fruit\\basaha-1_mask.bmp");
	loadimage(&img_peach_L1, ".\\source\\images\\fruit\\peach-1.bmp");
	loadimage(&img_peach_L2, ".\\source\\images\\fruit\\peach-1_mask.bmp");
	loadimage(&img_sandia_L1, ".\\source\\images\\fruit\\sandia-1.bmp");
	loadimage(&img_sandia_L2, ".\\source\\images\\fruit\\sandia-1_mask.bmp");
	
	loadimage(&img_x, ".\\source\\images\\x.png");
	loadimage(&img_xx, ".\\source\\images\\xx.png");
	loadimage(&img_xxx, ".\\source\\images\\xxx.png");
	loadimage(&img_xf, ".\\source\\images\\xf.png");
	loadimage(&img_xxf, ".\\source\\images\\xxf.png");
	loadimage(&img_xxxf, ".\\source\\images\\xxxf.png");
	
	loadimage(&img_score, ".\\source\\images\\score.png");

	loadimage(&img_newgame1, ".\\source\\images\\new-game.png");
	loadimage(&img_fruit, ".\\source\\images\\logo.png");
	loadimage(&img_ninja, ".\\source\\images\\ninja.png");
	loadimage(&img_new, ".\\source\\images\\new.png");
	loadimage(&img_shallow, ".\\source\\images\\home-mask.png");
	loadimage(&img_tip, ".\\source\\images\\home-desc.png");
	loadimage(&img_dojo1, ".\\source\\images\\dojo.png");
	loadimage(&img_quit1, ".\\source\\images\\quit.png");

	loadimage(&img_gameover_1, ".\\source\\images\\game-over.png");





	loadimage(&chaomeng1, ".\\congwu\\chaomeng.png");
	loadimage(&chenglong1, ".\\congwu\\chenglong.png");
	loadimage(&jienigui1, ".\\congwu\\jienigui.png");
	loadimage(&kabi1, ".\\congwu\\kabi.png");
	loadimage(&pikaqiu1, ".\\congwu\\pikaqiu.png");
	loadimage(&qinglong1, ".\\congwu\\qinglong.png");
	loadimage(&menghuan1, ".\\congwu\\menghuan.png");
	loadimage(&shuijingling1, ".\\congwu\\shuijingling.png");
	loadimage(&yibu1, ".\\congwu\\yibu.png");
	loadimage(&xiaohuolong1, ".\\congwu\\xiaohuolong.png");

	loadimage(&congwu_bj, ".\\congwu\\congwu_bj.jpg");

	loadimage(&pikai_s, ".\\congwu\\pika_s.png");





	loadimage(&cw_fh1, ".\\congwu\\cw_fh.png");



}
void startup()
{
	t1 = 1;
	t2 = 1;
	t3 = 1;
	t4 = 1;
	flag1 = 1;
	flag2 = 0,
	flag3 = 0,
	flag4 = 0;
	flag = 0;
	srand((unsigned)time(NULL));

	int k;
	for (k = 0; k < 10; k++)	{
		Fruit_x1[k] = 200 + rand() % 100;
		Fruit_y1[k] = High + 20;
	}
	for (k = 0; k < 10; k++)	{
		Fruit_x2[k] = 200 + rand() % 100;
		Fruit_y2[k] = High + 20;
	}
	for (k = 0; k < 3; k++)	{
		Boom_x1[k] = 200 + rand() % 100;
		Boom_y1[k] = High + 20;
	}
	for (k = 0; k < 3; k++)	{
		Boom_x2[k] = 200 + rand() % 100;
		Boom_y2[k] = High + 20;
	}

	Fruit_n1 = rand() % 7 + 1;
	Fruit_n2 = rand() % 7 + 1;
	initgraphEx();
	initgraph(640, 480);
	loadimage_x();
}
void show_menu()
{
	cleardevice();
	BeginBatchDraw();
	putimage(0, 0, &img_bk);
	putimage(0, 0, &img_shallow);
	putimage(20, 10, &img_fruit);
	putimage(315, 45, &img_ninja);
	putimage(20, 135, &img_tip);
	//显示西瓜——新游戏
	if (sandiaL_roll == 1)
		putimage(260, 250, &img_sandia2);
	//西瓜 外面的图片———新游戏
	if (newgameL_roll == 1)
		putimage(190, 175, &img_newgame2);
	//显示 芒果
	if (peachL_roll == 1)
		putimage(80, 280, &img_peach2);
	//芒果的背景 图
	if (dojoL_roll == 1)
		putimage(0, 200, &img_dojo2);
	//显示 炸弹 ——离开游戏
	if (boomL_roll == 1)
		putimage(500, 310, &img_boom2);
	//游戏名字 背景图
	if (quitL_roll == 1)
		putimage(450, 260, &img_quit2);
	//显示皮卡丘
	if (pikaqiuL_roll == 1)
		putimage(500, 150, &pikaqiu2);



	FlushBatchDraw();
	Sleep(20);
}
void updateWithoutInput_menu()
{
	mciSendString(_T("open .\\source\\sound\\menu.mp3 alias bkmusic"), NULL, 0, NULL);//打开背景音乐
	mciSendString(_T("play bkmusic repeat"), NULL, 0, NULL);  // 循环播放
	//让 菜单界面的图片旋转起来
	rotateimage(&img_sandia2, &img_sandia1, sandia_rotate += 3.3);
	sandiaL_roll = 1;

	rotateimage(&img_newgame2, &img_newgame1, newgame_rotate -= 1.6);
	newgameL_roll = 1;

	rotateimage(&img_peach2, &img_peach1, peach_rotate += 1.1);
	peachL_roll = 1;

	rotateimage(&img_dojo2, &img_dojo1, dojo_rotate -= 1.7);
	dojoL_roll = 1;

	rotateimage(&img_boom2, &img_boom1, boom_rotate -= 1.8);
	boomL_roll = 1;

	rotateimage(&img_quit2, &img_quit1, quit_rotate += 1.2);
	quitL_roll = 1;

	rotateimage(&pikaqiu2, &pikaqiu1, pikaqiu_rotate += 3.5);
	pikaqiuL_roll = 1;
}
void updateWithInput_menu()
{
	HWND hwnd = GetHWnd();
	POINT fruit_knife;															//定义水果刀的位置

	

	if (KEY_DOWN(VK_LBUTTON))
	{
		GetCursorPos(&fruit_knife);
		ScreenToClient(hwnd, &fruit_knife);										//获取光标的位置，即为水果刀的位置
																		//以下为水果刀切到水果
		
		//切西瓜后 进行的一系列操作
		if ((fruit_knife.x - 260 - 49)*(fruit_knife.x - 260 - 49) + (fruit_knife.y - 250 - 43)*(fruit_knife.y - 250 - 43) < 1800)
		{
			flag = 1;
			start = time(NULL);
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			mciSendString(_T("close bkmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(_T("close startmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString("open .\\source\\sound\\start.mp3 alias startmusic", NULL, 0, NULL); // 打开开始音乐
			mciSendString("play startmusic", NULL, 0, NULL); // 仅播放一次开始音乐
		}
		//切炸弹后的操作
		if ((fruit_knife.x - 500 - 33)*(fruit_knife.x - 500 - 33) + (fruit_knife.y - 310 - 33)*(fruit_knife.y - 310 - 33) < 1089)
		{
			exit(0);
		}
		//切芒果后的操作
		if ((fruit_knife.x - 80 - 31)*(fruit_knife.x - 80 - 31) + (fruit_knife.y - 280 - 30)*(fruit_knife.y - 280 - 30) < 900)
		{
			flag = 3;
			start = time(NULL);
			start2 = time(NULL);
			start3 = clock();
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			mciSendString(_T("close bkmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString(_T("close startmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
			mciSendString("open .\\source\\sound\\start.mp3 alias startmusic", NULL, 0, NULL); // 打开开始音乐
			mciSendString("play startmusic", NULL, 0, NULL); // 仅播放一次开始音乐
		}
		//切除皮卡丘后的操作
		if ((fruit_knife.x - 500 - 33)*(fruit_knife.x - 500 - 33) + (fruit_knife.y - 150 - 33)*(fruit_knife.y - 150 - 33) < 1089)
		{
			flag = 4;
		}
	}

}

void congwu_show()
{
	mciSendString(_T("close bkmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
	cleardevice();
	BeginBatchDraw();
	putimage(0, 0, &congwu_bj);
	putimage(20, 70, &pikai_s);


	//显示 提示
	char s[100];
	LOGFONT f;
	char tisi[100] = "开局一只yzm，进化全靠砍水果";
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 40;                      // 设置字体高度为 40
	_tcscpy_s(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC	或者VS推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	setcolor(RED);                    //作图色为黄色
	settextstyle(&f);                     // 设置字体样式
	sprintf_s(s, "%s", tisi);
	setbkmode(TRANSPARENT);
	outtextxy(0, 13, s);
	if (cw_fhL_roll == 1)
		putimage(500, 350, &cw_fh2);
	FlushBatchDraw();
}
void updateWithoutInput_congwu()
{
	rotateimage(&cw_fh2, &cw_fh1, cw_fh_rotate += 0.3);
	cw_fhL_roll = 1;
}
void updateWithInput_congwu()
{
	HWND hwnd = GetHWnd();
	POINT fruit_knife;															//定义水果刀的位置
	if (KEY_DOWN(VK_LBUTTON))
	{
		GetCursorPos(&fruit_knife);
		ScreenToClient(hwnd, &fruit_knife);
		if ((fruit_knife.x - 500 - 33)*(fruit_knife.x - 500 - 33) + (fruit_knife.y - 350 - 33)*(fruit_knife.y - 350 - 33) < 1089)
		{
			flag = 0;
		}
	}
}

void method()
{
	if (Fruit_n1 == 1) {
		if (peach_flag1 == 1) {
			if (peachL_roll == 1)
				putimage(Fruit_x1[2], Fruit_y1[2], &img_peach2);
		}
	}
	if (Fruit_n1 == 2) {
		if (apple_flag1 == 1) {
			if (appleL_roll == 1)
				putimage(Fruit_x1[1], Fruit_y1[1], &img_apple2);
		}
		if (banana_flag1 == 1) {
			if (bananaL_roll == 1)
				putimage(Fruit_x1[0], Fruit_y1[0], &img_banana2);
		}
	}
	if (Fruit_n1 == 3) {
		if (peach_flag1 == 1) {
			if (peachL_roll == 1)
				putimage(Fruit_x1[2], Fruit_y1[2], &img_peach2);
		}
		if (sandia_flag1 == 1) {
			if (sandiaL_roll == 1)
				putimage(Fruit_x1[3], Fruit_y1[3], &img_sandia2);
		}
	}
	if (Fruit_n1 == 4) {
		if (apple_flag1 == 1) {
			if (appleL_roll == 1)
				putimage(Fruit_x1[1], Fruit_y1[1], &img_apple2);
		}
		if (sandia_flag1 == 1) {
			if (sandiaL_roll == 1)
				putimage(Fruit_x1[3], Fruit_y1[3], &img_sandia2);
		}
	}
	if (Fruit_n1 == 5) {
		if (banana_flag1 == 1) {
			if (bananaL_roll == 1)
				putimage(Fruit_x1[0], Fruit_y1[0], &img_banana2);
		}
		if (peach_flag1 == 1) {
			if (peachL_roll == 1)
				putimage(Fruit_x1[2], Fruit_y1[2], &img_peach2);
		}
		if (basaha_flag1 == 1) {
			if (basahaL_roll == 1)
				putimage(Fruit_x1[4], Fruit_y1[4], &img_basaha2);
		}
	}
	if (Fruit_n1 == 6) {
		if (basaha_flag1 == 1) {
			if (basahaL_roll == 1)
				putimage(Fruit_x1[4], Fruit_y1[4], &img_basaha2);
		}
	}
	if (Fruit_n1 == 7) {
		if (apple_flag1 == 1) {
			if (appleL_roll == 1)
				putimage(Fruit_x1[1], Fruit_y1[1], &img_apple2);
		}
		if (basaha_flag1 == 1) {
			if (basahaL_roll == 1)
				putimage(Fruit_x1[4], Fruit_y1[4], &img_basaha2);
		}
	}
	if (Fruit_n2 == 1) {
		if (banana_flag2 == 1) {
			if (bananaR_roll == 1)
				putimage(Fruit_x2[0], Fruit_y2[0], &img_banana2);
		}
		if (peach_flag2 == 1) {
			if (peachR_roll == 1)
				putimage(Fruit_x2[2], Fruit_y2[2], &img_peach2);
		}
	}
	if (Fruit_n2 == 2) {
		if (peach_flag2 == 1) {
			if (peachR_roll == 1)
				putimage(Fruit_x2[2], Fruit_y2[2], &img_peach2);
		}
		if (sandia_flag2 == 1) {
			if (sandiaR_roll == 1)
				putimage(Fruit_x2[3], Fruit_y2[3], &img_sandia2);
		}
		if (basaha_flag2 == 1) {
			if (basahaR_roll == 1)
				putimage(Fruit_x2[4], Fruit_y2[4], &img_basaha2);
		}
	}
	if (Fruit_n2 == 3) {
		if (sandia_flag2 == 1) {
			if (sandiaR_roll == 1)
				putimage(Fruit_x2[3], Fruit_y2[3], &img_sandia2);
		}
	}
	if (Fruit_n2 == 4) {
		if (banana_flag2 == 1) {
			if (bananaR_roll == 1)
				putimage(Fruit_x2[0], Fruit_y2[0], &img_banana2);
		}
		if (peach_flag2 == 1) {
			if (peachR_roll == 1)
				putimage(Fruit_x2[2], Fruit_y2[2], &img_peach2);
		}
	}
	if (Fruit_n2 == 5) {
		if (banana_flag2 == 1) {
			if (bananaR_roll == 1)
				putimage(Fruit_x2[0], Fruit_y2[0], &img_banana2);
		}
		if (apple_flag2 == 1) {
			if (appleR_roll)
				putimage(Fruit_x2[1], Fruit_y2[1], &img_apple2);
		}
	}
	if (Fruit_n2 == 6) {
		if (basaha_flag2 == 1) {
			if (basahaR_roll == 1)
				putimage(Fruit_x2[4], Fruit_y2[4], &img_basaha2);
		}
	}
	if (Fruit_n2 == 7) {
		if (peach_flag2 == 1) {
			if (peachR_roll == 1)
				putimage(Fruit_x2[2], Fruit_y2[2], &img_peach2);
		}
		if (basaha_flag2 == 1)
		{
			if (basahaR_roll == 1)
				putimage(Fruit_x2[4], Fruit_y2[4], &img_basaha2);
		}

	}
}
void show()
{
	mciSendString(_T("close bkmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
	cleardevice();
	BeginBatchDraw();
	putimage(0, 0, &img_bk);	// 显示背景
	putimage(545, 15, &img_x);
	putimage(570, 15, &img_xx);
	putimage(600, 15, &img_xxx);
	putimage(15, 15, &img_score);

	//显示炸弹
	char s[5];
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 40;                      // 设置字体高度为 40
	_tcscpy_s(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC	或者VS推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	setcolor(YELLOW);                    //作图色为黄色
	settextstyle(&f);                     // 设置字体样式
	sprintf_s(s, "%d", score);
	setbkmode(TRANSPARENT);
	outtextxy(55, 13, s);

	//显示红叉
	if (flag_omit1 == 1)
		putimage(545, 15, &img_xf);
	if (flag_omit2 == 1){
		putimage(545, 15, &img_xf);
		putimage(570, 15, &img_xxf);
	}
	if (flag_omit3 == 1){
		putimage(545, 15, &img_xf);
		putimage(570, 15, &img_xxf);
		putimage(600, 15, &img_xxxf);
	}

	//自定义生成水果的方法
	method();
	end = time(NULL);
}
void ShowBoom()
{
	if (boomL_roll == 1)
		putimage(Boom_x1[0], Boom_y1[0], &img_boom2);

	if (boomR_roll == 1)
		putimage(Boom_x2[0], Boom_y2[0], &img_boom2);
	FlushBatchDraw();
	Sleep(2);
}

void speed1(float *x, float *y)
{
	*y = High + 20 + 20 + Velocity_y1 * t1;
	*x += Velocity_x1;
}
void speed2(float *x, float *y)
{
	*y = High + 20 + 20 + Velocity_y2 * t2;
	*x += -0.7*Velocity_x2;
}
void speed3(float *x, float *y)
{
	*y = High + 20 + 20 + 1.5*Velocity_y3 * t3;
	*x += -0.5*Velocity_x3;
}
void speed4(float *x, float *y)
{
	*y = High + 20 + 20 + 1.2*Velocity_y4 * t4;
	*x += 1.7*Velocity_x4;
}

void method2()
{
	if (count1 == 400) {
		flag_2 = 0;
	}
	else if (count1 == 900) {
		flag_1 = 0;
	}
	else if (count1 == 1400) {
		flag_2 = 0;
	}
	else if (count1 == 1200) {
		flag_3 = 0;
	}

	else if (count1 == 2000) {
		flag_1 = 0;
		flag_4 = 0;
		count1 = 0;
	}
	if (flag_2 == 0)
	{
		banana_flag2 = 1;//香蕉的出现
		apple_flag2 = 1;//苹果的出现
		peach_flag2 = 1;//芒果的出现
		sandia_flag2 = 1;//西瓜的出现
		basaha_flag2 = 1;//草莓的出现
		Fruit_n2 = rand() % 7 + 1;
		PlaySound(".\\source\\sound\\throw.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		Velocity_y2 = v0;
		t2 = 1;
		for (k2 = 0; k2 < 10; k2++)
		{
			Fruit_x2[k2] = 200 + rand() % (Width - 460);
			Fruit_y2[k2] = High + 20;
		}
		flag2 = 1;
		flag_2 = 1;
	}

	if (flag2 == 1)
	{
		if (Fruit_n2 == 1)
		{
			speed2(&Fruit_x2[0], &Fruit_y2[0]);
			speed2(&Fruit_x2[2], &Fruit_y2[2]);
		}
		if (Fruit_n2 == 2)
		{
			speed2(&Fruit_x2[2], &Fruit_y2[2]);
			speed2(&Fruit_x2[3], &Fruit_y2[3]);
			speed2(&Fruit_x2[4], &Fruit_y2[4]);
		}
		if (Fruit_n2 == 3)
		{
			speed2(&Fruit_x2[3], &Fruit_y2[3]);
		}
		if (Fruit_n2 == 4)
		{
			speed2(&Fruit_x2[0], &Fruit_y2[0]);
			speed2(&Fruit_x2[2], &Fruit_y2[2]);
		}
		if (Fruit_n2 == 5)
		{
			speed2(&Fruit_x2[0], &Fruit_y2[0]);
			speed2(&Fruit_x2[1], &Fruit_y2[1]);
		}
		if (Fruit_n2 == 6)
		{
			speed2(&Fruit_x2[4], &Fruit_y2[4]);
		}
		if (Fruit_n2 == 7)
		{
			speed2(&Fruit_x2[2], &Fruit_y2[2]);
			speed2(&Fruit_x2[4], &Fruit_y2[4]);
		}
	}
	if (flag_1 == 0)
	{
		banana_flag1 = 1;//香蕉的出现
		apple_flag1 = 1;//苹果的出现
		peach_flag1 = 1;//芒果的出现
		sandia_flag1 = 1;//西瓜的出现
		basaha_flag1 = 1;//草莓的出现
		Fruit_n1 = rand() % 7 + 1;
		PlaySound(".\\source\\sound\\throw.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		t1 = 1;
		Velocity_y1 = v0;
		for (k1 = 0; k1 < 10; k1++)
		{
			Fruit_x1[k1] = 200 + rand() % (Width - 460);
			Fruit_y1[k1] = High + 20;
		}
		flag1 = 1;
		flag_1 = 1;
	}
	if (flag1 == 1)
	{
		if (Fruit_n1 == 1)
		{
			speed1(&Fruit_x1[2], &Fruit_y1[2]);
		}
		if (Fruit_n1 == 2)
		{
			speed1(&Fruit_x1[1], &Fruit_y1[1]);
			speed1(&Fruit_x1[0], &Fruit_y1[0]);
		}
		if (Fruit_n1 == 3)
		{
			speed1(&Fruit_x1[2], &Fruit_y1[2]);
			speed1(&Fruit_x1[3], &Fruit_y1[3]);
		}
		if (Fruit_n1 == 4)
		{
			speed1(&Fruit_x1[1], &Fruit_y1[1]);
			speed1(&Fruit_x1[3], &Fruit_y1[3]);
		}
		if (Fruit_n1 == 5)
		{
			speed1(&Fruit_x1[0], &Fruit_y1[0]);
			speed1(&Fruit_x1[2], &Fruit_y1[2]);
		}
		if (basaha_flag1 == 1)
		{
			speed1(&Fruit_x1[4], &Fruit_y1[4]);
		}
		if (Fruit_n1 == 6)
		{
			speed1(&Fruit_x1[4], &Fruit_y1[4]);
		}
		if (Fruit_n1 == 7)
		{
			speed1(&Fruit_x1[1], &Fruit_y1[1]);
			speed1(&Fruit_x1[4], &Fruit_y1[4]);
		}
	}
}
void method3()
{
	rotateimage(&img_apple2, &img_apple1, apple_rotate += 1);
	appleL_roll = 1;
	appleR_roll = 1;
	rotateimage(&img_banana2, &img_banana1, banana_rotate += 1.5);
	bananaL_roll = 1;
	bananaR_roll = 1;
	rotateimage(&img_peach2, &img_peach1, peach_rotate -= 0.9);
	peachL_roll = 1;
	peachR_roll = 1;
	rotateimage(&img_basaha2, &img_basaha1, basaha_rotate += 1.2);
	basahaL_roll = 1;
	basahaR_roll = 1;
	rotateimage(&img_sandia2, &img_sandia1, sandia_rotate -= 1.3);
	sandiaL_roll = 1;
	sandiaR_roll = 1;
	rotateimage(&img_boom2, &img_boom1, boom_rotate += 2);
	boomL_roll = 1;
	boomR_roll = 1;
}

void updateWithoutInput()
{
	if (end - start > 3)//3秒以后再出现水果
	{
		count1++;
		method2();
		if (flag_3 == 0)
		{
			for (k1 = 0; k1 < 2; k1++)
			{
				Boom_x1[k1] = 200 + rand() % (Width - 460);
				Boom_y1[k1] = High + 20;
			}
			PlaySound(".\\source\\sound\\throw.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			Velocity_y3 = v0;
			t3 = 1;
			flag3 = 1;
			flag_3 = 1;
		}
		if (flag3 == 1)
		{
			speed3(Boom_x1, Boom_y1);
		}
		if (flag_4 == 0)
		{
			for (k1 = 0; k1 < 2; k1++)
			{
				Boom_x2[k1] = 200 + rand() % (Width - 460);
				Boom_y2[k1] = High + 20;
			}

			Velocity_y4 = v0;
			t4 = 1;
			flag4 = 1;
			flag_4 = 1;
		}
		if (flag4 == 1)
		{
			speed4(Boom_x2, Boom_y2);
		}
		Velocity_y1 += g * t1;
		Velocity_y2 += (1.4)*g * t2;
		Velocity_y3 += 1.8*g*t3;
		Velocity_y4 += 1.6*g*t4;
		t1++;
		t2++;
		t3++;
		t4++;
	}
	method3();
	if ((Fruit_y1[0] == 495.000005) || (Fruit_y1[1] == 495.000005) || (Fruit_y1[2] == 495.000005) || (Fruit_y1[3] == 495.000005) || (Fruit_y1[4] == 495.000005) || (Fruit_y2[0] == 495.000005) || (Fruit_y2[1] == 495.000005) || (Fruit_y2[2] == 495.000005) || (Fruit_y2[3] == 495.000005) || (Fruit_y2[4] == 495.000005))
		omit++;
	if ((Fruit_y1[0] == 505.000000) || (Fruit_y1[1] == 505.000000) || (Fruit_y1[2] == 505.000000) || (Fruit_y1[3] == 505.000000) || (Fruit_y1[4] == 505.000000) || (Fruit_y2[0] == 505.000000) || (Fruit_y2[1] == 505.000000) || (Fruit_y2[2] == 505.000000) || (Fruit_y2[3] == 505.000000) || (Fruit_y2[4] == 505.000000) && omit == 1)
		omit++;
	if ((Fruit_y1[0] == 505.000000) || (Fruit_y1[1] == 505.000000) || (Fruit_y1[2] == 505.000000) || (Fruit_y1[3] == 505.000000) || (Fruit_y1[4] == 505.000000) || (Fruit_y2[0] == 505.000000) || (Fruit_y2[1] == 505.000000) || (Fruit_y2[2] == 505.000000) || (Fruit_y2[3] == 505.000000) || (Fruit_y2[4] == 505.000000) && omit == 2)
		omit++;
}
void updateWithInput()
{
	HWND hwnd = GetHWnd();
	POINT fruit_knife;				//定义水果刀的位置
	if (KEY_DOWN(VK_LBUTTON))
	{
		GetCursorPos(&fruit_knife);
		ScreenToClient(hwnd, &fruit_knife);			//获取光标的位置，即为水果刀的位置
		if ((banana_flag1 == 1) && (fruit_knife.x - Fruit_x1[0] - 63)*(fruit_knife.x - Fruit_x1[0] - 63) + (fruit_knife.y - Fruit_y1[0] - 25)*(fruit_knife.y - Fruit_y1[0] - 25) <= 900){
			score++;
			banana_flag1 = 0;
			putimage(Fruit_x1[0] + 63, Fruit_y1[0] + 25, &img_flash);
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((apple_flag1 == 1) && ((fruit_knife.x - Fruit_x1[1] - 33)*(fruit_knife.x - Fruit_x1[1] - 33) + (fruit_knife.y - Fruit_y1[1] - 33)*(fruit_knife.y - Fruit_y1[1] - 33)) <= 1000){
			score++;
			apple_flag1 = 0;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((peach_flag1 == 1) && ((fruit_knife.x - Fruit_x1[2] - 33)*(fruit_knife.x - Fruit_x1[2] - 33) + (fruit_knife.y - Fruit_y1[2] - 33)*(fruit_knife.y - Fruit_y1[2] - 33)) <= 1000){
			score++;
			peach_flag1 = 0;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((sandia_flag1 == 1) && ((fruit_knife.x - Fruit_x1[3] - 49)*(fruit_knife.x - Fruit_x1[3] - 49) + (fruit_knife.y - Fruit_y1[3] - 42)*(fruit_knife.y - Fruit_y1[3] - 42)) <= 1600){
			score++;
			sandia_flag1 = 0;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((basaha_flag1 == 1) && ((fruit_knife.x - Fruit_x1[4] - 34)*(fruit_knife.x - Fruit_x1[4] - 34) + (fruit_knife.y - Fruit_y1[4] - 36)*(fruit_knife.y - Fruit_y1[4] - 36)) <= 900){
			score++;
			basaha_flag1 = 0;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}



		if ((banana_flag2 == 1) && (fruit_knife.x - Fruit_x2[0] - 63)*(fruit_knife.x - Fruit_x2[0] - 63) + (fruit_knife.y - Fruit_y2[0] - 25)*(fruit_knife.y - Fruit_y2[0] - 25) <= 1000){
			score++;
			banana_flag2 = 0;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((apple_flag2 == 1) && ((fruit_knife.x - Fruit_x2[1] - 33)*(fruit_knife.x - Fruit_x2[1] - 33) + (fruit_knife.y - Fruit_y2[1] - 33)*(fruit_knife.y - Fruit_y2[1] - 33)) <= 1000){
			score++;
			apple_flag2 = 0;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((peach_flag2 == 1) && ((fruit_knife.x - Fruit_x2[2] - 33)*(fruit_knife.x - Fruit_x2[2] - 33) + (fruit_knife.y - Fruit_y2[2] - 33)*(fruit_knife.y - Fruit_y2[2] - 33)) <= 1000){
			score++;
			peach_flag2 = 0;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((sandia_flag2 == 1) && ((fruit_knife.x - Fruit_x2[3] - 49)*(fruit_knife.x - Fruit_x2[3] - 49) + (fruit_knife.y - Fruit_y2[3] - 42)*(fruit_knife.y - Fruit_y2[3] - 42)) <= 1600){
			score++;
			sandia_flag2 = 0;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((basaha_flag2 == 1) && ((fruit_knife.x - Fruit_x2[4] - 34)*(fruit_knife.x - Fruit_x2[4] - 34) + (fruit_knife.y - Fruit_y2[4] - 36)*(fruit_knife.y - Fruit_y2[4] - 36)) <= 900)
		{
			score++;
			basaha_flag2 = 0;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}


		if ((fruit_knife.x - Boom_x1[0] - 33)*(fruit_knife.x - Boom_x1[0] - 33) + (fruit_knife.y - Boom_y1[0] - 33)*(fruit_knife.y - Boom_y1[0] - 33) <= 1089)
		{
			PlaySound(".\\source\\sound\\over.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			flag = 2;
		}
		if ((fruit_knife.x - Boom_x2[0] - 33)*(fruit_knife.x - Boom_x2[0] - 33) + (fruit_knife.y - Boom_y2[0] - 33)*(fruit_knife.y - Boom_y2[0] - 33) <= 1089)
		{
			PlaySound(".\\source\\sound\\over.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			flag = 2;
		}
	}
}

void show_over()
{
	cleardevice();
	BeginBatchDraw();
	putimage(0, 0, &img_bk);

	char s[5];
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 40;                      // 设置字体高度为 40
	_tcscpy_s(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC	或者VS推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	setcolor(YELLOW);                    //作图色为黄色
	settextstyle(&f);                     // 设置字体样式
	sprintf_s(s, "%d", score);
	setbkmode(TRANSPARENT);
	outtextxy(150, 256, "You Score is：");
	outtextxy(420, 256, s);


	//此模式下结束的样子
	putimage(55, 100, &img_gameover_1);
	/*if (gameover_roll == 1)
		putimage(55, 0, &img_gameover_2);*/
	if (sandiaL_roll == 1)
		putimage(55, 315, &img_sandia2);
	if (newgameL_roll == 1)
		putimage(-15, 240, &img_newgame2);

	FlushBatchDraw();
	Sleep(20);
}
void updateWithoutInput_over()
{
	rotateimage(&img_sandia2, &img_sandia1, sandia_rotate += 1.3);
	sandiaL_roll = 1;

	rotateimage(&img_newgame2, &img_newgame1, newgame_rotate -= 1.6);
	newgameL_roll = 1;
}
void updateWithInput_over()
{
	HWND hwnd = GetHWnd();
	POINT fruit_knife;				//定义水果刀的位置
	if (KEY_DOWN(VK_LBUTTON)) {
		GetCursorPos(&fruit_knife);
		ScreenToClient(hwnd, &fruit_knife);			//获取光标的位置，即为水果刀的位置												//以下为水果刀切到水果
		if ((fruit_knife.x - 55 - 49)*(fruit_knife.x - 55 - 49) + (fruit_knife.y - 315 - 43)*(fruit_knife.y - 315 - 43) < 1000) {
			flag = 0;
			score = 0;
			t1 = 1;
			t2 = 1;
			t3 = 1;
			t4 = 1;

			Velocity_x1 = -0.2; Velocity_y1 = 0;
			Velocity_x2 = -0.2; Velocity_y2 = 0;
			Velocity_x3 = -0.2; Velocity_y3 = 0;
			Velocity_x4 = -0.2; Velocity_y4 = 0;
			v0 = -1.15; g = 0.000004;

			flag1 = 1;
			flag2 = 0;
			flag3 = 0;
			flag4 = 0;

			flag = 0;

			srand((unsigned)time(NULL));

			//给所有向左的图片定义一个初始位置

			int k;
			for (k = 0; k < 10; k++)
			{
				Fruit_x1[k] = 200 + rand() % 100;
				Fruit_y1[k] = High + 20;
			}


			//给所有向右的图片定义一个初始位置
			for (k = 0; k < 10; k++)
			{
				Fruit_x2[k] = 200 + rand() % 100;
				Fruit_y2[k] = High + 20;
			}

			for (k = 0; k < 3; k++)
			{
				Boom_x1[k] = 200 + rand() % 100;
				Boom_y1[k] = High + 20;
			}

			for (k = 0; k < 3; k++)
			{
				Boom_x2[k] = 200 + rand() % 100;
				Boom_y2[k] = High + 20;
			}

			//获得一个随机的数字，来实现随机的水果输出
			Fruit_n1 = rand() % 7 + 1;
			Fruit_n2 = rand() % 7 + 1;
			initgraphEx();

		}
	}
}









void show_time()
{
	cleardevice();
	BeginBatchDraw();

	putimage(0, 0, &img_bk);		// 显示背景
	putimage(15, 15, &img_score);


	char s[5];
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 40;                      // 设置字体高度为 40
	_tcscpy_s(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC	或者VS推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	setcolor(YELLOW);                    //作图色为黄色
	settextstyle(&f);                     // 设置字体样式
	sprintf_s(s, "%d", score);
	setbkmode(TRANSPARENT);
	outtextxy(55, 13, s);

	char c[5];
	LOGFONT o;
	gettextstyle(&o);                     // 获取当前字体设置
	o.lfHeight = 40;                      // 设置字体高度为 40
	_tcscpy_s(o.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC	或者VS推荐使用 _tcscpy_s 函数)
	o.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	setcolor(YELLOW);                    //作图色为黄色
	settextstyle(&o);                     // 设置字体样式
	sprintf_s(c, "%d", minute);
	setbkmode(TRANSPARENT);
	outtextxy(535, 13, c);

	outtextxy(550, 11, ":");

	char a[5];
	LOGFONT p;
	gettextstyle(&p);                     // 获取当前字体设置
	p.lfHeight = 40;                      // 设置字体高度为 40
	_tcscpy_s(p.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC	或者VS推荐使用 _tcscpy_s 函数)
	p.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	setcolor(YELLOW);                     //作图色为黄色
	settextstyle(&p);                     // 设置字体样式
	sprintf_s(a, "%d", second);
	setbkmode(TRANSPARENT);
	outtextxy(565, 13, a);

	method();
	FlushBatchDraw();
	end = time(NULL);
	end2 = time(NULL);
	finish3 = clock();
	Sleep(1);
}
void updateWithoutInput_time()
{
	if (1000 <= finish3 - start3 && finish3 - start3 <= 1015)
	{
		second--;
		start3 = clock();
	}

	if (second == 0 && minute != 0)
		minute -= 1, second = 60;

	if (second == 0 && minute == 0)
		flag = 2;
	if (end - start > 3)//3秒以后再出现水果
	{
		count1++;
		method2();
		Velocity_y1 += g * t1;
		Velocity_y2 += (1.4)*g * t2;
		Velocity_y3 += 1.8*g*t3;
		t1++;
		t2++;
		t3++;
	}
	method3();
}
void updateWithInput_time()
{
	updateWithInput();
}






void gameover()
{
	EndBatchDraw();
	_getch();
	closegraph();
}






int main()
{
	startup();  // 数据初始化	
	while (1)  //  游戏循环执行
	{
		if (flag == 0)
		{
			show_menu();
			updateWithoutInput_menu();
			updateWithInput_menu();
		}
		else if (flag == 1)
		{
			show();  // 显示画面
			ShowBoom();  //显示炸弹
			updateWithoutInput();  // 与用户输入无关的更新
			updateWithInput();     // 与用户输入有关的更新
		}
		else if (flag == 2)
		{
			show_over();
			updateWithoutInput_over();
			updateWithInput_over();
		}
		else if (flag == 3)
		{
			show_time();
			updateWithoutInput_time();
			updateWithInput_time();
		}
		else if(flag == 4)
		{
			congwu_show();
			updateWithoutInput_congwu();
			updateWithInput_congwu();
		}

	}
	gameover();     // 游戏结束、后续处理
	return 0;
}