/* FUN_00428600 @ 00428600 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00428600(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_258 [16];
  char *local_218;
  uint local_214;
  undefined4 local_210;
  uint local_20c [65];
  uint local_108 [64];
  undefined4 uStack_8;
  
  puVar3 = local_258;
  for (iVar2 = 0x95; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_00442670('\x01');
  cVar1 = FUN_004427e0("Target Directory",(LPBYTE)local_108);
  local_214._0_1_ = cVar1;
  cVar1 = FUN_004427e0("Source Directory",(LPBYTE)local_20c);
  local_214 = CONCAT31(local_214._1_3_,(char)local_214 + cVar1);
  iVar2 = FUN_00442860("Language",(LPBYTE)&local_210);
  if (iVar2 != 0) {
    _DAT_004e85ac = local_210;
  }
  GetCurrentDirectoryA(0x104,&DAT_004f2460);
  __chkesp();
  if ((local_214 & 0xff) == 2) {
    iVar2 = FUN_00442860("Movies",(LPBYTE)&local_210);
    if (iVar2 == 0) {
      FUN_00497270((uint *)&DAT_004f5560,local_20c);
    }
    else {
      FUN_00497270((uint *)&DAT_004f5560,local_108);
    }
    iVar2 = FUN_00442860("Game Data",(LPBYTE)&local_210);
    if (iVar2 == 0) {
      FUN_00497270((uint *)&DAT_004f5680,local_20c);
    }
    else {
      FUN_00497270((uint *)&DAT_004f5680,local_108);
    }
    FUN_004b24ae((LPCSTR)local_108);
  }
  else {
    FUN_00497270((uint *)&DAT_004f5560,(uint *)&DAT_004f2460);
    FUN_00497270((uint *)&DAT_004f5680,(uint *)&DAT_004f2460);
  }
  iVar2 = FUN_00442860("CD Volume",&DAT_004f58a0);
  if (iVar2 == 0) {
    _DAT_004f58a0 = 0x46;
  }
  iVar2 = FUN_00442860("Audio Volume",&DAT_004f58ac);
  if (iVar2 == 0) {
    _DAT_004f58ac = 100;
  }
  iVar2 = FUN_00442860("Keyboard Hand",(LPBYTE)&DAT_004e8750);
  if (iVar2 == 0) {
    DAT_004e8750 = 0;
  }
  FUN_00442770();
  local_218 = _strrchr(&DAT_004f5560,0x5c);
  if ((local_218 != (char *)0x0) && (local_218[1] == '\0')) {
    *local_218 = '\0';
  }
  local_218 = _strrchr(&DAT_004f5680,0x5c);
  if ((local_218 != (char *)0x0) && (local_218[1] == '\0')) {
    *local_218 = '\0';
  }
  uStack_8 = 0x42884f;
  __chkesp();
  return;
}

