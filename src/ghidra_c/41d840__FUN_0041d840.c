/* FUN_0041d840 @ 0041d840 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041d840(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int local_10;
  byte *local_c;
  ushort *local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(ushort **)(param_1 + 8);
  if ((char)local_8[1] == '\x01') {
    for (local_10 = 0; local_10 < (int)(uint)*local_8; local_10 = local_10 + 1) {
      local_c = *(byte **)(local_8 + local_10 * 2 + 2);
      if (local_c != (byte *)0x0) {
        FUN_004803f0(local_c);
      }
    }
  }
  local_8 = (ushort *)0x41d8bb;
  __chkesp();
  return;
}

