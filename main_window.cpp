#include <Windows.h>

LRESULT CALLBACK MainWindowMessagesProcessor(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	switch (message)
	{
	case WM_SIZE:
	{

		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	case WM_CLOSE:
	{
		if (MessageBox(hwnd, L"Really quit?", L"Handmade Hero Game", MB_OKCANCEL) == IDOK)
		{
			DestroyWindow(hwnd);
		}
		break;
	}
	case WM_ACTIVATEAPP:
	{
		break;
	}

	case WM_PAINT:
	{
		//We passing the window we try to paint, which is hwnd
		//Then, we need to use the paint struct that will receive painting information.
		PAINTSTRUCT Paint;
		HDC DeviceContext = BeginPaint(hwnd, &Paint);

		// All painting occurs here, between BeginPaint and EndPaint.
		FillRect(DeviceContext, &Paint.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

		EndPaint(hwnd, &Paint);
		break;
	}
	default: {
		result = DefWindowProc(hwnd, message, wParam, lParam);
	}

	}
	return result;
}


void ListenToMainWindowMessages(HWND HandleMainWindow) {
	MSG Message = { };
	BOOL MessageResult;
	while (MessageResult = GetMessage(&Message, HandleMainWindow, 0, 0) != 0)
	{
		if (MessageResult == -1) {
			//TODO: handling error
			break;
		}
		else {
			TranslateMessage(&Message);
			DispatchMessage(&Message);
		}
	}
}

