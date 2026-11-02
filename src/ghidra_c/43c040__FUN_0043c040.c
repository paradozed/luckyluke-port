/* FUN_0043c040 @ 0043c040 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0043c040(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [25];
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  switch(*(undefined4 *)(*(int *)(param_1 + 0x14) + param_2 * 0x54)) {
  case 0:
    iVar1 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    *(undefined4 *)(iVar1 + 0x24) = param_3;
    *(undefined4 *)(iVar1 + 0x28) = param_4;
    *(undefined4 *)(iVar1 + 0x2c) = param_5;
    break;
  case 1:
    iVar1 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    *(undefined4 *)(iVar1 + 0x2c) = param_3;
    *(undefined4 *)(iVar1 + 0x30) = param_4;
    *(undefined4 *)(iVar1 + 0x34) = param_5;
    break;
  case 2:
    iVar1 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    *(undefined4 *)(iVar1 + 0x30) = param_3;
    *(undefined4 *)(iVar1 + 0x34) = param_4;
    *(undefined4 *)(iVar1 + 0x38) = param_5;
    break;
  case 3:
    iVar1 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    *(undefined4 *)(iVar1 + 0x3c) = param_3;
    *(undefined4 *)(iVar1 + 0x40) = param_4;
    *(undefined4 *)(iVar1 + 0x44) = param_5;
    break;
  case 4:
    iVar1 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    *(undefined4 *)(iVar1 + 0x2c) = param_3;
    *(undefined4 *)(iVar1 + 0x30) = param_4;
    *(undefined4 *)(iVar1 + 0x34) = param_5;
    break;
  case 5:
    iVar1 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    *(undefined4 *)(iVar1 + 0x38) = param_3;
    *(undefined4 *)(iVar1 + 0x3c) = param_4;
    *(undefined4 *)(iVar1 + 0x40) = param_5;
    break;
  case 6:
    iVar1 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    *(undefined4 *)(iVar1 + 0x38) = param_3;
    *(undefined4 *)(iVar1 + 0x3c) = param_4;
    *(undefined4 *)(iVar1 + 0x40) = param_5;
    break;
  case 7:
    iVar1 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    *(undefined4 *)(iVar1 + 0x48) = param_3;
    *(undefined4 *)(iVar1 + 0x4c) = param_4;
    *(undefined4 *)(iVar1 + 0x50) = param_5;
  }
  return;
}

