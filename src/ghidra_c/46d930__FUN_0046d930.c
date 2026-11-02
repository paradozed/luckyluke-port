/* FUN_0046d930 @ 0046d930 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_0046d930(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 == 2) {
    DAT_004be100 = DAT_004be100 + -1;
    DAT_004f2268 = 0;
  }
  else {
    DAT_004be100 = DAT_004be100 + -1;
    (&DAT_004f2260)[param_1] = (&DAT_004f2260)[DAT_004be100];
  }
  return 1;
}

