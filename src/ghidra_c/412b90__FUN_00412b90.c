/* FUN_00412b90 @ 00412b90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00412b90(int param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = (undefined4 *)FUN_00407580(param_1);
  DAT_004e8612 = FUN_004074b0(param_2,2);
  sVar1 = FUN_004074b0(param_2,2);
  *local_8 = (&PTR_FUN_004bd048)[sVar1];
  sVar1 = FUN_004074b0(param_2,2);
  *(undefined4 *)(&DAT_004f2c64 + sVar1 * 4) = local_8[2];
  uVar2 = FUN_004074b0(param_2,4);
  sVar1 = FUN_004074b0(param_2,2);
  *(undefined2 *)(*(int *)(&DAT_004f2c64 + sVar1 * 4) + 0x3c) = uVar2;
  sVar1 = FUN_004074b0(param_2,5);
  DAT_004f2c60 = (&PTR_FUN_004bc488)[sVar1];
  local_8 = (undefined4 *)0x412c41;
  __chkesp();
  return;
}

