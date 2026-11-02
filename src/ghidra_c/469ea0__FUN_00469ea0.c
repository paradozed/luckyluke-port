/* FUN_00469ea0 @ 00469ea0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00469ea0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (**(char **)(*(int *)(*DAT_004f2458 + 0xe4) + 0x14) != '\x02') {
    DAT_004f23c4 = FUN_00469ef0;
    DAT_004f23f8 = FUN_00466900;
  }
  return;
}

