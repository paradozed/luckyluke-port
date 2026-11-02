/* FUN_004165e0 @ 004165e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004165e0(int param_1,void *param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_60 [16];
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  iVar3 = 0x17;
  puVar4 = local_60;
  while( true ) {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = (undefined4 *)FUN_00407580(param_1);
  local_c = local_8[2];
  sVar1 = FUN_004074b0(param_2,2);
  uVar2 = local_14._2_2_;
  local_10 = *(int *)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_14 = (uint)local_14._2_2_ << 0x10;
  local_18 = (uint)local_18._2_2_ << 0x10;
  while ((local_18 & 0xffff) < 3) {
    if (*(int *)(local_c + 0x44 + (local_18 & 0xffff) * 0xc) == local_10) {
      local_14 = CONCAT22(uVar2,(short)local_18);
      break;
    }
    if (*(int *)(local_c + 0x44 + (local_18 & 0xffff) * 0xc) == 0) {
      local_14 = CONCAT22(uVar2,(short)local_18);
      break;
    }
    local_18 = CONCAT22(local_18._2_2_,(short)local_18 + 1);
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_1c = (int)sVar1 & 7;
  switch(local_1c) {
  case 0:
    *(code **)(local_c + 0x40 + (local_14 & 0xffff) * 0xc) = FUN_00457eb0;
    break;
  case 1:
    *(code **)(local_c + 0x40 + (local_14 & 0xffff) * 0xc) = FUN_004584d0;
    break;
  case 2:
    *(code **)(local_c + 0x40 + (local_14 & 0xffff) * 0xc) = FUN_00458890;
    break;
  case 3:
    *(code **)(local_c + 0x40 + (local_14 & 0xffff) * 0xc) = FUN_00458c40;
    break;
  case 7:
    if ((*(ushort *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) & 0x40) != 0) {
      *(uint *)(*(int *)(local_c + 0x44 + (local_14 & 0xffff) * 0xc) + 0x10) =
           *(uint *)(*(int *)(local_c + 0x44 + (local_14 & 0xffff) * 0xc) + 0x10) & 0xffffffeb;
    }
    if ((*(ushort *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) & 0x80) != 0) {
      *(uint *)(*(int *)(local_c + 0x44 + (local_14 & 0xffff) * 0xc) + 0x10) =
           *(uint *)(*(int *)(local_c + 0x44 + (local_14 & 0xffff) * 0xc) + 0x10) & 0xfffeffd7;
    }
    *(undefined4 *)(local_c + 0x44 + (local_14 & 0xffff) * 0xc) = 0;
    goto LAB_00416950;
  }
  sVar1 = FUN_004074b0(param_2,2);
  *(int *)(local_c + 0x44 + (local_14 & 0xffff) * 0xc) = (int)sVar1;
  *(undefined2 *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) = 0;
  uVar2 = FUN_004074b0(param_2,3);
  if ((uVar2 & 0x20) != 0) {
    *(ushort *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) =
         *(ushort *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) | 0x20;
  }
  uVar2 = FUN_004074b0(param_2,3);
  if ((uVar2 & 0x100) != 0) {
    *(ushort *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) =
         *(ushort *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) | 0x100;
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_20 = (int)sVar1 & 0x18;
  if (local_20 == 0) {
    *(undefined2 *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) =
         *(undefined2 *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc);
  }
  else if (local_20 == 8) {
    *(ushort *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) =
         *(ushort *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) | 8;
  }
  else if (local_20 == 0x10) {
    *(ushort *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) =
         *(ushort *)(local_c + 0x48 + (local_14 & 0xffff) * 0xc) | 0x10;
  }
  *local_8 = FUN_00457c60;
  *(undefined1 *)((int)local_8 + 0x11) = 1;
LAB_00416950:
  local_8 = (undefined4 *)0x41695d;
  __chkesp();
  return;
}

