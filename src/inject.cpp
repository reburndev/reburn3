#include "inject.h"

#include "cxbx/cxbxbinding.h"

void WriteMemory(size_t offset, void *data, size_t size)
{
  memcpy((void *) offset, data, size);
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
  // Novelty hack to replace the loading screen text
  /*const wchar_t *msg = L"WELCOME TO REBURN";
  WriteMemory(0x2f845, &msg, sizeof(const wchar_t *));
  WriteMemory(0x2f87A, &msg, sizeof(const wchar_t *));*/

  // Fix initial graphics and crashes
  WriteByte(0x3366D, 0x90);
  WriteBytes(0x33675, 0x90, 5);
  WriteBytes(0x44A0F, 0x90, 5);
  WriteByte(0x1AE38A, 0x90);
  WriteBytes(0x1AE391, 0x90, 11);
  WriteBytes(0x1AE731, 0x90, 11);

  // Inject 1920 display width
  //WriteMemory(0x1dd670, "\xba\x80\x07\x00\x00\x90", 6);

  // Inject 1080 display height
  //WriteMemory(0x1dd6b8, "\xba\x38\x04\x00\x00\x90", 6);
}