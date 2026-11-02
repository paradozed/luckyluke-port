/* FUN_00418580 @ 00418580 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00418580(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar4 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  if (local_8 != 0) {
    uVar2 = FUN_004074b0(param_2,3);
    *(char *)(local_8 + 0x12) = (char)uVar2;
    if ((((*(ushort *)(local_8 + 0xe) & 1) != 0) &&
        (local_c = **(int **)(local_8 + 8), *(char *)(local_c + 1) != '\x05')) &&
       (*(char *)(local_c + 1) != '\a')) {
      FUN_00479de0(local_8);
    }
  }
  local_8 = 0x418613;
  __chkesp();
  return;
}

