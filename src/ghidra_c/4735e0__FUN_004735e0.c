/* FUN_004735e0 @ 004735e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004735e0(undefined4 *param_1)

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
  if (*(char *)((int)param_1 + 0x11) != '\0') {
    (*(code *)*param_1)(param_1);
    __chkesp();
  }
  FUN_00473450((int)param_1);
  param_1[1] = FUN_00473450;
  uStack_8 = 0x47363c;
  __chkesp();
  return;
}

