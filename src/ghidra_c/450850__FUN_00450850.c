/* FUN_00450850 @ 00450850 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x0045091b) */
/* WARNING: Removing unreachable block (ram,0x00450921) */
/* WARNING: Removing unreachable block (ram,0x00450936) */

void FUN_00450850(void)

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
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = 0;
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x32) = 0;
      DAT_004f23f8 = FUN_00450950;
      FUN_00450950();
    }
  }
  else {
    DAT_004e8610 = '\0';
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
    DAT_004f23f8 = FUN_00450690;
    FUN_00450690();
  }
  local_8 = 0x450948;
  __chkesp();
  return;
}

