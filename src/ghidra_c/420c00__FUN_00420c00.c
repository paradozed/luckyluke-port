/* FUN_00420c00 @ 00420c00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00420c00(int param_1,undefined4 *param_2,uint param_3,int param_4)

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
  FUN_00497690(param_2,(undefined4 *)(param_1 + param_4),param_3);
  uStack_8 = 0x420c3f;
  __chkesp();
  return;
}

