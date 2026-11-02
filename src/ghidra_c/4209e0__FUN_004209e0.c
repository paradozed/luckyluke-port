/* FUN_004209e0 @ 004209e0 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_004209e0(void *this,uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 < *(uint *)((int)this + 0xc)) &&
     (*(int *)(*(int *)((int)this + 4) + param_1 * 4) == 0)) {
    *(undefined4 *)(*(int *)((int)this + 4) + param_1 * 4) = param_2;
  }
  return;
}

