/* FUN_0043ae50 @ 0043ae50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043ae50(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  longlong lVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_50 [16];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = *(undefined4 *)(param_2 + 0x20);
  local_c = *(undefined4 *)(param_2 + 0x24);
  local_8 = *(undefined4 *)(param_2 + 0x28);
  lVar4 = __ftol();
  *(short *)(param_2 + 0xc) = (short)lVar4;
  lVar4 = __ftol();
  *(short *)(param_2 + 0xe) = (short)lVar4;
  lVar4 = __ftol();
  *(short *)(param_2 + 0x14) = (short)lVar4;
  lVar4 = __ftol();
  *(short *)(param_2 + 0x16) = (short)lVar4;
  lVar4 = __ftol();
  *(short *)(param_2 + 0x1c) = (short)lVar4;
  lVar4 = __ftol();
  *(short *)(param_2 + 0x1e) = (short)lVar4;
  uVar6 = 4;
  iVar5 = 0;
  lVar4 = __ftol();
  iVar2 = (int)lVar4;
  lVar4 = __ftol();
  iVar1 = (int)lVar4;
  lVar4 = __ftol();
  FUN_0047d910(param_2 + 4,(int)lVar4,iVar1,iVar2,iVar5,uVar6);
  local_8 = 0x43af6f;
  __chkesp();
  return;
}

