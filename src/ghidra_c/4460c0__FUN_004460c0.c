/* FUN_004460c0 @ 004460c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004460c0(int param_1,ushort param_2,char param_3,ushort param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_3 == '\0') {
    *(byte *)(param_1 + 7) = *(byte *)(param_1 + 7) & 0xfd;
  }
  else {
    *(byte *)(param_1 + 7) = *(byte *)(param_1 + 7) | 2;
  }
  *(ushort *)(param_1 + 0x16) = param_4 & 0xff9f | (param_2 & 3) << 5;
  return;
}

