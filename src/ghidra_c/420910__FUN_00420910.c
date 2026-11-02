/* FUN_00420910 @ 00420910 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00420910(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1;
  if (*param_1 != -0x22222223) {
    FUN_00495280((void *)*param_1);
  }
  if (local_8[1] != -0x22222223) {
    FUN_00495280((void *)local_8[1]);
  }
  *local_8 = 0;
  *local_8 = 0;
  local_8 = (int *)0x420980;
  __chkesp();
  return;
}

