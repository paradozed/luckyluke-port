/* FUN_004687b0 @ 004687b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004687b0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_00456150(DAT_004f2438);
  local_8 = CONCAT22(local_8._2_2_,(short)uVar1);
  if ((uVar1 & 0xffff) == 8) {
    DAT_004f23f8 = FUN_00468650;
    FUN_00468650();
  }
  else {
    *(undefined2 *)(DAT_004f2458 + 0xa4) = *(undefined2 *)(&DAT_004bdf80 + (uVar1 & 0xffff) * 2);
    if ((DAT_004f2438 & 0x4000) == 0) {
      DAT_004f23f8 = FUN_00468750;
      FUN_00468750();
    }
  }
  local_8 = 0x468848;
  __chkesp();
  return;
}

