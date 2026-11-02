/* FUN_0047f6d0 @ 0047f6d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047f6d0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  undefined2 local_1c [2];
  undefined2 local_18;
  undefined2 local_14;
  int local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; local_8 = param_3, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (local_8 = local_8 + -1, -1 < local_8) {
    FUN_004826e0((short *)(param_1 + local_8 * 8),(int *)local_1c);
    *(undefined2 *)(param_2 + local_8 * 8) = local_1c[0];
    *(undefined2 *)(param_2 + 2 + local_8 * 8) = local_18;
    *(undefined2 *)(param_2 + 4 + local_8 * 8) = local_14;
  }
  local_8 = 0x47f757;
  __chkesp();
  return;
}

