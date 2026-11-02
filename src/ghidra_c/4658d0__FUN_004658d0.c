/* FUN_004658d0 @ 004658d0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x00465a03) */

void __cdecl FUN_004658d0(char *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_154 [16];
  int local_114;
  uint *local_110;
  byte *local_10c;
  CHAR local_108 [256];
  undefined4 uStack_8;
  
  puVar3 = local_154;
  for (iVar2 = 0x54; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_00497080(local_108,0x4b60a8);
  FUN_00458ec0();
  while( true ) {
    local_10c = (byte *)FUN_00465720(local_108);
    iVar2 = _strcmp(param_1,"\\Cinema\\Butter\\Butter_I.BIZ");
    if (iVar2 == 0) break;
    if (local_10c != (byte *)0x0) {
      local_114 = FUN_00465810(local_108);
      local_110 = (uint *)(local_10c + local_114 + -8 + 4);
      if (*(int *)(local_10c + local_114 + -8) == 0x33435243) {
        uVar1 = FUN_004656b0(local_10c,local_114 + -8);
        if (*local_110 == uVar1) break;
        FUN_00465890(local_10c);
      }
      else {
        FUN_00465890(local_10c);
      }
    }
  }
  uStack_8 = 0x465a15;
  __chkesp();
  return;
}

