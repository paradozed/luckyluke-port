/* FUN_0045a550 @ 0045a550 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045a550(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1 & 0xffff;
  if (((local_8 != 0) && (local_8 != 1)) && (local_8 != 2)) {
    FUN_00497610((byte *)"Error: File %s, Line %d");
  }
  local_8 = 0x45a5b7;
  __chkesp();
  return;
}

