/* FUN_0046de90 @ 0046de90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046de90(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  size_t local_c;
  int *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_2 + 0xc;
  local_8 = (int *)FUN_00494c40(local_c,1);
  _memset(local_8,0,local_c);
  FUN_0046de30(local_8,param_1);
  local_8 = (int *)0x46def4;
  __chkesp();
  return;
}

