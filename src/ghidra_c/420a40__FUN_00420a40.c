/* FUN_00420a40 @ 00420a40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00420a40(undefined4 param_1,void *param_2,undefined4 param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_004074b0(param_2,1);
  local_8 = CONCAT22(local_8._2_2_,uVar1);
  if ((uVar1 < DAT_004d2898) && (*(int *)(DAT_004d2890 + (uint)uVar1 * 4) != 0)) {
    (**(code **)(DAT_004d2890 + (uint)uVar1 * 4))(param_1,param_2,param_3);
    __chkesp();
  }
  local_8 = 0x420ac5;
  __chkesp();
  return;
}

