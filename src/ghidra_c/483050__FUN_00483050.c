/* FUN_00483050 @ 00483050 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00483050(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004e8aa8 = param_1;
  DAT_004e8aac = param_2;
  _DAT_00508820 = param_1 << 4;
  _DAT_00508824 = param_2 << 4;
  return;
}

