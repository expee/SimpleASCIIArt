#include<iostream>
#include<stdio.h>

// #include<delaytext.h>
// #include<contrastcontrol.h>
// #include<tga.h>
// #include<textselector.h>

#include<TGA.h>
#include<AsciiPainter.h>

int s_width;
int s_height;
int s_bpp;

AsciiPainter painter;
int main (int argc, char** argv)
{
	char *pBuffer = LoadTGA("../../../ExamplePic/NukeThumb.tga", &s_width, &s_height, &s_bpp);
	painter.SetImageData(pBuffer, s_width, s_height, s_bpp);
	painter.SetTextsToPaint(" ~c6N#", 6);
	painter.Paint();
	std::cout << "Press ENTER to continue..." << std::flush;
	std::cin.get();
	return 0;
}
