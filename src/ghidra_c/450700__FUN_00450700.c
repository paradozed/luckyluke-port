/* FUN_00450700 @ 00450700 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x004507ab) */
/* WARNING: Removing unreachable block (ram,0x004507b1) */
/* WARNING: Removing unreachable block (ram,0x004507c6) */

void FUN_00450700(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00450ca0();
  if (DAT_004e8610 == '\0') {
    if (DAT_004e863f == '\0') {
      local_8 = 0;
      FUN_0044f770(5,3);
      FUN_0044f570();
    }
    else {
      DAT_004e863f = '\0';
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
      DAT_004f23f8 = FUN_004507e0;
      FUN_004507e0();
    }
  }
  else {
    DAT_004e8610 = '\0';
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
    DAT_004f23f8 = FUN_0044fe50;
    FUN_0044fe50();
  }
  local_8 = 0x4507d8;
  __chkesp();
  return;
}

