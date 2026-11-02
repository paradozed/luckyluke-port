/* FUN_00421f60 @ 00421f60 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00421f60(void *this,uint param_1,undefined2 param_2,undefined2 param_3)

{
  uint uVar1;
  void *this_00;
  undefined2 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  void *local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = CONCAT22(0xcccc,param_2);
  local_8 = this;
  this_00 = (void *)FUN_00421420(this,param_1 & 0xffff);
  puVar2 = (undefined2 *)FUN_00421fc0(this_00,uVar1);
  *puVar2 = param_3;
  local_8 = (void *)0x421faf;
  __chkesp();
  return;
}

