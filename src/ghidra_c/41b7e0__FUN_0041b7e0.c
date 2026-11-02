/* FUN_0041b7e0 @ 0041b7e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041b7e0(undefined4 param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 *puVar5;
  short sVar6;
  short sVar7;
  undefined4 local_4c [16];
  byte *local_c;
  int local_8;
  
  puVar5 = local_4c;
  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  local_c = (byte *)**(undefined4 **)(local_8 + 8);
  sVar7 = -1;
  sVar6 = 0;
  sVar1 = FUN_004074b0(param_2,5);
  sVar2 = FUN_004074b0(param_2,4);
  sVar3 = FUN_004074b0(param_2,3);
  FUN_0041b3c0(local_c,sVar3,sVar2,sVar1,sVar6,sVar7);
  if ((local_c[1] == 5) || (local_c[1] == 7)) {
    *(undefined1 *)(local_8 + 0x14) = 1;
  }
  local_8 = 0x41b879;
  __chkesp();
  return;
}

