/* FUN_00442df0 @ 00442df0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00442df0(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  uint local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = 0;
  if ((param_1 != (undefined4 *)0x0) && (param_2 < (uint)param_1[0x82])) {
    local_8 = *(uint *)(param_1[0x83] + param_2 * 4);
    FUN_004988b0((uint *)*param_1,local_8,0);
    do {
      do {
        if ((uint)param_1[0x81] <= local_8) goto LAB_00442ee0;
        uVar1 = FUN_00498340((int *)*param_1);
        *(char *)((int)param_1 + local_c + 4) = (char)uVar1;
        local_8 = local_8 + 1;
        iVar2 = local_c + 4;
        local_c = local_c + 1;
      } while (*(char *)((int)param_1 + iVar2) != '\r');
      uVar1 = FUN_00498340((int *)*param_1);
      *(char *)((int)param_1 + local_c + 4) = (char)uVar1;
      local_8 = local_8 + 1;
      iVar2 = local_c + 4;
      local_c = local_c + 1;
    } while (*(char *)((int)param_1 + iVar2) != '\n');
LAB_00442ee0:
    *(undefined1 *)((int)param_1 + local_c + 2) = 0;
  }
  local_8 = 0x442efd;
  __chkesp();
  return;
}

