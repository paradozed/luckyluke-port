/* FUN_0041e560 @ 0041e560 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0041e560(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 *puVar2;
  float10 fVar3;
  longlong lVar4;
  undefined4 local_54 [16];
  double local_14;
  int local_c;
  uint local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = local_8 & 0xffffff00;
  while ((local_8 & 0xff) < 100) {
    local_c = 100 - (local_8 & 0xff);
    fVar3 = (float10)FUN_00497a74(local_8 & 0xff);
    local_14 = (double)fVar3;
    FUN_00497a74(extraout_ECX);
    lVar4 = __ftol();
    (&DAT_004d1eb8)[local_8 & 0xff] = (char)lVar4;
    local_8 = CONCAT31(local_8._1_3_,(char)local_8 + '\x01');
  }
  DAT_004d1f1c = 100;
  local_8 = 0x41e603;
  __chkesp();
  return;
}

