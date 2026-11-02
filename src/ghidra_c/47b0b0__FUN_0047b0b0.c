/* FUN_0047b0b0 @ 0047b0b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047b0b0(uint *param_1)

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
  FUN_00497270((uint *)&DAT_00508880,param_1);
  uStack_8 = 0x47b0e6;
  __chkesp();
  return;
}

