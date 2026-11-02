/* FUN_00415de0 @ 00415de0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415de0(int param_1,void *param_2)

{
  byte bVar1;
  short sVar2;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_48 [16];
  undefined4 local_8;
  undefined2 uVar3;
  
  puVar5 = local_48;
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  sVar2 = FUN_004074b0(param_2,3);
  if (sVar2 < 0) {
    sVar2 = sVar2 + 0xfff;
  }
  local_8 = CONCAT22(local_8._2_2_,sVar2);
  uVar3 = FUN_004074b0(param_2,2);
  bVar1 = (byte)uVar3;
  iVar4 = FUN_00407580(param_1);
  FUN_004474f0(*(int *)(iVar4 + 8),bVar1,sVar2);
  local_8 = 0x415e4c;
  __chkesp();
  return;
}

