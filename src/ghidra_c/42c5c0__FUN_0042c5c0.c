/* FUN_0042c5c0 @ 0042c5c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042c5c0(byte *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_70 [17];
  undefined4 local_2c [6];
  short local_12;
  undefined4 uStack_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((*(int *)(&DAT_004f6140 + (uint)*param_1 * 4) != 0) && (*param_1 != 0x20)) {
    FUN_00497690(local_2c,*(undefined4 **)(&DAT_004f6544 + (uint)*param_1 * 0xc),0x28);
    local_12 = (short)(((longlong)
                        (int)(((longlong)(int)local_12 * (longlong)DAT_004be3cc & 0xffffffffU) /
                             0x1e0) * (longlong)DAT_004bcfe4 & 0xffffffffU) / 100);
  }
  uStack_8 = 0x42c667;
  __chkesp();
  return;
}

