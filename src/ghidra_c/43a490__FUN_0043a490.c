/* FUN_0043a490 @ 0043a490 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043a490(float *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  fVar4 = (float10)FUN_00497534(param_1);
  fVar1 = (float)fVar4;
  *param_1 = *param_1 / fVar1;
  param_1[1] = param_1[1] / fVar1;
  param_1[2] = param_1[2] / fVar1;
  local_8 = 0x43a517;
  __chkesp();
  return;
}

