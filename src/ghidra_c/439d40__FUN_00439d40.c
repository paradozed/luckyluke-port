/* FUN_00439d40 @ 00439d40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439d40(undefined4 *param_1)

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
  _memset(param_1,0,0x40);
  *param_1 = 0x3f800000;
  param_1[5] = 0x3f800000;
  param_1[10] = 0x3f800000;
  param_1[0xf] = 0x3f800000;
  uStack_8 = 0x439d9c;
  __chkesp();
  return;
}

