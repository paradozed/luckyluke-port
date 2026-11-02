/* FUN_00493e80 @ 00493e80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00493e80(short *param_1,short *param_2,int param_3,int param_4)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  for (; 0 < param_3; param_3 = param_3 + -1) {
    sVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = *param_2 + (short)((uint)(sVar1 * param_4) >> 8);
    param_2 = param_2 + 1;
  }
  return;
}

