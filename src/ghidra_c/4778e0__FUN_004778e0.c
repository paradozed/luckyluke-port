/* FUN_004778e0 @ 004778e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004778e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 uStack_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00458ec0();
  FUN_004464f0(DAT_004f175c);
  uStack_8 = 0x477920;
  __chkesp();
  return;
}

