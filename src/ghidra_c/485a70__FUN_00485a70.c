/* FUN_00485a70 @ 00485a70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00485a70(byte *param_1,int param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,
            undefined1 param_6,undefined1 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  uint local_10;
  uint local_c;
  undefined2 *local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = local_10 & 0xffffff00;
  if (*(int *)(param_1 + 0xcc) == 0) {
    uVar1 = FUN_00439af0(0x80);
    *(undefined4 *)(param_1 + 0xcc) = uVar1;
    local_10 = CONCAT31(local_10._1_3_,1);
    *(undefined2 *)(*(int *)(param_1 + 0xcc) + 0xc) = 0;
  }
  local_8 = *(undefined2 **)(param_1 + 0xcc);
  *(int *)(local_8 + 0x14) = param_2;
  *local_8 = *(undefined2 *)(param_2 + 2);
  local_8[1] = *(undefined2 *)(param_2 + 2);
  local_8[2] = param_4;
  local_8[3] = 1;
  local_8[8] = param_3;
  **(undefined2 **)(param_1 + 0x3c) = param_3;
  FUN_00485dd0((int)param_1,param_5,param_6,param_7,param_8);
  FUN_00485e30((int)param_1,0,0);
  *(undefined4 *)(local_8 + 0x3e) = 0;
  *(uint *)(local_8 + 4) = DAT_004e8abc >> 5;
  if ((*param_1 & 2) == 0) {
    local_c = local_c & 0xffffff00;
  }
  else {
    FUN_0047f140(param_1);
    local_c = CONCAT31(local_c._1_3_,1);
  }
  *(undefined4 *)(local_8 + 0x10) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(local_8 + 0x12) = *(undefined4 *)(param_1 + 0x50);
  if ((local_10 & 0xff) != 0) {
    FUN_004857c0((int)param_1);
  }
  if (local_8[6] == 0) {
    FUN_00485d70((int)param_1);
  }
  if ((local_c & 0xff) != 0) {
    FUN_0047f2d0(param_1);
  }
  local_8 = (undefined2 *)0x485bfb;
  __chkesp();
  return;
}

