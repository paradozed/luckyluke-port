/* FUN_004490f0 @ 004490f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004490f0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  short local_10;
  short *local_c;
  int *local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(int **)(param_1 + 8);
  if (DAT_004bd6b0 != '\0') {
    local_10 = FUN_00482cb0(DAT_004e868a);
    *local_8 = ((int)(-DAT_004e9370 + (-DAT_004e9370 >> 0x1f & 0xfU)) >> 4) + (int)local_10 / 2;
    local_10 = FUN_00482cb0(DAT_004e8688);
    local_8[1] = ((int)(-DAT_004e9374 + (-DAT_004e9374 >> 0x1f & 0x3fU)) >> 6) +
                 (int)local_10 / 0x60;
    for (local_c = (short *)local_8[3]; local_c != (short *)0x0;
        local_c = *(short **)(local_c + 0x16)) {
      if ((char)local_c[0xd] != '\0') {
        FUN_00448e30(local_8,local_c);
        if ((char)local_c[0xc] != -1) {
          FUN_004475b0((int)local_c);
        }
      }
    }
  }
  local_8 = (int *)0x4491ee;
  __chkesp();
  return;
}

