/* FUN_00472780 @ 00472780 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00472780(short param_1)

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
  if (((((&DAT_004f182c)[param_1] != '\0') && (param_1 < 2)) &&
      (*(short *)(*(int *)(&DAT_004f1820 + param_1 * 4) + 2 +
                 (uint)*(ushort *)(&DAT_004f1828 + param_1 * 2) * 4) =
            *(short *)(*(int *)(&DAT_004f1820 + param_1 * 4) + 2 +
                      (uint)*(ushort *)(&DAT_004f1828 + param_1 * 2) * 4) + -1,
      *(short *)(*(int *)(&DAT_004f1820 + param_1 * 4) + 2 +
                (uint)*(ushort *)(&DAT_004f1828 + param_1 * 2) * 4) == 0)) &&
     (*(short *)(&DAT_004f1828 + param_1 * 2) = *(short *)(&DAT_004f1828 + param_1 * 2) + 1,
     *(short *)(*(int *)(&DAT_004f1820 + param_1 * 4) + 2 +
               (uint)*(ushort *)(&DAT_004f1828 + param_1 * 2) * 4) == 0)) {
    (&DAT_004f182c)[param_1] = 0;
    DAT_004f182e = DAT_004f182e + -1;
    if (DAT_004f182e == '\0') {
      FUN_00472700();
    }
  }
  uStack_8 = 0x4728b6;
  __chkesp();
  return;
}

