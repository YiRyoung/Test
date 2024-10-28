#pragma once
#include <Windows.h>
#include <iostream>
#include <io.h>

// 경로 이름 제한
const int MAXPATH = 256;

class UEngineFile
{
public:
	UEngineFile();
	~UEngineFile();

	// 경로 설정
	inline void SetPath(const char* _Path)
	{
		strcpy_s(Path, _Path);
	}

	inline bool IsExits()
	{
		// 파일의 모드 확인
		// 00 : 존재만 / 02 : 쓰기 전용 / 04 : 읽기 전용 / 06 : 읽기 및 쓰기
		// 존재하면 0 반환, 존재하지 않을 시 -1 반환
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
