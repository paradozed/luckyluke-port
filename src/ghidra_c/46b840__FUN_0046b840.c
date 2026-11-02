/* FUN_0046b840 @ 0046b840 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046b840(void)

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
  if ((DAT_004f245c & 0x80) == 0) {
    if ((DAT_004f245c & 0x20) == 0) {
      if ((DAT_004f2438 & 0x40) == 0) {
        DAT_004f23f8 = FUN_0046b040;
        FUN_0046b040();
      }
      else if ((DAT_004f2458[4] & 0x20U) == 0) {
        DAT_004f23f8 = FUN_0046bcf0;
        FUN_0046bcf0();
      }
      else if ((DAT_004f245c & 0x8000) == 0) {
        if ((DAT_004f29ac == '\0') && (**(char **)(*(int *)(*DAT_004f2458 + 0xe4) + 0x14) == '\x03')
           ) {
          DAT_004f23f8 = FUN_0046ac90;
          FUN_0046ac90();
        }
      }
      else {
        DAT_004f23f8 = FUN_0046ba90;
        FUN_0046ba90();
      }
    }
    else {
      DAT_004f23f8 = FUN_0046b530;
      FUN_0046b530();
    }
  }
  else {
    DAT_004f23f8 = FUN_0046b7b0;
    FUN_0046b7b0();
  }
  uStack_8 = 0x46b947;
  __chkesp();
  return;
}

