/* FUN_00469dd0 @ 00469dd0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00469dd0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [18];
  undefined2 local_c;
  undefined2 local_a;
  undefined4 local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  local_a = 0;
  local_8 = 0;
  if (**(char **)(*(int *)(*DAT_004f2458 + 0xe4) + 0x14) == '\x01') {
    *(undefined2 *)(DAT_004f2458 + 0x29) = *(undefined2 *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58);
    FUN_00467440(*DAT_004f2458,0,(short)DAT_004f2458[0x29],0);
  }
  else {
    DAT_004f23c4 = FUN_00469ef0;
    DAT_004f23f8 = FUN_00466900;
    DAT_004f245c = 0;
    DAT_004f2438 = 0;
  }
  local_8 = 0x469e93;
  __chkesp();
  return;
}

