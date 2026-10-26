#include <iostream>
//using Windows API to make the window
#include <Windows.h>
#include <tchar.h>
using namespace std;

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
){};

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