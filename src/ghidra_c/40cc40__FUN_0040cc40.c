/* FUN_0040cc40 @ 0040cc40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040cc40(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  if (sVar1 == 0) {
    DAT_004f23f8 = FUN_00466900;
  }
  else {
    DAT_004f23f8 = FUN_00465a40;
  }
  uStack_8 = 0x40cc90;
  __chkesp();
  return;
}

