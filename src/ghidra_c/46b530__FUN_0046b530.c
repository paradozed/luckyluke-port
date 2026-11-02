/* FUN_0046b530 @ 0046b530 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046b530(void)

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
  FUN_0041f7b0(DAT_004f23bc);
  FUN_0041fc80(DAT_004f23bc);
  DAT_004f23bc = 0;
  FUN_00466510(2,FUN_00465a40);
  FUN_004663b0(DAT_004f2404,2,FUN_00465a40);
  _DAT_004f2408 = DAT_004e89e0;
  DAT_004f23f8 = FUN_0046b350;
  FUN_0046b350();
  uStack_8 = 0x46b5b7;
  __chkesp();
  return;
}

