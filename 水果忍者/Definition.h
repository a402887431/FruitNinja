#pragma once
#include"EasyXPng.h"
#include <time.h>
int flag_1 = 0, flag_2 = 1, flag_3 = 1, flag_4 = 1;

int k1, i1;
int k2, i2;
int count1;
int score = 0;
time_t start, end,start2,end2;
int minute = 1;
int second = 30;
clock_t start3, finish3;

int omit = 0;//��©��ˮ��
int flag_omit1 = 0;
int flag_omit2 = 0;
int flag_omit3 = 0;


//��ת����
float apple_rotate = 0;													//ƻ������ת����
float banana_rotate = 0;												//�㽶����ת����
float peach_rotate = 0;													//���ӵ���ת����
float sandia_rotate = 0;												//���ϵ���ת����
float basaha_rotate = 0;												//��ݮ����ת����
float boom_rotate = 0;													//ը������ת����
float newgame_rotate = 0;													//�˵�����ת����
float gameover_rotate = 0;												//��Ϸ��������ת����
float quit_rotate = 0;													//quit����ת
float dojo_rotate = 0;													//dojo����ת

float cw_fh_rotate = 0;

//������ת����
float chaomeng_rotate = 0;
float chenglong_rotate = 0;
float jienigui_rotate = 0;
float kabi_rotate = 0;
float pikaqiu_rotate = 0;
float qinglong_rotate = 0;
float menghuan_rotate = 0;
float shuijingling_rotate = 0;
float yibu_rotate = 0;
float xiaohuolong_rotate = 0;


//ˮ��+ը���������
float Fruit_x1[10];
float Fruit_y1[10];						//�������ˮ��
float Fruit_x2[10];
float Fruit_y2[10];						//���ҷ����ˮ��
float Fruit_lx1[10];
float Fruit_ly1[10];					//���һ��ˮ��
float Fruit_lx2[10];
float Fruit_ly2[10];					//���һ��ˮ��
float Fruit_rx1[10];
float Fruit_ry1[10];					//�ұ�һ��ˮ��
float Fruit_rx2[10];
float Fruit_ry2[10];					//�ұ�һ��ˮ��
float Boom_x1[3], Boom_y1[3];
float Boom_x2[3], Boom_y2[3];

//������ת����
float animal_x1[10];
float animal_y1[10];
float animal_x2[10];
float animal_y2[10];





//�������˶��ĳ��ٶ�+���ٶ�+�Զ���ĳ���
float Velocity_x1 = -0.2, Velocity_y1 = 0;
float Velocity_x2 = -0.2, Velocity_y2 = 0;
float Velocity_x3 = -0.2, Velocity_y3 = 0;
float Velocity_x4 = -0.2, Velocity_y4 = 0;
float v0 = -1.15, g = 0.0000038;
float t1, t2, t3, t4;									//ˮ���ƶ��ĳ�ʼֵ


int Fruit_n1, Fruit_n2;									//���ˮ�����ֵ����
int flag1, flag2;
int flag3, flag4;





//�ж�ˮ���Ƿ���� 1��ʾ 0 ����ʾ
int banana_flag1 = 1;
int apple_flag1 = 1;
int peach_flag1 = 1;
int sandia_flag1 = 1;
int basaha_flag1 = 1;
int banana_flag2 = 1;
int apple_flag2 = 1;
int peach_flag2 = 1;
int sandia_flag2 = 1;
int basaha_flag2 = 1;

//�жϾ������Ƿ���ʾ
int chanmeng_flag = 1;
int chenglong_flag = 1;
int jienigui_flag = 1;
int kabi_flag = 1;
int pikaqiu_flag = 1;
int qinglong_flag = 1;
int menghuan_flag = 1;
int yibu_flag = 1;
int xiaohuolong_flag = 1;



//���ڽ����ת ���ֵ�bug ����ˮ���Ƿ���ת ��ת1 ����ת�������ڼ�Ϊ0��
//ˮ���� ��� �� �ұ� ������ ���Է�����ת������ת
int appleL_roll = 0;
int appleR_roll = 0;
int bananaL_roll = 0;
int bananaR_roll = 0;
int basahaL_roll = 0;
int basahaR_roll = 0;
int sandiaL_roll = 0;
int sandiaR_roll = 0;
int peachL_roll = 0;
int peachR_roll = 0;
int boomL_roll = 0;
int boomR_roll = 0;

int newgameL_roll = 0;									//�˵�������תflag
int quitL_roll = 0;										//�˳���������תflag
int dojoL_roll = 0;										//��ʱģʽ������תflag


//ȫ��������ת
int chaomengL_roll = 0;
int chenglongL_roll = 0;
int jieniguiL_roll = 0;
int kabiL_roll = 0;
int pikaqiuL_roll = 0;
int qinglongL_roll = 0;
int menghuanL_roll = 0;
int shuijinglingL_roll = 0;
int yibuL_roll = 0;
int xiaohuolongL_roll = 0;


int cw_fhL_roll = 0;


//���¶�������ͼƬ
IMAGE img_bk;
IMAGE_PNG img_apple1, img_apple2;		//ƻ��
IMAGE_PNG img_banana1, img_banana2;		//�㽶
IMAGE_PNG img_basaha1, img_basaha2;		//��ݮ
IMAGE_PNG img_peach1, img_peach2;		//����
IMAGE_PNG img_sandia1, img_sandia2;		//����

IMAGE_PNG img_apple_L1, img_apple_L2;		//ƻ������
IMAGE_PNG img_banana_L1, img_banana_L2;		//�㽶����
IMAGE_PNG img_basaha_L1, img_basaha_L2;		//��ݮ����
IMAGE_PNG img_peach_L1, img_peach_L2;		//��������
IMAGE_PNG img_sandia_L1, img_sandia_L2;		//��������

IMAGE_PNG img_apple_R1, img_apple_R2;		//ƻ���Ұ��
IMAGE_PNG img_banana_R1, img_banana_R2;		//�㽶�Ұ��
IMAGE_PNG img_basaha_R1, img_basaha_R2;		//��ݮ�Ұ��
IMAGE_PNG img_peach_R1, img_peach_R2;		//�����Ұ��
IMAGE_PNG img_sandia_R1, img_sandia_R2;		//�����Ұ��

IMAGE_PNG img_flash;



IMAGE_PNG img_boom1, img_boom2;						//ը��
IMAGE_PNG img_x, img_xx, img_xxx;					//���Ͻǲ�
IMAGE_PNG img_xf, img_xxf, img_xxxf;				//���ϽǺ��
IMAGE_PNG img_score;								//���ϽǷ���

//�˵�ѡ��
IMAGE_PNG img_newgame1, img_newgame2;
IMAGE_PNG img_fruit;
IMAGE_PNG img_ninja;
IMAGE_PNG img_new;
IMAGE_PNG img_shallow;
IMAGE_PNG img_tip;
IMAGE_PNG img_quit1, img_quit2;
IMAGE_PNG img_dojo1, img_dojo2;


//��Ϸ����
IMAGE_PNG img_gameover_1;
IMAGE_PNG img_gameover_2;
int newgameR_roll = 0;//��Ϸ����ʱ�˵�������תflag
int gameover_roll = 0;//��Ϸ����������תflag
int flag;


//����
IMAGE_PNG chaomeng1,chaomeng2;
IMAGE_PNG chenglong1, chenglong2;
IMAGE_PNG jienigui1, jienigui2;
IMAGE_PNG kabi1, kabi2;
IMAGE_PNG menghuan1,menghuan2;
IMAGE_PNG pikaqiu1,pikaqiu2;
IMAGE_PNG qinglong1,qinglong2;
IMAGE_PNG shuijingling1,shuijingling2;
IMAGE_PNG xiaohuolong1,xiaohuolong2;
IMAGE_PNG yibu1,yibu2;

IMAGE congwu_bj;





IMAGE_PNG pikai_s;



IMAGE_PNG cw_fh1,cw_fh2;



