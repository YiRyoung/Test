#include "PreCompile.h"
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
	// 파일 열기
	fopen_s(&File, Path, _Mode);

	// 파일을 열지 못했을 경우
	if (nullptr == File)
	{
		MSGASSERT(std::string(Path) + "파일 오픈에 실패했습니다.");
	}
}

void UEngineFile::Write(const void* _Ptr, size_t _Size)
{
	if (0 == _Size)
	{
		MSGASSERT("크기가 0인 데이터를 쓸 수 없습니다.");
		return;
	}

	if (nullptr == _Ptr)
	{
		MSGASSERT("존재하지 않는 메모리를 사용하려고 했습니다.");
		return;
	}

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
		return;
	}

	if (nullptr == _Ptr)
	{
		MSGASSERT("존재하지 않는 메모리를 읽으려고 했습니다.");
		return;
	}

	if (nullptr == File)
	{
		MSGASSERT("열지 않은 파일에 내용을 쓰려고 했습니다");
		return;
	}

	fread(_Ptr, _Size, 1, File);
}

void UEngineFile::Close()
{
	if (nullptr != File)
	{
		fclose(File);
		File = nullptr;
	}
}
