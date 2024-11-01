#include "EngineFile.h"
#include "EngineDebug.h"

#include "EngineFile.h"
#include "EngineDebug.h"

UEngineFile::UEngineFile()
{


}

UEngineFile::~UEngineFile()
{
	Close();
}

void UEngineFile::FileOpen(const char* _Mode)
{
	fopen_s(&File, Path, _Mode);

	// 방어코드
	if (nullptr == File)
	{
		MSGASSERT(Path);
	}
}


void UEngineFile::Write(const void* _Ptr, size_t _Size)
{
	if (0 == _Size)
	{
		MSGASSERT("크기가 0인 데이터를 쓸수는 없습니다.");
	}

	if (nullptr == _Ptr)
	{
		MSGASSERT("존재하지 않는 메모리를 사용하려고 했습니다.");
	}

	// w일 경우에 대한 예외처리
	if (nullptr == File)
	{
		MSGASSERT("열지 않은 파일에 내용을 쓰려고 했습니다");
		return;
	}

	fwrite(_Ptr, _Size, 1, File);
}

void UEngineFile::Read(void* _Ptr, size_t _Size)
{
	if (0 == _Size)
	{
		MSGASSERT("크기가 0인 데이터를 읽을수는 없습니다.");
	}

	if (nullptr == _Ptr)
	{
		MSGASSERT("존재하지 않는 메모리를 읽으려고 했습니다.");
	}

	if (nullptr == File)
	{
		MSGASSERT("열지 않은 파일에 내용을 쓰려고 했습니다");
		return;
	}

	fread(_Ptr, _Size, 1, File);
}

bool UEngineFile::IsExits()
{
	// 00 : 존재 확인 02 : 쓰기 전용 04 : 읽기 전용 06 : 읽기 및 쓰기
	// 0이면 존재 0 이외의 값이면 존재하지 않음
	int Result = _access(Path, 00);
	return (0 == Result);
}

void UEngineFile::Close()
{
	// 방어코드
	if (nullptr != File)
	{
		fclose(File);
		File = nullptr;
	}
}

