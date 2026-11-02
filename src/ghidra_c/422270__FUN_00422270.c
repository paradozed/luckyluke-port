/* FUN_00422270 @ 00422270 */
/* decompiled from Lucky.exe (Game.run) */


int __thiscall FUN_00422270(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(int *)((int)this + 4) + param_1 * 4;
}

