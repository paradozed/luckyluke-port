/* FUN_00420d10 @ 00420d10 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00420d10(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined4 local_c;
  char *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = this;
  (*DAT_004d28a8)(param_1,this,4,0);
  iVar1 = __chkesp();
  if ((((3 < iVar1) && (*local_8 == 'S')) && (local_8[1] == 'O')) &&
     ((local_8[2] == 'O' && (local_8[3] == 'L')))) {
    (*DAT_004d28a8)(param_1,local_8 + 4,4,4);
    iVar1 = __chkesp();
    if (3 < iVar1) {
      (*DAT_004d28a8)(param_1,local_8 + 8,2,8);
      iVar1 = __chkesp();
      if (1 < iVar1) {
        local_c = FUN_00496760((uint)*(ushort *)(local_8 + 8) << 3);
        *(undefined4 *)(local_8 + 0x18) = local_c;
        if (*(int *)(local_8 + 0x18) != 0) {
          (*DAT_004d28a8)(param_1,*(undefined4 *)(local_8 + 0x18),
                          (uint)*(ushort *)(local_8 + 8) << 3,10);
          iVar1 = __chkesp();
          if (-1 < iVar1) {
            *(undefined4 *)(local_8 + 0xc) = *(undefined4 *)(local_8 + 0x18);
            *(uint *)(local_8 + 0x10) =
                 *(int *)(local_8 + 0x18) + (uint)*(ushort *)(local_8 + 8) * 4;
            *(uint *)(local_8 + 0x14) =
                 *(int *)(local_8 + 0x18) + (uint)*(ushort *)(local_8 + 8) * 4 +
                 (uint)*(ushort *)(local_8 + 8) * 2;
          }
        }
      }
    }
  }
  local_8 = (char *)0x420ea6;
  __chkesp();
  return;
}

