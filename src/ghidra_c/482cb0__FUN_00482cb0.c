/* FUN_00482cb0 @ 00482cb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00482cb0(short param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  iVar2 = (int)param_1;
  do {
    iVar3 = iVar2 + 0x1000;
    bVar1 = iVar2 < -0x1000;
    iVar2 = iVar3;
  } while (bVar1);
  for (; 0x2000 < iVar3; iVar3 = iVar3 + -0x1000) {
  }
  uStack_8 = 0x482cfa;
  __chkesp();
  return;
}

