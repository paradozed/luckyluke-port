/* FUN_0041fd20 @ 0041fd20 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0041fd20(void)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004bcfd0 != 0) {
    local_8 = local_8 & 0xffffff00;
    local_c = local_c & 0xffffff00;
    while ((local_c & 0xff) < 0x40) {
      if ((&DAT_004d2394)[(local_c & 0xff) * 0x10] == '\0') {
        local_10 = *(int *)(&DAT_004d2390 + (local_c & 0xff) * 0x10);
        bVar1 = FUN_00493790(local_10);
        local_14 = (uint)bVar1;
        if (local_14 == 0) {
          local_8 = CONCAT31(local_8._1_3_,(char)local_8 + '\x01');
        }
      }
      local_c = CONCAT31(local_c._1_3_,(char)local_c + '\x01');
    }
  }
  local_8 = 0x41fdc7;
  __chkesp();
  return;
}

