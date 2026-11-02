/* FUN_00475330 @ 00475330 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00475330(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_14c [16];
  uint local_10c;
  uint local_108 [64];
  undefined4 uStack_8;
  
  puVar2 = local_14c;
  for (iVar1 = 0x52; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10c = local_10c & 0xffffff00;
  FUN_00497270(local_108,(uint *)PTR_s_IMAGE_PUEBLOS_TIM_004be27c);
  if (((DAT_004e8914 == 0x1a) || (DAT_004e8914 == 0x1b)) || (DAT_004e8914 == 0x1c)) {
    FUN_00497270(local_108,(uint *)PTR_s_IMAGE_BLEVEL_TIM_004be258);
  }
  else {
    local_10c = local_10c & 0xffffff00;
    while ((local_10c & 0xff) < 0xd) {
      if (DAT_004e8914 == *(short *)(&DAT_004be260 + (local_10c & 0xff) * 8)) {
        FUN_00497270(local_108,(uint *)(&PTR_s_IMAGE_ABILENE_TIM_004be264)[(local_10c & 0xff) * 2]);
        break;
      }
      local_10c = CONCAT31(local_10c._1_3_,(char)local_10c + '\x01');
    }
  }
  FUN_0043fe80();
  FUN_00474c50();
  FUN_00449840(local_108,'\0');
  uStack_8 = 0x475451;
  __chkesp();
  return;
}

