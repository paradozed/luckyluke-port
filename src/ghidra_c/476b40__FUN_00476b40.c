/* FUN_00476b40 @ 00476b40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00476b40(undefined4 *param_1,int param_2,undefined2 param_3,undefined2 param_4)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_78 [16];
  short local_38;
  undefined2 local_34;
  int local_30;
  short local_2c;
  undefined2 local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  undefined2 local_18;
  uint local_8;
  
  puVar4 = local_78;
  for (iVar2 = 0x1d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_18 = 0;
  local_1c = local_1c & 0xffff0000;
  local_20 = local_20 & 0xffff0000;
  local_8 = local_8 & 0xffff0000;
  while (((local_8 & 0xffff) < 10 && (((local_1c & 0xffff) == 0 || ((local_20 & 0xffff) == 0))))) {
    if ((*(short *)(&DAT_004f13ca + (local_8 & 0xffff) * 0x2c) == 0) && ((local_1c & 0xffff) == 0))
    {
      local_18 = (short)local_8;
      local_1c = CONCAT22(local_1c._2_2_,1);
      *(undefined2 *)(&DAT_004f13ca + (local_8 & 0xffff) * 0x2c) = param_4;
      *(undefined2 *)(&DAT_004f13c8 + (local_8 & 0xffff) * 0x2c) = 1;
      *(undefined2 *)(&DAT_004f13e0 + (local_8 & 0xffff) * 0x2c) = param_3;
      local_24 = *(int *)(*(int *)(*(int *)(&DAT_004f13c0 + (local_8 & 0xffff) * 0x2c) + 0xcc) +
                         0x28);
      local_28 = *(undefined2 *)(*(int *)(local_24 + 8) + 4);
      local_2c = FUN_00476f70(local_24);
      local_2c = local_2c + -1;
      FUN_00485a70(*(byte **)(&DAT_004f13c0 + (local_8 & 0xffff) * 0x2c),local_24,0,0,local_2c,0,0,4
                  );
      sVar1 = FUN_00482c60(*(short *)(param_2 + 2) + -0x400);
      *(int *)(&DAT_004f13d0 + (local_8 & 0xffff) * 0x2c) = (int)sVar1;
      uVar3 = local_8 & 0xffff;
      sVar1 = FUN_00482c60(*(short *)(param_2 + 4));
      *(int *)(&DAT_004f13d0 + (local_8 & 0xffff) * 0x2c) =
           *(int *)(&DAT_004f13d0 + uVar3 * 0x2c) * (int)sVar1;
      *(int *)(&DAT_004f13d0 + (local_8 & 0xffff) * 0x2c) =
           *(int *)(&DAT_004f13d0 + (local_8 & 0xffff) * 0x2c) >> 0x10;
      sVar1 = FUN_00482cb0(*(short *)(param_2 + 2) + -0x400);
      *(int *)(&DAT_004f13d8 + (local_8 & 0xffff) * 0x2c) = (int)sVar1;
      uVar3 = local_8 & 0xffff;
      sVar1 = FUN_00482c60(*(short *)(param_2 + 4));
      *(int *)(&DAT_004f13d8 + (local_8 & 0xffff) * 0x2c) =
           *(int *)(&DAT_004f13d8 + uVar3 * 0x2c) * (int)sVar1;
      *(int *)(&DAT_004f13d8 + (local_8 & 0xffff) * 0x2c) =
           *(int *)(&DAT_004f13d8 + (local_8 & 0xffff) * 0x2c) >> 0x10;
      sVar1 = FUN_00482cb0(*(short *)(param_2 + 4));
      *(int *)(&DAT_004f13d4 + (local_8 & 0xffff) * 0x2c) = -(int)sVar1;
      *(int *)(&DAT_004f13d4 + (local_8 & 0xffff) * 0x2c) =
           *(int *)(&DAT_004f13d4 + (local_8 & 0xffff) * 0x2c) >> 4;
      FUN_004739f0(*(int *)(&DAT_004f13c0 + (local_8 & 0xffff) * 0x2c),*param_1,param_1[1],
                   param_1[2]);
    }
    if ((*(short *)(&DAT_004f13cc + (local_8 & 0xffff) * 0x2c) == 0) && ((local_20 & 0xffff) == 0))
    {
      local_20 = CONCAT22(local_20._2_2_,1);
      *(undefined2 *)(&DAT_004f13cc + (local_8 & 0xffff) * 0x2c) = 1;
      local_30 = *(int *)(*(int *)(*(int *)(&DAT_004f13c4 + (local_8 & 0xffff) * 0x2c) + 0xcc) +
                         0x28);
      local_34 = *(undefined2 *)(*(int *)(local_30 + 8) + 4);
      local_38 = FUN_00476f70(local_30);
      local_38 = local_38 + -1;
      FUN_00485a70(*(byte **)(&DAT_004f13c4 + (local_8 & 0xffff) * 0x2c),local_30,0,0,local_38,0,0,4
                  );
      FUN_00476fa0(*(int *)(&DAT_004f13c4 + (local_8 & 0xffff) * 0x2c),FUN_00476b10,
                   &DAT_004f13c0 + (local_8 & 0xffff) * 0x2c);
      FUN_004739f0(*(int *)(&DAT_004f13c4 + (local_8 & 0xffff) * 0x2c),*param_1,param_1[1],
                   param_1[2]);
    }
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  local_8 = 0x476f69;
  __chkesp();
  return;
}

