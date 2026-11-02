/* FUN_004258f0 @ 004258f0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __thiscall FUN_004258f0(void *this,undefined2 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)((int)this + *(int *)((int)this + 100) * 2) = param_1;
  *(int *)((int)this + 100) = *(int *)((int)this + 100) + 1;
  return CONCAT31((int3)((uint)this >> 8),1);
}

