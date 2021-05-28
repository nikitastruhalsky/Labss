// lab1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "windows.h"
#include "lab1.h"
#include "cmath"
#include "string"
#include "map"

#define MAX_LOADSTRING 100
//#define ID_STATIC 501

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB1));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

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
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static double x, y;
    static HPEN hPenAxes;
    static HPEN hPenArrows;
    static HPEN hPenScale;
    static HBRUSH brush;
    static double t = 0;
    static int sx, sy;
    static std::map <int, int> Map;
    std::map <int, int> :: iterator it;
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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
    case WM_SIZE:
        {
            sx = LOWORD(lParam);
            sy = HIWORD(lParam);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            hPenAxes = CreatePen(PS_DASH, 1, RGB(1, 0, 0));
            SelectObject(hdc, hPenAxes);
            MoveToEx(hdc, 0, sy / 2, 0);
            LineTo(hdc, sx, sy / 2);
            MoveToEx(hdc, sx / 2, 0, 0);
            LineTo(hdc, sx / 2, sy);
            MoveToEx(hdc, 0, sy / 2 + 1, 0);
            LineTo(hdc, sx, sy / 2 + 1);
            MoveToEx(hdc, sx / 2 + 1, 0, 0);
            LineTo(hdc, sx / 2 + 1, sy);




            // стрелки
            hPenArrows = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            SelectObject(hdc, hPenArrows);
            MoveToEx(hdc, sx, sy / 2, 0);
            LineTo(hdc, sx - 17, sy / 2 - 17);
            MoveToEx(hdc, sx, sy / 2, 0);
            LineTo(hdc, sx - 17, sy / 2 + 17);

            MoveToEx(hdc, sx / 2, 0, 0);
            LineTo(hdc, sx / 2 - 17, 17);
            MoveToEx(hdc, sx / 2, 0, 0);
            LineTo(hdc, sx / 2 + 17, 17);


            hPenScale = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
            SelectObject(hdc, hPenScale);
            for (int i = sx / 2; i < sx; i++)
            {
                if ((i - sx / 2) % 30 == 0 && (i - sx / 2) / 30 != 0)
                {
                    MoveToEx(hdc, i, sy / 2, 0);
                    LineTo(hdc, i, sy / 2 - 7);
                    MoveToEx(hdc, i, sy / 2, 0);
                    LineTo(hdc, i, sy / 2 + 7);
                }
            }
            hPenScale = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
            SelectObject(hdc, hPenScale);
            for (int i = sx / 2; i > 0; i--)
            {
                if ((sx / 2 - i) % 30 == 0 && (sx / 2 - i) / 30 != 0)
                {
                    MoveToEx(hdc, i, sy / 2, 0);
                    LineTo(hdc, i, sy / 2 - 7);
                    MoveToEx(hdc, i, sy / 2, 0);
                    LineTo(hdc, i, sy / 2 + 7);
                }
            }
            hPenScale = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
            SelectObject(hdc, hPenScale);
            for (int i = sy / 2; i < sy; i++)
            {
                if ((i - sy / 2) % 30 == 0 && (i - sy / 2) / 30 != 0)
                {
                    MoveToEx(hdc, sx / 2, i, 0);
                    LineTo(hdc, sx / 2 - 7, i);
                    MoveToEx(hdc, sx / 2, i, 0);
                    LineTo(hdc, sx / 2 + 7, i);
                }
            }
            hPenScale = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
            SelectObject(hdc, hPenScale);
            for (int i = sy / 2; i > 0; i--)
            {
                if ((sy / 2 - i) % 30 == 0 && (sy / 2 - i) / 30 != 0)
                {
                    MoveToEx(hdc, sx / 2, i, 0);
                    LineTo(hdc, sx / 2 - 7, i);
                    MoveToEx(hdc, sx / 2, i, 0);
                    LineTo(hdc, sx / 2 + 7, i);
                }
            }
            
            SelectObject(hdc, brush);
            Ellipse(hdc, x - 10, y + 10, x + 10, y - 10);

            SelectObject(hdc, brush);
            Map.insert({ x, y });
            for (it = Map.begin(); it != Map.end(); ++it)
            {
                Ellipse(hdc, it->first - 1, it->second + 1, it->first + 1, it->second - 1);
            }

            auto textRect = RECT{ 30, 30, 250, 140 };
            std::string text = std::to_string((double)(x - sx / 2) / 100) + ", " + std::to_string((double)(y - sy / 2) / 100);
            std::wstring stemp = std::wstring(text.begin(), text.end());
            LPCWSTR sw = stemp.c_str();
            static LOGFONT lf;
            HFONT hFont = CreateFontIndirect(&lf);
            SetTextColor(hdc, RGB(255, 155, 0));
            DrawText(hdc, sw, -1, &textRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
           

            brush = CreateSolidBrush(RGB(255, 255, 0));
            SelectObject(hdc, brush);
            Ellipse(hdc, x - 10, y + 10, x + 10, y - 10);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_CREATE:
    {
        SetTimer(hWnd, 1, 30, NULL);
    }
    break;
    case WM_TIMER:
    {
        x = sx / 2 + sin(3 * t / 7) * cos(t) * 100;
        y = sy / 2 + sin(3 * t / 7) * sin(t) * 100;
        t += 0.1;
        //SendMessage(hWnd, ID_STATIC, LB_ADDSTRING, (LPARAM)"123");

        InvalidateRect(hWnd, NULL, TRUE);
    }
    break;
    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
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
