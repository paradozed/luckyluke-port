/* FUN_00418920 @ 00418920 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00418920(void *param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_54 [16];
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar4 = local_54;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,5);
  if (sVar1 == 5) {
    DAT_004f22a4 = (int *)FUN_00439a90(DAT_004e85ec,200);
    _memset(DAT_004f22a4,0,200);
    local_8 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
    uVar2 = FUN_004074b0(param_2,3);
    FUN_00417fb0(local_8,DAT_004f22a4,uVar2);
    *local_8 = FUN_0046c910;
    local_8[1] = FUN_0047ac50;
    sVar1 = FUN_004074b0(param_2,2);
    iVar3 = FUN_00418120((int)sVar1);
    local_c = (undefined4 *)FUN_00417f30(iVar3);
    FUN_00497690(DAT_004f22a4,local_c,0x74);
    if (local_c != (undefined4 *)0x0) {
      FUN_00439c30(local_c);
      local_c = (undefined4 *)0x0;
    }
    DAT_004f22a4[0x27] = (int)local_8;
    uVar2 = FUN_004074b0(param_2,4);
    *(undefined2 *)(DAT_004f22a4 + 0xf) = uVar2;
    DAT_004f22a4[0x28] = 0;
    sVar1 = FUN_004074b0(param_2,5);
    DAT_004f2294 = (&PTR_FUN_004bdd58)[sVar1];
    sVar1 = FUN_004074b0(param_2,5);
    DAT_004f23b0 = (&PTR_FUN_004bdd80)[sVar1];
    *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_8 + 3) * 4) = local_8;
    *(ushort *)(*(int *)(&DAT_004f1e40 + (uint)*(ushort *)(local_8 + 3) * 4) + 0xe) =
         *(ushort *)(*(int *)(&DAT_004f1e40 + (uint)*(ushort *)(local_8 + 3) * 4) + 0xe) | 2;
    FUN_00412c50(param_1,local_8);
    FUN_00412ee0(param_1,FUN_00417de0);
    FUN_0047f0f0((byte *)*DAT_004f22a4);
    if (((DAT_004e8914 == 5) || (DAT_004e8914 == 4)) || (DAT_004e8914 == 6)) {
      FUN_00478980(*DAT_004f22a4,0);
    }
  }
  else {
    DAT_004f2458 = (int *)FUN_00439a90(DAT_004e85ec,200);
    _memset(DAT_004f2458,0,200);
    local_10 = (undefined4 *)FUN_004714a0(DAT_004f1e24);
    uVar2 = FUN_004074b0(param_2,3);
    FUN_00417fb0(local_10,DAT_004f2458,uVar2);
    *local_10 = FUN_004662e0;
    local_10[1] = FUN_0047ac50;
    sVar1 = FUN_004074b0(param_2,2);
    iVar3 = FUN_00418120((int)sVar1);
    local_14 = (undefined4 *)FUN_00417f30(iVar3);
    FUN_00497690(DAT_004f2458,local_14,0x74);
    if (local_14 != (undefined4 *)0x0) {
      FUN_00439c30(local_14);
      local_14 = (undefined4 *)0x0;
    }
    DAT_004f2458[0x27] = (int)local_10;
    uVar2 = FUN_004074b0(param_2,4);
    *(undefined2 *)(DAT_004f2458 + 0xf) = uVar2;
    DAT_004f2458[0x28] = 0;
    sVar1 = FUN_004074b0(param_2,5);
    DAT_004f23f8 = (&PTR_FUN_004bdd58)[sVar1];
    sVar1 = FUN_004074b0(param_2,5);
    DAT_004f23c4 = (&PTR_FUN_004bdd80)[sVar1];
    sVar1 = FUN_004074b0(param_2,5);
    DAT_004f23c0 = (&PTR_FUN_004bdda8)[sVar1];
    *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_10 + 3) * 4) = local_10;
    *(ushort *)(*(int *)(&DAT_004f1e40 + (uint)*(ushort *)(local_10 + 3) * 4) + 0xe) =
         *(ushort *)(*(int *)(&DAT_004f1e40 + (uint)*(ushort *)(local_10 + 3) * 4) + 0xe) | 2;
    FUN_00412c50(param_1,local_10);
    FUN_00412ee0(param_1,FUN_00417de0);
    DAT_004f23b8 = 0;
    FUN_0047f0f0((byte *)*DAT_004f2458);
    if (((DAT_004e8914 == 5) || (DAT_004e8914 == 4)) || (DAT_004e8914 == 6)) {
      FUN_00478980(*DAT_004f2458,1);
    }
  }
  local_8 = (undefined4 *)0x418d15;
  __chkesp();
  return;
}

