/* FUN_00473bf0 @ 00473bf0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00473bf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_84 [16];
  uint local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_84;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00497080((undefined1 *)local_44,0x4b88a0);
  FUN_0042c9e0(param_3,param_4,local_44);
  uStack_8 = 0x473c48;
  __chkesp();
  return;
}

