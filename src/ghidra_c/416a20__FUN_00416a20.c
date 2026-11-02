/* FUN_00416a20 @ 00416a20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00416a20(undefined4 param_1,void *param_2)

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
  uVar1 = FUN_004074b0(param_2,3);
  switch(uVar1) {
  case 0:
    DAT_004f23f8 = FUN_00466900;
    break;
  case 1:
    DAT_004f23f8 = FUN_00466cf0;
    break;
  case 2:
    DAT_004f23f8 = FUN_00466f10;
    break;
  case 3:
    DAT_004f23f8 = FUN_00467830;
    break;
  case 5:
    DAT_004f23f8 = FUN_00467230;
    break;
  case 6:
    DAT_004f23f8 = FUN_004670a0;
    break;
  case 7:
    DAT_004f23f8 = FUN_00467a70;
    break;
  case 8:
    DAT_004f23f8 = FUN_00465a40;
    break;
  case 9:
    DAT_004f23f8 = FUN_004689f0;
    break;
  case 10:
    DAT_004f23f8 = FUN_00468bd0;
    break;
  case 0xb:
    DAT_004f23f8 = FUN_00466af0;
    break;
  case 0xc:
    DAT_004f23f8 = FUN_00467300;
    break;
  case 0xd:
    DAT_004f23f8 = FUN_00467370;
    break;
  case 0xe:
    DAT_004f23f8 = FUN_00467550;
    break;
  case 0xf:
    DAT_004f23f8 = FUN_00467b20;
  }
  local_8 = 0x416b27;
  __chkesp();
  return;
}

