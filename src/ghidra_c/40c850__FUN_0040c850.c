/* FUN_0040c850 @ 0040c850 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040c850(undefined4 param_1,void *param_2)

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
  local_8 = CONCAT22(local_8._2_2_,sVar1);
  local_c = FUN_0046e8d0((int)sVar1);
  local_8 = 0x40c8a1;
  __chkesp();
  return;
}

