/* FUN_00472b60 @ 00472b60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00472b60(uint *param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined4 local_e4 [16];
  uint local_a4;
  byte *local_a0;
  size_t local_9c;
  int local_98;
  uint local_94;
  uint local_90 [32];
  uint *local_10;
  short local_c [2];
  int local_8;
  
  puVar3 = local_e4;
  for (iVar2 = 0x38; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c[0] = 0;
  puVar4 = (uint *)&DAT_004b8718;
  puVar1 = FUN_00497270(local_90,(uint *)"option\\");
  puVar1 = FUN_00497280(puVar1,param_1);
  FUN_00497280(puVar1,puVar4);
  FUN_00474c50();
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    if (*(int *)(&DAT_004f1820 + local_8 * 4) != 0) {
      *(short *)(&DAT_004f1828 + local_8 * 2) = *(short *)(&DAT_004f1828 + local_8 * 2) + 1;
      *(undefined2 *)
       (*(int *)(&DAT_004f1820 + local_8 * 4) + 2 +
       (uint)*(ushort *)(&DAT_004f1828 + local_8 * 2) * 4) = 0;
      local_c[0] = local_c[0] + 1;
    }
  }
  local_10 = (uint *)FUN_00497d00((LPCSTR)local_90,"wb");
  if (local_10 != (uint *)0x0) {
    FUN_00497d20(&DAT_004f182f,1,0xdc,(int *)local_10);
    FUN_00497d20(&DAT_004f190b,1,2,(int *)local_10);
    FUN_00497d20(&DAT_004f190d,1,2,(int *)local_10);
    FUN_00497d20((char *)local_c,1,2,(int *)local_10);
    for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
      if (*(int *)(&DAT_004f1820 + local_8 * 4) != 0) {
        FUN_00497d20(s_PADDLE_1_004be192 + local_8 * 0xc,1,8,(int *)local_10);
        local_94._0_2_ = (undefined2)local_8;
        FUN_00497d20((char *)&local_94,1,2,(int *)local_10);
        local_94 = CONCAT22(local_94._2_2_,*(short *)(&DAT_004f1828 + local_8 * 2) + 1);
        FUN_00497d20((char *)&local_94,1,2,(int *)local_10);
        FUN_00497d20(*(char **)(&DAT_004f1820 + local_8 * 4),1,(local_94 & 0xffff) << 2,
                     (int *)local_10);
      }
    }
    FUN_00497b30((int *)local_10);
  }
  local_10 = (uint *)FUN_00497d00((LPCSTR)local_90,"rb");
  if (local_10 != (uint *)0x0) {
    FUN_004988b0(local_10,0,2);
    local_98 = FUN_00498dc0(local_10);
    FUN_004988b0(local_10,0,0);
    local_9c = (0x808 - (local_98 + 8U & 0x7ff)) + local_98;
    local_a0 = (byte *)FUN_00494840(local_9c);
    _memset(local_a0,0,local_9c);
    FUN_004989e0((char *)local_a0,1,local_9c,(int *)local_10);
    FUN_00497b30((int *)local_10);
    local_a4 = FUN_004656b0(local_a0,local_9c - 8);
    local_a0[local_9c - 8] = 0x43;
    local_a0[local_9c - 7] = 0x52;
    local_a0[local_9c - 6] = 0x43;
    local_a0[local_9c - 5] = 0x33;
    FUN_00497690((undefined4 *)(local_a0 + (local_9c - 4)),&local_a4,4);
    local_10 = (uint *)FUN_00497d00((LPCSTR)local_90,"wb");
    FUN_00497d20((char *)local_a0,1,local_9c,(int *)local_10);
    FUN_00497b30((int *)local_10);
  }
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    if ((*(int *)(&DAT_004f1820 + local_8 * 4) != 0) &&
       (*(int *)(&DAT_004f1820 + local_8 * 4) != -0x22222223)) {
      FUN_00495280(*(void **)(&DAT_004f1820 + local_8 * 4));
    }
  }
  DAT_004e8974 = 0;
  local_8 = 0x472f66;
  __chkesp();
  return;
}

