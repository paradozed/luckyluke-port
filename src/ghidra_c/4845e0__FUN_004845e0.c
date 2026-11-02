/* FUN_004845e0 @ 004845e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_004845e0(int param_1,int param_2,int param_3,int param_4,int param_5,undefined2 param_6)

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
  FUN_00484150(param_1,param_2,param_3,param_4,param_5,CONCAT22(0xcccc,param_6),1);
  if ((*(byte *)(param_2 + 0x3c) & 2) != 0) {
    if (*(char *)(param_1 + 0x37) == '\0') {
      *(short *)(param_2 + 0x44) =
           *(short *)(param_3 + 0x1c) +
           (short)((uint)((((int)*(short *)(param_4 + 0x1c) +
                           (int)*(short *)(*(int *)(param_1 + 8) + 4)) -
                          (int)*(short *)(param_3 + 0x1c)) * param_5) >> 0x10);
      *(short *)(param_2 + 0x46) =
           *(short *)(param_3 + 0x1e) +
           (short)((uint)((((int)*(short *)(param_4 + 0x1e) +
                           (int)*(short *)(*(int *)(param_1 + 8) + 6)) -
                          (int)*(short *)(param_3 + 0x1e)) * param_5) >> 0x10);
      *(short *)(param_2 + 0x48) =
           *(short *)(param_3 + 0x20) +
           (short)((uint)((((int)*(short *)(param_4 + 0x20) +
                           (int)*(short *)(*(int *)(param_1 + 8) + 8)) -
                          (int)*(short *)(param_3 + 0x20)) * param_5) >> 0x10);
    }
    else {
      *(short *)(param_2 + 0x44) =
           *(short *)(param_3 + 0x1c) +
           (short)((uint)((((int)*(short *)(param_4 + 0x1c) -
                           (int)*(short *)(*(int *)(param_1 + 8) + 4)) -
                          (int)*(short *)(param_3 + 0x1c)) * param_5) >> 0x10);
      *(short *)(param_2 + 0x46) =
           *(short *)(param_3 + 0x1e) +
           (short)((uint)((((int)*(short *)(param_4 + 0x1e) -
                           (int)*(short *)(*(int *)(param_1 + 8) + 6)) -
                          (int)*(short *)(param_3 + 0x1e)) * param_5) >> 0x10);
      *(short *)(param_2 + 0x48) =
           *(short *)(param_3 + 0x20) +
           (short)((uint)((((int)*(short *)(param_4 + 0x20) -
                           (int)*(short *)(*(int *)(param_1 + 8) + 8)) -
                          (int)*(short *)(param_3 + 0x20)) * param_5) >> 0x10);
    }
  }
  uStack_8 = 0x484782;
  __chkesp();
  return;
}

