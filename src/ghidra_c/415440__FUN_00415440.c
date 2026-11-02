/* FUN_00415440 @ 00415440 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415440(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (DAT_00507f38 != (undefined1 *)0x0) {
    if (DAT_005081a0 == '\0') {
      sVar1 = FUN_004074b0(param_2,2);
      if (sVar1 == 0) {
        sVar1 = FUN_004074b0(param_2,4);
        if (sVar1 != 0) {
          sVar1 = FUN_004074b0(param_2,2);
          if (sVar1 == 0) {
            uVar2 = FUN_004074b0(param_2,4);
            *(short *)(DAT_00507f38 + 8) = (short)(1 << ((byte)uVar2 & 0x1f));
          }
        }
      }
      else {
        *(undefined2 *)(DAT_00507f38 + 8) = 0x400;
      }
    }
    uVar2 = FUN_004074b0(param_2,4);
    *(short *)(DAT_00507f38 + 6) = (short)(1 << ((byte)uVar2 & 0x1f));
    uVar2 = FUN_004074b0(param_2,3);
    *DAT_00507f38 = (char)uVar2;
    uVar2 = FUN_004074b0(param_2,5);
    DAT_00507f38[3] = (char)uVar2;
    sVar1 = FUN_004074b0(param_2,2);
    if (sVar1 == -1) {
      DAT_00507f38[1] = 0;
      *(undefined2 *)(DAT_00507f38 + 8) = 0x400;
      DAT_005081a0 = '\0';
    }
    else {
      uVar2 = FUN_004074b0(param_2,2);
      DAT_00507f38[1] = (char)uVar2;
      DAT_005081a0 = '\x01';
    }
  }
  uStack_8 = 0x415568;
  __chkesp();
  return;
}

