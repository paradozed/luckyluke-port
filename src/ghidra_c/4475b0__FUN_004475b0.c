/* FUN_004475b0 @ 004475b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004475b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x18) < '\t') {
      iVar1 = (int)*(short *)(param_1 + 0xc) * (int)*(char *)(param_1 + 0x18);
      *(char *)(param_1 + 0x15) =
           *(char *)(param_1 + 0x12) + (char)((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3);
      iVar1 = (int)*(short *)(param_1 + 0xe) * (int)*(char *)(param_1 + 0x18);
      *(char *)(param_1 + 0x16) =
           *(char *)(param_1 + 0x13) + (char)((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3);
      iVar1 = (int)*(short *)(param_1 + 0x10) * (int)*(char *)(param_1 + 0x18);
      *(char *)(param_1 + 0x17) =
           *(char *)(param_1 + 0x14) + (char)((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3);
      *(undefined1 *)(param_1 + 0x28) = 2;
      *(char *)(param_1 + 0x18) = *(char *)(param_1 + 0x18) + '\x01';
    }
    else {
      *(undefined1 *)(param_1 + 0x18) = 0xff;
      if (*(int *)(param_1 + 0x38) != 0) {
        (**(code **)(param_1 + 0x38))(*(undefined4 *)(param_1 + 0x3c));
        __chkesp();
      }
    }
  }
  uStack_8 = 0x4476b3;
  __chkesp();
  return;
}

