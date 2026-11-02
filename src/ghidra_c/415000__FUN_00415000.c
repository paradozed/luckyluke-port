/* FUN_00415000 @ 00415000 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415000(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  int local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  uVar2 = FUN_004074b0(param_2,3);
  *(undefined2 *)(local_8 + 4) = uVar2;
  if (*(ushort *)(local_8 + 2) < *(ushort *)(local_8 + 4)) {
    *(undefined2 *)(local_8 + 4) = *(undefined2 *)(local_8 + 2);
  }
  local_8 = 0x415074;
  __chkesp();
  return;
}

