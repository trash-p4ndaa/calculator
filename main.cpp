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
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd
){
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
};

//as shown in the name, this function holds the procedures that will execute for specific events
int WindProcedure(
    _In_ HWND hwnd,
    _In_ UINT uMsg,
    _In_ WPARAM wParam,
    _In_ LPARAM lParam
){}

//void since it is not returning anything
void calculator(){
    if(sign == 43){
        int sum = a+b;
        cout << a << " + " << b << " = " << sum << endl;
    }
    if(sign == 45){
        int diff = a-b;
        cout << a << " - " << b << " = " << diff << endl;
    }
    if(sign == 42){
        int  product = a*b;
        cout << a << " * " << b << " = " << product << endl;
    }
    if(sign == 47 && a>0 &&b>0){
        int quotient = a/b;
        cout << a << " / " << b << " = " << quotient << endl;
        
        if(a==0 || b==0){
            cout << "Undefined." << endl;
        }
    }
}