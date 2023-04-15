#include "inject.h"

#include "cxbx/cxbxbinding.h"

void WriteMemory(size_t offset, void *data, size_t size)
{
  WriteProcessMemory(g_cxbxHandle, (LPVOID) offset, data, size, NULL);
  //memcpy((void *) offset, data, size);
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
  WriteByte(0x3366D, 0x90);
  WriteBytes(0x33675, 0x90, 5);
  WriteBytes(0x44A0F, 0x90, 5);
  WriteByte(0x1AE38A, 0x90);
  WriteBytes(0x1AE391, 0x90, 11);
  WriteBytes(0x1AE731, 0x90, 11);
}