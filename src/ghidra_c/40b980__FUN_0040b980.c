/* FUN_0040b980 @ 0040b980 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040b980(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar5 = local_44;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  uVar1 = FUN_004074b0(param_2,4);
  sVar2 = FUN_004074b0(param_2,2);
  sVar3 = FUN_004074b0(param_2,3);
  *(undefined2 *)(&DAT_004f13e2 + sVar3 * 2 + sVar2 * 0x2c) = uVar1;
  uStack_8 = 0x40b9db;
  __chkesp();
  return;
}

