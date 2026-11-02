/* FUN_00446690 @ 00446690 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00446690(int param_1,char *param_2,short *param_3,int param_4,int param_5)

{
  int iVar1;
  undefined2 extraout_var;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  undefined1 local_18 [12];
  uint *local_c;
  byte *local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((((*DAT_004e8310 & 1) != 0) && (param_1 != 0)) &&
     (local_8 = (byte *)FUN_004465c0(param_1,0), local_8 != (byte *)0x0)) {
    *(short *)(local_8 + 4) = *param_3;
    *(short *)(local_8 + 6) = param_3[1];
    *(short *)(local_8 + 8) = param_3[2];
    *(short *)(local_8 + 10) = param_3[3];
    local_8[0xc] = 0x80;
    local_8[0xd] = 0x80;
    local_8[0xe] = 0x80;
    *(undefined2 *)(local_8 + 2) = *(undefined2 *)(param_4 + 0xe);
    local_c = *(uint **)(local_8 + 0x1c);
    *local_c = *local_c & 0xffffff | 0x9000000;
    *(undefined1 *)((int)local_c + 7) = 0x2c;
    *(char *)(local_c + 3) = *param_2;
    *(char *)((int)local_c + 0xd) = param_2[2];
    *(char *)(local_c + 5) = *param_2 + -1 + (char)*(undefined2 *)(param_2 + 4);
    *(char *)((int)local_c + 0x15) = param_2[2];
    *(char *)(local_c + 7) = *param_2;
    *(char *)((int)local_c + 0x1d) = param_2[2] + -1 + (char)*(undefined2 *)(param_2 + 6);
    *(char *)(local_c + 9) = *param_2 + -1 + (char)*(undefined2 *)(param_2 + 4);
    *(char *)((int)local_c + 0x25) = param_2[2] + -1 + (char)*(undefined2 *)(param_2 + 6);
    *(short *)(local_c + 2) = *param_3;
    *(short *)((int)local_c + 10) = param_3[1];
    *(short *)(local_c + 4) = *param_3 + param_3[2];
    *(short *)((int)local_c + 0x12) = param_3[1];
    *(short *)(local_c + 6) = *param_3;
    *(short *)((int)local_c + 0x1a) = param_3[1] + param_3[3];
    *(short *)(local_c + 8) = *param_3 + param_3[2];
    *(short *)((int)local_c + 0x22) = param_3[1] + param_3[3];
    *(undefined2 *)((int)local_c + 0x16) = *(undefined2 *)(local_8 + 2);
    *(undefined2 *)((int)local_c + 0xe) = *(undefined2 *)(param_5 + 0xc);
    (*(code *)(&PTR_FUN_004bd020)[*local_8])(local_8 + 0xc,local_18,param_1 + 0x15);
    __chkesp();
    (*(code *)(&PTR_FUN_004bd010)[*local_8])(local_c,local_18);
    __chkesp();
    (*(code *)(&PTR_FUN_004bd030)[*local_8])
              (local_c,*(byte *)(param_1 + 0x19) & 0xfb,(int)(*(byte *)(param_1 + 0x19) & 4) >> 2,
               CONCAT22(extraout_var,*(undefined2 *)(local_8 + 2)));
    __chkesp();
    FUN_00497690(*(undefined4 **)(local_8 + 0x20),*(undefined4 **)(local_8 + 0x1c),0x28);
  }
  local_8 = (byte *)0x446950;
  __chkesp();
  return;
}

