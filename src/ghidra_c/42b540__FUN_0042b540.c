/* FUN_0042b540 @ 0042b540 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042b540(undefined4 *param_1)

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
  FUN_00497690(&DAT_004f7320,(undefined4 *)*param_1,0x50);
  FUN_00497690(&DAT_004f7380,(undefined4 *)param_1[1],0x2cc);
  uStack_8 = 0x42b598;
  __chkesp();
  return;
}

