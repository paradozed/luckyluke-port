/* FUN_0043b790 @ 0043b790 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043b790(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(undefined4 *)(param_2 + 0x38);
  local_c = *(undefined4 *)(param_2 + 0x3c);
  local_10 = *(undefined4 *)(param_2 + 0x40);
  FUN_0043a8c0(param_1,*(int *)(param_2 + 0x2c),*(int *)(param_2 + 0x30),*(int *)(param_2 + 0x34),
               &local_8,&local_c,&local_10);
  *(undefined1 *)(param_2 + 0x20) = (undefined1)local_8;
  *(undefined1 *)(param_2 + 0x14) = (undefined1)local_8;
  *(undefined1 *)(param_2 + 8) = (undefined1)local_8;
  *(undefined1 *)(param_2 + 0x21) = (undefined1)local_c;
  *(undefined1 *)(param_2 + 0x15) = (undefined1)local_c;
  *(undefined1 *)(param_2 + 9) = (undefined1)local_c;
  *(undefined1 *)(param_2 + 0x22) = (undefined1)local_10;
  *(undefined1 *)(param_2 + 0x16) = (undefined1)local_10;
  *(undefined1 *)(param_2 + 10) = (undefined1)local_10;
  local_8 = 0x43b84e;
  __chkesp();
  return;
}

