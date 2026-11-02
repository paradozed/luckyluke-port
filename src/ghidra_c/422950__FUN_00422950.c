/* FUN_00422950 @ 00422950 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall
FUN_00422950(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,size_t param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  undefined4 *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = this;
  FUN_004258b0((int)this + 8);
  *local_8 = param_1;
  local_8[1] = 0;
  *(undefined2 *)(local_8 + 0x1c) = 0xffff;
  *(undefined2 *)((int)local_8 + 0x72) = 0;
  local_8[0x1d] = 0;
  local_8[0x1e] = local_8;
  *(undefined2 *)(local_8 + 0x1f) = 0;
  *(undefined2 *)((int)local_8 + 0x7e) = 0;
  *(undefined1 *)(local_8 + 0x20) = 0;
  local_c = FUN_00496760(param_4);
  local_8[0x21] = local_c;
  if (local_c == 0) {
    FUN_00477a60();
  }
  (*DAT_004d28a8)(param_2,local_8[0x21],param_4,param_3);
  iVar1 = __chkesp();
  if (iVar1 < 0) {
    FUN_00477a60();
  }
  if (*(short *)(local_8[0x21] + 0xe) == 0) {
    local_8[0x22] = 0;
  }
  else {
    local_8[0x22] = local_8[0x21] + 0x10;
  }
  local_8[0x23] = param_4;
  local_8[0x24] = param_5;
  local_8[0x25] = 0;
  local_8 = (undefined4 *)0x422a9e;
  __chkesp();
  return;
}

