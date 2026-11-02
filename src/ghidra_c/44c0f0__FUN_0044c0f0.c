/* FUN_0044c0f0 @ 0044c0f0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044c0f0(void)

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
  if ((int)(uint)DAT_004bd056 < (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16)) {
    if ((int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16) < (int)(uint)DAT_004bd05e) {
      DAT_004f23f8 = FUN_0044c300;
      FUN_0044c300();
    }
    else {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
           *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
      DAT_004f23f8 = FUN_0044c5c0;
      FUN_0044c5c0();
    }
  }
  else {
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
         *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
    DAT_004f23f8 = FUN_0044beb0;
    FUN_0044beb0();
  }
  uStack_8 = 0x44c1a8;
  __chkesp();
  return;
}

