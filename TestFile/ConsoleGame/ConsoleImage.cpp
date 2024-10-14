#include "ConsoleImage.h"

ConsoleImage::~ConsoleImage()
{
	Release();
}

void ConsoleImage::Release()
{
	if (0 == X || 0 == Y)
	{
		return;
	}

	for (size_t y = 0; y < Y; y++)
	{
		delete[] Arr[y];
	}
	delete[] Arr;
}

void ConsoleImage::Create(int _X, int _Y, char _BaseChar)
{
	X = _X;
	Y = _Y;

	// 얼마
	Arr = new char* [_Y];
	for (size_t y = 0; y < _Y; y++)
	{
		Arr[y] = new char[_X + 1];
	}

	Clear(_BaseChar);
}

void ConsoleImage::Clear(char _Clearchar)
{
	for (size_t y = 0; y < Y; y++)
	{
		for (size_t x = 0; x < X; x++)
		{
			Arr[y][x] = _Clearchar;
		}
		// 마지막라인에 0을 넣는다.
		Arr[y][X] = 0;
	}
}

void ConsoleImage::SetPixel(FIntPoint _Pos, char _Char)
{
	// 화면 바깥에 그려지는것 막은것
	if (0 > _Pos.X || X < _Pos.X)
	{
		return;
	}

	// 화면 바깥에 그려지는것 막은것.
	if (0 > _Pos.Y || X < _Pos.Y)
	{
		return;
	}

	Arr[_Pos.Y][_Pos.X] = _Char;
}

void ConsoleImage::Copy(FIntPoint _Offset, ConsoleImage& _Image)
{
	// 2차원
	// 상대도 2차원
	for (int y = 0; y < _Image.GetImageSizeY(); y++)
	{
		for (int x = 0; x < _Image.GetImageSizeX(); x++)
		{
			FIntPoint SetPos = _Offset + FIntPoint{ x, y };

			char X = _Image.GetPixel(x, y);

			SetPixel(SetPos, X);
		}
	}
}