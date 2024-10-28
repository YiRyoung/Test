#pragma once
#include <Windows.h>
#include <iostream>
#include <io.h>

// ��� �̸� ����
const int MAXPATH = 256;

class UEngineFile
{
public:
	UEngineFile();
	~UEngineFile();

	// ��� ����
	inline void SetPath(const char* _Path)
	{
		strcpy_s(Path, _Path);
	}

	inline bool IsExits()
	{
		// ������ ��� Ȯ��
		// 00 : ���縸 / 02 : ���� ���� / 04 : �б� ���� / 06 : �б� �� ����
		// �����ϸ� 0 ��ȯ, �������� ���� �� -1 ��ȯ
		int Result = _access_s(Path, 00);
		return (0 == Result);
	}

	void FileOpen(const char* _Mode);
	void Write(const void* _Ptr, size_t _Size);
	void Read(void* _Ptr, size_t _Size);
	void Close();

private:
	char Path[MAXPATH] = "";
	FILE* File = nullptr;
};
