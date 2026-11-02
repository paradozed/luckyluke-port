/* FUN_0042f8a0 @ 0042f8a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042f8a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e846c = DAT_004e846c ^ 1;
  return;
}

