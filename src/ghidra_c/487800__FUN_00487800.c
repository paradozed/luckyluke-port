/* FUN_00487800 @ 00487800 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00487800(int param_1)

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
  (*(code *)PTR_FUN_004c64d4)(param_1);
  __chkesp();
  FUN_00487760(param_1);
  uStack_8 = 0x487847;
  __chkesp();
  return;
}

