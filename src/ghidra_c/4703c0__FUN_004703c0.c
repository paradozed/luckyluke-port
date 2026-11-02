/* FUN_004703c0 @ 004703c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004703c0(int param_1,int param_2,undefined4 param_3,int param_4)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_68 [16];
  short local_28;
  ushort local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  short local_c;
  int local_8;
  
  puVar3 = local_68;
  for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = param_4;
  local_c = -*(short *)(param_2 + 4);
  if ((*(ushort *)(param_4 + 0x40) & 8) == 0) {
    *(short *)(param_4 + 0x3e) = *(short *)(param_4 + 0x3e) + local_c + *(short *)(param_4 + 0x38);
  }
  else {
    *(short *)(param_4 + 0x3e) = *(short *)(param_4 + 0x3e) - (local_c + *(short *)(param_4 + 0x38))
    ;
  }
  *(ushort *)(param_4 + 0x40) = *(ushort *)(param_4 + 0x40) & 0xffbf;
  if ((*(short *)(param_4 + 0x3c) < *(short *)(param_4 + 0x3e)) || (*(short *)(param_4 + 0x3e) < 0))
  {
    local_24 = 0;
    local_28 = 0;
    FUN_00470200(param_4);
    if ((*(ushort *)(local_8 + 0x40) & 0x10) != 0) {
      sVar1 = FUN_004836a0((int)*(short *)(local_8 + 0x34),(int)*(short *)(local_8 + 0x30));
      local_24 = -(sVar1 + 0x400);
      *(ushort *)(local_8 + 0x42) = local_24;
      *(ushort *)(local_8 + 0x42) = *(ushort *)(local_8 + 0x42) & 0xfff;
      if ((*(ushort *)(local_8 + 0x40) & 8) != 0) {
        local_24 = local_24 + 0x800;
      }
      local_24 = local_24 & 0xfff;
    }
    if ((*(ushort *)(local_8 + 0x40) & 0x20) != 0) {
      local_28 = FUN_004836a0((int)*(short *)(local_8 + 0x32),(int)*(short *)(local_8 + 0x3c));
      *(short *)(local_8 + 0x44) = local_28;
    }
    if ((*(ushort *)(local_8 + 0x40) & 0x30) != 0) {
      FUN_0047c7f0((undefined2 *)(param_1 + 0x5c),local_28,local_24,0);
    }
  }
  local_10 = ((int)*(short *)(local_8 + 0x3e) << 0x10) / (int)*(short *)(local_8 + 0x3c);
  local_20 = *(int *)(local_8 + 0x20) + (*(short *)(local_8 + 0x30) * local_10 >> 0x10);
  local_1c = *(int *)(local_8 + 0x24) + (*(short *)(local_8 + 0x32) * local_10 >> 0x10);
  local_18 = *(int *)(local_8 + 0x28) + (*(short *)(local_8 + 0x34) * local_10 >> 0x10);
  FUN_00470600(param_1,local_20,local_1c,local_18);
  local_8 = 0x4705ee;
  __chkesp();
  return;
}

