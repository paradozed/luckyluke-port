/* FUN_00450150 @ 00450150 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x0045021c) */
/* WARNING: Removing unreachable block (ram,0x00450222) */
/* WARNING: Removing unreachable block (ram,0x00450237) */

void FUN_00450150(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_004505b0();
  if (DAT_004e8610 == '\0') {
    if (DAT_004e863f == '\0') {
      local_8 = CONCAT31(local_8._1_3_,2);
      local_c = 0;
      FUN_0044f770(5,3);
      FUN_0044f570();
    }
    else {
      DAT_004e863f = '\0';
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
      DAT_004f23f8 = FUN_0044ff90;
      FUN_0044ff90();
    }
  }
  else {
    DAT_004e8610 = '\0';
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x32) = 0;
    DAT_004f23f8 = FUN_00450250;
    FUN_00450250();
  }
  local_8 = 0x450249;
  __chkesp();
  return;
}

