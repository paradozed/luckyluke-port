/* FUN_00433f50 @ 00433f50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00433f50(HWND param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DialogBoxParamA(DAT_004f5b74,(LPCSTR)0x72,param_1,FUN_00433e00,0);
  __chkesp();
  uStack_8 = 0x433f98;
  __chkesp();
  return;
}

