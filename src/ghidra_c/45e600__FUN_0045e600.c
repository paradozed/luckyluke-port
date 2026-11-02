/* FUN_0045e600 @ 0045e600 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045e600(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  HWND pHVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_48 [16];
  undefined4 uStack_8;
  
  puVar5 = local_48;
  for (iVar4 = 0x11; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  FUN_0045f650();
  FUN_00458ec0();
  FUN_00458ec0();
  uVar1 = FUN_00445840();
  uVar2 = FUN_00445810();
  FUN_0043ec90(uVar2,uVar1);
  FUN_00458ec0();
  uVar1 = FUN_00445840();
  uVar2 = FUN_00445810();
  FUN_0043f140(uVar2,uVar1);
  FUN_00458ec0();
  uVar1 = FUN_00445840();
  pHVar3 = (HWND)FUN_00445810();
  FUN_0043f330(pHVar3,uVar1);
  FUN_0045e8a0(0,0);
  FUN_0045e280();
  FUN_0043f9c0(DAT_004e877c,1,0x21,0xffff);
  FUN_0043f9c0(DAT_004e8764,2,4,0xffff);
  FUN_0043f9c0(DAT_004e8768,2,5,0xffff);
  FUN_0043f9c0(DAT_004e876c,2,6,0xffff);
  FUN_0043f9c0(DAT_004e8770,2,7,0xffff);
  DAT_004e8774 = FUN_0043f950((uint *)"Start/Pause");
  DAT_004e8778 = FUN_0043f950((uint *)"Select");
  FUN_0043f9c0(DAT_004e8774,1,0x1c,0xffff);
  FUN_0043f9c0(DAT_004e8778,1,0x1f,0);
  FUN_0043f9c0(DAT_004e8774,2,8,0xffff);
  FUN_0043f9c0(DAT_004e8778,2,9,0xffff);
  DAT_004e8780 = FUN_0043f950((uint *)"Toggle object show");
  FUN_0043f9c0(DAT_004e8780,3,10,0xffff);
  DAT_004e8784 = FUN_0043f950((uint *)"Pause");
  FUN_0043f9c0(DAT_004e8784,1,0x19,0xffff);
  DAT_004e8788 = FUN_0043f950((uint *)"Exit game");
  FUN_0043f9c0(DAT_004e8788,1,1,0xffff);
  DAT_004e8790 = FUN_0043f950((uint *)"CD Audio music");
  FUN_0043f9c0(DAT_004e8790,1,0x32,0xffff);
  DAT_004e878c = FUN_0043f950((uint *)"Digital effects");
  FUN_0043f9c0(DAT_004e878c,1,0x1f,0xffff);
  FUN_00458ec0();
  FUN_0043fe50(1);
  uStack_8 = 0x45e88d;
  __chkesp();
  return;
}

