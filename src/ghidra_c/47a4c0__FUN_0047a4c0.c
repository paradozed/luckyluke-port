/* FUN_0047a4c0 @ 0047a4c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047a4c0(int param_1)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  ushort *local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10 = *(ushort **)(param_1 + 8);
  local_8 = **(int **)(local_10 + 8);
  local_c = *(int *)(*(int *)(local_10 + 8) + (*local_10 - 1) * 0x20);
  sVar1 = FUN_0047a5d0(local_8);
  if (*(char *)(DAT_004e89f0 + 5 + sVar1 * 0x20) != '\x01') {
    sVar1 = FUN_0047a5d0(local_c);
    if (*(char *)(DAT_004e89f0 + 5 + sVar1 * 0x20) != '\x01') {
      *(undefined1 *)(param_1 + 0x15) = 0;
      goto LAB_0047a55b;
    }
  }
  *(undefined1 *)(param_1 + 0x15) = 1;
LAB_0047a55b:
  if ((*(char *)(param_1 + 0x15) == '\x01') && (*(char *)(param_1 + 0x13) == '\x01')) {
    FUN_004164e0(param_1,0);
    *(undefined1 *)(param_1 + 0x13) = 0;
  }
  else if ((*(char *)(param_1 + 0x15) == '\0') && (*(char *)(param_1 + 0x13) == '\0')) {
    FUN_004164e0(param_1,1);
    *(undefined1 *)(param_1 + 0x13) = 1;
  }
  local_8 = 0x47a5c6;
  __chkesp();
  return;
}

