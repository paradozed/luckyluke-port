/* FUN_0046d3d0 @ 0046d3d0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046d3d0(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = FUN_0044ce10(5);
  local_8 = CONCAT31(local_8._1_3_,(char)uVar2);
  if (((uVar2 & 0xff) != (uint)DAT_004f22a0) && (((uVar2 & 0xff) == 4 || ((uVar2 & 0xff) == 0xb))))
  {
    FUN_0041fc80(DAT_004f2298);
    bVar1 = FUN_0041f5e0(5,9,0,0x8fc,0x400,'\0');
    _DAT_004f2298 = (ushort)bVar1;
    FUN_0041fc30(bVar1);
  }
  DAT_004f22a0 = (undefined1)local_8;
  if ((DAT_004f245c & 0x8000) != 0) {
    FUN_0041f7b0(DAT_004f2298);
    FUN_0041fc80(DAT_004f2298);
    DAT_004f23f8 = FUN_0046d630;
    FUN_0046d630();
  }
  local_8 = 0x46d4bc;
  __chkesp();
  return;
}

