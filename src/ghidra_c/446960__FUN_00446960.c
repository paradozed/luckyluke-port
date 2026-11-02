/* FUN_00446960 @ 00446960 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00446960(int param_1,undefined1 *param_2,undefined2 *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined2 extraout_var;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  undefined1 local_1c [12];
  uint local_10;
  int local_c;
  byte *local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = local_10 & 0xffffff00;
  if ((((*DAT_004e8310 & 1) != 0) && (param_1 != 0)) &&
     (local_8 = (byte *)FUN_004465c0(param_1,3), local_8 != (byte *)0x0)) {
    *(undefined2 *)(local_8 + 4) = *param_3;
    *(undefined2 *)(local_8 + 6) = param_3[1];
    *(undefined2 *)(local_8 + 8) = param_3[2];
    *(undefined2 *)(local_8 + 10) = param_3[3];
    local_8[0xc] = 0x80;
    local_8[0xd] = 0x80;
    local_8[0xe] = 0x80;
    *(undefined2 *)(local_8 + 2) = *(undefined2 *)(param_4 + 0xe);
    (*(code *)(&PTR_FUN_004bd020)[*local_8])(local_8 + 0xc,local_1c,param_1 + 0x15);
    __chkesp();
    do {
      local_c = *(int *)(local_8 + (local_10 & 0xff) * 4 + 0x1c);
      local_10 = CONCAT31(local_10._1_3_,(char)local_10 + '\x01');
      FUN_00426660();
      *(undefined1 *)(local_c + 0x18) = *param_2;
      *(undefined1 *)(local_c + 0x19) = param_2[2];
      *(undefined2 *)(local_c + 0x14) = *param_3;
      *(undefined2 *)(local_c + 0x16) = param_3[1];
      *(undefined2 *)(local_c + 0x1c) = *(undefined2 *)(param_2 + 4);
      *(undefined2 *)(local_c + 0x1e) = *(undefined2 *)(param_2 + 6);
      *(undefined2 *)(local_c + 0x1a) = *(undefined2 *)(param_5 + 0xc);
      (*(code *)(&PTR_FUN_004bd010)[*local_8])(local_c,local_1c);
      __chkesp();
      FUN_00426640();
      FUN_00426680();
      (*(code *)(&PTR_FUN_004bd030)[*local_8])
                (local_c,*(byte *)(param_1 + 0x19) & 0xfb,(int)(*(byte *)(param_1 + 0x19) & 4) >> 2,
                 CONCAT22(extraout_var,*(undefined2 *)(local_8 + 2)));
      __chkesp();
    } while ((local_10 & 0xff) < 2);
  }
  local_8 = (byte *)0x446b88;
  __chkesp();
  return;
}

