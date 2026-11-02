/* FUN_0043d0f0 @ 0043d0f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043d0f0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined4 local_48 [16];
  float local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  param_1[10] = param_1[4];
  fVar3 = (float10)FUN_00497f54(param_1);
  local_8 = (float)fVar3;
  param_1[0xb] = (int)(float)(fVar3 * (float10)(float)param_1[3] + (float10)(float)param_1[5]);
  param_1[0xc] = param_1[6];
  FUN_0043a2f0((float *)(*param_1 + 0x18),(float *)(param_1 + 10));
  local_8 = 6.228117e-39;
  __chkesp();
  return;
}

