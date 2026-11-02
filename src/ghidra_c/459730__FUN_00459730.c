/* FUN_00459730 @ 00459730 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00459730(ushort *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (((DAT_004f2750 & 0x10) != 0) && (*param_1 != 0)) {
    *param_1 = *param_1 - 1;
  }
  if (((DAT_004f2750 & 0x40) != 0) && ((uint)*param_1 != (param_2 & 0xffff) - 1)) {
    *param_1 = *param_1 + 1;
  }
  return;
}

