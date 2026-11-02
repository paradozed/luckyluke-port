/* FUN_0041f5e0 @ 0041f5e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0041f5e0(uint param_1,uint param_2,short param_3,ushort param_4,undefined2 param_5,char param_6)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_6c [16];
  ushort local_2c [2];
  ushort local_28 [2];
  uint local_24;
  undefined2 local_20;
  undefined2 uStack_1e;
  int local_1c;
  uint local_18;
  int *local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  puVar4 = local_6c;
  for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if ((DAT_004bcfd0 != 0) && (param_4 != 0)) {
    if (param_6 == '\x01') {
      local_8 = **(int **)(*(int *)(&DAT_004f1e40 + (param_1 & 0xffff) * 4) + 8);
      FUN_00451d70(local_8,(int *)&local_c,&local_10);
      if (((int)local_c < 0) || (DAT_004be3c8 < local_c)) goto LAB_0041f79b;
    }
    FUN_00420490((int *)&local_14,(char *)&local_18);
    if (local_14 != (int *)0x0) {
      local_1c = *(int *)(&DAT_004d2790 + (param_2 & 0xffff) * 4);
      uVar2 = FUN_004933a0(local_1c);
      _local_20 = CONCAT22(uStack_1e,(short)uVar2);
      iVar3 = (uVar2 & 0xffff) + (int)param_3;
      uVar1 = (undefined2)iVar3;
      local_24 = CONCAT22(local_24._2_2_,uVar1);
      *(undefined2 *)(&DAT_004d2396 + ((local_18 & 0xff) - 1) * 0x10) = uVar1;
      FUN_00420580(CONCAT31((int3)((uint)local_28 >> 8),(undefined1)local_18),param_4,
                   CONCAT22((short)((uint)iVar3 >> 0x10),param_5),local_28,local_2c);
      *(ushort *)(&DAT_004d2398 + ((local_18 & 0xff) - 1) * 0x10) = param_4;
      *(undefined2 *)(&DAT_004d239a + ((local_18 & 0xff) - 1) * 0x10) = param_5;
      (&DAT_004d239c)[((local_18 & 0xff) - 1) * 0x10] = 0;
      FUN_004933d0((int)local_14,local_24 & 0xffff);
      FUN_004935e0((int)local_14,1,local_28[0]);
      FUN_004935e0((int)local_14,2,local_2c[0]);
      FUN_00493430(*(int *)(&DAT_004d2790 + (param_2 & 0xffff) * 4),local_14);
    }
  }
LAB_0041f79b:
  local_8 = 0x41f7a8;
  __chkesp();
  return;
}

