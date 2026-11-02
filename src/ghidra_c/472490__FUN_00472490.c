/* FUN_00472490 @ 00472490 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00472490(uint *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  ushort *puVar4;
  undefined4 *puVar5;
  uint *puVar6;
  undefined4 local_e4 [16];
  uint local_a4;
  uint local_a0;
  undefined4 local_9c [2];
  undefined1 local_94;
  uint local_90 [32];
  undefined4 *local_10;
  undefined4 *local_c;
  uint local_8;
  
  puVar5 = local_e4;
  for (iVar3 = 0x38; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  puVar6 = (uint *)&DAT_004b8718;
  puVar1 = FUN_00497270(local_90,(uint *)"\\option\\");
  puVar1 = FUN_00497280(puVar1,param_1);
  FUN_00497280(puVar1,puVar6);
  FUN_00474c50();
  DAT_004f182e = '\0';
  for (local_8 = 0; (int)local_8 < 2; local_8 = local_8 + 1) {
    *(undefined4 *)(&DAT_004f1820 + local_8 * 4) = 0;
    (&DAT_004f182c)[local_8] = 0;
  }
  local_10 = (undefined4 *)FUN_004658d0((char *)local_90);
  local_c = local_10;
  if (local_10 != (undefined4 *)0x0) {
    FUN_00497690((undefined4 *)&DAT_004f22c0,local_10,0xdc);
    DAT_004f23b4 = *(undefined2 *)(local_c + 0x37);
    DAT_004f23b6 = *(undefined2 *)((int)local_c + 0xde);
    puVar4 = (ushort *)(local_c + 0x38);
    local_a0 = CONCAT22(local_a0._2_2_,*puVar4);
    local_c = (undefined4 *)((int)local_c + 0xe2);
    for (local_8 = (uint)*puVar4; 0 < (int)local_8; local_8 = local_8 - 1) {
      FUN_00497690(local_9c,local_c,8);
      local_94 = 0;
      local_a4 = CONCAT22(local_a4._2_2_,*(undefined2 *)(local_c + 2));
      puVar4 = (ushort *)((int)local_c + 10);
      local_a0 = CONCAT22(local_a0._2_2_,*puVar4);
      local_c = local_c + 3;
      uVar2 = FUN_00494c40((uint)*puVar4 << 2,1);
      *(undefined4 *)(&DAT_004f1820 + (local_a4 & 0xffff) * 4) = uVar2;
      FUN_00497690(*(undefined4 **)(&DAT_004f1820 + (local_a4 & 0xffff) * 4),local_c,
                   (local_a0 & 0xffff) << 2);
      local_c = local_c + (local_a0 & 0xffff);
      *(undefined2 *)(&DAT_004f1828 + (local_a4 & 0xffff) * 2) = 0;
      (&DAT_004f182c)[local_a4 & 0xffff] = 1;
      DAT_004f182e = DAT_004f182e + '\x01';
    }
    FUN_00465890(local_10);
    DAT_004e8974 = 2;
  }
  local_8 = 0x4726ee;
  __chkesp();
  return;
}

