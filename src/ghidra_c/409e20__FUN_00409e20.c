/* FUN_00409e20 @ 00409e20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00409e20(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = *(undefined4 *)(param_1 + (param_2 & 0xff) * 4);
  *(undefined4 *)(param_1 + (param_2 & 0xff) * 4) = *(undefined4 *)(param_1 + (param_3 & 0xff) * 4);
  *(undefined4 *)(param_1 + (param_3 & 0xff) * 4) = uVar1;
  return;
}

