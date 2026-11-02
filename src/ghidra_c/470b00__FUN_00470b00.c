/* FUN_00470b00 @ 00470b00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470b00(int param_1,short param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != 0) {
    *(short *)(param_1 + 0x38) = (short)((param_2 * 0x32) / 0x3c);
  }
  return;
}

