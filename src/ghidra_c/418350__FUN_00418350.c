/* FUN_00418350 @ 00418350 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00418350(void *param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 local_58 [16];
  undefined4 *local_18;
  int *local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  puVar5 = local_58;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_8 = CONCAT22(local_8._2_2_,sVar1);
  local_c = FUN_0046e8d0((int)sVar1);
  local_10 = *(undefined4 *)(*(int *)(local_c + 8) + 4);
  sVar1 = FUN_004074b0(param_2,4);
  iVar3 = FUN_00486410((ushort)local_10,sVar1);
  local_14 = (int *)FUN_00417f30(iVar3);
  local_18 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar2 = FUN_004074b0(param_2,2);
  FUN_00417fb0(local_18,local_14,uVar2);
  *(undefined1 *)((int)local_18 + 0x11) = 1;
  *local_18 = FUN_0047aa50;
  *(undefined1 *)(local_18 + 5) = 0;
  *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_18 + 3) * 4) = local_18;
  FUN_00412c50(param_1,local_18);
  FUN_00412ee0(param_1,FUN_00417d40);
  FUN_0047f0f0((byte *)*local_14);
  piVar4 = (int *)(*local_14 + 0xa4);
  piVar6 = local_14 + 9;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar6 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar6 = piVar6 + 1;
  }
  local_8 = 0x41845b;
  __chkesp();
  return;
}

