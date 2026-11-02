/* FUN_00439540 @ 00439540 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439540(int param_1)

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
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00498130(*(int **)(param_1 + 0xc),
                 (byte *)"<FONT color=00AA00>Memory released at %x on line %d of %s</FONT><BR>\n");
    FUN_00499050(*(int **)(param_1 + 0xc));
  }
  uStack_8 = 0x43959f;
  __chkesp();
  return;
}

