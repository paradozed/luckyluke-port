/* FUN_00403800 @ 00403800 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl
FUN_00403800(short param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4,
            undefined1 *param_5,undefined1 *param_6,undefined1 *param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004d1d64 == 0) {
    uVar1 = 0;
  }
  else if ((param_1 < 1) || (DAT_004d1cdc < param_1)) {
    uVar1 = 0;
  }
  else if (DAT_004d1d68 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = DAT_004d1d68 + -6 + param_1 * 8;
    *param_2 = *(undefined1 *)(iVar2 + 2);
    *param_3 = *(undefined1 *)(iVar2 + 3);
    *param_4 = *(undefined1 *)(iVar2 + 4);
    *param_5 = *(undefined1 *)(iVar2 + 5);
    *param_6 = *(undefined1 *)(iVar2 + 6);
    *param_7 = *(undefined1 *)(iVar2 + 7);
    uVar1 = 1;
  }
  return uVar1;
}

