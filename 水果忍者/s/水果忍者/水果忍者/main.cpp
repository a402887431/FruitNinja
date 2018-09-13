#include"EasyXPng.h"

int main()
{
	initgraphEx();
	initgraph(1024, 768);
	IMAGE bk;
	loadimage(&bk, "back.jpg");
	IMAGE_PNG man;
	loadimage(&man, "man.png");
	IMAGE_PNG maned;
	float angle = 0;
	while (true)
	{
		rotateimage(&maned, &man, angle++);
		BeginBatchDraw();
		putimage(0, 0, &bk);
		putimage(0, 0, &man);
		putimage(300, 0, &maned);
		FlushBatchDraw();
		EndBatchDraw();
		//Sleep(10);
	}
	return 0;
}