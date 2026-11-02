/* FUN_0045db80 @ 0045db80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045db80(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_34c [16];
  uint local_30c;
  undefined1 local_308 [256];
  undefined1 local_208 [256];
  undefined1 local_108 [256];
  undefined4 local_8;
  
  puVar2 = local_34c;
  for (iVar1 = 0xd2; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  if (DAT_004f2458 == (int *)0x0) {
    FUN_00497080(local_108,0x4b8034);
    FUN_004266b0();
  }
  else if ((*(int *)(*DAT_004f2458 + 0xe4) == 0) && (DAT_004e86fa == 0)) {
    FUN_00497080(local_208,0x4b8034);
    FUN_004266b0();
  }
  else if (DAT_004f23c4 != FUN_0046be30) {
    local_30c = param_1 & 0xffff;
    if (local_30c != 0) {
      if (local_30c == 1) {
        if (((DAT_004f2750 & 0x80) != 0) && (DAT_004e86fa != 0)) {
          DAT_004e86fa = DAT_004e86fa - 1;
          FUN_00469ca0((uint)DAT_004e86fa);
        }
        if (((DAT_004f2750 & 0x20) != 0) && ((&PTR_DAT_004bdb1c)[DAT_004e86fa] != (undefined *)0x0))
        {
          DAT_004e86fa = DAT_004e86fa + 1;
          FUN_00469ca0((uint)DAT_004e86fa);
        }
        FUN_00497080(local_308,0x4b8034);
        FUN_004266b0();
        goto LAB_0045ddef;
      }
      if (local_30c != 2) {
        FUN_00497610((byte *)"Error: File %s, Line %d");
        goto LAB_0045ddef;
      }
    }
    FUN_00497080(local_308,0x4b8034);
    FUN_004266b0();
  }
LAB_0045ddef:
  local_8 = 0x45ddff;
  __chkesp();
  return;
}

