/* FUN_004257b0 @ 004257b0 */
/* decompiled from Lucky.exe (Game.run) */


uint __thiscall FUN_004257b0(void *this,short param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [17];
  void *local_c;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(short *)(*(int *)((int)this + 0x84) + 6) != 0) {
    iVar1 = *(int *)((int)this + 0x84) + (uint)*(ushort *)(*(int *)((int)this + 0x84) + 4);
    for (local_c = (void *)0x0;
        ((int)local_c < (int)(uint)*(ushort *)(*(int *)((int)this + 0x84) + 6) &&
        (*(short *)(iVar1 + (int)local_c * 4) != param_1)); local_c = (void *)((int)local_c + 1)) {
    }
    this = (void *)(uint)*(ushort *)(*(int *)((int)this + 0x84) + 6);
    if (local_c != this) {
      return (uint)*(ushort *)(iVar1 + 2 + (int)local_c * 4);
    }
  }
  return (uint)this & 0xffff0000;
}

