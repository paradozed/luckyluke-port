/* FUN_0041e500 @ 0041e500 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0041e500(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004d1eb1 = 0;
  DAT_004d2389 = 1;
  DAT_004d1f1e = DAT_004f58ac;
  DAT_004d2882 = 1;
  DAT_004d238c = DAT_004f58a0;
  DAT_004d238a = 0x9c4;
  return;
}

