/* FUN_004318a0 @ 004318a0 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004318a0(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (*DAT_004f58a8 == 0x536f6674) {
    uVar1 = param_3 | param_2 << 6 | param_1 << 0xb;
  }
  else {
    uVar1 = param_3 | param_2 << 5 | param_1 << 10 | param_4 << 0xf;
  }
  return uVar1;
}

