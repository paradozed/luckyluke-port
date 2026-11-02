/* FUN_00451740 @ 00451740 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00451740(short param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_60 [23];
  
  puVar5 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  if ((param_1 != -1) && (*(char *)(DAT_004e89f0 + 5 + param_1 * 0x20) == '\0')) {
    uVar2 = (uint)DAT_004e89f4;
    uVar3 = (uint)DAT_004e89f6;
    uVar4 = (uint)DAT_004e89f6;
    *(int *)(DAT_004e89f0 + 8 + param_1 * 0x20) =
         ((int)param_1 % (int)(uint)DAT_004e89f4 - DAT_004e8670) * (int)DAT_004bc4e8;
    *(int *)(DAT_004e89f0 + 0xc + param_1 * 0x20) =
         (((int)param_1 / (int)uVar2) % (int)uVar3 - DAT_004e8674) * (int)DAT_004bc4ea;
    *(int *)(DAT_004e89f0 + 0x10 + param_1 * 0x20) =
         (((int)param_1 / (int)uVar2) / (int)uVar4 - DAT_004e8678) * (int)DAT_004bc4ec;
    *(undefined1 *)(DAT_004e89f0 + 5 + param_1 * 0x20) = 1;
  }
  return;
}

