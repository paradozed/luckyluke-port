/* FUN_00415e50 @ 00415e50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415e50(void *param_1,void *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_48 [16];
  int local_8;
  undefined2 uVar5;
  
  puVar8 = local_48;
  for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0xcccccccc;
    puVar8 = puVar8 + 1;
  }
  uVar2 = FUN_004074b0(param_2,5);
  uVar3 = FUN_004074b0(param_2,4);
  uVar4 = FUN_004074b0(param_2,3);
  uVar5 = FUN_004074b0(param_2,2);
  bVar1 = (byte)uVar5;
  iVar7 = FUN_00407580((int)param_1);
  local_8 = FUN_004476c0(*(int *)(iVar7 + 8),bVar1,uVar4,uVar3,uVar2);
  sVar6 = FUN_004074b0(param_2,6);
  if ((sVar6 == 0) || (*(char *)(local_8 + 0x18) == -1)) {
    FUN_004477d0(local_8,0,param_1);
  }
  else {
    FUN_004477d0(local_8,FUN_00425870,param_1);
    FUN_00417250(param_1,2,1);
  }
  local_8 = 0x415f0a;
  __chkesp();
  return;
}

