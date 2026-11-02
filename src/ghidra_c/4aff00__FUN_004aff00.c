/* FUN_004aff00 @ 004aff00 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_004aff00(undefined4 *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  undefined4 unaff_EDI;
  
  uVar1 = (uint)DAT_004c84b8;
  puVar2 = (uint *)FUN_004b1d40(DAT_0050ab24,0x8c,unaff_EDI);
  if (puVar2 == (uint *)0x0) {
    OutputDebugStringA(s_ERROR_>_iEnumDisplayDevice___goA_004c84bc);
    do {
      iVar3 = FUN_004ae250(s_Pt______void___0__004c8518,0x4c84e8,0x21);
    } while (iVar3 != 0);
  }
  FUN_00497270(puVar2,param_2);
  FUN_00497270(puVar2 + 0x19,param_3);
  if (param_1 == (undefined4 *)0x0) {
    _memset(puVar2 + 0x1e,0,0x10);
  }
  else {
    FUN_00497690(puVar2 + 0x1e,param_1,0x10);
  }
  puVar2[0x22] = uVar1;
  DAT_004c84b8 = puVar2;
  return 1;
}

