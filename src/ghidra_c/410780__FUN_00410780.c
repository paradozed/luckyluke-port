/* FUN_00410780 @ 00410780 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410780(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  short sVar2;
  undefined2 extraout_var;
  int iVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_004074b0(param_2,4);
  uVar5 = (undefined1)uVar1;
  uVar1 = FUN_004074b0(param_2,3);
  iVar3 = CONCAT22(extraout_var,uVar1);
  sVar2 = FUN_004074b0(param_2,2);
  FUN_00477bf0(DAT_004f13a0,sVar2,iVar3,uVar5);
  uStack_8 = 0x4107d4;
  __chkesp();
  return;
}

