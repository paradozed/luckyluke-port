/* FUN_004836a0 @ 004836a0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004836a0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined4 local_4c [16];
  double local_c;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  fVar3 = (float10)FUN_004980e0(SUB84((double)param_1,0),(int)((ulonglong)(double)param_1 >> 0x20),
                                SUB84((double)param_2,0),(int)((ulonglong)(double)param_2 >> 0x20));
  local_c = (double)(fVar3 * (float10)_DAT_004b8e40 * (float10)_DAT_004b8e38);
  local_4c[0] = 0x4836ec;
  __ftol();
  __chkesp();
  return;
}

