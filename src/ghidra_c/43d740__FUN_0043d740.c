/* FUN_0043d740 @ 0043d740 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043d740(int *param_1)

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
  FUN_0043a2f0((float *)(*param_1 + 0x18),(float *)(param_1 + 1));
  uStack_8 = 0x43d784;
  __chkesp();
  return;
}

