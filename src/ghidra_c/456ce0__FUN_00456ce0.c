/* FUN_00456ce0 @ 00456ce0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00456ce0(ushort param_1,ushort param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (undefined4 *)FUN_00439a90(DAT_004e85ec,0x10);
  _memset(local_8,0,0x10);
  uVar1 = FUN_00439a90(DAT_004e85ec,(uint)param_1 * 0x14);
  *local_8 = uVar1;
  _memset((void *)*local_8,0,(uint)param_1 * 0x14);
  uVar1 = FUN_00439a90(DAT_004e85ec,(uint)param_2 * 0x60);
  local_8[1] = uVar1;
  _memset((void *)local_8[1],0,(uint)param_2 * 0x60);
  *(undefined2 *)(local_8 + 2) = 0;
  *(undefined2 *)((int)local_8 + 10) = 0;
  *(ushort *)(local_8 + 3) = param_1;
  *(ushort *)((int)local_8 + 0xe) = param_2;
  local_8 = (undefined4 *)0x456dcf;
  __chkesp();
  return;
}

