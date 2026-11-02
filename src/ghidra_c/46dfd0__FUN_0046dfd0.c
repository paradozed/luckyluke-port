/* FUN_0046dfd0 @ 0046dfd0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046dfd0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar1 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = 0xcccccccc;
    puVar1 = puVar1 + 1;
  }
  puVar1 = (undefined4 *)FUN_00494c40(0xc,1);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  local_8 = 0x46e024;
  __chkesp();
  return;
}

