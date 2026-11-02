/* FUN_004a4030 @ 004a4030 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004a4030(void)

{
  byte *local_18;
  int local_10;
  undefined4 *local_c;
  int local_8;
  
  if (DAT_0050a2ac == 0) {
    FUN_004a9710();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_004e8d20,0x104);
  DAT_004e8c9c = &DAT_004e8d20;
  if (*DAT_0050a2a4 == 0) {
    local_18 = &DAT_004e8d20;
  }
  else {
    local_18 = DAT_0050a2a4;
  }
  FUN_004a4110(local_18,(undefined4 *)0x0,(byte *)0x0,&local_10,&local_8);
  local_c = (undefined4 *)FUN_00494860(local_8 + local_10 * 4,2,0x4bb528,0x80);
  if (local_c == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  FUN_004a4110(local_18,local_c,(byte *)(local_c + local_10),&local_10,&local_8);
  DAT_004e8c80 = local_10 + -1;
  DAT_004e8c84 = local_c;
  return;
}

