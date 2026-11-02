/* FUN_004200e0 @ 004200e0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004200e0(char param_1)

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
  if ((DAT_004bcfd0 != 0) && (DAT_004d2884 != '\0')) {
    if (DAT_004d1f1f != '\0') {
      if (param_1 == '\x01') {
        _DAT_004d2888 = (uint)DAT_004d238c;
        FUN_00420240(0);
      }
      else {
        FUN_00420240((byte)_DAT_004d2888);
      }
    }
    DAT_004d1f1d = param_1;
  }
  uStack_8 = 0x420165;
  __chkesp();
  return;
}

