/* FUN_0047c470 @ 0047c470 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047c470(short *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_004834d0(*param_1);
  local_8 = CONCAT22(local_8._2_2_,uVar1);
  FUN_00483540(param_1[2]);
  local_8 = 0x47c4d7;
  __chkesp();
  return;
}

