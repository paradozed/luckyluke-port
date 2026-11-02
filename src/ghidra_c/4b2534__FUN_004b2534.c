/* FUN_004b2534 @ 004b2534 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004b2534(uint param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  undefined2 local_8;
  
  uVar4 = param_1;
  if (param_1 < 0x100) {
    if (((&DAT_00509041)[param_1] & 0x20) == 0x20) {
      uVar4 = (uint)(byte)(&DAT_00508f40)[param_1];
    }
  }
  else {
    uVar5 = (undefined1)param_1;
    uVar2 = param_1 >> 8;
    uVar1 = param_1 >> 8;
    param_1 = CONCAT13(uVar5,CONCAT12((char)uVar1,(undefined2)param_1));
    if ((((&DAT_00509041)[uVar2 & 0xff] & 4) != 0) &&
       (iVar3 = FUN_004a9740(DAT_00509144,0x200,(char *)((int)&param_1 + 2),2,&local_8,2,
                             DAT_00508f20,1), iVar3 != 0)) {
      uVar4 = (uint)CONCAT11((undefined1)local_8,local_8._1_1_);
    }
  }
  return uVar4;
}

