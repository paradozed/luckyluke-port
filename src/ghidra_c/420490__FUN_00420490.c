/* FUN_00420490 @ 00420490 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00420490(int *param_1,char *param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_50 [16];
  uint local_10;
  int local_c;
  undefined4 local_8;
  
  puVar4 = local_50;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  *param_2 = '\0';
  *param_1 = 0;
  local_8 = CONCAT31(local_8._1_3_,DAT_004d1eb1);
  do {
    if ((&DAT_004d2394)[(char)local_8 * 0x10] == '\0') {
      local_c = *(int *)(&DAT_004d2390 + (char)local_8 * 0x10);
      bVar1 = FUN_00493790(local_c);
      local_10 = (uint)bVar1;
      if (local_10 == 0) {
        *param_1 = local_c;
        *param_2 = (char)local_8 + '\x01';
        DAT_004d1eb1 = DAT_004d1eb1 + 1;
        if (0x3f < DAT_004d1eb1) {
          DAT_004d1eb1 = 0;
        }
        break;
      }
    }
    cVar2 = (char)local_8 + '\x01';
    local_8._0_1_ = cVar2;
    if ('?' < cVar2) {
      local_8._0_1_ = '\0';
    }
  } while ((int)(char)local_8 != (uint)DAT_004d1eb1);
  local_8 = 0x420570;
  __chkesp();
  return;
}

