/* FUN_00444060 @ 00444060 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00444060(short *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  short *local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = *(short **)(param_2 + 8);
  while ((((local_8 != (short *)0x0 && (*param_1 < 0x100)) && (param_1[1] < 0x100)) &&
         ((((int)*param_1 + (int)param_1[2] < 0x101 && ((int)param_1[1] + (int)param_1[3] < 0x101))
          && (uVar1 = FUN_00444120(param_1,local_8), (uVar1 & 0xff) == 0))))) {
    local_8 = *(short **)(local_8 + 6);
  }
  local_8 = (short *)0x444119;
  __chkesp();
  return;
}

