#ifndef ASCII_PAINTER_H
#define ASCII_PAINTER_H

#include <TextSelector.h>

#if defined(_WIN32) && defined(_MSVC)
# if defined(SimpleAsciiArt_EXPORTS)
#  define SIMPLEASCIIART_EXPORT __declspec(dllexport)
# else
#  define SIMPLEASCIIART_EXPORT __declspec(dllimport)
# endif // SimpleAsciiArt_EXPORTS
#else // _WIN32
# define SIMPLEASCIIART_EXPORT
#endif

class AsciiPainter
{
public:
	SIMPLEASCIIART_EXPORT AsciiPainter();
	SIMPLEASCIIART_EXPORT ~AsciiPainter();
	SIMPLEASCIIART_EXPORT void SetImageData(char* data, int width, int height, int bpp);
	SIMPLEASCIIART_EXPORT void Paint();
	SIMPLEASCIIART_EXPORT void SetTextsToPaint(const char* text, int level);
	
private:
	void ConvertToGrayScale();
	void DeleteImageData();
	struct ImageInfo
	{
		int height;
		int width;
		int bpp;
		
		ImageInfo():
		height(0),
		width(0),
		bpp(0)
		{}
		
		int CalculateImageDataSize()
		{
			return height * width * bpp / 8;
		}
	};
	
	typedef struct ImageData24
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
	}ImageData24;
	
	typedef struct ImageData32
	{
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	}ImageData32;
	
	struct ImageInfo m_imgInfo;
	
	ImageData24* m_imageData24;
	ImageData32* m_imageData32;
	unsigned char* m_grayScaleImage;
	int m_dataSize;
	
	TextSelector textSelector;
};
#endif	//ASCII_PAINTER_H
