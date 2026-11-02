/* FUN_00407080 @ 00407080 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00407080(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = (int)sVar1;
  FUN_00497534(extraout_ECX);
  __ftol();
  local_8 = 0x4070cb;
  __chkesp();
  return;
}

