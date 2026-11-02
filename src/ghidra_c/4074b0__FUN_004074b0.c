/* FUN_004074b0 @ 004074b0 */
/* decompiled from Lucky.exe (Game.run) */


undefined2 __thiscall FUN_004074b0(void *this,int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [18];
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return *(undefined2 *)((int)this + (*(int *)((int)this + 100) - param_1) * 2);
}

