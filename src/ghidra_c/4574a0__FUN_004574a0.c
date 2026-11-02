/* FUN_004574a0 @ 004574a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004574a0(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_74 [16];
  int local_34 [6];
  int local_1c [5];
  undefined4 uStack_8;
  
  puVar2 = local_74;
  for (iVar1 = 0x1c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_0040da10(param_1,0,local_1c);
  FUN_0040da10(param_2,0,local_34);
  FUN_0040d810(local_1c,local_34);
  uStack_8 = 0x457506;
  __chkesp();
  return;
}

