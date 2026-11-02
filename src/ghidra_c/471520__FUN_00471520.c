/* FUN_00471520 @ 00471520 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00471520(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  undefined4 *local_10;
  uint local_c;
  undefined4 local_8;
  
  iVar1 = 0x13;
  puVar2 = local_50;
  while( true ) {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e85b8 != 10) {
    (*(code *)PTR_FUN_004bd5d8)();
    __chkesp();
  }
  local_c = CONCAT22(local_c._2_2_,(short)DAT_004f1e24[1]);
  local_8 = (uint)local_8._2_2_ << 0x10;
  while (((local_8 & 0xffff) < (local_c & 0xffff) &&
         (local_10 = *(undefined4 **)(*DAT_004f1e24 + (local_8 & 0xffff) * 4),
         (local_c & 0xffff) < (uint)*(ushort *)((int)DAT_004f1e24 + 6)))) {
    if (((local_10 != (undefined4 *)0x0) && (local_10[2] != -0x22222223)) &&
       (*(char *)((int)local_10 + 0x11) != '\0')) {
      (*(code *)*local_10)(local_10);
      __chkesp();
    }
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  if (DAT_004e85b8 == 10) {
    (*(code *)PTR_FUN_004bd5d8)();
    __chkesp();
  }
  local_8 = 0x471617;
  __chkesp();
  return;
}

