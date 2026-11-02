/* FUN_00459a80 @ 00459a80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00459a80(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  if ((DAT_004f2458 != (int *)0x0) && (*(int *)(*DAT_004f2458 + 0xe4) != 0)) {
    local_c = param_1 & 0xffff;
    if ((local_c != 0) && ((local_c != 1 && (local_c != 2)))) {
      FUN_00497610((byte *)"Error: File %s, Line %d");
    }
    local_10 = (uint)**(byte **)(*(int *)(*DAT_004f2458 + 0xe4) + 0x14);
    switch(local_10) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    default:
      FUN_004266b0();
    }
  }
  local_8 = 0x459b7a;
  __chkesp();
  return;
}

