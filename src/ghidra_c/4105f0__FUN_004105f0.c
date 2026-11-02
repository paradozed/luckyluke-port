/* FUN_004105f0 @ 004105f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004105f0(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  int local_8;
  
  puVar4 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = FUN_00407580(param_1);
  sVar1 = FUN_004074b0(param_2,4);
  iVar2 = sVar1 * 100;
  sVar1 = FUN_004074b0(param_2,3);
  iVar3 = sVar1 * 100;
  sVar1 = FUN_004074b0(param_2,2);
  FUN_00411c90(**(int **)(local_8 + 8),sVar1 * 100,iVar3,iVar2);
  local_8 = 0x410664;
  __chkesp();
  return;
}

