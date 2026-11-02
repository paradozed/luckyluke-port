/* FUN_004277b0 @ 004277b0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004277b0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  undefined4 local_5c [16];
  float local_1c;
  float local_18;
  int local_14;
  int local_10;
  float local_c;
  float local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = param_1 - DAT_004d28b4;
  local_8 = (float)local_10;
  local_14 = param_2 - DAT_004d28b0;
  local_c = (float)local_14;
  local_18 = local_8;
  if (local_8 < _DAT_004b4938) {
    local_18 = -local_8;
  }
  local_1c = local_c;
  if (local_c < _DAT_004b4938) {
    local_1c = -local_c;
  }
  fVar3 = (float10)FUN_004980e0(SUB84((double)local_1c,0),(int)((ulonglong)(double)local_1c >> 0x20)
                                ,SUB84((double)local_18,0),
                                (int)((ulonglong)(double)local_18 >> 0x20));
  DAT_004d2924 = (float)fVar3;
  if ((local_8 <= _DAT_004b4938) && (local_c < _DAT_004b4938)) {
    DAT_004d2924 = (float)_DAT_004b4950 - DAT_004d2924;
  }
  if ((local_8 <= _DAT_004b4938) && (_DAT_004b4938 <= local_c)) {
    DAT_004d2924 = DAT_004d2924 + (float)_DAT_004b4950;
  }
  if ((_DAT_004b4938 < local_8) && (_DAT_004b4938 <= local_c)) {
    DAT_004d2924 = (float)_DAT_004b4948 - DAT_004d2924;
  }
  if ((_DAT_004b4938 < local_8) && (local_c < _DAT_004b4938)) {
    DAT_004d2924 = DAT_004d2924 + (float)_DAT_004b4948;
  }
  __chkesp();
  return;
}

