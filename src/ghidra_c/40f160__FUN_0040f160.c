/* FUN_0040f160 @ 0040f160 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __cdecl FUN_0040f160(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  short unaff_BP;
  undefined4 *puVar3;
  short unaff_retaddr;
  undefined4 local_64 [16];
  int local_24;
  undefined4 *local_20;
  int local_1c;
  undefined4 *local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  puVar3 = local_64;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_1c = FUN_00407580(param_1);
  local_24 = **(int **)(local_1c + 8);
  sVar1 = FUN_004074b0(param_2,2);
  local_14 = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,3);
  local_10 = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,4);
  local_c = (int)sVar1;
  FUN_00410130(local_24,local_14,local_10,local_c);
  local_20 = &local_8;
  local_18 = local_20;
  FUN_004100e0(local_24,(short)local_8,unaff_BP,unaff_retaddr);
  local_8 = 0x40f218;
  __chkesp();
  return;
}

