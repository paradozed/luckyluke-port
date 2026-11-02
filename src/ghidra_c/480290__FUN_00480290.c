/* FUN_00480290 @ 00480290 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_00480290(int param_1)

{
  ushort uVar1;
  uint3 uVar4;
  ushort *puVar2;
  uint uVar3;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_50 [19];
  
  puVar6 = local_50;
  for (iVar5 = 0x13; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  if (DAT_004be3d4 == 1) {
    puVar2 = (ushort *)(param_1 + 0xe8);
    if (*puVar2 == 0x11e) {
      return 0x100;
    }
    if (*puVar2 == 0x11f) {
      return (uint)(byte)(*puVar2 >> 8) << 8;
    }
    if (*puVar2 == 0x120) {
      return (uint)puVar2 & 0xffffff00;
    }
    if (*puVar2 == 0x121) {
      return 0x100;
    }
    if (*puVar2 == 0x122) {
      return (uint)(byte)(*puVar2 >> 8) << 8;
    }
    if (*puVar2 == 0x126) {
      return (uint)puVar2 & 0xffffff00;
    }
    uVar1 = *puVar2;
    uVar4 = (uint3)(byte)(uVar1 >> 8);
    if (uVar1 == 0x12a) {
      return (uint)uVar4 << 8;
    }
    uVar3 = (uint)uVar1;
    if (*puVar2 == 0x12e) {
      return (uint)uVar4 << 8;
    }
  }
  else {
    uVar3 = DAT_004be3d4;
    if (DAT_004be3d4 == 0x19) {
      puVar2 = (ushort *)(param_1 + 0xe8);
      if (*puVar2 == 0xee) {
        return (uint)puVar2 & 0xffffff00;
      }
      if (*puVar2 == 0xf2) {
        return (uint)puVar2 & 0xffffff00;
      }
      uVar1 = *puVar2;
      uVar4 = (uint3)(byte)(uVar1 >> 8);
      if (uVar1 == 0xf6) {
        return (uint)uVar4 << 8;
      }
      uVar3 = (uint)uVar1;
      if (*puVar2 == 0xf7) {
        return (uint)uVar4 << 8;
      }
    }
  }
  return CONCAT31((int3)(uVar3 >> 8),1);
}

