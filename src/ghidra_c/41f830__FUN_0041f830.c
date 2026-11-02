/* FUN_0041f830 @ 0041f830 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041f830(char param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  ushort local_14 [2];
  ushort local_10 [2];
  int local_c;
  uint local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((DAT_004bcfd0 != 0) && (DAT_004d2883 != '\0')) {
    DAT_004d2388 = param_1;
    if (param_1 == '\x01') {
      local_8 = (uint)local_8._1_3_ << 8;
      while ((local_8 & 0xff) < 0x40) {
        if ((&DAT_004d239c)[(local_8 & 0xff) * 0x10] != '\x04') {
          local_c = *(int *)(&DAT_004d2390 + (local_8 & 0xff) * 0x10);
          FUN_004935e0(local_c,1,0);
          FUN_004935e0(local_c,2,0);
        }
        local_8 = CONCAT31(local_8._1_3_,(char)local_8 + '\x01');
      }
    }
    else {
      local_8 = (uint)local_8._1_3_ << 8;
      while ((local_8 & 0xff) < 0x40) {
        local_c = *(int *)(&DAT_004d2390 + (local_8 & 0xff) * 0x10);
        if (((&DAT_004d239c)[(local_8 & 0xff) * 0x10] != '\x04') &&
           (((&DAT_004d2394)[(local_8 & 0xff) * 0x10] == '\x01' ||
            (cVar1 = FUN_00493790(local_c), cVar1 == '\x01')))) {
          FUN_00420580((local_8 & 0xff) + 1,*(ushort *)(&DAT_004d2398 + (local_8 & 0xff) * 0x10),
                       CONCAT22((short)((uint)local_14 >> 0x10),
                                *(undefined2 *)(&DAT_004d239a + (local_8 & 0xff) * 0x10)),local_10,
                       local_14);
          FUN_004935e0(local_c,1,local_10[0]);
          FUN_004935e0(local_c,2,local_14[0]);
        }
        local_8 = CONCAT31(local_8._1_3_,(char)local_8 + '\x01');
      }
    }
  }
  local_8 = 0x41f9e5;
  __chkesp();
  return;
}

