/* FUN_00428130 @ 00428130 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00428130(HWND param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_3a8 [16];
  short local_368 [2];
  uint local_364 [65];
  short local_260;
  short local_25c;
  int local_258;
  char local_254 [4];
  char local_250 [4];
  char local_24c [4];
  char local_248;
  undefined4 local_247;
  HANDLE local_150;
  _WIN32_FIND_DATAA local_14c;
  HWND local_c;
  uint local_8;
  
  puVar4 = local_3a8;
  for (iVar3 = 0xe9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  FUN_00458ec0();
  GetDlgItem(param_1,0x3ed);
  local_c = (HWND)__chkesp();
  FUN_00458ec0();
  SendMessageA(local_c,0x14b,0,0);
  __chkesp();
  if (DAT_004e859c == 0) {
    local_8 = local_8 & 0xffff0000;
    while ((local_8 & 0xffff) < 0x1e) {
      SendMessageA(local_c,0x14a,0xffffffff,
                   (LPARAM)(&PTR_s_1__Menu_screen_004bc4fc)[local_8 & 0xffff]);
      uVar2 = __chkesp();
      local_368[0] = (short)uVar2;
      SendMessageA(local_c,0x151,(int)local_368[0],(local_8 & 0xffff) + 1);
      __chkesp();
      local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
    }
  }
  else {
    local_254[0] = s_option___rec_004b4d6c[0];
    local_254[1] = s_option___rec_004b4d6c[1];
    local_254[2] = s_option___rec_004b4d6c[2];
    local_254[3] = s_option___rec_004b4d6c[3];
    local_250[0] = s_option___rec_004b4d6c[4];
    local_250[1] = s_option___rec_004b4d6c[5];
    local_250[2] = s_option___rec_004b4d6c[6];
    local_250[3] = s_option___rec_004b4d6c[7];
    local_24c[0] = s_option___rec_004b4d6c[8];
    local_24c[1] = s_option___rec_004b4d6c[9];
    local_24c[2] = s_option___rec_004b4d6c[10];
    local_24c[3] = s_option___rec_004b4d6c[0xb];
    local_248 = s_option___rec_004b4d6c[0xc];
    puVar4 = &local_247;
    for (iVar3 = 0x3d; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    *(undefined2 *)puVar4 = 0;
    *(undefined1 *)((int)puVar4 + 2) = 0;
    local_258 = 1;
    FindFirstFileA(local_254,&local_14c);
    local_150 = (HANDLE)__chkesp();
    if (local_150 == (HANDLE)0x0) goto LAB_004283b3;
    while (local_258 != 0) {
      FUN_00497270(local_364,(uint *)local_14c.cFileName);
      sVar1 = _strlen((char *)local_364);
      *(undefined1 *)((int)local_368 + sVar1) = 0;
      local_260 = FUN_00475020((char *)local_364);
      SendMessageA(local_c,0x14a,0xffffffff,(&DAT_004bc4f8)[local_260]);
      uVar2 = __chkesp();
      local_25c = (short)uVar2;
      SendMessageA(local_c,0x151,(int)local_25c,(int)local_260);
      __chkesp();
      FindNextFileA(local_150,&local_14c);
      local_258 = __chkesp();
    }
    FindClose(local_150);
    __chkesp();
  }
  SendMessageA(local_c,0x14e,0,0);
  __chkesp();
LAB_004283b3:
  local_8 = 0x4283c3;
  __chkesp();
  return;
}

