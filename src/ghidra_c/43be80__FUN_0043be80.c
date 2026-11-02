/* FUN_0043be80 @ 0043be80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0043be80(int param_1,int param_2,undefined2 param_3,undefined1 param_4,undefined1 param_5,
            undefined1 param_6,undefined1 param_7,undefined1 param_8,undefined1 param_9)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_70 [20];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = local_70;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x14) + param_2 * 0x54);
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    local_10 = *(undefined4 *)(iVar2 + 0x18);
    local_c = *(undefined4 *)(iVar2 + 0x1c);
    local_8 = *(undefined4 *)(iVar2 + 0x20);
    local_18 = *(undefined4 *)(iVar2 + 0x24);
    local_1c = *(undefined4 *)(iVar2 + 0x28);
    local_20 = *(undefined4 *)(iVar2 + 0x2c);
  }
  else if (iVar2 == 4) {
    iVar2 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    local_10 = *(undefined4 *)(iVar2 + 0x20);
    local_c = *(undefined4 *)(iVar2 + 0x24);
    local_8 = *(undefined4 *)(iVar2 + 0x28);
    local_18 = *(undefined4 *)(iVar2 + 0x2c);
    local_1c = *(undefined4 *)(iVar2 + 0x30);
    local_20 = *(undefined4 *)(iVar2 + 0x34);
  }
  else if (iVar2 == 6) {
    iVar2 = *(int *)(param_1 + 0x14) + param_2 * 0x54;
    local_10 = *(undefined4 *)(iVar2 + 0x2c);
    local_c = *(undefined4 *)(iVar2 + 0x30);
    local_8 = *(undefined4 *)(iVar2 + 0x34);
    local_18 = *(undefined4 *)(iVar2 + 0x38);
    local_1c = *(undefined4 *)(iVar2 + 0x3c);
    local_20 = *(undefined4 *)(iVar2 + 0x40);
  }
  puVar1 = (undefined4 *)(*(int *)(param_1 + 0x14) + param_2 * 0x54);
  puVar1[9] = local_10;
  puVar1[10] = local_c;
  puVar1[0xb] = local_8;
  *(undefined1 *)(puVar1 + 4) = param_4;
  *(undefined1 *)((int)puVar1 + 0x11) = param_5;
  *(undefined1 *)(puVar1 + 6) = param_6;
  *(undefined1 *)((int)puVar1 + 0x19) = param_7;
  *(undefined1 *)(puVar1 + 8) = param_8;
  *(undefined1 *)((int)puVar1 + 0x21) = param_9;
  puVar1[0xc] = local_18;
  puVar1[0xd] = local_1c;
  puVar1[0xe] = local_20;
  *(undefined2 *)((int)puVar1 + 0x1a) = param_3;
  *puVar1 = 2;
  return;
}

