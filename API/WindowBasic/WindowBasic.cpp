// WindowBasic.cpp : 애플리케이션에 대한 진입점을 정의합니다.

// Window는 주소값이나 코드를 공개하지 않아 직접 관리할 수 없다.
// 대신 Window에서 제공하는 ID값(핸들)과 함수들을 통해 이용할 수 있도록 했다.

#include "framework.h"
#include "WindowBasic.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스(현재 실행된 프로세스의 시작 주소)입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 전방 선언
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// _IN_ , _Opt_ : SAL 주석으로 입출력 구분을 해줌
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,  // 이전 창의 메모리를 받는데, 가상메모리가 등장하며 필요없어진 인자.
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    // 리소스 뷰에서 문자열에 부여된 ID를 확인할 수 있다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWBASIC, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance); // 윈도우 클래스 등록 (기본 설정)

    // 애플리케이션 초기화를 수행합니다:
    // 윈도우 생성(초기 베이스 윈도우가 만들어지지 않았다면 프로그램 종료)
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // 윈도우 단축키 (사용 X)
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWBASIC));

    MSG msg;

    // 기본 메시지 루프입니다:
    // 윈도우의 상호작용을 감지하여 그에 따른 함수 작동
    // GetMessage : 메세지가 감지될 때까지 대기
    // DispathMessage : 상호작용된 상황에 따라 그에 따른 함수를 작동시키는 매크로

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//       구조체의 변수 설정 
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;             // 윈도우 스타일
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;                           // 현재 프로세스의 주소
    wcex.hIcon = nullptr;                                      // 윈도우 아이콘 설정
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);             // 윈도우 창 커서 설정
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = nullptr;                               // 윈도우 창 상단의 메뉴 설정
    wcex.lpszClassName  = szWindowClass;                       // 해당 윈도우의 클래스 이름(구분자)
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   // 윈도우 생성(등록)
   // 등록된 윈도우 클래스를 기반으로 윈도우 창이 생성됨
   // HWND(Handle to Window) : Window OS에서 창을 식별하는 고유 ID를 가진 핸들
   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다. (함수 포인터)
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            // HDC(Handle to Device Context) : 장치 컨텍스트를 나타내는 핸들
            // 장치 컨텍스트 : 화면에 그림을 그리거나 글씨를 쓰기위한 설정과 데이터를 보관하며
            //               그래픽 출력 작업을 위해 특정 장치와의 연결을 나타내는 메모리 영역
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);     // 메세지 함수가 0을 리턴하도록하는 함수
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
