/* FUN_004b0063 @ 004b0063 */
/* decompiled from Lucky.exe (Game.run) */


char __fastcall FUN_004b0063(uint param_1)

{
  char local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  uint *local_8;
  
  FUN_004b1045(param_1,&local_30);
  local_34 = '\0';
  if ((local_24 == 0) || (DAT_004e8ee8 == (uint *)0x0)) {
    local_34 = '\x01';
  }
  else {
    local_8 = DAT_004e8ee8;
    while ((local_8 != (uint *)0x0 && (local_34 == '\0'))) {
      if ((local_8[2] == local_28) && ((*local_8 == local_30 && (local_8[1] == local_2c)))) {
        local_34 = '\x01';
      }
      local_8 = (uint *)local_8[3];
    }
  }
  return local_34;
}

