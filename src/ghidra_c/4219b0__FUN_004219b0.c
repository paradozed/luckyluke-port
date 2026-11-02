/* FUN_004219b0 @ 004219b0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_004219b0(int param_1)

{
  undefined2 uVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_64 [16];
  ushort *local_24;
  void *local_20;
  int local_1c;
  ushort *local_18;
  void *local_14;
  void *local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_64;
  for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = param_1;
  for (local_c = 0; local_c < *(int *)(local_8 + 4); local_c = local_c + 1) {
    puVar3 = (undefined4 *)FUN_00422270((void *)(local_8 + 0x24),local_c);
    local_10 = (void *)*puVar3;
    if (((local_10 != (void *)0x0) && (iVar4 = FUN_00421be0(local_10,1), (char)iVar4 == '\0')) &&
       (iVar4 = FUN_00421c90((int)local_10), iVar4 != 0)) {
      uVar1 = FUN_00421c60((int)local_10);
      FUN_00421c20(local_10,uVar1);
      FUN_00421d00((int)local_10);
      iVar4 = FUN_00421db0((int)local_10);
      FUN_00422130(iVar4);
      FUN_00417250(local_10,2,0);
    }
  }
  for (local_c = 0; local_c < *(int *)(local_8 + 4); local_c = local_c + 1) {
    puVar3 = (undefined4 *)FUN_00422270((void *)(local_8 + 0x24),local_c);
    local_14 = (void *)*puVar3;
    if (((local_14 != (void *)0x0) && (iVar4 = FUN_00421be0(local_14,1), (char)iVar4 == '\0')) &&
       (iVar4 = FUN_00421be0(local_14,2), (char)iVar4 == '\0')) {
      local_18 = (ushort *)FUN_00421d50((int)local_14);
      FUN_00417250(local_14,8,1);
      local_1c = 0;
      while ((iVar4 = FUN_00421be0(local_14,2), (char)iVar4 == '\0' &&
             (((iVar4 = FUN_00421be0(local_14,8), (char)iVar4 != '\0' && (local_1c < 0x1e)) ||
              (iVar4 = FUN_00421be0(local_14,4), (char)iVar4 != '\0'))))) {
        FUN_00422dc0(local_14,local_18);
        if (2000000 < local_1c) {
          FUN_00417250(local_14,4,0);
        }
        local_1c = local_1c + 1;
      }
    }
  }
  for (local_c = 0; local_c < *(int *)(local_8 + 4); local_c = local_c + 1) {
    puVar3 = (undefined4 *)FUN_00422270((void *)(local_8 + 0x24),local_c);
    local_20 = (void *)*puVar3;
    if (((local_20 != (void *)0x0) && (iVar4 = FUN_00421be0(local_20,1), (char)iVar4 == '\0')) &&
       (sVar2 = FUN_00421cc0((int)local_20), sVar2 != -1)) {
      local_24 = (ushort *)FUN_00421d80((int)local_20);
      do {
        iVar4 = FUN_00424330(local_20,local_24);
      } while (iVar4 != 0);
    }
  }
  local_8 = 0x421bd5;
  __chkesp();
  return;
}

