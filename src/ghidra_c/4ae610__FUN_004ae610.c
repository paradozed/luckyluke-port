/* FUN_004ae610 @ 004ae610 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_004ae610(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = DAT_004e8ee8;
  puVar2 = (undefined4 *)FUN_00494840(0x10);
  if (puVar2 == (undefined4 *)0x0) {
    OutputDebugStringA(s_ERROR_>_iEnumDisplayMode___goAll_004c7fc0);
    do {
      iVar3 = FUN_004ae250(s_Pt______void___0__004c8018,0x4c7fe8,0x37);
    } while (iVar3 != 0);
  }
  *puVar2 = *(undefined4 *)(param_1 + 0xc);
  puVar2[1] = *(undefined4 *)(param_1 + 8);
  puVar2[2] = *(undefined4 *)(param_1 + 0x54);
  puVar2[3] = uVar1;
  DAT_004e8ee8 = puVar2;
  return 1;
}

