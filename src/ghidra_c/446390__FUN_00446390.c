/* FUN_00446390 @ 00446390 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00446390(short param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004f2e04 = (undefined4 *)FUN_00439a90(DAT_004e85ec,0x14);
  iVar1 = ((int)param_1 << 8) / DAT_004be3cc;
  *DAT_004f2e04 = 0;
  DAT_004f2e04[1] = 0;
  DAT_004f2e04[2] = 0;
  DAT_004f2e04[3] = 0;
  *(undefined1 *)((int)DAT_004f2e04 + 0x12) = 0;
  *(short *)(DAT_004f2e04 + 4) = -(short)iVar1;
  local_8 = 0x446421;
  __chkesp();
  return;
}

