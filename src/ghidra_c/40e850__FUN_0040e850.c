/* FUN_0040e850 @ 0040e850 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_0040e850(short param_1)

{
  uint uVar1;
  uint3 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [16];
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (param_1 == -1) {
    uVar1 = (uint)(DAT_004f2be4 == 0);
  }
  else {
    uVar2 = (uint3)(char)((ushort)param_1 >> 8);
    if (DAT_004f2b62 == param_1) {
      uVar1 = CONCAT31(uVar2,DAT_004f2b64);
    }
    else {
      uVar1 = (uint)uVar2 << 8;
    }
  }
  return uVar1;
}

