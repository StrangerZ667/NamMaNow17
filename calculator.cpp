#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND,UINT , WPARAM ,LPARAM);
HWND Button,textfield,number1,number2;
char Text1[20];
char Text2[20];

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
    switch(Message) {
        case WM_CREATE:
            textfield = CreateWindow("STATIC","Please input two numbers", WS_VISIBLE | WS_CHILD ,30,10,170,25,hwnd,NULL,NULL,NULL);
            number1 = CreateWindow("EDIT","", WS_BORDER | WS_CHILD | WS_VISIBLE ,30,40,170,25,hwnd,NULL,NULL,NULL);
            number2 = CreateWindow("EDIT","", WS_BORDER | WS_CHILD | WS_VISIBLE ,30,70,170,25,hwnd,NULL,NULL,NULL);
            Button = CreateWindow("Button","+", WS_VISIBLE | WS_CHILD | WS_BORDER ,70,120,20,20,hwnd,(HMENU) 1,NULL,NULL);
            Button = CreateWindow("Button","-", WS_VISIBLE | WS_CHILD | WS_BORDER ,95,120,20,20,hwnd,(HMENU) 2,NULL,NULL);
            Button = CreateWindow("Button","*", WS_VISIBLE | WS_CHILD | WS_BORDER ,120,120,20,20,hwnd,(HMENU) 3,NULL,NULL);
            Button = CreateWindow("Button","/", WS_VISIBLE | WS_CHILD | WS_BORDER ,145,120,20,20,hwnd,(HMENU) 4,NULL,NULL);
            break;

        case WM_COMMAND:
            if(LOWORD(wParam)!=0){
                    int stat1 =0,stat2 =0;
                    stat1 = GetWindowText(number1,&Text1[0],20);
                    stat2 = GetWindowText(number2,&Text2[0],20);
                }
                if(LOWORD(wParam)==1){
                    float re=atof(Text1)+atof(Text2);
                    char t[100];
                    sprintf(t, "%f", re);
                    :: MessageBox(hwnd,t,"Result",MB_OK);
                }
                if(LOWORD(wParam)==2){
                    float re=atof(Text1)-atof(Text2);
                    char t[100];
                    sprintf(t, "%f", re);
                    :: MessageBox(hwnd,t,"Result",MB_OK);
                }
                if(LOWORD(wParam)==3){
                    float re=atof(Text1)*atof(Text2);
                    char t[100];
                    sprintf(t, "%f", re);
                    :: MessageBox(hwnd,t,"Result",MB_OK);
                }
                if(LOWORD(wParam)==4){
                    float re=atof(Text1)/atof(Text2);
                    char t[100];
                    sprintf(t, "%f", re);
                    :: MessageBox(hwnd,t,"Result",MB_OK);
                }
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;

        default:
            return DefWindowProc(hwnd ,Message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG msg;

    memset(&wc,0,sizeof(wc));
    wc.cbSize    = sizeof(WNDCLASSEX);
    wc.lpfnWndProc   = WndProc;
    wc.hInstance     = hInstance;
    wc.hCursor   = LoadCursor(NULL, IDC_ARROW);
   
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+9);
    wc.lpszClassName = "WindowClass";
    wc.hIcon     = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm   = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE ,"WindowClass","My Calculator",WS_VISIBLE|WS_SYSMENU,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        250,
        200,
        NULL,NULL,hInstance,NULL);

    if(hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
        return 0;
    }

    while(GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
