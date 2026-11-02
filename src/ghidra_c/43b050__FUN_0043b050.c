/* FUN_0043b050 @ 0043b050 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043b050(undefined4 param_1,int param_2)

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
  local_14 = *(undefined4 *)(param_2 + 0x28);
  local_10 = *(undefined4 *)(param_2 + 0x2c);
  local_c = *(undefined4 *)(param_2 + 0x30);
  local_8 = *(undefined4 *)(param_2 + 0x34);
  lVar5 = __ftol();
  *(short *)(param_2 + 0xc) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0xe) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x14) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x16) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x1c) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x1e) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x24) = (short)lVar5;
  lVar5 = __ftol();
  *(short *)(param_2 + 0x26) = (short)lVar5;
  uVar6 = 5;
  lVar5 = __ftol();
  iVar3 = (int)lVar5;
  lVar5 = __ftol();
  iVar1 = (int)lVar5;
  lVar5 = __ftol();
  iVar2 = (int)lVar5;
  lVar5 = __ftol();
  FUN_0047d910(param_2 + 4,(int)lVar5,iVar2,iVar1,iVar3,uVar6);
  local_8 = 0x43b1ba;
  __chkesp();
  return;
}

