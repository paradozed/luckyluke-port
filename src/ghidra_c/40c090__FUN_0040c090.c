/* FUN_0040c090 @ 0040c090 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040c090(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_5c [16];
  uint local_1c;
  ushort local_18;
  undefined2 uStack_16;
  ushort local_14;
  undefined2 uStack_12;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar4 = local_5c;
  for (iVar3 = 0x16; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_004074b0(param_2,2);
  local_8 = CONCAT22(local_8._2_2_,uVar1);
  uVar1 = FUN_004074b0(param_2,3);
  local_c = CONCAT22(local_c._2_2_,uVar1);
  uVar1 = FUN_004074b0(param_2,4);
  local_10 = CONCAT22(local_10._2_2_,uVar1);
  uVar2 = FUN_004074b0(param_2,5);
  _local_14 = CONCAT22(uStack_12,uVar2);
  uVar2 = (ushort)((local_8 & 0xffff) << 0xc) | (ushort)((local_c & 0xffff) << 8) |
          (ushort)((local_10 & 0xffff) << 4) | uVar2;
  _local_18 = CONCAT22(uStack_16,uVar2);
  local_1c = local_1c & 0xffffff00;
  do {
    if (9 < (local_1c & 0xff)) {
      DAT_004e8914 = 2;
LAB_0040c1a0:
      local_8 = 0x40c1ad;
      __chkesp();
      return;
    }
    if (uVar2 == *(ushort *)(&DAT_004be1ac + (local_1c & 0xff) * 6)) {
      DAT_004e898c = *(undefined2 *)(&DAT_004be1b0 + (local_1c & 0xff) * 6);
      DAT_004e8914 = *(undefined2 *)(&DAT_004be1b0 + (local_1c & 0xff) * 6);
      goto LAB_0040c1a0;
    }
    local_1c = CONCAT31(local_1c._1_3_,(char)local_1c + '\x01');
  } while( true );
}

