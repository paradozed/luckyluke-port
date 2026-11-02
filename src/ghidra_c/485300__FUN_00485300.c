/* FUN_00485300 @ 00485300 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00485300(ushort *param_1,undefined2 param_2)

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
  do {
    (**(code **)(&DAT_00507fa8 + (uint)*param_1 * 0x34))(param_1,param_2);
    __chkesp();
    param_1 = *(ushort **)(param_1 + 8);
  } while (param_1 != (ushort *)0x0);
  uStack_8 = 0x48535a;
  __chkesp();
  return;
}

