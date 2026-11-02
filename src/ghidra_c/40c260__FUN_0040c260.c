/* FUN_0040c260 @ 0040c260 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040c260(undefined4 param_1,void *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  do {
    if (9 < local_8) {
LAB_0040c2ce:
      local_8 = 0x40c2db;
      __chkesp();
      return;
    }
    if (*(short *)(&DAT_004f13ca + local_8 * 0x2c) != 0) {
      FUN_004074b0(param_2,2);
      goto LAB_0040c2ce;
    }
    local_8 = local_8 + 1;
  } while( true );
}

