/* FUN_0040eeb0 @ 0040eeb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040eeb0(undefined4 param_1,void *param_2)

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
  sVar1 = FUN_004074b0(param_2,3);
  *(int *)(local_8 + 4) = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,4);
  *(int *)(local_8 + 8) = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,5);
  *(int *)(local_8 + 0xc) = (int)sVar1;
  uVar2 = FUN_004074b0(param_2,6);
  *(undefined2 *)(local_8 + 0x14) = uVar2;
  local_8 = 0x40ef39;
  __chkesp();
  return;
}

