/* FUN_0041b650 @ 0041b650 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041b650(void *param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  undefined4 *puVar6;
  short sVar7;
  undefined4 local_50 [16];
  int local_10;
  byte *local_c;
  int local_8;
  
  puVar6 = local_50;
  for (iVar5 = 0x13; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  local_8 = FUN_00407580((int)param_1);
  local_c = (byte *)**(undefined4 **)(local_8 + 8);
  sVar1 = FUN_004074b0(param_2,6);
  if (sVar1 < 0) {
    local_10 = 0;
  }
  else {
    sVar1 = FUN_004074b0(param_2,6);
    local_10 = (int)sVar1;
  }
  sVar7 = (short)local_10;
  sVar1 = FUN_004074b0(param_2,5);
  sVar2 = FUN_004074b0(param_2,4);
  sVar3 = FUN_004074b0(param_2,3);
  sVar4 = FUN_004074b0(param_2,2);
  FUN_0041b3c0(local_c,sVar4,sVar3,sVar2,sVar1,sVar7);
  FUN_0041b610((int)local_c,FUN_0041b370,param_1);
  if ((local_c[1] == 5) || (local_c[1] == 7)) {
    *(undefined1 *)(local_8 + 0x14) = 1;
  }
  FUN_00417250(param_1,2,1);
  local_8 = 0x41b734;
  __chkesp();
  return;
}

