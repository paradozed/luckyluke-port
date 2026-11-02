/* FUN_004a5b30 @ 004a5b30 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004a5b30(uint param_1,uint param_2)

{
  undefined4 in_EAX;
  uint uVar1;
  undefined2 in_FPUControlWord;
  
  uVar1 = FUN_004a5c00(CONCAT22((short)((uint)in_EAX >> 0x10),in_FPUControlWord));
  uVar1 = param_1 & param_2 | uVar1 & ~param_2;
  FUN_004a5d80(uVar1);
  return uVar1;
}

