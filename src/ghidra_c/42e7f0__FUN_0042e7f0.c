/* FUN_0042e7f0 @ 0042e7f0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042e7f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (undefined4 *)FUN_0042cb20((uint *)"SA_MURS",0);
  if (local_8 != (undefined4 *)0x0) {
    FUN_00497690(local_8,(undefined4 *)&DAT_004e8380,0xe8);
    (**(code **)(*(int *)(DAT_004e8378 + 0xd0) + 0x10))(DAT_004e8378);
    __chkesp();
  }
  DAT_004bc738 = 1;
  local_8 = (undefined4 *)0x42e86f;
  __chkesp();
  return;
}

