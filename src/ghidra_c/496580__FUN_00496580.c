/* FUN_00496580 @ 00496580 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_00496580(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_38 [2];
  int local_30;
  int local_2c;
  int local_24;
  
  FUN_00495f20(local_38);
  if (((local_24 == 0) && (local_30 == 0)) && (((DAT_004c6e88 & 0x10) == 0 || (local_2c == 0)))) {
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_004999a0(0,0,0,0,&DAT_004b8034);
    if (iVar2 == 1) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    FUN_004961b0((undefined4 *)0x0);
    uVar3 = 1;
  }
  return uVar3;
}

