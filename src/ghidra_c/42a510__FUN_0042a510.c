/* FUN_0042a510 @ 0042a510 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042a510(BITMAPINFO *param_1,void **param_2,LONG param_3,LONG param_4,WORD param_5)

{
  RGBQUAD RVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  HDC local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  (param_1->bmiHeader).biSize = 0x28;
  (param_1->bmiHeader).biWidth = param_3;
  (param_1->bmiHeader).biHeight = param_4;
  (param_1->bmiHeader).biPlanes = 1;
  (param_1->bmiHeader).biBitCount = param_5;
  (param_1->bmiHeader).biCompression = 0;
  (param_1->bmiHeader).biSizeImage = 0;
  (param_1->bmiHeader).biXPelsPerMeter = 0;
  (param_1->bmiHeader).biYPelsPerMeter = 0;
  (param_1->bmiHeader).biClrUsed = 0;
  (param_1->bmiHeader).biClrImportant = 0;
  GetWindowDC((HWND)0x0);
  local_8 = (HDC)__chkesp();
  if (local_8 != (HDC)0x0) {
    CreateDIBSection(local_8,param_1,0,param_2,(HANDLE)0x0,0);
    RVar1 = (RGBQUAD)__chkesp();
    param_1->bmiColors[0].rgbBlue = RVar1.rgbBlue;
    param_1->bmiColors[0].rgbGreen = RVar1.rgbGreen;
    param_1->bmiColors[0].rgbRed = RVar1.rgbRed;
    param_1->bmiColors[0].rgbReserved = RVar1.rgbReserved;
    ReleaseDC((HWND)0x0,local_8);
    __chkesp();
  }
  local_8 = (HDC)0x42a5ff;
  __chkesp();
  return;
}

