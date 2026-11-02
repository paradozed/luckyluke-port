/* FUN_0046dbe0 @ 0046dbe0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046dbe0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  code *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (code *)(&DAT_004f2260)[param_1];
  (*local_8)(param_1);
  local_8 = (code *)0x46dc1e;
  __chkesp();
  return;
}

