/* FUN_0044c380 @ 0044c380 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044c380(void)

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
  if ((int)(uint)DAT_004bd05e < (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16)) {
    if ((int)(uint)DAT_004bd068 <= (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16)) {
      *(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x16) = DAT_004bd068;
    }
    if (DAT_004e8610 == '\0') {
      DAT_004f23f8 = FUN_0044c5c0;
      FUN_0044c5c0();
    }
    else {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
           *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = 0;
      DAT_004f23f8 = FUN_0044c820;
      FUN_0044c820();
    }
  }
  else {
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
         *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
    DAT_004f23f8 = FUN_0044c300;
    FUN_0044c300();
  }
  uStack_8 = 0x44c478;
  __chkesp();
  return;
}

