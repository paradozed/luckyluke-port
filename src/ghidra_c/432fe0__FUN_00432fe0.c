/* FUN_00432fe0 @ 00432fe0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00432fe0(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_454 [16];
  uint local_414 [256];
  int *local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  puVar3 = local_454;
  for (iVar2 = 0x114; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_00432f50();
  DAT_004f17ea = (undefined2)param_1;
  _DAT_004e85ac = param_1;
  local_14 = (int *)FUN_00497d00((&PTR_s_win_language_english_txt_004bc744)[param_1 & 0xffff],"rb");
  if (local_14 != (int *)0x0) {
    for (local_8 = 0; local_8 < 100; local_8 = local_8 + 1) {
      local_c = 0;
      while ((local_10 = FUN_00498340(local_14), local_10 != 0xd && (local_10 != 0xffffffff))) {
        *(undefined1 *)((int)local_414 + local_c) = (undefined1)local_10;
        local_c = local_c + 1;
      }
      if (local_c == 0) break;
      local_10 = FUN_00498340(local_14);
      if (local_10 != 10) {
        if (local_10 == 0xffffffff) break;
        FUN_00498bb0(local_10,local_14);
      }
      *(undefined1 *)((int)local_414 + local_c) = 0;
      uVar1 = FUN_00494c40(local_c + 1,1);
      (&DAT_004f5d80)[local_8] = uVar1;
      if ((&DAT_004f5d80)[local_8] == 0) goto LAB_00433147;
      FUN_00497270((uint *)(&DAT_004f5d80)[local_8],local_414);
    }
    DAT_004e8490 = local_8 + -1;
    FUN_00497b30(local_14);
  }
LAB_00433147:
  local_8 = 0x433157;
  __chkesp();
  return;
}

