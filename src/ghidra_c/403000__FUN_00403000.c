/* FUN_00403000 @ 00403000 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_00403000(void *this,int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [17];
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_2 = *(undefined4 *)((int)this + param_1 * 0x94 + 0x134);
  *param_3 = *(undefined4 *)((int)this + param_1 * 0x94 + 0x138);
  return;
}

