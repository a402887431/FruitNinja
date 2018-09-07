#include <iostream>
#include <math.h>

#include "easyx.h"
#include "./GDIPlus/Includes/Gdiplus.h"
#include "MyEasyX.h"

#include "EasyXPng.h"

#pragma comment(lib, "./GDIPlus/Gdiplus.lib")

using namespace Gdiplus;
//using namespace DllExport;
using namespace std;

static ULONG_PTR gdiplusToken;
static Gdiplus::GdiplusStartupInput gdiplusStartupInput;

#define WCHAR_BUFFER_MAX 1024
static wchar_t wcharBuffer[WCHAR_BUFFER_MAX];

wchar_t * charToWChar(const char * ss)
{
	int nLen = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, ss, -1, NULL, 0);
	if (nLen == 0 || (nLen * sizeof(wchar_t)) >= WCHAR_BUFFER_MAX)
	{
		return NULL;
	}

	int ret = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, ss, -1, wcharBuffer, nLen);

	return wcharBuffer;
}

Gdiplus::Bitmap * ResizeBitmap(Gdiplus::Bitmap * bmpSrc, int destWidth, int destHeight, bool keepAspect = false)
{
	//ȡ��ԴͼƬ��Ⱥ͸߶� 
	int srcWidth = bmpSrc->GetWidth();
	int srcHeight = bmpSrc->GetHeight();
	//����������������ű��� 
	float scaleH = (float)destWidth / srcWidth;
	float scaleV = (float)destHeight / srcHeight;
	//�����Ҫ���ֳ���ȣ�����������ͳһ���ý�С�����ű��� 
	if (keepAspect)
	{
		if (scaleH > scaleV)
		{
			scaleH = scaleV;
		}
		else
		{
			scaleV = scaleH;
		}
	}
	//����Ŀ���� 
	destWidth = (int)(srcWidth * scaleH);
	destHeight = (int)(srcHeight * scaleV);
	//����Ŀ��Bitmap 
	Gdiplus::Bitmap * bmpDest = new Gdiplus::Bitmap(destWidth, destHeight, PixelFormat32bppARGB);
	Gdiplus::Graphics graphic(bmpDest);
	//���ò�ֵ�㷨 
	graphic.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);
	//��Դͼ����Ƶ�Ŀ��ͼ���� 
	graphic.DrawImage(bmpSrc, Gdiplus::Rect(0, 0, destWidth, destHeight),
		0, 0, srcWidth, srcHeight, Gdiplus::UnitPixel);
	graphic.Flush();
	return bmpDest;
}

void initgraphEx()
{
	int ret = Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
}

void closegraphEx()
{
	if (gdiplusToken)
		Gdiplus::GdiplusShutdown(gdiplusToken);

	closegraph();
}

void loadimage(CMyEasyX * image, LPCTSTR pImgFile, int nWidth, int nHeight)
{
	if (image == NULL || image->pngImage != NULL)
		return;

	wchar_t * wFileName = charToWChar(pImgFile);

	std::wcout << wFileName << endl;

	image->pngImage = Gdiplus::Bitmap::FromFile(wFileName);

	if (nWidth != 0 && nHeight != 0)
	{
		Bitmap * backup = image->pngImage;

		image->pngImage = ResizeBitmap(image->pngImage, nWidth, nHeight);

		delete backup;
	}
}

void putimage(int dstX, int dstY, CMyEasyX *image)
{
	Gdiplus::Graphics * graphic = Gdiplus::Graphics::FromHDC(GetImageHDC());

	graphic->DrawImage(image->pngImage, dstX, dstY, image->getWidth(), image->getHeight());

	delete graphic;
}

void rotateimage(CMyEasyX *dstimg, CMyEasyX *srcimg, float angle)
{
	if (dstimg == NULL || srcimg == NULL)
		return;

	//���ԭʼͼƬ�Ĵ�С
	int srcWidth = srcimg->getWidth();
	int srcHeight = srcimg->getHeight();

	//�����ԭʼͼƬ�Խ��ߵľ��룬��ΪĿ��ͼƬ�ĳ��Ϳ�
	int dstWidth = sqrt(srcWidth*srcWidth + srcHeight * srcHeight);
	int dstHeight = dstWidth;

	if (dstimg->pngImage != NULL)
		delete dstimg->pngImage;

	//����ԭʼͼƬ�Խ��߳��ȣ�����Ŀ��ͼƬ���Ϳ��������Ƴ�����ת��ͼƬ�����ᱻ��������������
	dstimg->pngImage = new Gdiplus::Bitmap(dstWidth, dstHeight, PixelFormat32bppARGB);

	Gdiplus::Graphics graphic(dstimg->pngImage);

	Pen * pen = new Pen(Color::Yellow);//�����ߣ�������
	//graphic.DrawRectangle(pen, 0, 0, dstWidth - 1, dstHeight - 1);//�����ߣ������á����Ƴ���ת��ͼƬ�ı߽�

	Matrix m;//����任�õľ������
	PointF cp(REAL(srcWidth / 2.0f), REAL(srcHeight / 2.0f));//center point����ת������
	PointF mp(REAL((dstWidth - srcWidth) / 2.0f), (dstHeight - srcHeight) / 2.0f);

	//ע�⣬����任��˳���Ƿ��ģ�Ҳ����˵����������Ч���൱������ת�����ƶ���
	m.Translate(mp.X, mp.Y);//Ч��Ϊ���Ƚ�ԭʼͼƬ���ĵ��ƶ���Ŀ��ͼƬ�����ġ�
	m.RotateAt(angle, cp);//Ч��Ϊ������Ŀ��ͼƬ�����ĵ������ת��
	graphic.SetTransform(&m);//���þ���任�õľ��������

	//��ͼ��ͬʱ���о���任
	graphic.DrawImage(srcimg->pngImage, Gdiplus::Rect(0, 0, srcWidth, srcHeight),
		0, 0, srcWidth, srcHeight, Gdiplus::UnitPixel);
	//graphic.DrawRectangle(pen, 0, 0, srcWidth - 1, srcHeight - 1);//�����ߣ������á����Ƴ�ԭʼͼƬ��Ŀ��ͼ���е�λ�á�

	delete pen;
}