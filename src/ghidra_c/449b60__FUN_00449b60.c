/* FUN_00449b60 @ 00449b60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00449b60(uint *param_1,uint *param_2,int param_3)

{
  uint *_Str2;
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  size_t local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = _strlen((char *)param_1);
  _Str2 = FUN_004b2410(param_2);
  puVar1 = FUN_004b2410(param_1);
  _strcmp((char *)((int)puVar1 + (local_8 - param_3)),(char *)_Str2);
  local_8 = 0x449bbc;
  __chkesp();
  return;
}

