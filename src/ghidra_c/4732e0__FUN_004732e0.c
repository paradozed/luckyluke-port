/* FUN_004732e0 @ 004732e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004732e0(ushort param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  ushort *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (ushort *)FUN_00439a90(DAT_004e85ec,0x14);
  *local_8 = param_1;
  uVar1 = FUN_00439a90(DAT_004e85ec,(uint)param_1 << 5);
  *(undefined4 *)(local_8 + 8) = uVar1;
  local_8 = (ushort *)0x473346;
  __chkesp();
  return;
}

