#include"EasyXPng.h"
#include<graphics.h>
#include <conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#include<mmsystem.h>
#include<string.h>
float mx1 = 0, mx2 = 0, my1 = 0, my2 = 0;
float mx3 = 0, mx4 = 0, my3 = 0, my4 = 0;
float mx5 = 0, mx6 = 0, my5 = 0, my6 = 0;
float mx7 = 0, mx8 = 0, my7 = 0, my8 = 0;
int count = 0;
//显示刀光
int knifeflag = 0;

int iniFlag1 = 0;
int iniFlag2 = 1;
int iniFlag3 = 1;
int iniFlag4 = 1;
int run_count = 0;
int omit = 0;//遗漏的水果
int k1, i1;
int k2, i2;
int k = 0;//经典模式中best的flag
int h = 0;//禅宗模式中best的flag
int score = 0;
int minute = 0;
int second = 30;
int highest_score1 = 0;
int highest_score2 = 0;
int fakeflag = 0;
time_t start, end, start2, end2;
clock_t start3, finish3;
FILE *fp;
FILE *fp2;

float apple_Angle = 0;	//苹果的旋转参数
float banana_Angle = 0;	//香蕉的旋转参数
float peach_Angle = 0;	//桃子的旋转参数
float sandia_Angle = 0;	//西瓜的旋转参数
float basaha_Angle = 0;	//草莓的旋转参数

float apple1Half_AngleL = 0;		//向左抛被切后苹果的旋转参数
float apple1Half_AngleR = 0;		//向左抛被切后苹果的旋转参数
float basaha1Half_AngleL = 0;		//向左抛被切后草莓的旋转参数
float basaha1Half_AngleR = 0;		//向左抛被切后草莓的旋转参数
float banana1Half_AngleL = 0;		//向左抛被切后香蕉的旋转参数
float banana1Half_AngleR = 0;		//向左抛被切后香蕉的旋转参数
float sandia1Half_AngleL = 0;		//向左抛被切后西瓜的旋转参数
float sandia1Half_AngleR = 0;		//向左抛被切后西瓜的旋转参数
float peach1Half_AngleL = 0;		//向左抛被切后桃子的旋转参数
float peach1Half_AngleR = 0;		//向左抛被切后桃子的旋转参数

float apple2Half_AngleL = 0;		//向右抛被切后苹果的旋转参数
float apple2Half_AngleR = 0;		//向右抛被切后苹果的旋转参数
float basaha2Half_AngleL = 0;		//向右抛被切后草莓的旋转参数
float basaha2Half_AngleR = 0;		//向右抛被切后草莓的旋转参数
float banana2Half_AngleL = 0;		//向右抛被切后香蕉的旋转参数
float banana2Half_AngleR = 0;		//向右抛被切后香蕉的旋转参数
float sandia2Half_AngleL = 0;		//向右抛被切后西瓜的旋转参数
float sandia2Half_AngleR = 0;		//向右抛被切后西瓜的旋转参数
float peach2Half_AngleL = 0;		//向右抛被切后桃子的旋转参数
float peach2Half_AngleR = 0;		//向右抛被切后桃子的旋转参数

float apple2Half_Angle = 0;		//向右抛被切后苹果的旋转参数

float boom_Angle = 0;	//炸弹的旋转参数

float newgame_Angle = 0;//菜单的旋转参数
float gameover_Angle = 0;//游戏结束的旋转参数

float quit_Angle = 0;//quit的旋转
float dojo_Angle = 0;//dojo的旋转

float Fruit_x1[10];
float Fruit_y1[10];//向左发射的水果
float Fruit_x2[10];
float Fruit_y2[10];//向右发射的水果

float Fruit_lx1[10];
float Fruit_ly1[10];//左边一半水果
float Fruit_lx2[10];
float Fruit_ly2[10];//左边一半水果

float Fruit_rx1[10];
float Fruit_ry1[10];//右边一半水果
float Fruit_rx2[10];
float Fruit_ry2[10];//右边一半水果

//水果分开两半后的坐标
float apple1_L_x, apple1_L_y;
float apple1_R_x, apple1_R_y;

float banana1_L_x, banana1_L_y;
float banana1_R_x, banana1_R_y;

float basaha1_L_x, basaha1_L_y;
float basaha1_R_x, basaha1_R_y;

float peach1_L_x, peach1_L_y;
float peach1_R_x, peach1_R_y;

float sandia1_L_x, sandia1_L_y;
float sandia1_R_x, sandia1_R_y;

float apple2_L_x, apple2_L_y;
float apple2_R_x, apple2_R_y;

float banana2_L_x, banana2_L_y;
float banana2_R_x, banana2_R_y;

float basaha2_L_x, basaha2_L_y;
float basaha2_R_x, basaha2_R_y;

float peach2_L_x, peach2_L_y;
float peach2_R_x, peach2_R_y;

float sandia2_L_x, sandia2_L_y;
float sandia2_R_x, sandia2_R_y;

float Boom_x1[3], Boom_y1[3];
float Boom_x2[3], Boom_y2[3];
//左右两半分开的速度
float Velocity_1Half0_x = -0.4, Velocity_1Half0_y = 0;
float Velocity_1Half1_x = -0.3, Velocity_1Half1_y = 0;
float Velocity_1Half2_x = -0.4, Velocity_1Half2_y = 0;
float Velocity_1Half3_x = -0.3, Velocity_1Half3_y = 0;
float Velocity_1Half4_x = -0.5, Velocity_1Half4_y = 0;
float Velocity_2Half0_x = -0.4, Velocity_2Half0_y = 0;
float Velocity_2Half1_x = -0.34, Velocity_2Half1_y = 0;
float Velocity_2Half2_x = -0.2, Velocity_2Half2_y = 0;
float Velocity_2Half3_x = -0.5, Velocity_2Half3_y = 0;
float Velocity_2Half4_x = -0.4, Velocity_2Half4_y = 0;
//水果移动的初始值
float Velocity_x1 = -0.2, Velocity_y1 = 0;
float Velocity_x2 = -0.2, Velocity_y2 = 0;
float Velocity_x3 = -0.2, Velocity_y3 = 0;
float Velocity_x4 = -0.2, Velocity_y4 = 0;
float v0 = -1.15, g = 0.000004;
float t1, t2, t3, t4;//水果移动的初始值
//水果切成两半后运动的t的初始化
float T1[4] = { 1,1,1,1 };
float T2[4] = { 1,1,1,1 };
//显示左边水果两半
int half_1flag0 = 0;
int half_1flag1 = 0;
int half_1flag2 = 0;
int half_1flag3 = 0;
int half_1flag4 = 0;
//显示右边水果两半
int half_2flag0 = 0;
int half_2flag1 = 0;
int half_2flag2 = 0;
int half_2flag3 = 0;
int half_2flag4 = 0;
//分别进行一次对两半水果的初速度v和位置s的初始化的flag
int flag_1v0 = 1;
int flag_1s0 = 1;
int flag_1v1 = 1;
int flag_1s1 = 1;
int flag_1v2 = 1;
int flag_1s2 = 1;
int flag_1v3 = 1;
int flag_1s3 = 1;
int flag_1v4 = 1;
int flag_1s4 = 1;
int flag_2v0 = 1;
int flag_2s0 = 1;
int flag_2v1 = 1;
int flag_2s1 = 1;
int flag_2v2 = 1;
int flag_2s2 = 1;
int flag_2v3 = 1;
int flag_2s3 = 1;
int flag_2v4 = 1;
int flag_2s4 = 1;

int Fruit_n1, Fruit_n2;//随机水果出现的情况
int flag1, flag2, flag3, flag4;//时间的判断

	   //向左的水果出现
int Fruit_1flag0 = 1;//香蕉banana的出现
int Fruit_1flag1 = 1;//苹果apple的出现
int Fruit_1flag2 = 1;//芒果peach的出现
int Fruit_1flag3 = 1;//西瓜sandia的出现
int Fruit_1flag4 = 1;//草莓basaha的出现

	 //向右的水果出现
int Fruit_2flag0 = 1;//香蕉banana的出现
int Fruit_2flag1 = 1;//苹果apple的出现
int Fruit_2flag2 = 1;//芒果peach的出现
int Fruit_2flag3 = 1;//西瓜sandia的出现
int Fruit_2flag4 = 1;//草莓basaha的出现

int appleL_roll = 0;//苹果向左旋转flag
int appleR_roll = 0;//苹果向右旋转flag

int bananaL_roll = 0;//香蕉向左旋转flag
int bananaR_roll = 0;//香蕉向右旋转flag

int basahaL_roll = 0;//草莓向左旋转flag
int basahaR_roll = 0;//草莓向右旋转flag

int sandiaL_roll = 0;//西瓜向左旋转flag
int sandiaR_roll = 0;//西瓜向右旋转flag

int peachL_roll = 0;//桃子向左旋转flag
int peachR_roll = 0;//桃子向右旋转flag

int boomL_roll = 0;//炸弹向左旋转flag
int boomR_roll = 0;//炸弹向右旋转flag

int newgameL_roll = 0;//菜单向左旋转flag
int quitL_roll = 0;//退出键向左旋转flag
int dojoL_roll = 0;//禅宗模式向左旋转flag

int apple1HalfL_roll = 0;	//向左抛苹果被切成左边的一瓣旋转的flag
int apple1HalfR_roll = 0;	//向左抛苹果被切成右边的一瓣旋转的flag
int banana1HalfL_roll = 0;	//向左抛香蕉被切成左边的一瓣旋转的flag
int banana1HalfR_roll = 0;	//向左抛香蕉被切成右边的一瓣旋转的flag
int basaha1HalfL_roll = 0;	//向左抛草莓被切成左边的一瓣旋转的flag
int basaha1HalfR_roll = 0;	//向左抛草莓被切成右边的一瓣旋转的flag
int peach1HalfL_roll = 0;	//向左抛桃子被切成左边的一瓣旋转的flag
int peach1HalfR_roll = 0;	//向左抛桃子被切成右边的一瓣旋转的flag
int sandia1HalfL_roll = 0;	//向左抛西瓜被切成左边的一瓣旋转的flag
int sandia1HalfR_roll = 0;	//向左抛西瓜被切成右边的一瓣旋转的flag

int apple2HalfL_roll = 0;		//向右抛苹果被切成左边的一瓣旋转的flag
int apple2HalfR_roll = 0;	//向右抛苹果被切成右边的一瓣旋转的flag
int banana2HalfL_roll = 0;	//向右抛香蕉被切成左边的一瓣旋转的flag
int banana2HalfR_roll = 0;	//向右抛香蕉被切成右边的一瓣旋转的flag
int basaha2HalfL_roll = 0;	//向右抛草莓被切成左边的一瓣旋转的flag
int basaha2HalfR_roll = 0;	//向右抛草莓被切成右边的一瓣旋转的flag
int peach2HalfL_roll = 0;	//向右抛桃子被切成左边的一瓣旋转的flag
int peach2HalfR_roll = 0;	//向右抛桃子被切成右边的一瓣旋转的flag
int sandia2HalfL_roll = 0;	//向右抛西瓜被切成左边的一瓣旋转的flag
int sandia2HalfR_roll = 0;	//向右抛西瓜被切成右边的一瓣旋转的flag

	 //以下定义所有图片
IMAGE img_bk;
IMAGE_PNG img_apple1, img_apple2;		//苹果
IMAGE_PNG img_banana1, img_banana2;		//香蕉
IMAGE_PNG img_basaha1, img_basaha2;		//草莓
IMAGE_PNG img_peach1, img_peach2;		//桃子
IMAGE_PNG img_sandia1, img_sandia2;		//西瓜

IMAGE_PNG img_apple_1L1, img_apple_1L2;			//向左抛苹果左半边左瓣
IMAGE_PNG img_banana_1L1, img_banana_1L2;		//向左抛香蕉左半边左瓣
IMAGE_PNG img_basaha_1L1, img_basaha_1L2;		//向左抛草莓左半边左瓣
IMAGE_PNG img_peach_1L1, img_peach_1L2;			//向左抛桃子左半边左瓣
IMAGE_PNG img_sandia_1L1, img_sandia_1L2;		//向左抛西瓜左半边左瓣
IMAGE_PNG img_apple_1R1, img_apple_1R2;			//向左抛苹果左半边右瓣
IMAGE_PNG img_banana_1R1, img_banana_1R2;		//向左抛香蕉左半边右瓣
IMAGE_PNG img_basaha_1R1, img_basaha_1R2;		//向左抛草莓左半边右瓣
IMAGE_PNG img_peach_1R1, img_peach_1R2;			//向左抛桃子左半边右瓣
IMAGE_PNG img_sandia_1R1, img_sandia_1R2;		//向左抛西瓜左半边右瓣

IMAGE_PNG img_apple_2L1, img_apple_2L2;			//向右抛苹果左半边左瓣
IMAGE_PNG img_banana_2L1, img_banana_2L2;		//向右抛香蕉左半边左瓣
IMAGE_PNG img_basaha_2L1, img_basaha_2L2;		//向右抛草莓左半边左瓣
IMAGE_PNG img_peach_2L1, img_peach_2L2;			//向右抛桃子左半边左瓣
IMAGE_PNG img_sandia_2L1, img_sandia_2L2;		//向右抛西瓜左半边左瓣
IMAGE_PNG img_apple_2R1, img_apple_2R2;			//向右抛苹果左半边右瓣
IMAGE_PNG img_banana_2R1, img_banana_2R2;		//向右抛香蕉左半边右瓣
IMAGE_PNG img_basaha_2R1, img_basaha_2R2;		//向右抛草莓左半边右瓣
IMAGE_PNG img_peach_2R1, img_peach_2R2;			//向右抛桃子左半边右瓣
IMAGE_PNG img_sandia_2R1, img_sandia_2R2;		//向右抛西瓜左半边右瓣

IMAGE_PNG img_flash;
IMAGE_PNG img_boom1, img_boom2;//炸弹
IMAGE_PNG img_x, img_xx, img_xxx;//右上角叉
IMAGE_PNG img_xf, img_xxf, img_xxxf;//右上角红叉
IMAGE_PNG img_score;//左上角分数

					//菜单选项
IMAGE_PNG img_newgame1, img_newgame2;
IMAGE_PNG img_fruit;
IMAGE_PNG img_ninja;
IMAGE_PNG img_new;
IMAGE_PNG img_shallow;
IMAGE_PNG img_tip;
IMAGE_PNG img_quit1, img_quit2;
IMAGE_PNG img_dojo1, img_dojo2;

//游戏结束
IMAGE_PNG img_gameover_1;
IMAGE_PNG img_gameover_2;


int newgameR_roll = 0;//游戏结束时菜单向左旋转flag
int gameover_roll = 0;//游戏结束向右旋转flag
int flag;