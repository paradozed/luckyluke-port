/* FUN_00472090 @ 00472090 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00472090(int param_1)

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
  if (*(int *)(&DAT_004f1da0 + param_1 * 4) != 0) {
    FUN_00471ea0(param_1,*(uint *)(&DAT_004f1da0 + param_1 * 4));
  }
  uStack_8 = 0x4720d9;
  __chkesp();
  return;
}

