/* FUN_0041af80 @ 0041af80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041af80(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  short local_10;
  short local_c;
  undefined4 local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_0041aec0(param_1);
  local_8 = CONCAT22(local_8._2_2_,(short)iVar1);
  iVar1 = FUN_0041af00(param_1);
  local_c = (short)iVar1;
  iVar1 = FUN_0041af40(param_1);
  local_10 = (short)iVar1;
  if (((-1 < (short)local_8) && (-1 < local_c)) && (-1 < local_10)) {
    FUN_0041b010((short)local_8,local_c,local_10);
  }
  local_8 = 0x41b00a;
  __chkesp();
  return;
}

