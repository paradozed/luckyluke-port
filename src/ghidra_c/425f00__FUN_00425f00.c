/* FUN_00425f00 @ 00425f00 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00425f00(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 0x48) = param_1;
  *(undefined1 *)this = 0;
  return;
}

