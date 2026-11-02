/* FUN_004471b0 @ 004471b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_004471b0(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5
            ,undefined2 param_6)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  undefined4 local_10;
  undefined4 local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  puVar1 = (undefined2 *)FUN_00439a90(DAT_004e85ec,0x40);
  local_10 = 0;
  if (param_1 != 0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
    puVar1[0x12] = param_6;
    puVar1[4] = 0;
    puVar1[5] = 0;
    *(undefined1 *)((int)puVar1 + 0x19) = 0;
    *(undefined1 *)(puVar1 + 0x13) = 0;
    *(undefined1 *)((int)puVar1 + 0x27) = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0;
    puVar1[0x10] = 0;
    puVar1[0x11] = 0;
    *(undefined4 *)(puVar1 + 0x16) = 0;
    *(undefined4 *)(puVar1 + 0x18) = 0;
    *(undefined4 *)(puVar1 + 0x1a) = 0;
    *(undefined1 *)(puVar1 + 0x14) = 0;
    *(undefined1 *)(puVar1 + 0xd) = 1;
    *(undefined1 *)(puVar1 + 9) = 0x80;
    *(undefined1 *)((int)puVar1 + 0x13) = 0x80;
    *(undefined1 *)(puVar1 + 10) = 0x80;
    *(undefined1 *)((int)puVar1 + 0x15) = 0x80;
    *(undefined1 *)(puVar1 + 0xb) = 0x80;
    *(undefined1 *)((int)puVar1 + 0x17) = 0x80;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    *(undefined1 *)(puVar1 + 0xc) = 0xff;
    *(undefined4 *)(puVar1 + 0x1c) = 0;
    *(undefined4 *)(puVar1 + 0x1e) = 0;
    if (*(int *)(param_1 + 8) == 0) {
      *(undefined2 **)(param_1 + 0xc) = puVar1;
    }
    else {
      *(undefined2 **)(*(int *)(param_1 + 8) + 0x2c) = puVar1;
    }
    *(undefined2 **)(param_1 + 8) = puVar1;
    *(char *)(param_1 + 0x12) = *(char *)(param_1 + 0x12) + '\x01';
  }
  local_8 = 0x44734a;
  __chkesp();
  return;
}

