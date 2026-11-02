/* FUN_0042c050 @ 0042c050 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042c050(char *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  int local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_00458ec0();
  for (local_8 = 0; local_8 < param_3; local_8 = local_8 + 1) {
    uVar1 = FUN_00432d90(param_1,*(uint **)(param_2 + local_8 * 8));
    *(undefined4 *)(&DAT_004f6140 + (uint)*(byte *)(param_2 + 4 + local_8 * 8) * 4) = uVar1;
    if (*(int *)(&DAT_004f6140 + (uint)*(byte *)(param_2 + 4 + local_8 * 8) * 4) == 0)
    goto LAB_0042c261;
  }
  FUN_00458ec0();
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_004f6140 + local_8 * 4) == 0) {
      _memset(&DAT_004f6540 + local_8 * 0xc,0,0xc);
    }
    else {
      *(undefined4 *)(&DAT_004f6540 + local_8 * 0xc) = *(undefined4 *)(&DAT_004f6140 + local_8 * 4);
      local_10 = *(int *)(&DAT_004f6140 + local_8 * 4);
      local_c = FUN_00494c40(0x28,1);
      if (local_c == 0) break;
      *(undefined1 *)(local_c + 6) = 0xff;
      *(undefined1 *)(local_c + 5) = 0xff;
      *(undefined1 *)(local_c + 4) = 0xff;
      *(undefined2 *)(local_c + 8) = 0;
      *(undefined2 *)(local_c + 10) = 0;
      *(undefined2 *)(local_c + 0x10) = *(undefined2 *)(local_10 + 4);
      *(undefined2 *)(local_c + 0x12) = 0;
      *(undefined2 *)(local_c + 0x18) = 0;
      *(undefined2 *)(local_c + 0x1a) = *(undefined2 *)(local_10 + 6);
      *(undefined2 *)(local_c + 0x20) = *(undefined2 *)(local_10 + 4);
      *(undefined2 *)(local_c + 0x22) = *(undefined2 *)(local_10 + 6);
      *(undefined1 *)(local_c + 0xc) = 0;
      *(undefined1 *)(local_c + 0xd) = 0;
      *(char *)(local_c + 0x14) = (char)*(undefined2 *)(local_10 + 4) + -1;
      *(undefined1 *)(local_c + 0x15) = 0;
      *(undefined1 *)(local_c + 0x1c) = 0;
      *(char *)(local_c + 0x1d) = (char)*(undefined2 *)(local_10 + 6) + -1;
      *(char *)(local_c + 0x24) = (char)*(undefined2 *)(local_10 + 4) + -1;
      *(char *)(local_c + 0x25) = (char)*(undefined2 *)(local_10 + 6) + -1;
      *(int *)(&DAT_004f6544 + local_8 * 0xc) = local_c;
      (&DAT_004f6548)[local_8 * 0xc] = 3;
    }
  }
LAB_0042c261:
  local_8 = 0x42c26e;
  __chkesp();
  return;
}

