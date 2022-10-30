#include "includes.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void MainThread()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	internalTrainer::dllMain form;
	Application::Run(% form);
}

BOOL WINAPI DllMain(HINSTANCE hModule, DWORD reason, LPVOID reserved)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
	{
		CloseHandle(CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)MainThread, hModule, NULL, NULL));
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}

