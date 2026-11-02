/* FUN_0046c9d0 @ 0046c9d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046c9d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004f245c & 0x2000) != 0) {
    DAT_004f2294 = FUN_0046caf0;
    FUN_0046caf0();
  }
  uStack_8 = 0x46ca15;
  __chkesp();
  return;
}

