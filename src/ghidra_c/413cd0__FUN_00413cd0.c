/* FUN_00413cd0 @ 00413cd0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00413cd0(undefined4 param_1,void *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_a0 [16];
  int local_60;
  uint local_5c [19];
  uint local_10;
  uint local_c;
  uint *local_8;
  
  iVar3 = 0x27;
  puVar5 = local_a0;
  while( true ) {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_60 = sVar1 + -1;
  switch(local_60) {
  case 0:
    local_8 = (uint *)&DAT_004b4230;
    break;
  case 1:
    local_8 = (uint *)&DAT_004b422c;
    break;
  case 2:
    local_8 = (uint *)&DAT_004b4228;
    break;
  case 3:
    local_8 = (uint *)&DAT_004b4224;
    break;
  case 4:
    local_8 = (uint *)&DAT_004b4220;
    break;
  case 5:
    local_8 = (uint *)&DAT_004b421c;
    break;
  case 6:
    local_8 = (uint *)&DAT_004b4218;
    break;
  case 7:
    local_8 = (uint *)&DAT_004b4214;
    break;
  case 8:
    local_8 = (uint *)&DAT_004b4210;
    break;
  default:
    local_8 = (uint *)&DAT_004b33d4;
  }
  sVar1 = FUN_004074b0(param_2,4);
  local_c = CONCAT22(local_c._2_2_,
                     (short)((int)(sVar1 * DAT_004be3c8 + (sVar1 * DAT_004be3c8 >> 0x1f & 0x1ffU))
                            >> 9));
  sVar1 = FUN_004074b0(param_2,5);
  local_10 = CONCAT22(local_10._2_2_,
                      (short)(sVar1 * DAT_004be3cc + (sVar1 * DAT_004be3cc >> 0x1f & 0xffU) >> 8));
  sVar1 = FUN_004074b0(param_2,2);
  if (sVar1 == 8) {
    FUN_0042c9e0(local_c & 0xffff,local_10 & 0xffff,local_8);
  }
  else {
    sVar1 = FUN_004074b0(param_2,2);
    if (sVar1 == 9) {
      FUN_004074b0(param_2,3);
      FUN_00497080((undefined1 *)local_5c,0x4b4208);
      FUN_0042c9e0(local_c & 0xffff,local_10 & 0xffff,local_5c);
    }
    else {
      uVar4 = local_10 & 0xffff;
      uVar2 = local_c & 0xffff;
      sVar1 = FUN_004074b0(param_2,3);
      FUN_00473bf0(local_8,(int)sVar1,uVar2,uVar4);
    }
  }
  local_8 = (uint *)0x413e80;
  __chkesp();
  return;
}

