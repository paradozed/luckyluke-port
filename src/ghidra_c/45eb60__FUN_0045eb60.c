/* FUN_0045eb60 @ 0045eb60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045eb60(undefined4 param_1,byte param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  undefined *local_10;
  undefined *local_c;
  uint local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = local_8 & 0xffffff00;
  (&DAT_004f274c)[(uint)param_2 * 6] = 0;
  (&DAT_004f2750)[(uint)param_2 * 6] = 0;
  (&DAT_004f2744)[(uint)param_2 * 6] = 0;
  local_c = PTR_DAT_004bdce4;
  local_10 = PTR_DAT_004bdce4;
  if (DAT_004e8974 == '\x02') {
    if (*(int *)(&DAT_004f2608 + (uint)param_2 * 0x14) == 0) {
      uVar1 = FUN_00472780((ushort)param_2);
      *(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18) = uVar1 & 0xffff;
    }
    else {
      FUN_00472700();
    }
  }
  else {
    *(undefined4 *)(&DAT_004f2740 + (uint)param_2 * 0x18) =
         *(undefined4 *)(&DAT_004f2608 + (uint)param_2 * 0x14);
  }
  if (((*(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18) & 0x20) != 0) &&
     ((*(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18) & 0x80) != 0)) {
    *(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18) =
         *(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18) & 0xffffff5f;
  }
  if (((*(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18) & 0x10) != 0) &&
     ((*(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18) & 0x40) != 0)) {
    *(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18) =
         *(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18) & 0xffffffaf;
  }
  (&DAT_004f274c)[(uint)param_2 * 6] =
       ((&DAT_004f2748)[(uint)param_2 * 6] ^ *(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18)) &
       ~(&DAT_004f2748)[(uint)param_2 * 6];
  local_8 = local_8 & 0xffffff00;
  while ((local_8 & 0xff) < 0x10) {
    if ((*(uint *)(local_10 + (local_8 & 0xff) * 4) &
        *(uint *)(&DAT_004f2740 + (uint)param_2 * 0x18)) != 0) {
      (&DAT_004f2744)[(uint)param_2 * 6] =
           (&DAT_004f2744)[(uint)param_2 * 6] | *(uint *)(local_c + (local_8 & 0xff) * 4);
    }
    if ((*(uint *)(local_10 + (local_8 & 0xff) * 4) & (&DAT_004f274c)[(uint)param_2 * 6]) != 0) {
      (&DAT_004f2750)[(uint)param_2 * 6] =
           (&DAT_004f2750)[(uint)param_2 * 6] | *(uint *)(local_c + (local_8 & 0xff) * 4);
    }
    local_8 = CONCAT31(local_8._1_3_,(char)local_8 + '\x01');
  }
  (&DAT_004f2748)[(uint)param_2 * 6] = *(undefined4 *)(&DAT_004f2740 + (uint)param_2 * 0x18);
  if ((DAT_004e8584 != 0) && (DAT_004e8974 == '\x01')) {
    FUN_00472a00((ushort)param_2,*(short *)(&DAT_004f2740 + (uint)param_2 * 0x18));
  }
  local_8 = 0x45ee88;
  __chkesp();
  return;
}

