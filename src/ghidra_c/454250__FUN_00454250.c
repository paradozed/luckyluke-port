/* FUN_00454250 @ 00454250 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00454250(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004f23f8 == FUN_00466740) {
    DAT_004f2bfc = DAT_004f2bfc + 1;
    if ((DAT_004f2bfc == DAT_004f2bfe) && (*param_1 != 0)) {
      DAT_004f2bf8 = 8;
    }
  }
  else {
    DAT_004f2bfc = 0;
  }
  return;
}

