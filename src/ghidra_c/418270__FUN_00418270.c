/* FUN_00418270 @ 00418270 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00418270(void *param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_54 [16];
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar4 = local_54;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_8 = CONCAT22(local_8._2_2_,sVar1);
  local_c = *(undefined4 *)(DAT_004e8820 + 4 + sVar1 * 4);
  sVar1 = FUN_004074b0(param_2,4);
  iVar3 = FUN_00486410((ushort)local_c,sVar1);
  local_10 = (undefined4 *)FUN_00417f30(iVar3);
  local_14 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar2 = FUN_004074b0(param_2,2);
  FUN_00417fb0(local_14,local_10,uVar2);
  *(undefined1 *)((int)local_14 + 0x11) = 0;
  *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_14 + 3) * 4) = local_14;
  FUN_00412c50(param_1,local_14);
  FUN_00412ee0(param_1,FUN_00417d40);
  FUN_0047f0f0((byte *)*local_10);
  local_8 = 0x418349;
  __chkesp();
  return;
}

