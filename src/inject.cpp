#include "inject.h"

#include "cxbx/cxbxbinding.h"

void WriteMemory(size_t offset, void *data, size_t size)
{
  //memcpy((void *) offset, data, size);
  WriteProcessMemory(g_cxbxHandle, (LPVOID) offset, data, size, NULL);
}

void WriteByte(size_t offset, unsigned char byte)
{
  WriteMemory(offset, &byte, 1);
}

void WriteBytes(size_t offset, unsigned char byte, size_t count)
{
  for (size_t i = 0; i < count; i++) {
  	WriteByte(offset + i, byte);
  }
}

void Inject()
{
  const wchar_t *msg = L"Welcome to Reburn";
  WriteMemory(0x2f845, &msg, sizeof(const wchar_t *));
  WriteMemory(0x2f87A, &msg, sizeof(const wchar_t *));

  WriteByte(0x3366D, 0x90);
  WriteBytes(0x33675, 0x90, 5);
  WriteBytes(0x44A0F, 0x90, 5);
  WriteByte(0x1AE38A, 0x90);
  WriteBytes(0x1AE391, 0x90, 11);
  WriteBytes(0x1AE731, 0x90, 11);
}