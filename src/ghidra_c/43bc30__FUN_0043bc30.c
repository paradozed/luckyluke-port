/* FUN_0043bc30 @ 0043bc30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043bc30(int *param_1)

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
  FUN_0043a600(param_1);
  FUN_0043a640(param_1);
  FUN_0043bab0((int)param_1);
  FUN_0043bb60((int)param_1);
  uStack_8 = 0x43bc85;
  __chkesp();
  return;
}

