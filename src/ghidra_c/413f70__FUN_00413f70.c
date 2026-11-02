/* FUN_00413f70 @ 00413f70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00413f70(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  DAT_004f2c7b = DAT_004f2c6c;
  uVar1 = FUN_004074b0(param_2,2);
  DAT_004f2800 = (undefined1)uVar1;
  uStack_8 = 0x413fba;
  DAT_004f2c6c = DAT_004f2800;
  __chkesp();
  return;
}

