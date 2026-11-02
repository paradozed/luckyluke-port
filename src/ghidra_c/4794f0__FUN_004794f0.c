/* FUN_004794f0 @ 004794f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004794f0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [16];
  int local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  uint local_10;
  uint local_8;
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = 0; local_8 < *(uint *)(DAT_004e89f0 + 0x18 + param_1 * 0x20); local_8 = local_8 + 1
      ) {
    local_14 = (int *)(*(int *)(DAT_004e89f0 + 0x1c + param_1 * 0x20) + local_8 * 0x14);
    local_10 = local_14[2];
    local_18 = local_14[3];
    local_1c = local_14[4];
    local_20 = *(int *)(*local_14 + 0x3c);
    local_28 = local_14[1] + -2;
    switch(local_28) {
    case 0:
      if ((local_10 & 0xffff0000) == 0) {
        FUN_0046ecf0(local_18,local_1c,local_20,local_10);
        FUN_0048cd50(local_18,local_1c,local_20,local_10);
      }
      else {
        local_24 = (uint)*(ushort *)(local_20 + 0x10);
        *(undefined2 *)(local_20 + 0x10) = 1;
        FUN_0046ed90(local_18,local_1c,local_20,local_10 & 0xffff);
        FUN_0048cd50(local_18,local_1c,local_20,local_10 & 0xffff);
        *(undefined2 *)(local_20 + 0x10) = (undefined2)local_24;
      }
      break;
    case 1:
      FUN_0046ebc0(local_18,local_1c,local_20,local_10);
      FUN_0048b340(local_18,local_1c,local_20,local_10);
      break;
    case 4:
      FUN_00489f60(local_18,local_1c,local_20,local_10);
      break;
    case 5:
      FUN_0046ec60(local_18,local_1c,local_20,local_10);
      FUN_00488290(local_18,local_1c,local_20,local_10);
    }
  }
  local_8 = 0x4796c2;
  __chkesp();
  return;
}

