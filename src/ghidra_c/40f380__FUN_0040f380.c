/* FUN_0040f380 @ 0040f380 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040f380(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  FUN_004425a0((int)sVar1);
  uStack_8 = 0x40f3bf;
  __chkesp();
  return;
}

