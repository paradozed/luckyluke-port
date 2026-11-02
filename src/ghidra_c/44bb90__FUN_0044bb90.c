/* FUN_0044bb90 @ 0044bb90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0044bb90(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [18];
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  for (uVar1 = 0; uVar1 < 0x20; uVar1 = uVar1 + 1) {
    if ((((&DAT_004f2c80)[(uint)uVar1 * 3] == param_1) &&
        ((&DAT_004f2c84)[(uint)uVar1 * 3] == param_2)) &&
       ((&DAT_004f2c88)[(uint)uVar1 * 0xc] == '\0')) {
      (&DAT_004f2c80)[(uint)uVar1 * 3] = FUN_0044bb70;
      (&DAT_004f2c84)[(uint)uVar1 * 3] = 0;
    }
  }
  return;
}

