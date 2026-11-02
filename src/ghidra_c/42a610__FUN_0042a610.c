/* FUN_0042a610 @ 0042a610 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042a610(int param_1,HDC param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  HDC local_c;
  HGDIOBJ local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  CreateCompatibleDC(param_2);
  local_c = (HDC)__chkesp();
  SelectObject(local_c,*(HGDIOBJ *)(param_1 + 0x28));
  local_8 = (HGDIOBJ)__chkesp();
  BitBlt(param_2,param_3,param_4,*(int *)(param_1 + 4),*(int *)(param_1 + 8),local_c,0,0,0xcc0020);
  __chkesp();
  SelectObject(local_c,local_8);
  __chkesp();
  DeleteDC(local_c);
  __chkesp();
  local_8 = (HGDIOBJ)0x42a6c8;
  __chkesp();
  return;
}

