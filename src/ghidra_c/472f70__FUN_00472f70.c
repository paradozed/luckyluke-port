/* FUN_00472f70 @ 00472f70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00472f70(ushort param_1)

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
  local_8 = (undefined4 *)FUN_00439a90(DAT_004e85ec,8);
  _memset(local_8,0,8);
  uVar1 = FUN_00439a90(DAT_004e85ec,(uint)param_1 << 2);
  *local_8 = uVar1;
  _memset((void *)*local_8,0,(uint)param_1 << 2);
  *(ushort *)((int)local_8 + 6) = param_1;
  local_8 = (undefined4 *)0x473003;
  __chkesp();
  return;
}

