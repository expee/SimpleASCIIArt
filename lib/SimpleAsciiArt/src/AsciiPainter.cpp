#include <AsciiPainter.h>
#include <stdio.h>
#include <cstring>

using namespace std;

AsciiPainter::AsciiPainter():
	m_imageData24(nullptr),
	m_imageData32(nullptr),
	m_grayScaleImage(nullptr),
	m_dataSize(0)
{
	
}

AsciiPainter::~AsciiPainter()
{
	DeleteImageData();
}

void AsciiPainter::SetImageData(char* data, int width, int height, int bpp)
{
	DeleteImageData();
	
	m_imgInfo.width = width;
	m_imgInfo.height = height;
	m_imgInfo.bpp = bpp;
	m_dataSize = m_imgInfo.CalculateImageDataSize();
	
	if(bpp == 24)
	{
		m_imageData24 = new ImageData24[width * height];
		memcpy(m_imageData24, data, m_dataSize);
	}
	else
	{
		m_imageData32 = new ImageData32[width * height];
		memcpy(m_imageData32, data, m_dataSize);
	}
	
	ConvertToGrayScale();
}

void AsciiPainter::DeleteImageData()
{
	if(m_imageData24 != nullptr)
	{
		delete[] m_imageData24;
		m_imageData24 = nullptr;
	}
	if(m_imageData32 != nullptr)
	{
		delete[] m_imageData32;
		m_imageData32 = nullptr;
	}
	if(m_grayScaleImage != nullptr)
	{
		delete[] m_grayScaleImage;
		m_grayScaleImage = nullptr;
	}
}

void AsciiPainter::Paint()
{
	for (int j = m_imgInfo.height - 1; j >= 0 ; j--)
	{
		for(int i = 0; i < m_imgInfo.width; i++)
		{
			printf("%c", textSelector.SelectText(m_grayScaleImage[j * m_imgInfo.width + i]));
			if(i == m_imgInfo.width - 1)
				printf("\n");
		}
	}
}

void AsciiPainter::SetTextsToPaint(const char* text, int level)
{
	textSelector.SetText(text, level);
}

void AsciiPainter::ConvertToGrayScale()
{
	m_grayScaleImage = new unsigned char[m_imgInfo.width * m_imgInfo.height];
	if(m_imgInfo.bpp == 24)
	{
		for(int i = 0; i < m_imgInfo.width * m_imgInfo.height; i++)
		{
			unsigned int currentPixel = (unsigned int) (0.3f * (float)m_imageData24[i].r + 0.59f * (float)m_imageData24[i].g + 0.11f * (float)m_imageData24[i].b);
			m_grayScaleImage[i] = (unsigned char) (currentPixel > 0xff ? 0xff : currentPixel) ;
		}
	}
	else
	{
		for(int i = 0; i < m_imgInfo.width * m_imgInfo.height; i++)
		{
			unsigned int currentPixel = (unsigned int) (0.3f * (float)m_imageData32[i].r + 0.59f * (float)m_imageData32[i].g + 0.11f * (float)m_imageData32[i].b);
			m_grayScaleImage[i] = (unsigned char) (currentPixel > 0xff ? 0xff : currentPixel) ;
		}
	}
}
