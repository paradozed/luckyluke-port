/* FUN_0046e7d0 @ 0046e7d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0046e7d0(undefined2 *param_1,int param_2,uint param_3,undefined2 param_4,undefined2 param_5,
            undefined1 param_6,undefined1 param_7)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(int *)(param_1 + 0x14) = param_2;
  *param_1 = *(undefined2 *)(param_2 + 2);
  param_1[1] = *(undefined2 *)(param_2 + 2);
  param_1[2] = param_4;
  param_1[3] = 0xffff;
  *(uint *)(param_1 + 4) = DAT_004e8abc >> 5;
  param_1[8] = *(undefined2 *)(DAT_004e8820 + 4 + (param_3 & 0xffff) * 4);
  FUN_0046e890((int)param_1,param_5,param_6,param_7);
  *(undefined4 *)(param_1 + 0x3e) = 0;
  param_1[6] = 0;
  uStack_8 = 0x46e887;
  __chkesp();
  return;
}

