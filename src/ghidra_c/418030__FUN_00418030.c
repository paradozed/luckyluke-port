/* FUN_00418030 @ 00418030 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00418030(void *param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_50 [16];
  byte *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar4 = local_50;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  iVar3 = FUN_00418120((int)sVar1);
  local_8 = (undefined4 *)FUN_00417f30(iVar3);
  local_c = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar2 = FUN_004074b0(param_2,3);
  FUN_00417fb0(local_c,local_8,uVar2);
  *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_c + 3) * 4) = local_c;
  FUN_00412c50(param_1,local_c);
  FUN_00412ee0(param_1,FUN_00417ca0);
  FUN_0047f0f0((byte *)*local_8);
  if ((*(char *)((int)local_c + 0x13) == '\0') &&
     (local_10 = *(byte **)local_c[2], local_10[1] == 1)) {
    *local_10 = *local_10 & 0xfd;
    FUN_00479e60((int)local_c);
  }
  local_8 = (undefined4 *)0x41811a;
  __chkesp();
  return;
}

