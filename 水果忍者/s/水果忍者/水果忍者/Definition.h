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
//��ʾ����
int knifeflag = 0;

int iniFlag1 = 0;
int iniFlag2 = 1;
int iniFlag3 = 1;
int iniFlag4 = 1;
int run_count = 0;
int omit = 0;//��©��ˮ��
int k1, i1;
int k2, i2;
int k = 0;//����ģʽ��best��flag
int h = 0;//����ģʽ��best��flag
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

float apple_Angle = 0;	//ƻ������ת����
float banana_Angle = 0;	//�㽶����ת����
float peach_Angle = 0;	//���ӵ���ת����
float sandia_Angle = 0;	//���ϵ���ת����
float basaha_Angle = 0;	//��ݮ����ת����

float apple1Half_AngleL = 0;		//�����ױ��к�ƻ������ת����
float apple1Half_AngleR = 0;		//�����ױ��к�ƻ������ת����
float basaha1Half_AngleL = 0;		//�����ױ��к��ݮ����ת����
float basaha1Half_AngleR = 0;		//�����ױ��к��ݮ����ת����
float banana1Half_AngleL = 0;		//�����ױ��к��㽶����ת����
float banana1Half_AngleR = 0;		//�����ױ��к��㽶����ת����
float sandia1Half_AngleL = 0;		//�����ױ��к����ϵ���ת����
float sandia1Half_AngleR = 0;		//�����ױ��к����ϵ���ת����
float peach1Half_AngleL = 0;		//�����ױ��к����ӵ���ת����
float peach1Half_AngleR = 0;		//�����ױ��к����ӵ���ת����

float apple2Half_AngleL = 0;		//�����ױ��к�ƻ������ת����
float apple2Half_AngleR = 0;		//�����ױ��к�ƻ������ת����
float basaha2Half_AngleL = 0;		//�����ױ��к��ݮ����ת����
float basaha2Half_AngleR = 0;		//�����ױ��к��ݮ����ת����
float banana2Half_AngleL = 0;		//�����ױ��к��㽶����ת����
float banana2Half_AngleR = 0;		//�����ױ��к��㽶����ת����
float sandia2Half_AngleL = 0;		//�����ױ��к����ϵ���ת����
float sandia2Half_AngleR = 0;		//�����ױ��к����ϵ���ת����
float peach2Half_AngleL = 0;		//�����ױ��к����ӵ���ת����
float peach2Half_AngleR = 0;		//�����ױ��к����ӵ���ת����

float apple2Half_Angle = 0;		//�����ױ��к�ƻ������ת����

float boom_Angle = 0;	//ը������ת����

float newgame_Angle = 0;//�˵�����ת����
float gameover_Angle = 0;//��Ϸ��������ת����

float quit_Angle = 0;//quit����ת
float dojo_Angle = 0;//dojo����ת

float Fruit_x1[10];
float Fruit_y1[10];//�������ˮ��
float Fruit_x2[10];
float Fruit_y2[10];//���ҷ����ˮ��

float Fruit_lx1[10];
float Fruit_ly1[10];//���һ��ˮ��
float Fruit_lx2[10];
float Fruit_ly2[10];//���һ��ˮ��

float Fruit_rx1[10];
float Fruit_ry1[10];//�ұ�һ��ˮ��
float Fruit_rx2[10];
float Fruit_ry2[10];//�ұ�һ��ˮ��

//ˮ���ֿ�����������
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
//��������ֿ����ٶ�
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
//ˮ���ƶ��ĳ�ʼֵ
float Velocity_x1 = -0.2, Velocity_y1 = 0;
float Velocity_x2 = -0.2, Velocity_y2 = 0;
float Velocity_x3 = -0.2, Velocity_y3 = 0;
float Velocity_x4 = -0.2, Velocity_y4 = 0;
float v0 = -1.15, g = 0.000004;
float t1, t2, t3, t4;//ˮ���ƶ��ĳ�ʼֵ
//ˮ���г�������˶���t�ĳ�ʼ��
float T1[4] = { 1,1,1,1 };
float T2[4] = { 1,1,1,1 };
//��ʾ���ˮ������
int half_1flag0 = 0;
int half_1flag1 = 0;
int half_1flag2 = 0;
int half_1flag3 = 0;
int half_1flag4 = 0;
//��ʾ�ұ�ˮ������
int half_2flag0 = 0;
int half_2flag1 = 0;
int half_2flag2 = 0;
int half_2flag3 = 0;
int half_2flag4 = 0;
//�ֱ����һ�ζ�����ˮ���ĳ��ٶ�v��λ��s�ĳ�ʼ����flag
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

int Fruit_n1, Fruit_n2;//���ˮ�����ֵ����
int flag1, flag2, flag3, flag4;//ʱ����ж�

	   //�����ˮ������
int Fruit_1flag0 = 1;//�㽶banana�ĳ���
int Fruit_1flag1 = 1;//ƻ��apple�ĳ���
int Fruit_1flag2 = 1;//â��peach�ĳ���
int Fruit_1flag3 = 1;//����sandia�ĳ���
int Fruit_1flag4 = 1;//��ݮbasaha�ĳ���

	 //���ҵ�ˮ������
int Fruit_2flag0 = 1;//�㽶banana�ĳ���
int Fruit_2flag1 = 1;//ƻ��apple�ĳ���
int Fruit_2flag2 = 1;//â��peach�ĳ���
int Fruit_2flag3 = 1;//����sandia�ĳ���
int Fruit_2flag4 = 1;//��ݮbasaha�ĳ���

int appleL_roll = 0;//ƻ��������תflag
int appleR_roll = 0;//ƻ��������תflag

int bananaL_roll = 0;//�㽶������תflag
int bananaR_roll = 0;//�㽶������תflag

int basahaL_roll = 0;//��ݮ������תflag
int basahaR_roll = 0;//��ݮ������תflag

int sandiaL_roll = 0;//����������תflag
int sandiaR_roll = 0;//����������תflag

int peachL_roll = 0;//����������תflag
int peachR_roll = 0;//����������תflag

int boomL_roll = 0;//ը��������תflag
int boomR_roll = 0;//ը��������תflag

int newgameL_roll = 0;//�˵�������תflag
int quitL_roll = 0;//�˳���������תflag
int dojoL_roll = 0;//����ģʽ������תflag

int apple1HalfL_roll = 0;	//������ƻ�����г���ߵ�һ����ת��flag
int apple1HalfR_roll = 0;	//������ƻ�����г��ұߵ�һ����ת��flag
int banana1HalfL_roll = 0;	//�������㽶���г���ߵ�һ����ת��flag
int banana1HalfR_roll = 0;	//�������㽶���г��ұߵ�һ����ת��flag
int basaha1HalfL_roll = 0;	//�����ײ�ݮ���г���ߵ�һ����ת��flag
int basaha1HalfR_roll = 0;	//�����ײ�ݮ���г��ұߵ�һ����ת��flag
int peach1HalfL_roll = 0;	//���������ӱ��г���ߵ�һ����ת��flag
int peach1HalfR_roll = 0;	//���������ӱ��г��ұߵ�һ����ת��flag
int sandia1HalfL_roll = 0;	//���������ϱ��г���ߵ�һ����ת��flag
int sandia1HalfR_roll = 0;	//���������ϱ��г��ұߵ�һ����ת��flag

int apple2HalfL_roll = 0;		//������ƻ�����г���ߵ�һ����ת��flag
int apple2HalfR_roll = 0;	//������ƻ�����г��ұߵ�һ����ת��flag
int banana2HalfL_roll = 0;	//�������㽶���г���ߵ�һ����ת��flag
int banana2HalfR_roll = 0;	//�������㽶���г��ұߵ�һ����ת��flag
int basaha2HalfL_roll = 0;	//�����ײ�ݮ���г���ߵ�һ����ת��flag
int basaha2HalfR_roll = 0;	//�����ײ�ݮ���г��ұߵ�һ����ת��flag
int peach2HalfL_roll = 0;	//���������ӱ��г���ߵ�һ����ת��flag
int peach2HalfR_roll = 0;	//���������ӱ��г��ұߵ�һ����ת��flag
int sandia2HalfL_roll = 0;	//���������ϱ��г���ߵ�һ����ת��flag
int sandia2HalfR_roll = 0;	//���������ϱ��г��ұߵ�һ����ת��flag

	 //���¶�������ͼƬ
IMAGE img_bk;
IMAGE_PNG img_apple1, img_apple2;		//ƻ��
IMAGE_PNG img_banana1, img_banana2;		//�㽶
IMAGE_PNG img_basaha1, img_basaha2;		//��ݮ
IMAGE_PNG img_peach1, img_peach2;		//����
IMAGE_PNG img_sandia1, img_sandia2;		//����

IMAGE_PNG img_apple_1L1, img_apple_1L2;			//������ƻ���������
IMAGE_PNG img_banana_1L1, img_banana_1L2;		//�������㽶�������
IMAGE_PNG img_basaha_1L1, img_basaha_1L2;		//�����ײ�ݮ�������
IMAGE_PNG img_peach_1L1, img_peach_1L2;			//�����������������
IMAGE_PNG img_sandia_1L1, img_sandia_1L2;		//�����������������
IMAGE_PNG img_apple_1R1, img_apple_1R2;			//������ƻ�������Ұ�
IMAGE_PNG img_banana_1R1, img_banana_1R2;		//�������㽶�����Ұ�
IMAGE_PNG img_basaha_1R1, img_basaha_1R2;		//�����ײ�ݮ�����Ұ�
IMAGE_PNG img_peach_1R1, img_peach_1R2;			//���������������Ұ�
IMAGE_PNG img_sandia_1R1, img_sandia_1R2;		//���������������Ұ�

IMAGE_PNG img_apple_2L1, img_apple_2L2;			//������ƻ���������
IMAGE_PNG img_banana_2L1, img_banana_2L2;		//�������㽶�������
IMAGE_PNG img_basaha_2L1, img_basaha_2L2;		//�����ײ�ݮ�������
IMAGE_PNG img_peach_2L1, img_peach_2L2;			//�����������������
IMAGE_PNG img_sandia_2L1, img_sandia_2L2;		//�����������������
IMAGE_PNG img_apple_2R1, img_apple_2R2;			//������ƻ�������Ұ�
IMAGE_PNG img_banana_2R1, img_banana_2R2;		//�������㽶�����Ұ�
IMAGE_PNG img_basaha_2R1, img_basaha_2R2;		//�����ײ�ݮ�����Ұ�
IMAGE_PNG img_peach_2R1, img_peach_2R2;			//���������������Ұ�
IMAGE_PNG img_sandia_2R1, img_sandia_2R2;		//���������������Ұ�

IMAGE_PNG img_flash;
IMAGE_PNG img_boom1, img_boom2;//ը��
IMAGE_PNG img_x, img_xx, img_xxx;//���Ͻǲ�
IMAGE_PNG img_xf, img_xxf, img_xxxf;//���ϽǺ��
IMAGE_PNG img_score;//���ϽǷ���

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