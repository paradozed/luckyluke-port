/* FUN_004476c0 @ 004476c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004476c0(int param_1,byte param_2,ushort param_3,ushort param_4,ushort param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 != 0) && (iVar1 = FUN_00446540(param_1,param_2), iVar1 != 0)) {
    *(undefined1 *)(iVar1 + 0x12) = *(undefined1 *)(iVar1 + 0x15);
    *(undefined1 *)(iVar1 + 0x13) = *(undefined1 *)(iVar1 + 0x16);
    *(undefined1 *)(iVar1 + 0x14) = *(undefined1 *)(iVar1 + 0x17);
    *(ushort *)(iVar1 + 0xc) = (param_3 & 0xff) - (ushort)*(byte *)(iVar1 + 0x12);
    *(ushort *)(iVar1 + 0xe) = (param_4 & 0xff) - (ushort)*(byte *)(iVar1 + 0x13);
    *(ushort *)(iVar1 + 0x10) = (param_5 & 0xff) - (ushort)*(byte *)(iVar1 + 0x14);
    if ((*(short *)(iVar1 + 0xc) == 0) &&
       ((*(short *)(iVar1 + 0xe) == 0 && (*(short *)(iVar1 + 0x10) == 0)))) {
      *(undefined1 *)(iVar1 + 0x18) = 0xff;
    }
    else {
      *(undefined1 *)(iVar1 + 0x18) = 0;
      *(undefined1 *)(iVar1 + 0x28) = 2;
    }
  }
  local_8 = 0x4477be;
  __chkesp();
  return;
}

