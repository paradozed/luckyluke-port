/* FUN_00421fc0 @ 00421fc0 */
/* decompiled from Lucky.exe (Game.run) */


int __thiscall FUN_00421fc0(void *this,uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return (param_1 & 0xffff) + *(int *)((int)this + 0x84);
}

