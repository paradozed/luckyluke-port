/* FUN_0042a370 @ 0042a370 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042a370(HWND param_1,int param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_6c [16];
  tagCHOOSECOLORA local_2c;
  int local_8;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  SendDlgItemMessageA(param_1,0x3ed,0x147,0,0);
  local_8 = __chkesp();
  if (local_8 != -1) {
    if (param_2 == 0) {
      DAT_004e2938 = *(uint *)(&DAT_004f79f0 + local_8 * 0x1c) |
                     *(int *)(&DAT_004f79f4 + local_8 * 0x1c) << 8 |
                     *(int *)(&DAT_004f79f8 + local_8 * 0x1c) << 0x10;
    }
    else {
      DAT_004e2938 = *(uint *)(&DAT_004f79e4 + local_8 * 0x1c) |
                     *(int *)(&DAT_004f79e8 + local_8 * 0x1c) << 8 |
                     *(int *)(&DAT_004f79ec + local_8 * 0x1c) << 0x10;
    }
    _memset(&local_2c,0,0x24);
    local_2c.lStructSize = 0x24;
    local_2c.hwndOwner = param_1;
    local_2c.lpCustColors = (COLORREF *)&DAT_004e5690;
    local_2c.rgbResult = DAT_004e2938;
    local_2c.Flags = 3;
    BVar1 = ChooseColorA(&local_2c);
    if (BVar1 == 1) {
      if (param_2 == 0) {
        *(COLORREF *)(&DAT_004f79f0 + local_8 * 0x1c) = local_2c.rgbResult & 0xff;
        *(COLORREF *)(&DAT_004f79f4 + local_8 * 0x1c) = local_2c.rgbResult >> 8 & 0xff;
        *(COLORREF *)(&DAT_004f79f8 + local_8 * 0x1c) = local_2c.rgbResult >> 0x10 & 0xff;
      }
      else {
        *(COLORREF *)(&DAT_004f79e4 + local_8 * 0x1c) = local_2c.rgbResult & 0xff;
        *(COLORREF *)(&DAT_004f79e8 + local_8 * 0x1c) = local_2c.rgbResult >> 8 & 0xff;
        *(COLORREF *)(&DAT_004f79ec + local_8 * 0x1c) = local_2c.rgbResult >> 0x10 & 0xff;
      }
    }
  }
  local_8 = 0x42a509;
  __chkesp();
  return;
}

