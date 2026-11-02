/* FUN_0041df00 @ 0041df00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041df00(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_50 [16];
  undefined1 local_e;
  undefined1 local_d;
  uint local_c;
  int local_8;
  
  puVar4 = local_50;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_c = local_c & 0xffffff00;
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  sVar1 = FUN_004074b0(param_2,3);
  if (sVar1 < 4) {
    uVar2 = FUN_004074b0(param_2,3);
    local_c = CONCAT31(local_c._1_3_,(char)uVar2);
  }
  else {
    local_c = CONCAT31(local_c._1_3_,3);
  }
  if (*(char *)(local_8 + 1) == '\x05') {
    if ((local_c & 0xff) == 0) {
      *(byte *)(*(int *)(local_8 + 0x4c) + 7) = *(byte *)(*(int *)(local_8 + 0x4c) + 7) & 0xfd;
      local_d = *(undefined1 *)(*(int *)(local_8 + 0x4c) + 7);
    }
    else {
      *(byte *)(*(int *)(local_8 + 0x4c) + 7) = *(byte *)(*(int *)(local_8 + 0x4c) + 7) | 2;
      local_d = *(undefined1 *)(*(int *)(local_8 + 0x4c) + 7);
    }
    if ((local_c & 0xff) == 0) {
      *(byte *)(*(int *)(local_8 + 0x50) + 7) = *(byte *)(*(int *)(local_8 + 0x50) + 7) & 0xfd;
      local_e = *(undefined1 *)(*(int *)(local_8 + 0x50) + 7);
    }
    else {
      *(byte *)(*(int *)(local_8 + 0x50) + 7) = *(byte *)(*(int *)(local_8 + 0x50) + 7) | 2;
      local_e = *(undefined1 *)(*(int *)(local_8 + 0x50) + 7);
    }
  }
  local_8 = 0x41e022;
  __chkesp();
  return;
}

