/* FUN_00418620 @ 00418620 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00418620(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  undefined4 local_c;
  int local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  local_c = **(undefined4 **)(local_8 + 8);
  sVar1 = FUN_004074b0(param_2,3);
  if (sVar1 == 0) {
    if ((*(char *)(local_8 + 0x13) == '\x01') &&
       (*(undefined1 *)(local_8 + 0x13) = 0, (*(ushort *)(local_8 + 0xe) & 1) != 0)) {
      if (*(char *)(local_8 + 0x17) == '\0') {
        FUN_00479de0(local_8);
      }
      else {
        *(undefined1 *)(local_8 + 0x17) = 0;
      }
    }
  }
  else if ((*(char *)(local_8 + 0x13) == '\0') &&
          (*(undefined1 *)(local_8 + 0x13) = 1, (*(ushort *)(local_8 + 0xe) & 1) != 0)) {
    *(undefined1 *)(local_8 + 0x17) = 2;
  }
  local_8 = 0x4186e9;
  __chkesp();
  return;
}

