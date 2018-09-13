#include"stdafx.h"
#include "Definition.h"

#define KEY_DOWN(vk_c) (GetAsyncKeyState(vk_c)&0x8000?1:0)
#define KEY_UP(vk_c) (GetAsyncKeyState(vk_c)&0x8000?0:1)
#pragma comment(lib,"Winmm.lib")
#define Width 640
#define High 480

void daoguang_start()
{
	if (knifeflag == 1){
		//画刀刃
		setlinecolor(LIGHTGRAY);//轻蓝色刀刃
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 10);//线段为实线，端点为平坦
		line(mx8, my8, mx7, my7);
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 9);//以下的刀刃宽度逐渐减小
		line(mx7, my7, mx6, my6);
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 8);
		line(mx6, my6, mx5, my5);
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 7);
		line(mx4, my4, mx3, my3);
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 6);
		line(mx3, my3, mx2, my2);
		setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 5);
		line(mx2, my2, mx1, my1);
	}
}
void daoguang_end()
{
	HWND hwnd = GetHWnd();
	POINT fruit_knife;				//定义水果刀的位置
	if (KEY_UP(VK_LBUTTON)){
		knifeflag = 0;
	}
	GetCursorPos(&fruit_knife);
	ScreenToClient(hwnd, &fruit_knife);
	if (count == 1){
		mx1 = fruit_knife.x;
		my1 = fruit_knife.y;
	}
	if (count == 2){
		mx2 = fruit_knife.x;
		my2 = fruit_knife.y;
	}
	if (count == 3){
		mx3 = fruit_knife.x;
		my3 = fruit_knife.y;
	}
	if (count == 4){
		mx4 = fruit_knife.x;
		my4 = fruit_knife.y;
	}
	if (count == 5){
		mx5 = fruit_knife.x;
		my5 = fruit_knife.y;
	}
	if (count == 6){
		mx6 = fruit_knife.x;
		my6 = fruit_knife.y;
	}
	if (count == 7){
		mx7 = fruit_knife.x;
		my7 = fruit_knife.y;
	}
	if (count == 8){
		mx8 = fruit_knife.x;
		my8 = fruit_knife.y;
	}
	if (count == 9){
		cleardevice();
		count = 0;
	}
}

void startup()
{
	t1 = 1;
	t2 = 1;
	t3 = 1;
	t4 = 1;
	flag1 = 1;
	flag2 = 0;
	flag3 = 0;
	flag4 = 0;
	flag = 0;
	srand((unsigned)time(NULL));
	//给所有向左的图片定义一个初始位置
	int k;
	for (k = 0; k < 10; k++)	{
		Fruit_x1[k] = 200 + rand() % 100;
		Fruit_y1[k] = High + 20;
	}
	//给所有向右的图片定义一个初始位置
	for (k = 0; k < 10; k++){
		Fruit_x2[k] = 200 + rand() % 100;
		Fruit_y2[k] = High + 20;
	}
	for (k = 0; k < 3; k++)	{
		Boom_x1[k] = 200 + rand() % 100;
		Boom_y1[k] = High + 20;
	}
	for (k = 0; k < 3; k++){
		Boom_x2[k] = 200 + rand() % 100;
		Boom_y2[k] = High + 20;
	}
	//获得一个随机的数字，来实现随机的水果输出
	Fruit_n1 = rand() % 7 + 1;
	Fruit_n2 = rand() % 7 + 1;
	initgraphEx();
	initgraph(640, 480);
	//所有水果的图片
	loadimage(&img_flash, ".\\source\\images\\flash.jpg");
	loadimage(&img_bk, ".\\source\\images\\background.jpg");
	loadimage(&img_apple1, ".\\source\\images\\fruit\\apple.png");
	loadimage(&img_banana1, ".\\source\\images\\fruit\\banana.png");
	loadimage(&img_basaha1, ".\\source\\images\\fruit\\basaha.png");
	loadimage(&img_peach1, ".\\source\\images\\fruit\\peach.png");
	loadimage(&img_sandia1, ".\\source\\images\\fruit\\sandia.png");
	loadimage(&img_boom1, ".\\source\\images\\fruit\\boom.png");
	//所有切开水果左部分的图片
	loadimage(&img_apple_1L1, ".\\source\\images\\fruit\\apple-1.png");
	loadimage(&img_banana_1L1, ".\\source\\images\\fruit\\banana-1.png");
	loadimage(&img_basaha_1L1, ".\\source\\images\\fruit\\basaha-1.png");
	loadimage(&img_peach_1L1, ".\\source\\images\\fruit\\peach-1.png");
	loadimage(&img_sandia_1L1, ".\\source\\images\\fruit\\sandia-1.png");
	loadimage(&img_apple_1R1, ".\\source\\images\\fruit\\apple-2.png");
	loadimage(&img_banana_1R1, ".\\source\\images\\fruit\\banana-2.png");
	loadimage(&img_basaha_1R1, ".\\source\\images\\fruit\\basaha-2.png");
	loadimage(&img_peach_1R1, ".\\source\\images\\fruit\\peach-2.png");
	loadimage(&img_sandia_1R1, ".\\source\\images\\fruit\\sandia-2.png");

	loadimage(&img_apple_2L1, ".\\source\\images\\fruit\\apple-1.png");
	loadimage(&img_banana_2L1, ".\\source\\images\\fruit\\banana-1.png");
	loadimage(&img_basaha_2L1, ".\\source\\images\\fruit\\basaha-1.png");
	loadimage(&img_peach_2L1, ".\\source\\images\\fruit\\peach-1.png");
	loadimage(&img_sandia_2L1, ".\\source\\images\\fruit\\sandia-1.png");
	loadimage(&img_apple_2R1, ".\\source\\images\\fruit\\apple-2.png");
	loadimage(&img_banana_2R1, ".\\source\\images\\fruit\\banana-2.png");
	loadimage(&img_basaha_2R1, ".\\source\\images\\fruit\\basaha-2.png");
	loadimage(&img_peach_2R1, ".\\source\\images\\fruit\\peach-2.png");
	loadimage(&img_sandia_2R1, ".\\source\\images\\fruit\\sandia-2.png");
	//右上角的叉叉
	loadimage(&img_x, ".\\source\\images\\x.png");
	loadimage(&img_xx, ".\\source\\images\\xx.png");
	loadimage(&img_xxx, ".\\source\\images\\xxx.png");
	loadimage(&img_xf, ".\\source\\images\\xf.png");
	loadimage(&img_xxf, ".\\source\\images\\xxf.png");
	loadimage(&img_xxxf, ".\\source\\images\\xxxf.png");
	//左上角分数
	loadimage(&img_score, ".\\source\\images\\score.png");
	//菜单选项
	loadimage(&img_newgame1, ".\\source\\images\\new-game.png");
	loadimage(&img_fruit, ".\\source\\images\\logo.png");
	loadimage(&img_ninja, ".\\source\\images\\ninja.png");
	loadimage(&img_new, ".\\source\\images\\new.png");
	loadimage(&img_shallow, ".\\source\\images\\home-mask.png");
	loadimage(&img_tip, ".\\source\\images\\home-desc.png");
	loadimage(&img_dojo1, ".\\source\\images\\dojo.png");
	loadimage(&img_quit1, ".\\source\\images\\quit.png");
	//游戏结束
	loadimage(&img_gameover_1, ".\\source\\images\\game-over.png");
}

//以下5个函数为显示向左抛炸弹旋转
void ShowApple1Half(float Fruit_x, float Fruit_y)
{
	if (flag_1s1 == 1){
		apple1_L_x = Fruit_x;
		apple1_L_y = Fruit_y;
		apple1_R_x = Fruit_x;
		apple1_R_y = Fruit_y;
		flag_1s1 = 0;
	}
	if (apple1HalfL_roll == 1)
		putimage(apple1_L_x - 15, apple1_L_y, &img_apple_1L2);
	if (apple1HalfR_roll == 1)
		putimage(apple1_R_x + 15, apple1_R_y, &img_apple_1R2);
}
void ShowBanana1Half(float Fruit_x, float Fruit_y)
{
	if (flag_1s0 == 1)	{
		banana1_L_x = Fruit_x;
		banana1_L_y = Fruit_y;
		banana1_R_x = Fruit_x;
		banana1_R_y = Fruit_y;
		flag_1s0 = 0;
	}

	if (banana1HalfL_roll == 1)
		putimage(banana1_L_x - 15, banana1_L_y, &img_banana_1L2);
	if (banana1HalfR_roll == 1)
		putimage(banana1_R_x + 15, banana1_R_y, &img_banana_1R2);
}
void ShowBasaha1Half(float Fruit_x, float Fruit_y)
{
	if (flag_1s4 == 1){
		basaha1_L_x = Fruit_x;
		basaha1_L_y = Fruit_y;
		basaha1_R_x = Fruit_x;
		basaha1_R_y = Fruit_y;
		flag_1s4 = 0;
	}
	if (basaha1HalfL_roll == 1)
		putimage(basaha1_L_x - 15, basaha1_L_y, &img_basaha_1L2);
	if (basaha1HalfR_roll == 1)
		putimage(basaha1_R_x + 15, basaha1_R_y, &img_basaha_1R2);
}
void ShowPeach1Half(float Fruit_x, float Fruit_y)
{
	if (flag_1s2 == 1){
		peach1_L_x = Fruit_x;
		peach1_L_y = Fruit_y;
		peach1_R_x = Fruit_x;
		peach1_R_y = Fruit_y;
		flag_1s2 = 0;
	}
	if (peach1HalfL_roll == 1)
		putimage(peach1_L_x - 15, peach1_L_y, &img_peach_1L2);
	if (peach1HalfR_roll == 1)
		putimage(peach1_R_x + 15, peach1_R_y, &img_peach_1R2);
}
void ShowSandia1Half(float Fruit_x, float Fruit_y)
{
	if (flag_1s3 == 1) {
		sandia1_L_x = Fruit_x;
		sandia1_L_y = Fruit_y;
		sandia1_R_x = Fruit_x;
		sandia1_R_y = Fruit_y;
		flag_1s3 = 0;
	}
	if (sandia1HalfL_roll == 1)
		putimage(sandia1_L_x - 15, sandia1_L_y, &img_sandia_1L2);
	if (sandia1HalfR_roll == 1)
		putimage(sandia1_R_x + 15, sandia1_R_y, &img_sandia_1R2);
}
//以下5个函数为显示向右抛炸弹旋转
void ShowApple2Half(float Fruit_x, float Fruit_y)
{
	if (flag_2s1 == 1){
		apple2_L_x = Fruit_x;
		apple2_L_y = Fruit_y;
		apple2_R_x = Fruit_x;
		apple2_R_y = Fruit_y;
		flag_2s1 = 0;
	}
	if (apple2HalfL_roll == 1)
		putimage(apple2_L_x - 15, apple2_L_y, &img_apple_2L2);
	if (apple2HalfR_roll == 1)
		putimage(apple2_R_x + 15, apple2_R_y, &img_apple_2R2);
}
void ShowBanana2Half(float Fruit_x, float Fruit_y)
{
	if (flag_2s0 == 1){
		banana2_L_x = Fruit_x;
		banana2_L_y = Fruit_y;
		banana2_R_x = Fruit_x;
		banana2_R_y = Fruit_y;
		flag_2s0 = 0;
	}
	if (banana2HalfL_roll == 1)
		putimage(banana2_L_x - 15, banana2_L_y, &img_banana_2L2);
	if (banana2HalfR_roll == 1)
		putimage(banana2_R_x + 15, banana2_R_y, &img_banana_2R2);
}
void ShowBasaha2Half(float Fruit_x, float Fruit_y)
{
	if (flag_2s4 == 1)	{
		basaha2_L_x = Fruit_x;
		basaha2_L_y = Fruit_y;
		basaha2_R_x = Fruit_x;
		basaha2_R_y = Fruit_y;
		flag_2s4 = 0;
	}
	if (basaha2HalfL_roll == 1)
		putimage(basaha2_L_x - 15, basaha2_L_y, &img_basaha_2L2);
	if (basaha2HalfR_roll == 1)
		putimage(basaha2_R_x + 15, basaha2_R_y, &img_basaha_2R2);
}
void ShowPeach2Half(float Fruit_x, float Fruit_y)
{
	if (flag_2s2 == 1)	{
		peach2_L_x = Fruit_x;
		peach2_L_y = Fruit_y;
		peach2_R_x = Fruit_x;
		peach2_R_y = Fruit_y;
		flag_2s2 = 0;
	}
	if (peach2HalfL_roll == 1)
		putimage(peach2_L_x - 15, peach2_L_y, &img_peach_2L2);
	if (peach2HalfR_roll == 1)
		putimage(peach2_R_x + 15, peach2_R_y, &img_peach_2R2);
}
void ShowSandia2Half(float Fruit_x, float Fruit_y)
{
	if (flag_2s3 == 1){
		sandia2_L_x = Fruit_x;
		sandia2_L_y = Fruit_y;
		sandia2_R_x = Fruit_x;
		sandia2_R_y = Fruit_y;
		flag_2s3 = 0;
	}
	if (sandia2HalfL_roll == 1)
		putimage(sandia2_L_x - 15, sandia2_L_y, &img_sandia_2L2);
	if (sandia2HalfR_roll == 1)
		putimage(sandia2_R_x + 15, sandia2_R_y, &img_sandia_2R2);
}


void show_menu()
{
	omit = 0;
	cleardevice();
	BeginBatchDraw();
	putimage(0, 0, &img_bk);
	putimage(0, 0, &img_shallow);
	putimage(20, 10, &img_fruit);
	putimage(315, 45, &img_ninja);
	putimage(20, 135, &img_tip);
	daoguang_start();
	if (sandiaL_roll == 1)
		putimage(260, 250, &img_sandia2);
	if (newgameL_roll == 1)
		putimage(190, 175, &img_newgame2);
	if (peachL_roll == 1)
		putimage(80, 280, &img_peach2);
	if (dojoL_roll == 1)
		putimage(0, 200, &img_dojo2);
	if (boomL_roll == 1)
		putimage(500, 310, &img_boom2);
	if (quitL_roll == 1)
		putimage(450, 260, &img_quit2);
	FlushBatchDraw();
	Sleep(2);
}
void updateWithoutInput_menu()
{
	PlaySound(".\\source\\sound\\menu.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);
	rotateimage(&img_sandia2, &img_sandia1, sandia_Angle += 1.3);
	sandiaL_roll = 1;
	rotateimage(&img_newgame2, &img_newgame1, newgame_Angle -= 1.6);
	newgameL_roll = 1;
	rotateimage(&img_peach2, &img_peach1, peach_Angle += 1.1);
	peachL_roll = 1;
	rotateimage(&img_dojo2, &img_dojo1, dojo_Angle -= 1.7);
	dojoL_roll = 1;
	rotateimage(&img_boom2, &img_boom1, boom_Angle -= 1.8);
	boomL_roll = 1;
	rotateimage(&img_quit2, &img_quit1, quit_Angle += 1.2);
	quitL_roll = 1;
	count++;
}
void updateWithInput_menu()
{
	HWND hwnd = GetHWnd();
	POINT fruit_knife;				//定义水果刀的位置
	if (KEY_DOWN(VK_LBUTTON))
	{
		knifeflag = 1;
		GetCursorPos(&fruit_knife);
		ScreenToClient(hwnd, &fruit_knife);			//获取光标的位置，即为水果刀的位置
													//以下为水果刀切到水果
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
		if ((fruit_knife.x - 500 - 33)*(fruit_knife.x - 500 - 33) + (fruit_knife.y - 310 - 33)*(fruit_knife.y - 310 - 33) < 1089)
		{
			exit(0);
		}
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
		fakeflag = flag;
	}
	daoguang_end();
}


void show_fruit()
{
	if (half_1flag0 == 1)
	{
		ShowBanana1Half(Fruit_x1[0], Fruit_y1[0]);
	}
	if (half_1flag1 == 1)
	{
		ShowApple1Half(Fruit_x1[1], Fruit_y1[1]);
	}
	if (half_1flag2 == 1)
	{
		ShowPeach1Half(Fruit_x1[2], Fruit_y1[2]);
	}
	if (half_1flag3 == 1)
	{
		ShowSandia1Half(Fruit_x1[3], Fruit_y1[3]);
	}
	if (half_1flag4 == 1)
	{
		ShowBasaha1Half(Fruit_x1[4], Fruit_y1[4]);
	}

	if (Fruit_n1 == 1)
	{
		if (Fruit_1flag2 == 1)
		{
			if (peachL_roll == 1)
				putimage(Fruit_x1[2], Fruit_y1[2], &img_peach2);
		}
	}
	if (Fruit_n1 == 2)
	{
		if (Fruit_1flag1 == 1)
		{
			if (appleL_roll == 1)
				putimage(Fruit_x1[1], Fruit_y1[1], &img_apple2);
		}
		if (Fruit_1flag0 == 1)
		{
			if (bananaL_roll == 1)
				putimage(Fruit_x1[0], Fruit_y1[0], &img_banana2);
		}
	}
	if (Fruit_n1 == 3)
	{
		if (Fruit_1flag2 == 1)
		{
			if (peachL_roll == 1)
				putimage(Fruit_x1[2], Fruit_y1[2], &img_peach2);
		}
		if (Fruit_1flag3 == 1)
		{
			if (sandiaL_roll == 1)
				putimage(Fruit_x1[3], Fruit_y1[3], &img_sandia2);
		}
	}
	if (Fruit_n1 == 4)
	{
		if (Fruit_1flag1 == 1)
		{
			if (appleL_roll == 1)
				putimage(Fruit_x1[1], Fruit_y1[1], &img_apple2);
		}
		if (Fruit_1flag3 == 1)
		{
			if (sandiaL_roll == 1)
				putimage(Fruit_x1[3], Fruit_y1[3], &img_sandia2);
		}
	}
	if (Fruit_n1 == 5)
	{
		if (Fruit_1flag0 == 1)
		{
			if (bananaL_roll == 1)
				putimage(Fruit_x1[0], Fruit_y1[0], &img_banana2);
		}
		if (Fruit_1flag2 == 1)
		{
			if (peachL_roll == 1)
				putimage(Fruit_x1[2], Fruit_y1[2], &img_peach2);
		}
		if (Fruit_1flag4 == 1)
		{
			if (basahaL_roll == 1)
				putimage(Fruit_x1[4], Fruit_y1[4], &img_basaha2);
		}
	}
	if (Fruit_n1 == 6)
	{
		if (Fruit_1flag4 == 1)
		{
			if (basahaL_roll == 1)
				putimage(Fruit_x1[4], Fruit_y1[4], &img_basaha2);
		}
	}
	if (Fruit_n1 == 7)
	{
		if (Fruit_1flag1 == 1)
		{
			if (appleL_roll == 1)
				putimage(Fruit_x1[1], Fruit_y1[1], &img_apple2);
		}
		if (Fruit_1flag4 == 1)
		{
			if (basahaL_roll == 1)
				putimage(Fruit_x1[4], Fruit_y1[4], &img_basaha2);
		}
	}
	if (Fruit_n2 == 1)
	{
		if (Fruit_2flag0 == 1)
		{
			if (bananaR_roll == 1)
				putimage(Fruit_x2[0], Fruit_y2[0], &img_banana2);
		}
		if (Fruit_2flag2 == 1)
		{
			if (peachR_roll == 1)
				putimage(Fruit_x2[2], Fruit_y2[2], &img_peach2);
		}
	}
	if (Fruit_n2 == 2)
	{
		if (Fruit_2flag2 == 1)
		{
			if (peachR_roll == 1)
				putimage(Fruit_x2[2], Fruit_y2[2], &img_peach2);
		}
		if (Fruit_2flag3 == 1)
		{
			if (sandiaR_roll == 1)
				putimage(Fruit_x2[3], Fruit_y2[3], &img_sandia2);
		}
		if (Fruit_2flag4 == 1)
		{
			if (basahaR_roll == 1)
				putimage(Fruit_x2[4], Fruit_y2[4], &img_basaha2);
		}
	}
	if (Fruit_n2 == 3)
	{
		if (Fruit_2flag3 == 1)
		{
			if (sandiaR_roll == 1)
				putimage(Fruit_x2[3], Fruit_y2[3], &img_sandia2);
		}
	}
	if (Fruit_n2 == 4)
	{
		if (Fruit_2flag0 == 1)
		{
			if (bananaR_roll == 1)
				putimage(Fruit_x2[0], Fruit_y2[0], &img_banana2);
		}
		if (Fruit_2flag2 == 1)
		{
			if (peachR_roll == 1)
				putimage(Fruit_x2[2], Fruit_y2[2], &img_peach2);
		}
	}
	if (Fruit_n2 == 5)
	{
		if (Fruit_2flag0 == 1)
		{
			if (bananaR_roll == 1)
				putimage(Fruit_x2[0], Fruit_y2[0], &img_banana2);
		}
		if (Fruit_2flag1 == 1)
		{
			if (appleR_roll)
				putimage(Fruit_x2[1], Fruit_y2[1], &img_apple2);
		}
	}
	if (Fruit_n2 == 6)
	{
		if (Fruit_2flag4 == 1)
		{
			if (basahaR_roll == 1)
				putimage(Fruit_x2[4], Fruit_y2[4], &img_basaha2);
		}
	}
	if (Fruit_n2 == 7)
	{
		if (Fruit_2flag2 == 1)
		{
			if (peachR_roll == 1)
				putimage(Fruit_x2[2], Fruit_y2[2], &img_peach2);
		}
		if (Fruit_2flag4 == 1)
		{
			if (basahaR_roll == 1)
				putimage(Fruit_x2[4], Fruit_y2[4], &img_basaha2);
		}
	}
	if (half_2flag0 == 1)
	{
		ShowBanana2Half(Fruit_x2[0], Fruit_y2[0]);
	}
	if (half_2flag1 == 1)
	{
		ShowApple2Half(Fruit_x2[1], Fruit_y2[1]);
	}
	if (half_2flag2 == 1)
	{
		ShowPeach2Half(Fruit_x2[2], Fruit_y2[2]);
	}
	if (half_2flag3 == 1)
	{
		ShowSandia2Half(Fruit_x2[3], Fruit_y2[3]);
	}
	if (half_2flag4 == 1)
	{
		ShowBasaha2Half(Fruit_x2[4], Fruit_y2[4]);
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
	//显示红叉
	char s[5];
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 40;                      // 设置字体高度为 40
	_tcscpy_s(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC	或者VS推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	setcolor(YELLOW);						 //作图色为黄色
	settextstyle(&f);                     // 设置字体样式
	sprintf_s(s, "%d", score);
	setbkmode(TRANSPARENT);
	outtextxy(55, 13, s);

	char e[80];
	fopen_s(&fp, "highest_score1.txt", "r");
	fgets(e, 80, fp);
	fclose(fp);
	LOGFONT r;
	gettextstyle(&r);                     // 获取当前字体设置
	r.lfHeight = 21;                      // 设置字体高度为 21
	_tcscpy_s(r.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC	或者VS推荐使用 _tcscpy_s 函数)
	r.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	setcolor(GREEN);						 //作图色为绿色
	settextstyle(&r);                     // 设置字体样式
										  //sprintf_s(e, "%d", highest_score1);
	setbkmode(TRANSPARENT);
	outtextxy(5, 53, "best:");
	outtextxy(60, 55, e);

	daoguang_start();

	if (omit == 1)
		putimage(545, 15, &img_xf);
	if (omit == 2)
	{
		putimage(545, 15, &img_xf);
		putimage(570, 15, &img_xxf);
	}
	if (omit == 3)
	{
		putimage(545, 15, &img_xf);
		putimage(570, 15, &img_xxf);
		putimage(600, 15, &img_xxxf);
	}
	//以下显示水果,[0]为香蕉，[1]为苹果，[2]为桃子，[3]为西瓜，[4]为草莓
	show_fruit();
	//FlushBatchDraw();
	end = time(NULL);
}
void ShowBoom()
{
	if (boomL_roll == 1)
		putimage(Boom_x1[0], Boom_y1[0], &img_boom2);
	if (boomR_roll == 1)
		putimage(Boom_x2[0], Boom_y2[0], &img_boom2);
	FlushBatchDraw();
	Sleep(0.7);
}

//单独拿出来斜抛运动的运动函数，优化水果的运动
void Left_fruit_movement(float *x, float *y)
{
	*y = High + 20 + 20 + Velocity_y1 * t1;
	*x += Velocity_x1;
}
void Right_fruit_movement(float *x, float *y)
{
	*y = High + 20 + 20 + Velocity_y2 * t2;
	*x += -0.7*Velocity_x2;
}
void Left_boom_movement(float *x, float *y)
{
	*y = High + 20 + 20 + 1.5*Velocity_y3 * t3;
	*x += -0.5*Velocity_x3;
}
void Right_boom_movement(float *x, float *y)
{
	*y = High + 20 + 20 + 1.2*Velocity_y4 * t4;
	*x += 1.7*Velocity_x4;
}

//以下函数为水果被切成一半的运动函数
void act_1Half0_L(float *x, float *y)
{
	*y += Velocity_1Half0_y * T1[0];
	*x += Velocity_1Half0_x;
}
void act_1Half0_R(float *x, float *y)
{
	*y += Velocity_1Half0_y * T1[0];
	*x -= Velocity_1Half0_x;
}
void act_1Half1_L(float *x, float *y)
{
	*y += Velocity_1Half1_y * T1[1];
	*x += Velocity_1Half1_x;
}
void act_1Half1_R(float *x, float *y)
{
	*y += Velocity_1Half1_y * T1[1];
	*x -= Velocity_1Half1_x;
}
void act_1Half2_L(float *x, float *y)
{
	*y += Velocity_1Half2_y * T1[2];
	*x += Velocity_1Half2_x;
}
void act_1Half2_R(float *x, float *y)
{
	*y += Velocity_1Half2_y * T1[2];
	*x -= Velocity_1Half2_x;
}
void act_1Half3_L(float *x, float *y)
{
	*y += Velocity_1Half3_y * T1[3];
	*x += Velocity_1Half3_x;
}
void act_1Half3_R(float *x, float *y)
{
	*y += Velocity_1Half3_y * T1[3];
	*x -= Velocity_1Half3_x;
}
void act_1Half4_L(float *x, float *y)
{
	*y += Velocity_1Half4_y * T1[4];
	*x += Velocity_1Half4_x;
}
void act_1Half4_R(float *x, float *y)
{
	*y += Velocity_1Half4_y * T1[4];
	*x -= Velocity_1Half4_x;
}
void act_2Half0_L(float *x, float *y)
{
	*y += Velocity_2Half0_y * T2[0];
	*x += Velocity_2Half0_x;
}
void act_2Half0_R(float *x, float *y)
{
	*y += Velocity_2Half0_y * T2[0];
	*x -= Velocity_2Half0_x;
}
void act_2Half1_L(float *x, float *y)
{
	*y += Velocity_2Half1_y * T2[1];
	*x += Velocity_2Half1_x;
}
void act_2Half1_R(float *x, float *y)
{
	*y += Velocity_2Half1_y * T2[1];
	*x -= Velocity_2Half1_x;
}
void act_2Half2_L(float *x, float *y)
{
	*y += Velocity_2Half2_y * T2[2];
	*x += Velocity_2Half2_x;
}
void act_2Half2_R(float *x, float *y)
{
	*y += Velocity_2Half2_y * T2[2];
	*x -= Velocity_2Half2_x;
}
void act_2Half3_L(float *x, float *y)
{
	*y += Velocity_2Half3_y * T2[3];
	*x += Velocity_2Half3_x;
}
void act_2Half3_R(float *x, float *y)
{
	*y += Velocity_2Half3_y * T2[3];
	*x -= Velocity_2Half3_x;
}
void act_2Half4_L(float *x, float *y)
{
	*y += Velocity_2Half4_y * T2[4];
	*x += Velocity_2Half4_x;
}
void act_2Half4_R(float *x, float *y)
{
	*y += Velocity_2Half4_y * T2[4];
	*x -= Velocity_2Half4_x;
}

//水果被切后坐标的更新，旋转
void Half1Update0()
{
	if (flag_1v0 == 1)
	{
		Velocity_1Half0_y = 0;
		flag_1v0 = 0;
	}
	act_1Half0_L(&banana1_L_x, &banana1_L_y);
	act_1Half0_R(&banana1_R_x, &banana1_R_y);
	Velocity_1Half0_y += (0.3*g) * T1[0];
	T1[0]++;
	rotateimage(&img_banana_1L2, &img_banana_1L1, banana1Half_AngleL -= 0.3);
	banana1HalfL_roll = 1;
	rotateimage(&img_banana_1R2, &img_banana_1R1, banana1Half_AngleR += 0.3);
	banana1HalfR_roll = 1;
}
void Half1Update1()
{
	if (flag_1v1 == 1)
	{
		Velocity_1Half1_y = 0;
		flag_1v1 = 0;
	}
	act_1Half1_L(&apple1_L_x, &apple1_L_y);
	act_1Half1_R(&apple1_R_x, &apple1_R_y);
	Velocity_1Half1_y += (0.3*g) * T1[1];
	T1[1]++;
	rotateimage(&img_apple_1L2, &img_apple_1L1, apple1Half_AngleL -= 0.3);
	apple1HalfL_roll = 1;
	rotateimage(&img_apple_1R2, &img_apple_1R1, apple1Half_AngleR += 0.3);
	apple1HalfR_roll = 1;
}
void Half1Update2()
{
	if (flag_1v2 == 1)
	{
		Velocity_1Half2_y = 0;
		flag_1v2 = 0;
	}
	act_1Half2_L(&peach1_L_x, &peach1_L_y);
	act_1Half2_R(&peach1_R_x, &peach1_R_y);
	Velocity_1Half2_y += (0.3*g) * T1[2];
	T1[2]++;
	rotateimage(&img_peach_1L2, &img_peach_1L1, peach1Half_AngleL -= 0.3);
	peach1HalfL_roll = 1;
	rotateimage(&img_peach_1R2, &img_peach_1R1, peach1Half_AngleR += 0.3);
	peach1HalfR_roll = 1;
}
void Half1Update3()
{
	if (flag_1v3 == 1)
	{
		Velocity_1Half3_y = 0;
		flag_1v3 = 0;
	}
	act_1Half3_L(&sandia1_L_x, &sandia1_L_y);
	act_1Half3_R(&sandia1_R_x, &sandia1_R_y);
	Velocity_1Half3_y += (0.3*g) * T1[3];
	T1[3]++;
	rotateimage(&img_sandia_1L2, &img_sandia_1L1, sandia1Half_AngleL -= 0.3);
	sandia1HalfL_roll = 1;
	rotateimage(&img_sandia_1R2, &img_sandia_1R1, sandia1Half_AngleR += 0.3);
	sandia1HalfR_roll = 1;
}
void Half1Update4()
{
	if (flag_1v4 == 1)
	{
		Velocity_1Half4_y = 0;
		flag_1v4 = 0;
	}
	act_1Half4_L(&basaha1_L_x, &basaha1_L_y);
	act_1Half4_R(&basaha1_R_x, &basaha1_R_y);
	Velocity_1Half4_y += (0.3*g) * T1[4];
	T1[4]++;
	rotateimage(&img_basaha_1L2, &img_basaha_1L1, basaha1Half_AngleL -= 0.5);
	basaha1HalfL_roll = 1;
	rotateimage(&img_basaha_1R2, &img_basaha_1R1, basaha1Half_AngleR += 0.5);
	basaha1HalfR_roll = 1;
}

void Half2Update0()
{
	if (flag_2v0 == 1)
	{
		Velocity_2Half0_y = 0;
		flag_2v0 = 0;
	}
	act_2Half0_L(&banana2_L_x, &banana2_L_y);
	act_2Half0_R(&banana2_R_x, &banana2_R_y);
	Velocity_2Half0_y += (0.3*g) * T2[0];
	T2[0]++;
	rotateimage(&img_banana_2L2, &img_banana_2L1, banana2Half_AngleL -= 0.3);
	rotateimage(&img_banana_2R2, &img_banana_2R1, banana2Half_AngleR += 0.3);
	banana2HalfL_roll = 1;
	banana2HalfR_roll = 1;
}
void Half2Update1()
{
	if (flag_2v1 == 1)
	{
		Velocity_2Half1_y = 0;
		flag_2v1 = 0;
	}
	act_2Half1_L(&apple2_L_x, &apple2_L_y);
	act_2Half1_R(&apple2_R_x, &apple2_R_y);
	Velocity_2Half1_y += (0.3*g) * T2[1];
	T2[1]++;
	rotateimage(&img_apple_2L2, &img_apple_2L1, apple2Half_AngleL -= 0.3);
	rotateimage(&img_apple_2R2, &img_apple_2R1, apple2Half_AngleR += 0.3);
	apple2HalfL_roll = 1;
	apple2HalfR_roll = 1;
}
void Half2Update2()
{
	if (flag_2v2 == 1)
	{
		Velocity_2Half2_y = 0;
		flag_2v2 = 0;
	}
	act_2Half2_L(&peach2_L_x, &peach2_L_y);
	act_2Half2_R(&peach2_R_x, &peach2_R_y);
	Velocity_2Half2_y += (0.3*g) * T2[2];
	T2[2]++;
	rotateimage(&img_peach_2L2, &img_peach_2L1, peach2Half_AngleL -= 0.3);
	rotateimage(&img_peach_2R2, &img_peach_2R1, peach2Half_AngleR += 0.3);
	peach2HalfL_roll = 1;
	peach2HalfR_roll = 1;
}
void Half2Update3()
{
	if (flag_2v3 == 1)
	{
		Velocity_2Half3_y = 0;
		flag_2v3 = 0;
	}
	act_2Half3_L(&sandia2_L_x, &sandia2_L_y);
	act_2Half3_R(&sandia2_R_x, &sandia2_R_y);
	Velocity_2Half3_y += (0.3*g) * T2[3];
	T2[3]++;
	rotateimage(&img_sandia_2L2, &img_sandia_2L1, sandia2Half_AngleL -= 0.3);
	rotateimage(&img_sandia_2R2, &img_sandia_2R1, sandia2Half_AngleR += 0.3);
	sandia2HalfL_roll = 1;
	sandia2HalfR_roll = 1;
}
void Half2Update4()
{
	if (flag_2v4 == 1)
	{
		Velocity_2Half4_y = 0;
		flag_2v4 = 0;
	}
	act_2Half4_L(&basaha2_L_x, &basaha2_L_y);
	act_2Half4_R(&basaha2_R_x, &basaha2_R_y);
	Velocity_2Half4_y += (0.3*g) * T2[4];
	T2[4]++;
	rotateimage(&img_basaha_2L2, &img_basaha_2L1, basaha2Half_AngleL -= 0.3);
	rotateimage(&img_basaha_2R2, &img_basaha_2R1, basaha2Half_AngleR += 0.3);
	basaha2HalfL_roll = 1;
	basaha2HalfR_roll = 1;
}


void updateWithoutInput_fruit()
{
	if (iniFlag2 == 0)
	{
		//向右
		Fruit_2flag0 = 1;//香蕉的出现
		Fruit_2flag1 = 1;//苹果的出现
		Fruit_2flag2 = 1;//芒果的出现
		Fruit_2flag3 = 1;//西瓜的出现
		Fruit_2flag4 = 1;//草莓的出现
		Fruit_n2 = rand() % 7 + 1;

		half_2flag0 = 0;
		half_2flag1 = 0;
		half_2flag2 = 0;
		half_2flag3 = 0;
		half_2flag4 = 0;
		PlaySound(".\\source\\sound\\throw.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		Velocity_y2 = v0;
		t2 = 1;
		for (k2 = 0; k2 < 10; k2++)
		{
			Fruit_x2[k2] = 200 + rand() % (Width - 460);
			Fruit_y2[k2] = High + 20;
		}
		flag2 = 1;
		iniFlag2 = 1;
	}
	if (flag2 == 1)
	{
		if (Fruit_n2 == 1)
		{
			if (Fruit_2flag0 == 1)
				Right_fruit_movement(&Fruit_x2[0], &Fruit_y2[0]);
			if (Fruit_2flag2 == 1)
				Right_fruit_movement(&Fruit_x2[2], &Fruit_y2[2]);
		}
		if (Fruit_n2 == 2)
		{
			if (Fruit_2flag2 == 1)
				Right_fruit_movement(&Fruit_x2[2], &Fruit_y2[2]);
			if (Fruit_2flag3 == 1)
				Right_fruit_movement(&Fruit_x2[3], &Fruit_y2[3]);
			if (Fruit_2flag3 == 1)
				Right_fruit_movement(&Fruit_x2[4], &Fruit_y2[4]);
		}
		if (Fruit_n2 == 3)
		{
			if (Fruit_2flag3 == 1)
				Right_fruit_movement(&Fruit_x2[3], &Fruit_y2[3]);
		}
		if (Fruit_n2 == 4)
		{
			if (Fruit_2flag0 == 1)
				Right_fruit_movement(&Fruit_x2[0], &Fruit_y2[0]);
			if (Fruit_2flag2 == 1)
				Right_fruit_movement(&Fruit_x2[2], &Fruit_y2[2]);
		}
		if (Fruit_n2 == 5)
		{
			if (Fruit_2flag0 == 1)
				Right_fruit_movement(&Fruit_x2[0], &Fruit_y2[0]);
			if (Fruit_2flag1 == 1)
				Right_fruit_movement(&Fruit_x2[1], &Fruit_y2[1]);
		}
		if (Fruit_n2 == 6)
		{
			if (Fruit_2flag4 == 1)
				Right_fruit_movement(&Fruit_x2[4], &Fruit_y2[4]);
		}
		if (Fruit_n2 == 7)
		{
			if (Fruit_2flag2 == 1)
				Right_fruit_movement(&Fruit_x2[2], &Fruit_y2[2]);
			if (Fruit_2flag4 == 1)
				Right_fruit_movement(&Fruit_x2[4], &Fruit_y2[4]);
		}
	}
	//向左
	if (iniFlag1 == 0)
	{
		Fruit_1flag0 = 1;//香蕉的出现
		Fruit_1flag1 = 1;//苹果的出现
		Fruit_1flag2 = 1;//芒果的出现
		Fruit_1flag3 = 1;//西瓜的出现
		Fruit_1flag4 = 1;//草莓的出现
		Fruit_n1 = rand() % 7 + 1;

		half_1flag0 = 0;
		half_1flag1 = 0;
		half_1flag2 = 0;
		half_1flag3 = 0;
		half_1flag4 = 0;

		PlaySound(".\\source\\sound\\throw.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		t1 = 1;
		Velocity_y1 = v0;
		for (k1 = 0; k1 < 10; k1++)
		{
			Fruit_x1[k1] = 200 + rand() % (Width - 460);
			Fruit_y1[k1] = High + 20;
		}
		flag1 = 1;
		iniFlag1 = 1;
	}
	if (flag1 == 1)
	{
		if (Fruit_n1 == 1)
		{
			if (Fruit_1flag2 == 1)
				Left_fruit_movement(&Fruit_x1[2], &Fruit_y1[2]);
		}
		if (Fruit_n1 == 2)
		{
			if (Fruit_1flag1 == 1)
				Left_fruit_movement(&Fruit_x1[1], &Fruit_y1[1]);
			if (Fruit_1flag0 == 1)
				Left_fruit_movement(&Fruit_x1[0], &Fruit_y1[0]);

		}
		if (Fruit_n1 == 3)
		{
			if (Fruit_1flag2 == 1)
				Left_fruit_movement(&Fruit_x1[2], &Fruit_y1[2]);
			if (Fruit_1flag3 == 1)
				Left_fruit_movement(&Fruit_x1[3], &Fruit_y1[3]);
		}
		if (Fruit_n1 == 4)
		{
			if (Fruit_1flag1 == 1)
				Left_fruit_movement(&Fruit_x1[1], &Fruit_y1[1]);
			if (Fruit_1flag3 == 1)
				Left_fruit_movement(&Fruit_x1[3], &Fruit_y1[3]);
		}
		if (Fruit_n1 == 5)
		{
			if (Fruit_1flag0 == 1)
				Left_fruit_movement(&Fruit_x1[0], &Fruit_y1[0]);
			if (Fruit_1flag2 == 1)
				Left_fruit_movement(&Fruit_x1[2], &Fruit_y1[2]);
		}
		if (Fruit_n1 == 6)
		{
			if (Fruit_1flag4 == 1)
				Left_fruit_movement(&Fruit_x1[4], &Fruit_y1[4]);

		}
		if (Fruit_n1 == 7)
		{
			if (Fruit_1flag1 == 1)
				Left_fruit_movement(&Fruit_x1[1], &Fruit_y1[1]);
			if (Fruit_1flag4 == 1)
				Left_fruit_movement(&Fruit_x1[4], &Fruit_y1[4]);
		}
	}
}
void updateWithoutInput_ifhalfupdate()
{
	if (half_1flag0 == 1)
	{
		Half1Update0();
	}
	if (half_1flag1 == 1)
	{
		Half1Update1();
	}
	if (half_1flag2 == 1)
	{
		Half1Update2();
	}
	if (half_1flag3 == 1)
	{
		Half1Update3();
	}
	if (half_1flag4 == 1)
	{
		Half1Update4();
	}
	if (half_2flag0 == 1)
	{
		Half2Update0();
	}
	if (half_2flag1 == 1)
	{
		Half2Update1();
	}
	if (half_2flag2 == 1)
	{
		Half2Update2();
	}
	if (half_2flag3 == 1)
	{
		Half2Update3();
	}
	if (half_2flag4 == 1)
	{
		Half2Update4();
	}
}

void updateWithoutInput()
{
	updateWithoutInput_ifhalfupdate();
	if (omit >= 3)
	{
		flag = 2;
		PlaySound(".\\source\\sound\\over.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
	}

	count++;
	if (end - start > 3)//3秒以后再出现水果
	{
		run_count++;
		if (run_count == 400)
		{
			iniFlag2 = 0;
		}
		else if (run_count == 900)
		{
			iniFlag1 = 0;
		}
		else if (run_count == 1400)
		{
			iniFlag2 = 0;
		}
		else if (run_count == 1200)
		{
			iniFlag3 = 0;
		}
		else if (run_count == 2000)
		{
			iniFlag1 = 0;
			iniFlag4 = 0;
			run_count = 0;
		}
		updateWithoutInput_fruit();
		if (iniFlag3 == 0)
		{
			for (k1 = 0; k1 < 2; k1++)
			{
				Boom_x1[k1] = 200 + rand() % (Width - 460);
				Boom_y1[k1] = High + 10;
			}
			PlaySound(".\\source\\sound\\throw.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			Velocity_y3 = v0;
			t3 = 1;
			flag3 = 1;
			iniFlag3 = 1;
		}
		if (flag3 == 1)
		{
			Left_boom_movement(Boom_x1, Boom_y1);
		}
		if (iniFlag4 == 0)
		{

			for (k1 = 0; k1 < 2; k1++)
			{
				Boom_x2[k1] = 200 + rand() % (Width - 460);
				Boom_y2[k1] = High + 10;
			}
			Velocity_y4 = v0;
			t4 = 1;
			flag4 = 1;
			iniFlag4 = 1;
		}
		if (flag4 == 1)
		{
			Right_boom_movement(Boom_x2, Boom_y2);
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
	rotateimage(&img_apple2, &img_apple1, apple_Angle += 1);
	appleL_roll = 1;
	appleR_roll = 1;
	rotateimage(&img_banana2, &img_banana1, banana_Angle += 1.5);
	bananaL_roll = 1;
	bananaR_roll = 1;
	rotateimage(&img_peach2, &img_peach1, peach_Angle -= 0.9);
	peachL_roll = 1;
	peachR_roll = 1;
	rotateimage(&img_basaha2, &img_basaha1, basaha_Angle += 1.2);
	basahaL_roll = 1;
	basahaR_roll = 1;
	rotateimage(&img_sandia2, &img_sandia1, sandia_Angle -= 1.3);
	sandiaL_roll = 1;
	sandiaR_roll = 1;
	rotateimage(&img_boom2, &img_boom1, boom_Angle += 2);
	boomL_roll = 1;
	boomR_roll = 1;

	if (Fruit_y1[0] >= 520 && Fruit_y1[0] <= 521)
		omit++;
	if (Fruit_y1[1] >= 520 && Fruit_y1[1] <= 521)
		omit++;
	if (Fruit_y1[2] >= 520 && Fruit_y1[2] <= 521)
		omit++;
	if (Fruit_y1[3] >= 520 && Fruit_y1[3] <= 521)
		omit++;
	if (Fruit_y1[4] >= 520 && Fruit_y1[4] <= 521)
		omit++;

	if (Fruit_y2[0] >= 521 && Fruit_y2[0] <= 522)
		omit++;
	if (Fruit_y2[1] >= 521 && Fruit_y2[1] <= 522)
		omit++;
	if (Fruit_y2[2] >= 521 && Fruit_y2[2] <= 522)
		omit++;
	if (Fruit_y2[3] >= 521 && Fruit_y2[3] <= 522)
		omit++;
	if (Fruit_y2[4] >= 521 && Fruit_y2[4] <= 522)
		omit++;
}
void updateWithInput()
{
	HWND hwnd = GetHWnd();
	POINT fruit_knife;				//定义水果刀的位置
	if (KEY_DOWN(VK_LBUTTON))
	{
		knifeflag = 1;
		GetCursorPos(&fruit_knife);
		ScreenToClient(hwnd, &fruit_knife);			//获取光标的位置，即为水果刀的位置
													//以下为水果刀切到水果
		if ((Fruit_1flag0 == 1) && (fruit_knife.x - Fruit_x1[0] - 63)*(fruit_knife.x - Fruit_x1[0] - 63) + (fruit_knife.y - Fruit_y1[0] - 25)*(fruit_knife.y - Fruit_y1[0] - 25) <= 900)
		{
			score++;
			Fruit_1flag0 = 0;
			putimage(Fruit_x1[0] + 63, Fruit_y1[0] + 25, &img_flash);
			half_1flag0 = 1;
			flag_1v0 = 1;
			flag_1s0 = 1;
			T1[0] = 1;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((Fruit_1flag1 == 1) && ((fruit_knife.x - Fruit_x1[1] - 33)*(fruit_knife.x - Fruit_x1[1] - 33) + (fruit_knife.y - Fruit_y1[1] - 33)*(fruit_knife.y - Fruit_y1[1] - 33)) <= 1000)
		{
			score++;
			Fruit_1flag1 = 0;
			half_1flag1 = 1;
			flag_1v1 = 1;
			flag_1s1 = 1;
			T1[1] = 1;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((Fruit_1flag2 == 1) && ((fruit_knife.x - Fruit_x1[2] - 33)*(fruit_knife.x - Fruit_x1[2] - 33) + (fruit_knife.y - Fruit_y1[2] - 33)*(fruit_knife.y - Fruit_y1[2] - 33)) <= 1000)
		{
			score++;
			Fruit_1flag2 = 0;
			half_1flag2 = 1;
			flag_1v2 = 1;
			flag_1s2 = 1;
			T1[2] = 1;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((Fruit_1flag3 == 1) && ((fruit_knife.x - Fruit_x1[3] - 49)*(fruit_knife.x - Fruit_x1[3] - 49) + (fruit_knife.y - Fruit_y1[3] - 42)*(fruit_knife.y - Fruit_y1[3] - 42)) <= 1600)
		{
			score++;
			Fruit_1flag3 = 0;
			half_1flag3 = 1;
			flag_1v3 = 1;
			flag_1s3 = 1;
			T1[3] = 1;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((Fruit_1flag4 == 1) && ((fruit_knife.x - Fruit_x1[4] - 34)*(fruit_knife.x - Fruit_x1[4] - 34) + (fruit_knife.y - Fruit_y1[4] - 36)*(fruit_knife.y - Fruit_y1[4] - 36)) <= 900)
		{
			score++;
			Fruit_1flag4 = 0;
			half_1flag4 = 1;
			flag_1v4 = 1;
			flag_1s4 = 1;
			T1[4] = 1;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}

		//向右消失的水果
		if ((Fruit_2flag0 == 1) && (fruit_knife.x - Fruit_x2[0] - 63)*(fruit_knife.x - Fruit_x2[0] - 63) + (fruit_knife.y - Fruit_y2[0] - 25)*(fruit_knife.y - Fruit_y2[0] - 25) <= 1000)
		{
			score++;
			Fruit_2flag0 = 0;
			half_2flag0 = 1;
			flag_2v0 = 1;
			flag_2s0 = 1;
			T2[0] = 1;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			//putimage(Fruit_x1[0] + 63, Fruit_y1[0] + 25, &img_flash);
		}
		if ((Fruit_2flag1 == 1) && ((fruit_knife.x - Fruit_x2[1] - 33)*(fruit_knife.x - Fruit_x2[1] - 33) + (fruit_knife.y - Fruit_y2[1] - 33)*(fruit_knife.y - Fruit_y2[1] - 33)) <= 1000)
		{
			score++;
			Fruit_2flag1 = 0;
			half_2flag1 = 1;
			flag_2v1 = 1;
			flag_2s1 = 1;
			T2[1] = 1;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((Fruit_2flag2 == 1) && ((fruit_knife.x - Fruit_x2[2] - 33)*(fruit_knife.x - Fruit_x2[2] - 33) + (fruit_knife.y - Fruit_y2[2] - 33)*(fruit_knife.y - Fruit_y2[2] - 33)) <= 1000)
		{
			score++;
			Fruit_2flag2 = 0;
			half_2flag2 = 1;
			flag_2v2 = 1;
			flag_2s2 = 1;
			T2[2] = 1;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((Fruit_2flag3 == 1) && ((fruit_knife.x - Fruit_x2[3] - 49)*(fruit_knife.x - Fruit_x2[3] - 49) + (fruit_knife.y - Fruit_y2[3] - 42)*(fruit_knife.y - Fruit_y2[3] - 42)) <= 1600)
		{
			score++;
			Fruit_2flag3 = 0;
			half_2flag3 = 1;
			flag_2v3 = 1;
			flag_2s3 = 1;
			T2[3] = 1;
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
		}
		if ((Fruit_2flag4 == 1) && ((fruit_knife.x - Fruit_x2[4] - 34)*(fruit_knife.x - Fruit_x2[4] - 34) + (fruit_knife.y - Fruit_y2[4] - 36)*(fruit_knife.y - Fruit_y2[4] - 36)) <= 900)
		{
			score++;
			Fruit_2flag4 = 0;
			half_2flag4 = 1;
			flag_2v4 = 1;
			flag_2s4 = 1;
			T2[4] = 1;
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
	daoguang_end();
}


void show_over()
{
	cleardevice();
	BeginBatchDraw();
	putimage(0, 0, &img_bk);

	daoguang_start();
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
	putimage(55, 100, &img_gameover_1);
	/*if (gameover_roll == 1)
	putimage(55, 0, &img_gameover_2);*/
	if (sandiaL_roll == 1)
		putimage(55, 315, &img_sandia2);
	if (newgameL_roll == 1)
		putimage(-15, 240, &img_newgame2);

	if (boomL_roll == 1)
		putimage(500, 310, &img_boom2);
	if (quitL_roll == 1)
		putimage(450, 260, &img_quit2);

	FlushBatchDraw();
	Sleep(2);
}
void updateWithoutInput_over()
{
	char score_t[80];
	int i = 0, r;

	int score_s;
	score_s = score;
	while (score_s != 0)
	{
		r = score_s % 10;
		score_s = score_s / 10;
		score_t[i] = r + '0' - 0;
		i++;
	}
	score_t[i] = '\0';
	int score_high = strlen(score_t) - 1;
	int score_low = 0;

	while (score_high > score_low)
	{
		char t = score_t[score_high];
		score_t[score_high] = score_t[score_low];
		score_t[score_low] = t;
		score_high--;
		score_low++;
	}
	if (fakeflag == 1)
	{
		char highest_score[80];
		if (k == 0)
		{
			fopen_s(&fp, "highest_score1.txt", "r");
			fgets(highest_score, 80, fp);
			fclose(fp);
			int highest_score10 = 0;
			for (i = 0; highest_score[i] >= '0'&&highest_score[i] <= '9'; i++)
				highest_score10 = 10 * highest_score10 + (highest_score[i] - '0');

			if (score > highest_score10)
			{
				strcpy_s(highest_score, score_t);
				fopen_s(&fp, "highest_score1.txt", "w+");
				fputs(highest_score, fp);
				fclose(fp);
			}
			k = 1;
		}
	}
	if (fakeflag == 3)
	{
		char highest_score2[80];
		if (h == 0)
		{
			fopen_s(&fp2, "highest_score2.txt", "r");
			fgets(highest_score2, 80, fp2);
			fclose(fp2);
			int highest_score20 = 0;
			for (i = 0; highest_score2[i] >= '0'&&highest_score2[i] <= '9'; i++)
				highest_score20 = 10 * highest_score20 + (highest_score2[i] - '0');

			if (score > highest_score20)
			{
				strcpy_s(highest_score2, score_t);
				fopen_s(&fp2, "highest_score2.txt", "w+");
				fputs(highest_score2, fp2);
				fclose(fp2);
			}
			h = 1;
		}
	}
	count++;
	rotateimage(&img_sandia2, &img_sandia1, sandia_Angle += 1.3);
	sandiaL_roll = 1;

	rotateimage(&img_newgame2, &img_newgame1, newgame_Angle -= 1.6);
	newgameL_roll = 1;

	rotateimage(&img_boom2, &img_boom1, boom_Angle -= 1.8);
	boomL_roll = 1;

	rotateimage(&img_quit2, &img_quit1, quit_Angle += 1.2);
	quitL_roll = 1;
}
void updateWithInput_over()
{
	HWND hwnd = GetHWnd();
	POINT fruit_knife;				//定义水果刀的位置
	if (KEY_DOWN(VK_LBUTTON))
	{
		knifeflag = 1;
		GetCursorPos(&fruit_knife);
		ScreenToClient(hwnd, &fruit_knife);			//获取光标的位置，即为水果刀的位置
													//以下为水果刀切到水果
		if ((fruit_knife.x - 500 - 33)*(fruit_knife.x - 500 - 33) + (fruit_knife.y - 310 - 33)*(fruit_knife.y - 310 - 33) < 1089)
		{
			exit(0);
		}
		if ((fruit_knife.x - 55 - 49)*(fruit_knife.x - 55 - 49) + (fruit_knife.y - 315 - 43)*(fruit_knife.y - 315 - 43) < 1000)
		{
			PlaySound(".\\source\\sound\\splatter.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			omit = 0;
			flag = 0;
			score = 0;
			k = 0;
			h = 0;
			t1 = 1;
			t2 = 1;
			t3 = 1;
			t4 = 1;
			Velocity_x1 = -0.2; Velocity_y1 = 0;
			Velocity_x2 = -0.2; Velocity_y2 = 0;
			Velocity_x3 = -0.2; Velocity_y3 = 0;
			Velocity_x4 = -0.2; Velocity_y4 = 0;
			v0 = -1.15; g = 0.000004;

			flag1 = 0;
			flag2 = 0;
			flag3 = 0;
			flag4 = 0;

			flag = 0;

			minute = 0;
			second = 30;
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
	daoguang_end();
}


void show_dojo()
{

	cleardevice();
	BeginBatchDraw();

	putimage(0, 0, &img_bk);		// 显示背景
	putimage(15, 15, &img_score);

	daoguang_start();
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

	if (second >= 10)
	{
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
	}
	if (second < 10)
	{
		char b[5];
		LOGFONT q;
		gettextstyle(&q);                     // 获取当前字体设置
		q.lfHeight = 40;                      // 设置字体高度为 40
		_tcscpy_s(q.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC	或者VS推荐使用 _tcscpy_s 函数)
		q.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
		setcolor(YELLOW);                     //作图色为黄色
		settextstyle(&q);                     // 设置字体样式
		sprintf_s(b, "%d", second);
		setbkmode(TRANSPARENT);
		outtextxy(565, 13, "0");
		outtextxy(585, 13, b);
	}
	char h[80];
	fopen_s(&fp2, "highest_score2.txt", "r");
	fgets(h, 80, fp2);
	fclose(fp2);
	LOGFONT t;
	gettextstyle(&t);                     // 获取当前字体设置
	t.lfHeight = 21;                      // 设置字体高度为 23
	_tcscpy_s(t.lfFaceName, _T("黑体"));    // 设置字体为“黑体”(高版本 VC	或者VS推荐使用 _tcscpy_s 函数)
	t.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
	setcolor(GREEN);						 //作图色为绿色
	settextstyle(&t);                     // 设置字体样式
										  //sprintf_s(h, "%d", highest_score2);
	setbkmode(TRANSPARENT);
	outtextxy(5, 53, "best:");
	outtextxy(60, 55, h);

	show_fruit();
	FlushBatchDraw();
	end = time(NULL);
	end2 = time(NULL);
	finish3 = clock();
	Sleep(1);
}
void updateWithoutInput_dojo()
{
	count++;
	updateWithoutInput_ifhalfupdate();
	if (1000 <= finish3 - start3 && finish3 - start3 <= 1015)
	{
		second--;
		start3 = clock();
	}
	if (second == 0 && minute != 0)
	{
		minute -= 1;
		second = 60;
	}
	if (second == 0 && minute == 0)
	{
		flag = 2;
		PlaySound(".\\source\\sound\\over.wav", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
	}
	if (end - start > 3)//3秒以后再出现水果
	{
		run_count++;
		if (run_count == 400) {
			iniFlag2 = 0;
		}
		else if (run_count == 900) {
			iniFlag1 = 0;
		}
		else if (run_count == 1400) {
			iniFlag2 = 0;
		}
		else if (run_count == 1200) {

		}

		else if (run_count == 2000) {
			iniFlag1 = 0;

			run_count = 0;
		}
		updateWithoutInput_fruit();
		Velocity_y1 += g * t1;
		Velocity_y2 += (1.4)*g * t2;
		Velocity_y3 += 1.8*g*t3;
		t1++;
		t2++;
		t3++;
	}
	rotateimage(&img_apple2, &img_apple1, apple_Angle += 1);
	appleL_roll = 1;
	appleR_roll = 1;
	rotateimage(&img_banana2, &img_banana1, banana_Angle += 1.5);
	bananaL_roll = 1;
	bananaR_roll = 1;
	rotateimage(&img_peach2, &img_peach1, peach_Angle -= 0.9);
	peachL_roll = 1;
	peachR_roll = 1;
	rotateimage(&img_basaha2, &img_basaha1, basaha_Angle += 1.2);
	basahaL_roll = 1;
	basahaR_roll = 1;
	rotateimage(&img_sandia2, &img_sandia1, sandia_Angle -= 1.3);
	sandiaL_roll = 1;
	sandiaR_roll = 1;
	rotateimage(&img_boom2, &img_boom1, boom_Angle += 2);
	boomL_roll = 1;
	boomR_roll = 1;
}
void updateWithInput_dojo()
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
			updateWithoutInput();    // 与用户输入无关的更新
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
			show_dojo();
			updateWithoutInput_dojo();
			updateWithInput_dojo();
		}

	}
	gameover();     // 游戏结束、后续处理
	return 0;
}