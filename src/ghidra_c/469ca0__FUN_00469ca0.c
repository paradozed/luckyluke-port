/* FUN_00469ca0 @ 00469ca0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00469ca0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  uint local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = param_1 & 0xffff;
  if (local_18 == 0) {
    if (DAT_004e883c != 0) {
      DAT_004e883c = 0;
      DAT_004f23c4 = FUN_00469ef0;
      DAT_004f23b8 = (code *)0x0;
      DAT_004f23f8 = FUN_00466900;
      DAT_004f23c0 = FUN_0046a260;
      local_14 = *(int *)(*DAT_004f2458 + 0x90);
      local_10 = *(undefined4 *)(*DAT_004f2458 + 0x94);
      local_c = *(undefined4 *)(*DAT_004f2458 + 0x98);
      FUN_00457740(*DAT_004f2458,*(int *)(*DAT_004f2458 + 0xe4),&local_14);
    }
  }
  else if ((local_18 == 1) && (DAT_004e883c == 0)) {
    DAT_004e883c = 1;
    DAT_004f23c4 = FUN_00468570;
    DAT_004f23b8 = FUN_00465a40;
    DAT_004f23f8 = FUN_00468650;
    DAT_004f23c0 = FUN_00465a40;
  }
  uStack_8 = 0x469dbf;
  __chkesp();
  return;
}

