/* FUN_0047d4e0 @ 0047d4e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047d4e0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  byte *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (byte *)FUN_00439af0(0xe8);
  FUN_00497690((undefined4 *)local_8,param_1,0xe8);
  *(undefined4 **)(local_8 + 8) = param_1;
  *local_8 = *local_8 & 0xfd;
  local_8 = (byte *)0x47d543;
  __chkesp();
  return;
}

