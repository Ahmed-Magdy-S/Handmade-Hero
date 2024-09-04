#pragma once
#include <Windows.h>

//Define the characterstics about the window by making a function for it.
LRESULT CALLBACK MainWindowMessagesProcessor(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


//- Handling incoming windows messages (Uset/OS inputs).
//- If the function retrieves a message other than WM_QUIT, the return value is nonzero.
//- If the function retrieves the WM_QUIT message, the return value is zero.
void ListenToMainWindowMessages(HWND HandleMainWindow);