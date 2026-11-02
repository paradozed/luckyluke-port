/* FUN_004465c0 @ 004465c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004465c0(int param_1,byte param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  byte *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 != 0) {
    local_8 = (byte *)FUN_00439a90(DAT_004e85ec,0x24);
    *local_8 = param_2;
    local_8[0x18] = 0;
    local_8[0x19] = 0;
    local_8[0x1a] = 0;
    local_8[0x1b] = 0;
    (*(code *)(&PTR_FUN_004bcff0)[param_2])();
    uVar1 = __chkesp();
    *(undefined4 *)(local_8 + 0x1c) = uVar1;
    (*(code *)(&PTR_FUN_004bcff0)[param_2])();
    uVar1 = __chkesp();
    *(undefined4 *)(local_8 + 0x20) = uVar1;
    if (*(int *)(param_1 + 0x30) == 0) {
      *(byte **)(param_1 + 0x34) = local_8;
    }
    else {
      *(byte **)(*(int *)(param_1 + 0x30) + 0x18) = local_8;
    }
    *(byte **)(param_1 + 0x30) = local_8;
  }
  local_8 = (byte *)0x446680;
  __chkesp();
  return;
}

