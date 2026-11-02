/* FUN_004428e0 @ 004428e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004428e0(LPCSTR param_1)

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
  RegSetValueExA(DAT_004e855c,param_1,0,4,&stack0x00000008,4);
  __chkesp();
  uStack_8 = 0x442929;
  __chkesp();
  return;
}

