/* FUN_0042a6d0 @ 0042a6d0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0042a6d0(HWND param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  longlong lVar4;
  longlong lVar5;
  undefined4 local_68 [16];
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  SendDlgItemMessageA(param_1,0x3ed,0x147,0,0);
  local_8 = __chkesp();
  if (local_8 != -1) {
    if ((*(uint *)(&DAT_004f79e0 + local_8 * 0x1c) & 4) == 0) {
      for (local_10 = 0; (int)local_10 < 0x3f; local_10 = local_10 + 1) {
        for (local_c = 0; (int)local_c < 0x42; local_c = local_c + 1) {
          if ((local_c & 7) == (local_10 & 7)) {
            *(undefined2 *)(DAT_004f79c8 + (local_10 * 0x42 + local_c) * 2) = 0;
          }
          else {
            *(undefined2 *)(DAT_004f79c8 + (local_10 * 0x42 + local_c) * 2) = 0xffff;
          }
        }
      }
    }
    else {
      local_14 = (float)*(int *)(&DAT_004f79e4 + local_8 * 0x1c);
      local_18 = (float)*(int *)(&DAT_004f79e8 + local_8 * 0x1c);
      local_1c = (float)*(int *)(&DAT_004f79ec + local_8 * 0x1c);
      local_20 = ((float)*(int *)(&DAT_004f79f0 + local_8 * 0x1c) - local_14) / _DAT_004b5144;
      local_24 = ((float)*(int *)(&DAT_004f79f4 + local_8 * 0x1c) - local_18) / _DAT_004b5144;
      local_28 = ((float)*(int *)(&DAT_004f79f8 + local_8 * 0x1c) - local_1c) / _DAT_004b5144;
      for (local_10 = 0; (int)local_10 < 0x3f; local_10 = local_10 + 1) {
        for (local_c = 0; (int)local_c < 0x42; local_c = local_c + 1) {
          lVar3 = __ftol();
          lVar4 = __ftol();
          lVar5 = __ftol();
          *(ushort *)(DAT_004f79c8 + (local_10 * 0x42 + local_c) * 2) =
               (ushort)((int)lVar3 >> 3) | (ushort)(((int)lVar4 >> 3) << 5) |
               (ushort)(((int)lVar5 >> 3) << 10);
        }
        local_14 = local_14 + local_20;
        local_18 = local_18 + local_24;
        local_1c = local_1c + local_28;
      }
    }
    SendMessageA(param_1,0xf,0,0);
    __chkesp();
  }
  local_8 = 0x42a8cb;
  __chkesp();
  return;
}

