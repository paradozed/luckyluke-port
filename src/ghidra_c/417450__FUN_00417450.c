/* FUN_00417450 @ 00417450 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00417450(undefined4 param_1,void *param_2)

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
  FUN_004074b0(param_2,5);
  FUN_004074b0(param_2,4);
  FUN_004074b0(param_2,3);
  FUN_004074b0(param_2,2);
  FUN_0041fb90();
  uStack_8 = 0x4174a9;
  __chkesp();
  return;
}

