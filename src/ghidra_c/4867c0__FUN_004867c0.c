/* FUN_004867c0 @ 004867c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004867c0(ushort param_1,short param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar1 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  puVar1 = (undefined4 *)FUN_00486410(param_1,param_2);
  *puVar1 = DAT_004c6d60;
  puVar1[1] = DAT_004c6d64;
  puVar1[2] = DAT_004c6d68;
  local_8 = 0x486817;
  __chkesp();
  return;
}

