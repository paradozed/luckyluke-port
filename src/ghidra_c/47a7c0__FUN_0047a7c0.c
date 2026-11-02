/* FUN_0047a7c0 @ 0047a7c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0047a7c0(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_58 [16];
  byte *local_18;
  uint local_14;
  short local_10;
  int *local_c;
  uint local_8;
  
  puVar3 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_14 = CONCAT22(local_14._2_2_,(short)DAT_004f1e24[1]);
  local_8 = local_8 & 0xffff0000;
  while (((local_8 & 0xffff) < (local_14 & 0xffff) &&
         (local_c = *(int **)(*DAT_004f1e24 + (local_8 & 0xffff) * 4),
         (local_8 & 0xffff) < (uint)*(ushort *)((int)DAT_004f1e24 + 6)))) {
    if (((local_c != (int *)0x0) && (((uint)local_c & 0xa0000000) == 0)) &&
       (local_c[2] != -0x22222223)) {
      if ((*(ushort *)((int)local_c + 0xe) & 1) == 0) {
        if (((code *)*local_c == FUN_00473640) || ((code *)*local_c == FUN_00473660)) {
          FUN_0047a4c0((int)local_c);
        }
      }
      else {
        if (local_c[2] == -0x22222223) {
          local_18 = (byte *)0x0;
        }
        else {
          local_18 = *(byte **)local_c[2];
        }
        if (((local_18 != (byte *)0x0) && (local_18[1] != 5)) && (local_18[1] != 7)) {
          if (*(char *)((int)local_c + 0x17) == '\0') {
            if ((*(char *)((int)local_c + 0x13) == '\0') &&
               (local_10 = FUN_0047a5d0((int)local_18), local_10 != -1)) {
              if (*(char *)(DAT_004e89f0 + 5 + local_10 * 0x20) == '\0') {
                if (((*local_18 & 2) == 0) &&
                   (*(undefined1 *)((int)local_c + 0x15) = 0, *(char *)((int)local_c + 0x12) == '\0'
                   )) {
                  if (*(char *)((int)local_c + 0x16) == '\x01') {
                    FUN_00479e60((int)local_c);
                    *(undefined1 *)((int)local_c + 0x16) = 0;
                  }
                  else {
                    *(undefined1 *)((int)local_c + 0x16) = 1;
                    *(undefined1 *)((int)local_c + 0x15) = 0;
                  }
                }
              }
              else {
                uVar1 = FUN_00452860((int)local_18,4000);
                *(undefined1 *)((int)local_c + 0x15) = uVar1;
                if ((*(char *)((int)local_c + 0x15) == '\x01') && ((*local_18 & 2) != 0)) {
                  FUN_00479de0((int)local_c);
                  *(undefined1 *)((int)local_c + 0x16) = 0;
                }
              }
            }
          }
          else if (*(char *)((int)local_c + 0x17) == '\x01') {
            FUN_00479e60((int)local_c);
            *(undefined1 *)((int)local_c + 0x17) = 0;
          }
          else {
            *(undefined1 *)((int)local_c + 0x15) = 0;
            *(undefined1 *)((int)local_c + 0x17) = 1;
          }
        }
      }
    }
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  if (DAT_004e8703 != '\0') {
    FUN_0047a110();
  }
  if (DAT_004e8702 != '\0') {
    FUN_00479ee0();
  }
  local_8 = 0x47aa3d;
  __chkesp();
  return;
}

