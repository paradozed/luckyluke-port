/* FUN_0041e930 @ 0041e930 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0041e930(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (((DAT_004d1f1f != 0) && (DAT_004d2884 != '\0')) && (DAT_004bcfd0 != 0)) {
    FUN_00458ec0();
    local_8 = FUN_00403c10();
    FUN_00458ec0();
    local_8 = FUN_004038b0((ushort)DAT_004d1f1f);
    FUN_00458ec0();
    local_8 = FUN_004039b0();
    FUN_00458ec0();
    timeGetTime();
    uVar1 = __chkesp();
    *(undefined4 *)(&DAT_004d1f40 + (uint)DAT_004d1f1f * 0x1c) = uVar1;
  }
  local_8 = 0x41ea06;
  __chkesp();
  return;
}

