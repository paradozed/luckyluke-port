/* FUN_004214f0 @ 004214f0 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_004214f0(void *this,undefined4 param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  byte bVar4;
  undefined4 local_6c [16];
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  size_t local_14;
  int local_10;
  int local_c;
  void *local_8;
  
  puVar2 = local_6c;
  for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_2c = param_1;
  local_8 = this;
  switch(param_1) {
  case 0:
    local_10 = 0;
    for (local_c = 0; local_c < (int)(uint)*(ushort *)((int)local_8 + 0x10); local_c = local_c + 1)
    {
      (*(code *)param_2)(*(int *)((int)local_8 + 0x18) + local_c * 2,
                         *(int *)((int)local_8 + 0x1c) + local_c * 2);
      iVar3 = __chkesp();
      if ((iVar3 != 0) && (iVar3 = FUN_00421370(local_8,local_c), iVar3 == 0)) {
        if (local_c == *(int *)((int)local_8 + 4) + -1) {
          local_14 = *(int *)((int)local_8 + 0xc) -
                     *(int *)(*(int *)((int)local_8 + 0x14) + local_c * 4);
        }
        else {
          local_14 = *(int *)(*(int *)((int)local_8 + 0x14) + 4 + local_c * 4) -
                     *(int *)(*(int *)((int)local_8 + 0x14) + local_c * 4);
        }
        local_18 = FUN_00421120(local_c,*(undefined4 *)(*(int *)((int)local_8 + 0x14) + local_c * 4)
                                ,local_14);
        if ((local_18 == 0) || (local_18 == -1)) break;
        local_10 = local_10 + 1;
        puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_18 + -1);
        FUN_00421930((void *)*puVar2);
        iVar3 = 1;
        bVar4 = 1;
        puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_18 + -1);
        FUN_00417250((void *)*puVar2,bVar4,iVar3);
      }
    }
    break;
  case 1:
    local_10 = 0;
    for (local_c = 0; local_c < *(int *)((int)local_8 + 4); local_c = local_c + 1) {
      piVar1 = (int *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
      if (*piVar1 != 0) {
        puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
        local_1c = FUN_004214c0((undefined4 *)*puVar2);
        (*(code *)param_2)(*(int *)((int)local_8 + 0x18) + local_1c * 2,
                           *(int *)((int)local_8 + 0x1c) + local_1c * 2);
        iVar3 = __chkesp();
        if (iVar3 != 0) {
          local_10 = local_10 + 1;
          FUN_004212d0(local_8,local_c + 1);
        }
      }
    }
    break;
  case 2:
    local_10 = 0;
    for (local_c = 0; local_c < *(int *)((int)local_8 + 4); local_c = local_c + 1) {
      piVar1 = (int *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
      if (*piVar1 != 0) {
        puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
        local_20 = FUN_004214c0((undefined4 *)*puVar2);
        (*(code *)param_2)(*(int *)((int)local_8 + 0x18) + local_20 * 2,
                           *(int *)((int)local_8 + 0x1c) + local_20 * 2);
        iVar3 = __chkesp();
        if (iVar3 != 0) {
          local_10 = local_10 + 1;
          iVar3 = 0;
          bVar4 = 1;
          puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
          FUN_00417250((void *)*puVar2,bVar4,iVar3);
        }
      }
    }
    break;
  case 3:
    local_10 = 0;
    for (local_c = 0; local_c < *(int *)((int)local_8 + 4); local_c = local_c + 1) {
      piVar1 = (int *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
      if (*piVar1 != 0) {
        puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
        local_24 = FUN_004214c0((undefined4 *)*puVar2);
        (*(code *)param_2)(*(int *)((int)local_8 + 0x18) + local_24 * 2,
                           *(int *)((int)local_8 + 0x1c) + local_24 * 2);
        iVar3 = __chkesp();
        if (iVar3 != 0) {
          local_10 = local_10 + 1;
          iVar3 = 1;
          bVar4 = 1;
          puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
          FUN_00417250((void *)*puVar2,bVar4,iVar3);
        }
      }
    }
    break;
  case 4:
    local_10 = 0;
    for (local_c = 0; local_c < *(int *)((int)local_8 + 4); local_c = local_c + 1) {
      piVar1 = (int *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
      if (*piVar1 != 0) {
        puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
        local_28 = FUN_004214c0((undefined4 *)*puVar2);
        (*(code *)param_2)(*(int *)((int)local_8 + 0x18) + local_28 * 2,
                           *(int *)((int)local_8 + 0x1c) + local_28 * 2);
        iVar3 = __chkesp();
        if (iVar3 != 0) {
          local_10 = local_10 + 1;
          puVar2 = (undefined4 *)FUN_00422270((void *)((int)local_8 + 0x24),local_c);
          FUN_00421930((void *)*puVar2);
        }
      }
    }
  }
  local_8 = (void *)0x42190d;
  __chkesp();
  return;
}

