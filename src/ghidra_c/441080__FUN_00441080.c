/* FUN_00441080 @ 00441080 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00441080(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  undefined1 local_c;
  PVOID local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (_DAT_004e853e != 0) {
    if (*DAT_004f58a8 == 0x536f6674) {
      (*DAT_0050898c)((int)_DAT_004e853e);
      __chkesp();
    }
    else {
      local_8 = (PVOID)FUN_00440e80(0,0,(short)DAT_004be3c8,(short)DAT_004be3cc);
      *(undefined1 *)((int)local_8 + 4) = DAT_004e8540;
      *(undefined1 *)((int)local_8 + 5) = DAT_004e8541;
      *(undefined1 *)((int)local_8 + 6) = DAT_004e8542;
      *(byte *)((int)local_8 + 7) = *(byte *)((int)local_8 + 7) | 2;
      (*DAT_004e8a6c)(DAT_004e853e);
      uVar1 = __chkesp();
      local_c = (undefined1)uVar1;
      (*DAT_004e8a74)();
      __chkesp();
      (*DAT_004e8a30)();
      __chkesp();
      (*DAT_004e8a44)(local_8,0,0,0,0);
      __chkesp();
      (*DAT_004e8a70)();
      __chkesp();
      (*DAT_004e8a6c)(local_c);
      __chkesp();
      FUN_00439c30(local_8);
    }
  }
  local_8 = (PVOID)0x4411bc;
  __chkesp();
  return;
}

