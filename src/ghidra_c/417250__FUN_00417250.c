/* FUN_00417250 @ 00417250 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00417250(void *this,byte param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_2 == 0) {
    *(byte *)((int)this + 0x80) = *(byte *)((int)this + 0x80) & ~param_1;
  }
  else {
    *(byte *)((int)this + 0x80) = *(byte *)((int)this + 0x80) | param_1;
  }
  return;
}

