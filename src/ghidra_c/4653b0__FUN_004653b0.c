/* FUN_004653b0 @ 004653b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004653b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00458ec0();
  for (local_8 = 0; local_8 < 5; local_8 = local_8 + 1) {
    *(undefined2 *)(&DAT_004e87a8 + local_8 * 0x14) = 0;
    *(undefined2 *)(&DAT_004e87aa + local_8 * 0x14) = 0;
    (&DAT_004e87ac)[local_8 * 10] = 0;
    *(undefined2 *)(&DAT_004e87ae + local_8 * 0x14) = 0;
    *(undefined2 *)(&DAT_004e87b0 + local_8 * 0x14) = 0;
    (&DAT_004e87b2)[local_8 * 10] = 0;
    (&DAT_004e87b4)[local_8 * 10] = 0;
    (&DAT_004e87b6)[local_8 * 10] = 0;
    *(undefined2 *)(&DAT_004f25e0)[local_8] = 0;
    *(undefined2 *)((&DAT_004f25e0)[local_8] + 2) = 0;
    *(undefined2 *)((&DAT_004f25e0)[local_8] + 4) = 0;
    *(undefined2 *)((&DAT_004f25e0)[local_8] + 6) = 0;
    *(undefined2 *)((&DAT_004f25e0)[local_8] + 8) = 0;
    *(undefined2 *)((&DAT_004f25e0)[local_8] + 10) = 0;
    *(undefined2 *)((&DAT_004f25e0)[local_8] + 0xc) = 0;
    *(undefined2 *)((&DAT_004f25e0)[local_8] + 0xe) = 0;
    *(undefined2 *)((&DAT_004f25e0)[local_8] + 0x10) = 0;
  }
  for (local_c = 0; local_c < 9; local_c = local_c + 1) {
    *(undefined2 *)(&DAT_004f25a0)[local_c] = 0;
    *(undefined2 *)((&DAT_004f25a0)[local_8] + 2) = 0;
    *(undefined2 *)((&DAT_004f25a0)[local_8] + 4) = 0;
    *(undefined2 *)((&DAT_004f25a0)[local_8] + 6) = 0;
    *(undefined2 *)((&DAT_004f25a0)[local_8] + 8) = 0;
    *(undefined2 *)((&DAT_004f25a0)[local_8] + 10) = 0;
    *(undefined2 *)((&DAT_004f25a0)[local_8] + 0xc) = 0;
    *(undefined2 *)((&DAT_004f25a0)[local_8] + 0xe) = 0;
    *(undefined2 *)((&DAT_004f25a0)[local_8] + 0x10) = 0;
  }
  DAT_004e880c = 0;
  DAT_004e880d = 0;
  DAT_004e880e = 0;
  DAT_004e880f = 0;
  DAT_004bdd4c = 1;
  DAT_004e8810 = 0;
  DAT_004e8811 = 0;
  DAT_004e8812 = 0;
  DAT_004e8814 = 0;
  DAT_004e8816 = 0;
  DAT_004e8818 = 0;
  DAT_004e881a = 0;
  DAT_004bdd4e = 0x32;
  local_8 = 0x46561f;
  __chkesp();
  return;
}

