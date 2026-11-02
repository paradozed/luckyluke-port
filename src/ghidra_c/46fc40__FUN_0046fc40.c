/* FUN_0046fc40 @ 0046fc40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046fc40(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_54 [16];
  uint local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  puVar4 = local_54;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = *(int *)(param_1 + 8);
  local_c = local_8 + 0x30;
  local_14 = CONCAT22(local_14._2_2_,*(undefined2 *)(local_8 + 4));
  if (*(char *)(local_8 + 7) == '\x01') {
    FUN_0046ef60(local_8);
  }
  if (*(char *)(local_8 + 6) == '\x01') {
    FUN_0046f4c0(local_8);
  }
  local_10 = (uint)local_10._2_2_ << 0x10;
  while ((local_10 & 0xffff) < (local_14 & 0xffff)) {
    if (*(short *)(local_c + 0x52) == 0x3e9) {
      uVar1 = *(undefined4 *)(local_8 + 0x14);
      uVar2 = FUN_004971c0();
      *(ushort *)(local_c + 0x50) =
           ((ushort)uVar2 & (ushort)*(undefined4 *)(local_8 + 0x18)) - (short)uVar1;
      *(short *)(local_c + 0x52) = -(short)*(undefined4 *)(local_8 + 0x20);
      *(short *)(local_c + 0x50) = *(short *)(local_c + 0x50) + (short)DAT_004bd6a0;
    }
    *(short *)(local_c + 0x50) = *(short *)(local_c + 0x50) + *(short *)(local_c + 0x58);
    *(short *)(local_c + 0x52) = *(short *)(local_c + 0x52) + *(short *)(local_c + 0x5a);
    if (*(int *)(local_8 + 0x1c) < (int)*(short *)(local_c + 0x52)) {
      *(undefined2 *)(local_c + 0x52) = 0x3e9;
    }
    local_c = local_c + 100;
    local_10 = CONCAT22(local_10._2_2_,(short)local_10 + 1);
  }
  local_8 = 0x46fd7f;
  __chkesp();
  return;
}

