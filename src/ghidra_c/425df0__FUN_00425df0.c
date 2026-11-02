/* FUN_00425df0 @ 00425df0 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00425df0(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(*(int *)((int)this + (uint)*(byte *)((int)this + 0x44) * 4 + 4) + 4) = param_1;
  return;
}

