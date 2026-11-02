/* FUN_00402b80 @ 00402b80 */
/* decompiled from Lucky.exe (Game.run) */


undefined * __thiscall FUN_00402b80(void *this,int param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 < 0) {
    puVar1 = &DAT_004b33d4;
  }
  else if (param_1 < *(int *)((int)this + 0x34)) {
    puVar1 = (undefined *)((int)this + param_1 * 0x94 + 0xf4);
  }
  else {
    puVar1 = &DAT_004b33d4;
  }
  return puVar1;
}

