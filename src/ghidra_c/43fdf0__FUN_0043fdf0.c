/* FUN_0043fdf0 @ 0043fdf0 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_0043fdf0(void)

{
  uint uVar1;
  uint3 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  uint local_8;
  
  uVar1 = 0xcccccccc;
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = 0;
  while( true ) {
    uVar2 = (uint3)(uVar1 >> 8);
    if (0xff < local_8) {
      return (uint)uVar2 << 8;
    }
    if (((&DAT_004f58c0)[local_8] & 0x80) != 0) break;
    uVar1 = local_8 + 1;
    local_8 = uVar1;
  }
  return CONCAT31(uVar2,1);
}

