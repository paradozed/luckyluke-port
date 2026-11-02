/* FUN_00442510 @ 00442510 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00442510(void)

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
  if ((DAT_004e8544 != (void *)0x0) && (DAT_004e8544 != (void *)0xdddddddd)) {
    FUN_00495280(DAT_004e8544);
  }
  if ((DAT_004e8548 != (void *)0x0) && (DAT_004e8548 != (void *)0xdddddddd)) {
    FUN_00495280(DAT_004e8548);
  }
  DAT_004e8544 = (void *)0x0;
  DAT_004e8548 = (void *)0x0;
  uStack_8 = 0x442590;
  __chkesp();
  return;
}

