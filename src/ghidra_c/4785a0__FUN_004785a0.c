/* FUN_004785a0 @ 004785a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004785a0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [17];
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (local_8 = param_2 + -1, -1 < local_8) {
    iVar1 = param_3 + local_8 * 0x20;
    param_2 = local_8;
    if ((((*(char *)(iVar1 + 0xc) == *(char *)(iVar1 + 0x14)) &&
         (*(char *)(iVar1 + 0x14) == *(char *)(iVar1 + 0x1c))) &&
        (*(char *)(iVar1 + 0xd) == *(char *)(iVar1 + 0x15))) &&
       (*(char *)(iVar1 + 0x15) == *(char *)(iVar1 + 0x1d))) {
      *(char *)(iVar1 + 0x14) = *(char *)(iVar1 + 0x14) + '\x02';
      *(char *)(iVar1 + 0x1c) = *(char *)(iVar1 + 0x1c) + '\x02';
      *(char *)(iVar1 + 0x1d) = *(char *)(iVar1 + 0x1d) + '\x02';
    }
  }
  return;
}

