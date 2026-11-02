/* FUN_0046d8e0 @ 0046d8e0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_0046d8e0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004be100 = DAT_004be100 + 1;
  (&DAT_004f2260)[DAT_004be100] = param_1;
  return DAT_004be100;
}

