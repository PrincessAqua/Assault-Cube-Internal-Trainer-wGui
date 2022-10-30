#include "includes.h"

bool healthThreadStatus = 0;
bool jumpThreadStatus = 0;

void Patch(BYTE* destination, BYTE* source, unsigned int size)
{
	DWORD oldProtect;
	VirtualProtect(destination, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy(destination, source, size);
	VirtualProtect(destination, size, oldProtect, &oldProtect);

}
void Nop(BYTE* destination, unsigned int size)
{
	DWORD oldProtect;
	VirtualProtect(destination, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	memset(destination, 0x90, size);
	VirtualProtect(destination, size, oldProtect, &oldProtect);
}

int healthFunc()
{
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
	while (TRUE)
	{
		uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x17E0A8);

		if (localPlayerPtr)
		{
			*(int*)(*localPlayerPtr + 0xEC) = 999;
		}
		if (!healthThreadStatus)
		{
			ExitThread(0);
		}

		Sleep(5);
	}
}

int jmpFunc()
{
	uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
	while (TRUE)
	{
		uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x17E0A8);

		if (localPlayerPtr)
		{
			*(char*)(*localPlayerPtr + 0x5D) = 1;
		}
		if (!jumpThreadStatus)
		{
			ExitThread(0);
		}

		Sleep(5);
	}
}