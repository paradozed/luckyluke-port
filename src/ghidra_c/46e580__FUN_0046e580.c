/* FUN_0046e580 @ 0046e580 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046e580(PVOID param_1)

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
  FUN_00439c30(*(PVOID *)((int)param_1 + 4));
  FUN_00439c30(param_1);
  uStack_8 = 0x46e5c0;
  __chkesp();
  return;
}

