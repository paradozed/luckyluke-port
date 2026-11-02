/* FUN_004b08e1 @ 004b08e1 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004b08e1(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    OutputDebugStringA(s_ERROR_>_goW95PrimGetCurClip___pr_004c8888);
    do {
      iVar1 = FUN_004ae250(s_prect______void___0__004c88e4,0x4c88b4,0x166);
    } while (iVar1 != 0);
  }
  *param_1 = DAT_0050a2c8;
  param_1[2] = DAT_0050a2c4;
  param_1[1] = DAT_0050a2c0;
  param_1[3] = DAT_0050a2bc;
  return 1;
}

