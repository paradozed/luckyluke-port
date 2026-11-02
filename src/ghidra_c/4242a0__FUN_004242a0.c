/* FUN_004242a0 @ 004242a0 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_004242a0(void *this,short param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(short *)((int)this + 0x72) != param_1) {
    *(undefined4 *)((int)this + 0x74) = 1;
  }
  *(short *)((int)this + 0x72) = param_1;
  return;
}

