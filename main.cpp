#include <iostream>
//using Windows API to make the window
#include <Windows.h>
#include <tchar.h>
using namespace std;

//main reference point(s) for the window:
// - https://learn.microsoft.com/en-us/cpp/windows/walkthrough-creating-windows-desktop-applications-cpp?view=msvc-170
// - https://learn.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassexw

char sign;
int a;
int b;

//so the program recognises the function beforehand (you learn something new everyday X```X)
void calculator();

// int main(){
//     cout << "What are your numbers?" << endl;
//     cin >> a;
//     cin >> b;
//     cout << "First number: " << a << ", Second number: " << b << endl;
//     cout << "What would you like to do? (+, -, *, /)" << endl;
//     cin >> sign;

//     calculator();
// }

//Main window name
static TCHAR szWindowClass[] = _T("DesktopApp");
//what the user sees in the title bar
static TCHAR szTitle[] = _T("Calculator");
HINSTANCE hInst;
LRESULT CALLBACK WndProcedure(HWND, UINT, WPARAM, LPARAM);

int WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd
){
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProcedure;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(212, 43, 251));
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

    if(RegisterClassEx(&wcex) == 0){
        MessageBox(nullptr, _T("Call to RegisterClassEx failed!"), _T("Checking if the calc works"), NULL);
        return 1;
    }

    HWND hWnd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        200, 400,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );
    if(!hWnd){
        MessageBox(nullptr, _T("Call to CreateWindow failed!"), _T("Checking if the calc works"), NULL);
        return 1;
    }

    ShowWindow(hWnd, nShowCmd);
    UpdateWindow(hWnd);

    MSG msg;
    while(GetMessage(&msg, nullptr, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
};

//as shown in the name, this function holds the procedures that will execute for specific events
LRESULT CALLBACK WndProcedure(
    _In_ HWND hwnd,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
){
    PAINTSTRUCT ps;
    HDC hdc;
    
    switch(uMsg){
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            TextOut(hdc, 5, 5, _T("Hello, World!"), 13);
            EndPaint(hwnd, &ps);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
            break;
    }
    return 0;
}

//void since it is not returning anything
// void calculator(){
//     if(sign == 43){
//         int sum = a+b;
//         cout << a << " + " << b << " = " << sum << endl;
//     }
//     if(sign == 45){
//         int diff = a-b;
//         cout << a << " - " << b << " = " << diff << endl;
//     }
//     if(sign == 42){
//         int  product = a*b;
//         cout << a << " * " << b << " = " << product << endl;
//     }
//     if(sign == 47 && a>0 &&b>0){
//         int quotient = a/b;
//         cout << a << " / " << b << " = " << quotient << endl;
        
//         if(a==0 || b==0){
//             cout << "Undefined." << endl;
//         }
//     }
// }