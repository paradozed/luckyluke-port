/* FUN_0041fbb0 @ 0041fbb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041fbb0(char param_1)

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
  if ((DAT_004bcfd0 != 0) && (param_1 != '\0')) {
    local_8 = *(int *)(&DAT_004d2390 + (uint)(byte)(param_1 - 1) * 0x10);
    FUN_00493790(local_8);
  }
  local_8 = 0x41fc2b;
  __chkesp();
  return;
}

