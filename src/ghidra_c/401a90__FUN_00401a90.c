/* FUN_00401a90 @ 00401a90 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00401a90(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_5c [16];
  int local_1c;
  int local_18;
  uint local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_5c;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_18 = FUN_00494840(5);
  local_10 = (uint)local_10._2_2_ << 0x10;
  do {
    if ((uint)*(ushort *)(local_8 + 0xffc) <= (local_10 & 0xffff)) {
LAB_00401f63:
      local_8 = 0x401f70;
      __chkesp();
      return;
    }
    local_1c = *(int *)(local_8 + 0x198 + (local_10 & 0xffff) * 0x8c);
    if (local_1c == 0x73646976) {
      *(undefined4 *)(local_8 + 0xc9c + (local_10 & 0xffff) * 0x2c) = 0xe;
      *(undefined4 *)(local_8 + 0xc8c + (local_10 & 0xffff) * 0x2c) =
           *(undefined4 *)(local_8 + 0x19c + (local_10 & 0xffff) * 0x8c);
      *(undefined4 *)(local_8 + 0xc94 + (local_10 & 0xffff) * 0x2c) = 0xffffffff;
      *(undefined4 *)(local_8 + 0xc90 + (local_10 & 0xffff) * 0x2c) = 0xffffffff;
      *(undefined4 *)(local_8 + 0xc98 + (local_10 & 0xffff) * 0x2c) = 0;
      *(undefined4 *)(local_8 + 0xcb0 + (local_10 & 0xffff) * 0x2c) = 1;
      FUN_00458ec0();
      local_18 = local_8 + 0x19c + (local_10 & 0xffff) * 0x8c;
      FUN_00458ec0();
    }
    else if (local_1c == 0x73647561) {
      *(uint *)(local_8 + 0xc9c + (local_10 & 0xffff) * 0x2c) =
           *(uint *)(local_8 + 0xc9c + (local_10 & 0xffff) * 0x2c) | 8;
      *(undefined4 *)(local_8 + 0xcb0 + (local_10 & 0xffff) * 0x2c) = 1;
      uVar1 = AVIStreamStart(*(undefined4 *)(local_8 + (local_10 & 0xffff) * 4),0,&local_14);
      AVIStreamReadFormat(*(undefined4 *)(local_8 + (local_10 & 0xffff) * 4),uVar1);
      *(uint *)(local_8 + 0xca4 + (local_10 & 0xffff) * 0x2c) = local_14;
      if (local_14 != 0) {
        uVar1 = FUN_00494840(local_14);
        *(undefined4 *)(local_8 + 0xca0 + (local_10 & 0xffff) * 0x2c) = uVar1;
        FUN_00458ec0();
      }
      if (*(int *)(local_8 + 0xca0 + (local_10 & 0xffff) * 0x2c) != 0) {
        uVar1 = AVIStreamStart(*(undefined4 *)(local_8 + (local_10 & 0xffff) * 4),
                               *(undefined4 *)(local_8 + 0xca0 + (local_10 & 0xffff) * 0x2c),
                               &local_14);
        AVIStreamReadFormat(*(undefined4 *)(local_8 + (local_10 & 0xffff) * 4),uVar1);
        FUN_00425a70((void *)(local_8 + 0xe8),
                     *(undefined4 *)(local_8 + 0xca0 + (local_10 & 0xffff) * 0x2c));
      }
      FUN_00458ec0();
    }
    if (*(int *)(local_8 + 0x198 + (local_10 & 0xffff) * 0x8c) == 0x73646976) {
      uVar1 = AVIStreamGetFrameOpen(*(undefined4 *)(local_8 + (local_10 & 0xffff) * 4),0);
      *(undefined4 *)(local_8 + 0x148 + (local_10 & 0xffff) * 4) = uVar1;
      FUN_00458ec0();
      if (*(int *)(local_8 + 0x50) == 0) {
        *(undefined4 *)(local_8 + 0x50) = *(undefined4 *)(local_8 + (local_10 & 0xffff) * 4);
        *(uint *)(local_8 + 0x58) = local_10 & 0xffff;
        FUN_00458ec0();
        FUN_00458ec0();
      }
    }
    else if ((*(int *)(local_8 + 0x198 + (local_10 & 0xffff) * 0x8c) == 0x73647561) &&
            (*(int *)(local_8 + 0x54) == 0)) {
      *(undefined4 *)(local_8 + 0x54) = *(undefined4 *)(local_8 + (local_10 & 0xffff) * 4);
      *(uint *)(local_8 + 0x5c) = local_10 & 0xffff;
      FUN_00458ec0();
      if (DAT_004bc058 != 0) {
        if (*(char *)(local_8 + 0xe8) != '\0') {
          local_c = FUN_00425f70((void *)(local_8 + 0xe8),param_1,1);
          if (local_c != 1) {
            FUN_00458ec0();
            DAT_004bc058 = 0;
            goto LAB_00401f63;
          }
          FUN_00458ec0();
        }
        FUN_00425ba0();
        FUN_00425b60(local_8 + 0xe8);
      }
    }
    local_10 = CONCAT22(local_10._2_2_,(short)local_10 + 1);
  } while( true );
}

