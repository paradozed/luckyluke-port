/* FUN_00413080 @ 00413080 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00413080(undefined4 param_1,void *param_2)

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
  DAT_004d1e5c = FUN_004074b0(param_2,2);
  DAT_004d1e5e = FUN_004074b0(param_2,3);
  DAT_004d1e60 = FUN_004074b0(param_2,4);
  DAT_004d1e62 = FUN_004074b0(param_2,5);
  DAT_004d1e64 = FUN_004074b0(param_2,6);
  DAT_004d1e66 = FUN_004074b0(param_2,7);
  DAT_004d1e68 = FUN_004074b0(param_2,8);
  DAT_004d1e6a = FUN_004074b0(param_2,9);
  uStack_8 = 0x413125;
  __chkesp();
  return;
}

