/* FUN_004ab170 @ 004ab170 */
/* decompiled from Lucky.exe (Game.run) */


int __fastcall FUN_004ab170(uint param_1,uint param_2,ushort *param_3,ushort *param_4,int param_5)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined2 extraout_var;
  int local_8;
  
  local_8 = 0;
  if (param_5 != 0) {
    if (DAT_004e8e98 == 0) {
      do {
        if ((*param_3 < 0x5b) && (0x40 < *param_3)) {
          uVar1 = *param_3 + 0x20;
        }
        else {
          uVar1 = *param_3;
        }
        if ((*param_4 < 0x5b) && (0x40 < *param_4)) {
          uVar2 = *param_4 + 0x20;
        }
        else {
          uVar2 = *param_4;
        }
        param_3 = param_3 + 1;
        param_4 = param_4 + 1;
        param_5 = param_5 + -1;
      } while (((param_5 != 0) && (uVar1 != 0)) && (uVar1 == uVar2));
    }
    else {
      do {
        uVar1 = *param_3;
        uVar5 = CONCAT22((short)(param_2 >> 0x10),uVar1);
        param_3 = param_3 + 1;
        uVar3 = FUN_004ad540(CONCAT22((short)(param_1 >> 0x10),uVar1),uVar5,uVar5);
        uVar1 = (ushort)uVar3;
        uVar2 = *param_4;
        param_4 = param_4 + 1;
        uVar4 = FUN_004ad540(param_4,CONCAT22(extraout_var,uVar2),
                             CONCAT22((short)(uVar3 >> 0x10),uVar2));
        uVar2 = (ushort)uVar4;
        param_5 = param_5 + -1;
        if ((param_5 == 0) || ((uVar3 & 0xffff) == 0)) break;
        param_1 = uVar3 & 0xffff;
        param_2 = uVar4 & 0xffff;
      } while (param_1 == param_2);
    }
    local_8 = (uint)uVar1 - (uint)uVar2;
  }
  return local_8;
}

