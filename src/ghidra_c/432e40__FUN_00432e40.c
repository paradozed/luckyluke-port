/* FUN_00432e40 @ 00432e40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00432e40(char *param_1,uint *param_2,byte param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  void *local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (void *)FUN_00431fe0(param_1,param_2);
  local_8 = FUN_00435ee0(param_3,DAT_004e8488,DAT_004e848c,(int)local_c);
  if (local_c != (void *)0xdddddddd) {
    FUN_00495280(local_c);
  }
  local_8 = 0x432eb0;
  __chkesp();
  return;
}

