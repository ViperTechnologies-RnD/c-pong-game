//
// Created by Sobhan on 7/9/2021.
//
#include "utils.c"
#include <windows.h>

struct {
    int width, height;
    u32 *pixels;
    BITMAPINFO bitmap_info;

} typedef Render_Buffer;

Render_Buffer render_buffer;

global_variable boolean_32 isRunning = true;

internal LRESULT window_callback(_In_ HWND window, _In_ UINT message, _In_ WPARAM w_param, _In_ LPARAM l_param)
{

    //messages are comming from this function
    LRESULT result = 0;
    switch (message)
    {
        case WM_CLOSE:
        case WM_DESTROY:
        {
            isRunning = false;
        } break;
        case WM_SIZE: {
            //Get width and height
            //allocate the buffer
            //fill the bitmap_info
        } break;
        default:
        {
            result = DefWindowProcA(window, message, w_param, l_param);
        }
    }

    return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    //the call we want to make to make a window - from msdn
    //but before it we have to register a window class:
    WNDCLASSA window_class = {0};
    window_class.style = CS_HREDRAW | CS_VREDRAW;
    window_class.lpfnWndProc = window_callback;
    window_class.lpszClassName = "Game_Window_Class";

    RegisterClassA(&window_class);
    HWND window = CreateWindowExA(0, window_class.lpszClassName, "Pong-Breakout",
                                  WS_VISIBLE | WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, 0, 0);
    //Get Device Context
    HDC hdc = GetDC(window);

    while (isRunning)
    {
        //Input
        MSG message;
        while (PeekMessageA(&message, window, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        //Simulation


        //Render:
            //TODO: Buffer (Memory) -> Draw to it (up to the game)
            //Use the buffer (draw) -> StretchDIBits
        StretchDIBits(hdc, 0, 0, render_buffer.width, render_buffer.height, 0, 0, render_buffer.width, render_buffer.height, render_buffer.pixels, &render_buffer.bitmap_info, DIB_RGB_COLORS, SRCCOPY);

    }
}