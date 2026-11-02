/* FUN_0040ae50 @ 0040ae50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040ae50(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_88 [16];
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  byte *local_18;
  int local_14;
  int local_10;
  ushort *local_c;
  int local_8;
  
  puVar3 = local_88;
  for (iVar2 = 0x21; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = FUN_00407580(param_1);
  local_14 = **(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  local_c = *(ushort **)(local_8 + 8);
  if ((*(char *)(local_8 + 0x15) != '\0') && ((char)local_c[1] != '\0')) {
    for (local_10 = 0; local_10 < (int)(uint)*local_c; local_10 = local_10 + 1) {
      local_18 = *(byte **)(*(int *)(local_c + 8) + local_10 * 0x20);
      FUN_0040b070((int)local_18,&local_48);
      FUN_0040b070(local_14,&local_30);
      local_24 = local_24 + *(int *)(local_14 + 0x90);
      local_30 = local_30 + *(int *)(local_14 + 0x90);
      local_20 = local_20 + *(int *)(local_14 + 0x94);
      local_2c = local_2c + *(int *)(local_14 + 0x94);
      local_1c = local_1c + *(int *)(local_14 + 0x98);
      local_28 = local_28 + *(int *)(local_14 + 0x98);
      local_3c = local_3c + *(int *)(local_18 + 0x90);
      local_48 = local_48 + *(int *)(local_18 + 0x90);
      local_38 = local_38 + *(int *)(local_18 + 0x94);
      local_44 = local_44 + *(int *)(local_18 + 0x94);
      local_34 = local_34 + *(int *)(local_18 + 0x98);
      local_40 = local_40 + *(int *)(local_18 + 0x98);
      if ((*(short *)(*(int *)(local_c + 8) + 4 + local_10 * 0x20) == 1) &&
         (uVar1 = FUN_0040d810(&local_30,&local_48), (short)uVar1 != 0)) {
        *(undefined2 *)(*(int *)(local_c + 8) + 4 + local_10 * 0x20) = 0;
        if (DAT_004f1620 == 0) {
          *(undefined1 *)(*(int *)(local_c + 8) + 0x1f + local_10 * 0x20) = 0;
        }
        else {
          FUN_0041b3c0(local_18,DAT_004f1620,0,0x20,0,0);
          *(undefined1 *)(*(int *)(local_c + 8) + 0x1e + local_10 * 0x20) = 1;
        }
        break;
      }
    }
  }
  local_8 = 0x40b06a;
  __chkesp();
  return;
}

