/* FUN_004052b0 @ 004052b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004052b0(char *param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = 0;
  do {
    if (6 < local_8) {
LAB_00405314:
      local_8 = 0x405321;
      __chkesp();
      return;
    }
    if ((uint)DAT_004e8914 == *(uint *)(&DAT_004bc068 + local_8 * 4)) {
      sVar1 = _strlen(param_1);
      param_1[sVar1 - 2] = '\0';
      goto LAB_00405314;
    }
    local_8 = local_8 + 1;
  } while( true );
}

