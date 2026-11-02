/* FUN_00497a7d @ 00497a7d */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_00497a7d(int param_1,uint param_2)

{
  uint in_EAX;
  uint uVar1;
  uint extraout_EAX;
  bool in_ZF;
  ushort in_FPUControlWord;
  unkbyte10 in_ST0;
  undefined4 unaff_retaddr;
  
  if (!in_ZF) {
    if ((param_2 & 0x7ff00000) == 0) {
      if (((param_2 & 0xfffff) == 0) && (param_1 == 0)) {
        uVar1 = 2;
        goto LAB_00497b0d;
      }
    }
    else if ((param_2 & 0x80000000) != 0) goto LAB_00497adc;
    log2(in_ST0);
    uVar1 = param_2;
LAB_00497aaa:
    if (DAT_004e8c5c != 0) {
      return uVar1;
    }
    uVar1 = __math_exit(&DAT_004c6f00,0x1a,unaff_retaddr,param_1,param_2);
    return uVar1;
  }
  if (((in_EAX & 0xfffff) != 0) || (param_1 != 0)) {
    uVar1 = FUN_0049f5dc();
    goto LAB_00497b0d;
  }
  uVar1 = 0;
  if ((in_EAX & 0x80000000) == 0) goto LAB_00497aaa;
LAB_00497adc:
  uVar1 = 1;
LAB_00497b0d:
  if (DAT_004e8c5c != 0) {
    return uVar1;
  }
  __startOneArgErrorHandling(&DAT_004c6f00,0x1a,in_FPUControlWord,unaff_retaddr,param_1,param_2);
  return extraout_EAX;
}

