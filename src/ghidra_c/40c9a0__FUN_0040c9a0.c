/* FUN_0040c9a0 @ 0040c9a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040c9a0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  undefined4 local_c;
  undefined4 local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_c = **(undefined4 **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_8 = 0x40c9f1;
  __chkesp();
  return;
}

