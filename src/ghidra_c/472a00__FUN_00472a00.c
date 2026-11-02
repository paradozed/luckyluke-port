/* FUN_00472a00 @ 00472a00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00472a00(short param_1,short param_2)

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
  if (((&DAT_004f182c)[param_1] != '\0') && (param_1 < 2)) {
    if (*(short *)(*(int *)(&DAT_004f1820 + param_1 * 4) +
                  (uint)*(ushort *)(&DAT_004f1828 + param_1 * 2) * 4) == param_2) {
      *(short *)(*(int *)(&DAT_004f1820 + param_1 * 4) + 2 +
                (uint)*(ushort *)(&DAT_004f1828 + param_1 * 2) * 4) =
           *(short *)(*(int *)(&DAT_004f1820 + param_1 * 4) + 2 +
                     (uint)*(ushort *)(&DAT_004f1828 + param_1 * 2) * 4) + 1;
    }
    else if ((uint)*(ushort *)(&DAT_004f1828 + param_1 * 2) ==
             *(ushort *)(&DAT_004be190 + param_1 * 0xc) - 2) {
      FUN_00472b60((uint *)(&PTR_s_abilene_004be118)[DAT_004e8976]);
    }
    else {
      *(short *)(&DAT_004f1828 + param_1 * 2) = *(short *)(&DAT_004f1828 + param_1 * 2) + 1;
      *(short *)(*(int *)(&DAT_004f1820 + param_1 * 4) +
                (uint)*(ushort *)(&DAT_004f1828 + param_1 * 2) * 4) = param_2;
      *(undefined2 *)
       (*(int *)(&DAT_004f1820 + param_1 * 4) + 2 +
       (uint)*(ushort *)(&DAT_004f1828 + param_1 * 2) * 4) = 1;
    }
  }
  uStack_8 = 0x472b54;
  __chkesp();
  return;
}

