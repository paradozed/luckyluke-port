/* FUN_0042cb20 @ 0042cb20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042cb20(uint *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_14 = 0;
  FUN_004b2410(param_1);
  for (local_8 = 0; local_8 < (int)(uint)DAT_004e89fa; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < (int)(uint)*(ushort *)(DAT_004e89f0 + local_8 * 0x20);
        local_c = local_c + 1) {
      for (local_10 = 0; local_10 < DAT_004e85a4; local_10 = local_10 + 1) {
        FUN_004b2410((uint *)(DAT_004d1e74 + local_10 * 0x18));
        iVar1 = _strcmp((char *)(DAT_004d1e74 + local_10 * 0x18),(char *)param_1);
        if (iVar1 == 0) {
          if (local_14 == param_2) goto LAB_0042cc1c;
          local_14 = local_14 + 1;
        }
      }
    }
  }
LAB_0042cc1c:
  local_8 = 0x42cc29;
  __chkesp();
  return;
}

