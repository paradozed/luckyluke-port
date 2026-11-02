/* FUN_0041ffe0 @ 0041ffe0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041ffe0(char param_1)

{
  undefined4 uVar1;
  byte bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if ((DAT_004bcfd0 != 0) && (DAT_004d2884 != '\0')) {
    bVar2 = param_1 + 1;
    DAT_004d1f1d = 0;
    DAT_004d1f1f = bVar2;
    FUN_00403c10();
    FUN_004038b0((ushort)bVar2);
    FUN_004039b0();
    timeGetTime();
    uVar1 = __chkesp();
    *(undefined4 *)(&DAT_004d1f40 + (uint)bVar2 * 0x1c) = uVar1;
  }
  uStack_8 = 0x42006d;
  __chkesp();
  return;
}

