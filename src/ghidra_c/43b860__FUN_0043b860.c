/* FUN_0043b860 @ 0043b860 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043b860(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  longlong lVar5;
  uint uVar6;
  undefined4 local_54 [16];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar4 = local_54;
  for (iVar3 = 0x14; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_14 = *(undefined4 *)(param_2 + 0x38);
  local_10 = *(undefined4 *)(param_2 + 0x3c);
  local_c = *(undefined4 *)(param_2 + 0x40);
  local_8 = *(undefined4 *)(param_2 + 0x44);
  lVar5 = __ftol();
  *(short *)(param_2 + 0xc) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0xe) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x18) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x1a) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x24) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x26) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x30) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x32) = (short)lVar5;
  uVar6 = 7;
  lVar5 = __ftol();
  iVar3 = (int)lVar5;
  lVar5 = __ftol();
  iVar1 = (int)lVar5;
  lVar5 = __ftol();
  iVar2 = (int)lVar5;
  lVar5 = __ftol();
  FUN_0047d910(param_2 + 4,(int)lVar5,iVar2,iVar1,iVar3,uVar6);
  local_8 = 0x43b9ca;
  __chkesp();
  return;
}

