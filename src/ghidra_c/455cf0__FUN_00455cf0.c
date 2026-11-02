/* FUN_00455cf0 @ 00455cf0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00455cf0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_b0 [16];
  ushort local_70;
  undefined2 uStack_6e;
  short local_6c;
  short local_6a;
  short local_68;
  undefined2 local_66;
  int local_64 [4];
  undefined4 local_54 [8];
  undefined4 local_34 [8];
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = local_b0;
  for (iVar1 = 0x2b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  local_66 = 0;
  _local_70 = CONCAT22(uStack_6e,(ushort)DAT_004f2744);
  local_14 = *(int *)(*DAT_004f2458 + 0x90);
  local_10 = *(undefined4 *)(*DAT_004f2458 + 0x94);
  local_c = *(undefined4 *)(*DAT_004f2458 + 0x98);
  if ((((ushort)DAT_004f2744 & 0x800) != 0) && (((ushort)DAT_004f2744 & 0x80) != 0)) {
    DAT_004bd6a0 = DAT_004bd6a0 + -200;
  }
  if ((((ushort)DAT_004f2744 & 0x800) != 0) && (((ushort)DAT_004f2744 & 0x20) != 0)) {
    DAT_004bd6a0 = DAT_004bd6a0 + 200;
  }
  if ((((ushort)DAT_004f2744 & 0x800) != 0) && (((ushort)DAT_004f2744 & 0x10) != 0)) {
    DAT_004bd6a4 = DAT_004bd6a4 + -200;
  }
  if ((((ushort)DAT_004f2744 & 0x800) != 0) && (((ushort)DAT_004f2744 & 0x40) != 0)) {
    DAT_004bd6a4 = DAT_004bd6a4 + 200;
  }
  if ((((ushort)DAT_004f2744 & 0x200) != 0) && (((ushort)DAT_004f2744 & 0x10) != 0)) {
    DAT_004e8688 = DAT_004e8688 + -8;
  }
  if ((((ushort)DAT_004f2744 & 0x200) != 0) && (((ushort)DAT_004f2744 & 0x40) != 0)) {
    DAT_004e8688 = DAT_004e8688 + 8;
  }
  if ((((ushort)DAT_004f2744 & 0x200) != 0) && (((ushort)DAT_004f2744 & 0x80) != 0)) {
    DAT_004e868a = DAT_004e868a + -8;
  }
  if ((((ushort)DAT_004f2744 & 0x200) != 0) && (((ushort)DAT_004f2744 & 0x20) != 0)) {
    DAT_004e868a = DAT_004e868a + 8;
  }
  if ((((ushort)DAT_004f2744 & 0x200) != 0) && (((ushort)DAT_004f2744 & 0x400) != 0)) {
    DAT_004e868c = DAT_004e868c + -8;
  }
  if ((((ushort)DAT_004f2744 & 0x200) != 0) && (((ushort)DAT_004f2744 & 0x100) != 0)) {
    DAT_004e868c = DAT_004e868c + 8;
  }
  if ((((ushort)DAT_004f2744 & 0x800) != 0) && (((ushort)DAT_004f2744 & 0x400) != 0)) {
    DAT_004e864c = DAT_004e864c + -200;
  }
  if ((((ushort)DAT_004f2744 & 0x800) != 0) && (((ushort)DAT_004f2744 & 0x100) != 0)) {
    DAT_004e864c = DAT_004e864c + 200;
  }
  local_6c = DAT_004e8688;
  local_6a = DAT_004e868a;
  local_68 = DAT_004e868c;
  FUN_00482a90(&local_6c,local_34);
  FUN_004835d0((undefined2 *)local_34,(undefined2 *)local_54);
  FUN_00482760(local_54,&DAT_004bd6a0,local_64);
  FUN_00454330(&local_14,local_64);
  if (DAT_004f2bf8 != 0xb) {
    FUN_00451500(&local_14,&local_6c,DAT_004e864c);
  }
  local_8 = 0x456096;
  __chkesp();
  return;
}

