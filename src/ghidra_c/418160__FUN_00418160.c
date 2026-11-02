/* FUN_00418160 @ 00418160 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00418160(void *param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_50 [16];
  byte *local_10;
  undefined4 *local_c;
  int *local_8;
  
  puVar3 = local_50;
  for (iVar4 = 0x13; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  puVar3 = (undefined4 *)FUN_00418120((int)sVar1);
  iVar4 = FUN_0047d4e0(puVar3);
  local_8 = (int *)FUN_00417f30(iVar4);
  *(undefined4 *)(*local_8 + 0x54) = 0x100;
  local_c = (undefined4 *)FUN_004714a0(DAT_004f1e24);
  uVar2 = FUN_004074b0(param_2,3);
  FUN_00417fb0(local_c,local_8,uVar2);
  *(undefined4 **)(&DAT_004f1e40 + (uint)*(ushort *)(local_c + 3) * 4) = local_c;
  FUN_00412c50(param_1,local_c);
  FUN_00412ee0(param_1,FUN_00417d40);
  FUN_0047f0f0((byte *)*local_8);
  if ((*(char *)((int)local_c + 0x13) == '\0') &&
     (local_10 = *(byte **)local_c[2], local_10[1] == 1)) {
    *local_10 = *local_10 & 0xfd;
    FUN_00479e60((int)local_c);
  }
  local_8 = (int *)0x41825f;
  __chkesp();
  return;
}

