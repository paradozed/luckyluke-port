/* FUN_00420240 @ 00420240 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00420240(byte param_1)

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
  if ((DAT_004bcfd0 != 0) && (DAT_004d2884 != '\0')) {
    DAT_004d238c = param_1;
    FUN_00403d00((ushort)param_1);
  }
  uStack_8 = 0x420292;
  __chkesp();
  return;
}

