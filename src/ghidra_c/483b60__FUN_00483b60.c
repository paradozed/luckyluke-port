/* FUN_00483b60 @ 00483b60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00483b60(int param_1,ushort *param_2,short *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(char *)(param_1 + 0x37) == '\0') {
    *param_3 = *param_3 + 1;
    *(short *)(param_1 + 0x32) = *param_3;
    if (*(ushort *)(param_1 + 0x32) < *param_2) {
      if (*(char *)(param_1 + 0x24) != '\0') {
        *(undefined1 *)(param_1 + 0x24) = 0;
        *(int *)(param_1 + 0x14) =
             *(int *)(param_1 + 0x14) - (int)*(short *)(*(int *)(param_1 + 8) + 4);
        *(int *)(param_1 + 0x18) =
             *(int *)(param_1 + 0x18) - (int)*(short *)(*(int *)(param_1 + 8) + 6);
        *(int *)(param_1 + 0x1c) =
             *(int *)(param_1 + 0x1c) - (int)*(short *)(*(int *)(param_1 + 8) + 8);
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x32) = 0;
      *param_3 = 0;
      *(undefined1 *)(param_1 + 0x24) = 1;
    }
  }
  else {
    *param_3 = *param_3 + -1;
    *(short *)(param_1 + 0x32) = *param_3;
    if (*(short *)(param_1 + 0x32) == -1) {
      *(ushort *)(param_1 + 0x32) = *param_2 - 1;
      *param_3 = *(short *)(param_1 + 0x32);
      *(undefined1 *)(param_1 + 0x24) = 1;
    }
    else if (*(char *)(param_1 + 0x24) != '\0') {
      *(undefined1 *)(param_1 + 0x24) = 0;
      *(int *)(param_1 + 0x14) =
           *(int *)(param_1 + 0x14) + (int)*(short *)(*(int *)(param_1 + 8) + 4);
      *(int *)(param_1 + 0x18) =
           *(int *)(param_1 + 0x18) + (int)*(short *)(*(int *)(param_1 + 8) + 6);
      *(int *)(param_1 + 0x1c) =
           *(int *)(param_1 + 0x1c) + (int)*(short *)(*(int *)(param_1 + 8) + 8);
    }
  }
  return;
}

