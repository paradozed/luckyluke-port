/* FUN_00422000 @ 00422000 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00422000(void *this,uint param_1,undefined2 param_2)

{
  uint uVar1;
  void *this_00;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  void *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = CONCAT22(0xcccc,param_2);
  local_8 = this;
  this_00 = (void *)FUN_00421420(this,param_1 & 0xffff);
  FUN_00421fc0(this_00,uVar1);
  local_8 = (void *)0x42204b;
  __chkesp();
  return;
}

