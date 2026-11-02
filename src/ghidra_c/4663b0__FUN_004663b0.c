/* FUN_004663b0 @ 004663b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004663b0(int *param_1,ushort param_2,undefined4 param_3)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined4 local_50 [16];
  int local_10;
  undefined2 *local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = *param_1;
  local_8 = (undefined2 *)
            (DAT_004e8820 +
            *(int *)(DAT_004e8820 + 4 + ((uint)*(ushort *)(param_1 + 0xf) + (uint)param_2) * 4));
  *(ushort *)(param_1 + 6) = (short)param_1[0xf] + param_2;
  uVar5 = 0;
  uVar4 = 0;
  sVar1 = FUN_004664b0(local_8);
  FUN_00484e30(local_10,(int)local_8,0,sVar1 + -1,uVar4,uVar5);
  FUN_00466470(local_10,param_3,0);
  FUN_004664e0(local_10,0);
  local_8 = (undefined2 *)0x46646a;
  __chkesp();
  return;
}

