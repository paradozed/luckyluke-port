/* FUN_00470860 @ 00470860 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470860(int param_1,int param_2,ushort param_3)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_58 [16];
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  PVOID local_8;
  
  puVar4 = local_58;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_18 = *(int *)(param_1 + 0x90);
  local_14 = *(undefined4 *)(param_1 + 0x94);
  local_10 = *(undefined4 *)(param_1 + 0x98);
  local_8 = *(PVOID *)(param_1 + 0xe4);
  if (local_8 != (PVOID)0x0) {
    FUN_00470700(local_8);
  }
  local_8 = (PVOID)FUN_00470780(param_2,&local_18,param_3);
  *(int *)((int)local_8 + 0x48) = param_1;
  if ((*(ushort *)((int)local_8 + 0x40) & 0x30) != 0) {
    if ((*(ushort *)((int)local_8 + 0x40) & 0x10) != 0) {
      sVar1 = FUN_004836a0((int)*(short *)((int)local_8 + 0x34),(int)*(short *)((int)local_8 + 0x30)
                          );
      *(short *)((int)local_8 + 0x42) = -(sVar1 + 0x400);
      *(ushort *)((int)local_8 + 0x42) = *(ushort *)((int)local_8 + 0x42) & 0xfff;
    }
    if ((*(ushort *)((int)local_8 + 0x40) & 0x20) != 0) {
      uVar2 = FUN_004836a0((int)*(short *)((int)local_8 + 0x32),(int)*(short *)((int)local_8 + 0x3c)
                          );
      *(undefined2 *)((int)local_8 + 0x44) = uVar2;
    }
    FUN_0047c7f0((undefined2 *)(param_1 + 0x5c),*(short *)((int)local_8 + 0x44),
                 *(short *)((int)local_8 + 0x42),0);
  }
  FUN_00470600(param_1,*(undefined4 *)((int)local_8 + 0x20),*(undefined4 *)((int)local_8 + 0x24),
               *(undefined4 *)((int)local_8 + 0x28));
  FUN_00481ac0(param_1,1);
  FUN_004709f0(param_1,FUN_004703c0,local_8);
  local_8 = (PVOID)0x4709dd;
  __chkesp();
  return;
}

