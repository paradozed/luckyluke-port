/* FUN_004317d0 @ 004317d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004317d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8484 != 0) {
    if ((DAT_004e8484 != 1) && (DAT_004e8484 != 2)) {
      FUN_00430a10();
    }
    local_8 = DAT_004e8484 + -3;
    switch(local_8) {
    case 0:
      FUN_004316d0();
      break;
    case 1:
      FUN_00431710();
      break;
    case 2:
      FUN_00431750();
      break;
    case 3:
      FUN_00431790();
    }
  }
  local_8 = 0x431852;
  __chkesp();
  return;
}

