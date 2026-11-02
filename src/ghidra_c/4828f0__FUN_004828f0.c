/* FUN_004828f0 @ 004828f0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004828f0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = _DAT_00508840;
  param_1[1] = _DAT_00508844;
  param_1[2] = _DAT_00508848;
  param_1[3] = _DAT_0050884c;
  *(undefined2 *)(param_1 + 4) = DAT_00508850;
  uStack_8 = 0x482927;
  __chkesp();
  return;
}

