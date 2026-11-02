/* FUN_00416cd0 @ 00416cd0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00416cd0(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  undefined4 *puVar4;
  undefined4 local_54 [16];
  undefined4 local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  puVar4 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_c = FUN_00407580(param_1);
  sVar1 = FUN_004074b0(param_2,2);
  local_10 = *(int *)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_14 = *(undefined4 *)(local_c + 8);
  uVar3 = 0;
  do {
    if (1 < uVar3) {
LAB_00416d66:
      local_8 = 0x416d73;
      __chkesp();
      return;
    }
    if (*(int *)(local_10 + 0xbc + (uint)uVar3 * 4) == 0) {
      *(undefined4 *)(local_10 + 0xbc + (uint)uVar3 * 4) = local_14;
      goto LAB_00416d66;
    }
    uVar3 = uVar3 + 1;
  } while( true );
}

