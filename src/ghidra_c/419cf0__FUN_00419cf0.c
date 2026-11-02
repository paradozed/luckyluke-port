/* FUN_00419cf0 @ 00419cf0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00419cf0(int param_1,undefined2 *param_2)

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
  FUN_00419d30((undefined2 *)(param_1 + 0x14),param_2);
  uStack_8 = 0x419d28;
  __chkesp();
  return;
}

