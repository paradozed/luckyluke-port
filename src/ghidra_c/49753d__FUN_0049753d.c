/* FUN_0049753d @ 0049753d */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_0049753d(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint extraout_EAX;
  bool in_ZF;
  ushort in_FPUControlWord;
  undefined4 unaff_retaddr;
  
  if (in_ZF) {
    if (((param_2 & 0xfffff) != 0) || (param_1 != 0)) {
      uVar2 = FUN_0049f5dc();
      goto LAB_004975bb;
    }
    uVar2 = 0;
    uVar1 = param_2 & 0x80000000;
joined_r0x004975ac:
    if (uVar1 == 0) {
LAB_0049755e:
      if (DAT_004e8c5c != 0) {
        return uVar2;
      }
      uVar2 = __math_exit(&DAT_004c6ef0,5,unaff_retaddr,param_1,param_2);
      return uVar2;
    }
  }
  else {
    uVar2 = param_2;
    if (in_FPUControlWord != 0x27f) {
      uVar2 = FUN_0049f5c5();
    }
    if ((uVar2 & 0x80000000) == 0) goto LAB_0049755e;
    if (((uVar2 & 0x7ff00000) == 0) && (uVar1 = param_1, (uVar2 & 0xfffff) == 0))
    goto joined_r0x004975ac;
  }
  uVar2 = 1;
LAB_004975bb:
  if (DAT_004e8c5c != 0) {
    return uVar2;
  }
  __startOneArgErrorHandling(&DAT_004c6ef0,5,in_FPUControlWord,unaff_retaddr,param_1,param_2);
  return extraout_EAX;
}

