/* FUN_00439c90 @ 00439c90 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_00439c90(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  uVar1 = DAT_004e84e4;
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  DAT_004e84e4 = param_1;
  return uVar1;
}

