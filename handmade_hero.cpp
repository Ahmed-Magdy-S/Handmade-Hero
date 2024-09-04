#include <Windows.h>
#include "main_window.h"
/// <summary>
/// The main entry point for the game;
/// </summary>
/// <param name="hInstance">It's the handle to an instance or handle to a module. The operating system uses this value to identify the executable or EXE when it's loaded in memory. Certain Windows functions need the instance handle, for example to load icons or bitmaps.</param>
/// <param name="hPrevInstance">has no meaning. It was used in 16-bit Windows, but is now always zero.</param>
/// <param name="lpCmdLine">contains the command-line arguments as a Unicode string.</param>
/// <param name="nCmdShow">is a flag that indicates whether the main application window is minimized, maximized, or shown normally.</param>
/// <returns></returns>
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
) {
	const LPCWSTR mainWindowClassName = L"MainHandmadeHeroWindowClass";


	//Create a class for main window to add more data and behaviour,
	//then link to it a window procedure to process messages for it.
	WNDCLASS mainWindowClass = {};
	mainWindowClass.lpfnWndProc = &MainWindowMessagesProcessor;
	mainWindowClass.hInstance = hInstance;
	mainWindowClass.lpszClassName = mainWindowClassName;

	//Register The Main Window in Windows system by registring its class
	ATOM registerationResult = RegisterClass(&mainWindowClass);

	//Handling registration failure
	if (registerationResult == 0) {
		MessageBox(NULL,
			L"Failed to register main window class",
			L"Error in starting program",
			MB_OK);
		//TODO: use logging here
		return 1;
	}


	//Create the main window and disply it
	HWND handleMainWindow = CreateWindowEx(0, mainWindowClassName, L"Handmade Hero Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (handleMainWindow == NULL) {
		//TODO: handling error
		return 0;
	}


	ListenToMainWindowMessages(handleMainWindow);



}