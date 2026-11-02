/* FUN_00420580 @ 00420580 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00420580(uint param_1,ushort param_2,uint param_3,ushort *param_4,ushort *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004d2388 == '\x01') && ((&DAT_004d239c)[((param_1 & 0xff) - 1) * 0x10] != '\x04')) {
    *param_5 = 0;
    *param_4 = 0;
  }
  else {
    if (DAT_004d238e != 0) {
      param_2 = (ushort)((uint)param_2 * (uint)DAT_004d238e +
                         ((int)((uint)param_2 * (uint)DAT_004d238e) >> 0x1f & 0xffU) >> 8);
    }
    if (0x3fff < param_2) {
      param_2 = 0x3fff;
    }
    if (DAT_004d2389 == '\x01') {
      *param_4 = (ushort)((param_3 & 0xffff) * (uint)param_2 >> 0xb);
      *param_5 = param_2 - *param_4;
    }
    else {
      *param_5 = param_2;
      *param_4 = param_2;
    }
  }
  return;
}

