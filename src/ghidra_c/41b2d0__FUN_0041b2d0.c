/* FUN_0041b2d0 @ 0041b2d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041b2d0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(int *)param_1[2];
  FUN_0041b320(local_8,6);
  *param_1 = FUN_0047aba0;
  local_8 = 0x41b317;
  __chkesp();
  return;
}

