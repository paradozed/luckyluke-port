/* FUN_0043f590 @ 0043f590 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043f590(void)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_154 [16];
  byte local_114;
  undefined3 uStack_113;
  byte local_110;
  undefined3 uStack_10f;
  byte local_10c [256];
  uint local_c;
  int local_8;
  
  puVar3 = local_154;
  for (iVar2 = 0x54; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  while( true ) {
    (**(code **)(*DAT_004e8508 + 100))(DAT_004e8508);
    __chkesp();
    FUN_00497690((undefined4 *)local_10c,(undefined4 *)&DAT_004f59c0,0x100);
    (**(code **)(*DAT_004e8508 + 0x24))(DAT_004e8508,0x100,&DAT_004f59c0);
    local_8 = __chkesp();
    for (local_c = 0; local_c < 0x100; local_c = local_c + 1) {
      bVar1 = local_10c[local_c];
      _local_110 = CONCAT31(uStack_10f,bVar1);
      _local_114 = CONCAT31(uStack_113,(&DAT_004f59c0)[local_c]);
      (&DAT_004f58c0)[local_c] = (bVar1 ^ (&DAT_004f59c0)[local_c]) & bVar1;
    }
    if ((local_8 == 0) || (local_8 != -0x7ff8ffe2)) break;
    (**(code **)(*DAT_004e8508 + 0x1c))(DAT_004e8508);
    __chkesp();
  }
  local_10c[0xf4] = 0xbc;
  local_10c[0xf5] = 0xf6;
  local_10c[0xf6] = 0x43;
  local_10c[0xf7] = 0;
  __chkesp();
  return;
}

