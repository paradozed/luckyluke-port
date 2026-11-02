/* FUN_00451860 @ 00451860 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00451860(short param_1,char param_2)

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
  FUN_00451740(*(short *)(&DAT_004bd0e8 + param_1 * 8));
  if (param_2 == '\x01') {
    FUN_00451740(*(short *)(&DAT_004bd0ec + param_1 * 8));
    FUN_00451740(*(short *)(&DAT_004bd0ee + param_1 * 8));
  }
  uStack_8 = 0x4518d2;
  __chkesp();
  return;
}

