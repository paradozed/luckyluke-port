/* FUN_0042f420 @ 0042f420 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042f420(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_78 [16];
  int local_38;
  CHAR local_34 [32];
  int *local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_78;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00450ea0((int *)&DAT_004e85d8,&local_8,&local_c);
  FUN_004277b0(local_8,local_c);
  if ((DAT_004f2458 != (int *)0x0) && (*DAT_004f2458 != 0)) {
    local_8 = *(int *)(*DAT_004f2458 + 0x90);
    local_c = *(int *)(*DAT_004f2458 + 0x94);
    local_10 = *(undefined4 *)(*DAT_004f2458 + 0x98);
    (*DAT_004e8a2c)(10,0x46,"Lucky: %d, %d, %d",local_8,local_c,local_10);
    __chkesp();
  }
  (*DAT_004e8a2c)(10,0x50,"Cluster: %d",(int)DAT_004f2b50);
  __chkesp();
  if (DAT_004f5900 != '\0') {
    FUN_00497080(local_34,0x4b5cc4);
    local_14 = (int *)FUN_00497d00(local_34,"a");
    if (local_14 != (int *)0x0) {
      FUN_00498130(local_14,(byte *)"Checkpoint: \t%d\t%d\t%d\n");
      FUN_00497b30(local_14);
    }
  }
  if (DAT_004e846c != 0) {
    DAT_004e8468 = FUN_00488180(DAT_004bcdcc,DAT_004bcdd0);
    if (DAT_004e8468 != 0) {
      local_38 = 0;
      FUN_00480040(DAT_004e8468,0xff,0,0);
      FUN_0042cc30(DAT_004e8468);
      local_38 = DAT_004e8468;
      if (DAT_004e8474 != 0) {
        local_38 = DAT_004e8474;
      }
      if (local_38 != 0) {
        FUN_0042cd30(local_38,10,0x186);
        (*DAT_004e8a2c)(10,400,"Number of points: %d",*(undefined4 *)(local_38 + 0x10));
        __chkesp();
        (*DAT_004e8a2c)(10,0x19a,"Number of groups: %d",*(undefined4 *)(local_38 + 0x1c));
        __chkesp();
        (*DAT_004e8a2c)(10,0x1a4,"Number of primitives: %d",*(undefined4 *)(local_38 + 0x2c));
        __chkesp();
        (*DAT_004e8a2c)(10,0x1ae,"Current primitive: %d",DAT_004e8470);
        __chkesp();
        (*DAT_004e8a2c)(10,0x1b8,"------------------------");
        __chkesp();
        FUN_0047e260(local_38,DAT_004e8470);
        if (DAT_004f5987 != '\0') {
          DAT_004e8470 = (DAT_004e8470 + 1) % *(uint *)(local_38 + 0x2c);
        }
        if ((DAT_004f598f != '\0') && (DAT_004e8470 = DAT_004e8470 - 1, (int)DAT_004e8470 < 0)) {
          DAT_004e8470 = *(int *)(local_38 + 0x2c) - 1;
        }
        if (DAT_004f5992 != '\0') {
          DAT_004e8470 = (DAT_004e8470 + 10) % *(uint *)(local_38 + 0x2c);
        }
        if ((DAT_004f5993 != '\0') && (DAT_004e8470 = DAT_004e8470 - 10, (int)DAT_004e8470 < 0)) {
          DAT_004e8470 = *(int *)(local_38 + 0x2c) + DAT_004e8470;
        }
      }
    }
    FUN_00488130();
    FUN_0042cdc0();
  }
  FUN_0042eae0();
  local_8 = 0x42f779;
  __chkesp();
  return;
}

