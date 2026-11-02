/* FUN_00477aa0 @ 00477aa0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00477aa0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_4c [16];
  undefined2 *local_c;
  undefined4 local_8;
  
  puVar1 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  local_c = (undefined2 *)FUN_00494c40(0xcc,1);
  *local_c = 0;
  puVar1 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  *(undefined2 *)(puVar1 + 3) = 0xfc;
  *puVar1 = FUN_00477e30;
  *(undefined1 *)((int)puVar1 + 0x11) = 1;
  *(undefined1 *)(puVar1 + 4) = 0;
  puVar1[2] = local_c;
  local_8 = 0x477b1d;
  __chkesp();
  return;
}

