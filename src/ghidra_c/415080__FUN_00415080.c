/* FUN_00415080 @ 00415080 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415080(undefined4 param_1,void *param_2)

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
    FUN_0044a0d0();
  }
  else {
    FUN_0044a040();
  }
  uStack_8 = 0x4150c2;
  __chkesp();
  return;
}

