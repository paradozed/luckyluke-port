/* FUN_00459830 @ 00459830 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00459830(uint param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1 & 0xffff;
  if (local_8 < 2) {
    if ((DAT_004f2750 & 0x1000) == 0) goto LAB_004598be;
  }
  else if (local_8 != 2) {
    FUN_00497610((byte *)"Error: File %s, Line %d");
    goto LAB_004598be;
  }
  if (*param_2 == 0) {
    DAT_004e8706 = 0;
  }
  else {
    *(undefined4 *)(*param_2 + 4) = 0;
    *(undefined2 *)(param_2 + 2) = 0;
  }
LAB_004598be:
  local_8 = 0x4598cb;
  __chkesp();
  return;
}

