/* FUN_00488090 @ 00488090 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00488090(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8ae4 != 1000) {
    if (param_4 == 0) {
      *(undefined4 *)(DAT_004e8ae0 + DAT_004e8ae4 * 0xc) = param_1;
    }
    else {
      *(undefined4 *)(DAT_004e8ae0 + DAT_004e8ae4 * 0xc) = DAT_004e8ae8;
    }
    *(undefined4 *)(DAT_004e8ae0 + 4 + DAT_004e8ae4 * 0xc) = param_2;
    *(undefined4 *)(DAT_004e8ae0 + 8 + DAT_004e8ae4 * 0xc) = param_3;
    DAT_004e8ae4 = DAT_004e8ae4 + 1;
  }
  return;
}

