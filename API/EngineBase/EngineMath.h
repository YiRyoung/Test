#pragma once

class FVector2D
{
public:
	float X = 0.0f;
	float Y = 0;

	static const FVector2D ZERO;
	static const FVector2D LEFT;
	static const FVector2D RIGHT;
	static const FVector2D UP;
	static const FVector2D DOWN;

	FVector2D()
	{

	}

	FVector2D(float _X, float _Y) : X(_X), Y(_Y)	// ��� �̴ϼȶ�����
	{

	}

	FVector2D(int _X, int _Y) : X(static_cast<float>(_X)), Y(static_cast<float>(_Y))
	{

	}

	int iX()
	{
		return static_cast<int>(X);
	}

	int iY()
	{
		return static_cast<int>(Y);
	}

	FVector2D Half()
	{
		return { X * 0.5f, Y * 0.5f };
	}

	FVector2D operator* (float _Value) const
	{
		FVector2D Result;
		Result.X = X * _Value;
		Result.Y = Y * _Value;
		return Result;
	}


	FVector2D operator/ (float _Value) const
	{
		FVector2D Result;
		Result.X = X / _Value;
		Result.Y = Y / _Value;
		return Result;
	}

	FVector2D operator+ (FVector2D _Other) const
	{
		FVector2D Result;
		Result.X = X + _Other.X;
		Result.Y = Y + _Other.Y;
		return Result;
	}


	FVector2D operator- (FVector2D _Other) const
	{
		FVector2D Result;
		Result.X = X - _Other.X;
		Result.Y = Y - _Other.Y;
		return Result;
	}

	bool operator==(FVector2D _Other) const
	{
		return ((X == _Other.X) && (Y == _Other.Y));
	}

	FVector2D operator+=(FVector2D _Other)
	{
		X += _Other.X;
		Y += _Other.Y;
		return *this;
	}
};