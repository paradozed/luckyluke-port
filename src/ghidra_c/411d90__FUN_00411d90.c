/* FUN_00411d90 @ 00411d90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411d90(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_004074b0(param_2,2);
  DAT_004be2e5 = (undefined1)uVar1;
  sVar2 = FUN_004074b0(param_2,3);
  DAT_004bdaac = (int)sVar2 & 0xffffff;
  FUN_004830a0(DAT_004bdaac);
  DAT_004bdab0 = (undefined4)(0x100000 / (ulonglong)DAT_004bdaac);
  uStack_8 = 0x411e09;
  __chkesp();
  return;
}

