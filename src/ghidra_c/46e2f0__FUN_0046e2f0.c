/* FUN_0046e2f0 @ 0046e2f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046e2f0(int param_1,int param_2,char param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_64 [24];
  
  puVar5 = local_64;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  sVar1 = *(short *)(DAT_004d1e78 + param_1 * 4);
  sVar2 = *(short *)(DAT_004d1e78 + param_2 * 4);
  if ((sVar1 != sVar2) && (param_3 != '\0')) {
    iVar4 = DAT_004d1e7c + sVar1 * 0x14;
    iVar3 = DAT_004d1e7c + sVar2 * 0x14;
    *(undefined2 *)(iVar3 + 0xe) = *(undefined2 *)(iVar4 + 0xe);
    *(undefined1 *)(iVar3 + 0x12) = *(undefined1 *)(iVar4 + 0x10);
    *(undefined1 *)(iVar3 + 0x13) = *(undefined1 *)(iVar4 + 0x11);
  }
  return;
}

