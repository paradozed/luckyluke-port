/* FUN_0046bd50 @ 0046bd50 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046bd50(void)

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
  *(undefined2 *)(DAT_004f2458 + 0x29) = *(undefined2 *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58);
  *(undefined2 *)((int)DAT_004f2458 + 0xa6) = *(undefined2 *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x5a)
  ;
  DAT_004f2400 = FUN_0046a8f0;
  DAT_004f2404 = DAT_004f2458[0x2f];
  DAT_004f23fc = DAT_004f2458[0x30];
  DAT_004f245e = 0;
  DAT_004f23bc = 0;
  (**(code **)(*(int *)(*DAT_004f2458 + 0xd0) + 4))(*DAT_004f2458);
  __chkesp();
  DAT_004f23c4 = FUN_0046be30;
  FUN_0046be30();
  __chkesp();
  uStack_8 = 0x46be2b;
  __chkesp();
  return;
}

