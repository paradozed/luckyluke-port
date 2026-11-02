/* FUN_0043fc90 @ 0043fc90 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043fc90(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4c [16];
  char local_c;
  char *local_8;
  
  puVar4 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (param_1 != 0) {
    for (local_8 = *(char **)(param_1 + 0x100); local_8 != (char *)0x0;
        local_8 = *(char **)(local_8 + 0xc)) {
      if ((*(uint *)(local_8 + 8) & _DAT_004e8538) != 0) {
        local_c = *local_8;
        if (local_c == '\x01') {
          bVar1 = FUN_0043fb10(*(int *)(local_8 + 4));
          if (bVar1) break;
        }
        else {
          if (local_c == '\x02') {
            uVar2 = FUN_0043fb50(*(uint *)(local_8 + 4));
          }
          else {
            if (local_c != '\x03') goto LAB_0043fcc3;
            uVar2 = FUN_0043fc00(*(uint *)(local_8 + 4));
          }
          if ((uVar2 & 0xff) != 0) break;
        }
      }
LAB_0043fcc3:
    }
  }
  local_8 = (char *)0x43fd70;
  __chkesp();
  return;
}

