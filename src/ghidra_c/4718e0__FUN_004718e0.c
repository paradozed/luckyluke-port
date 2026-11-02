/* FUN_004718e0 @ 004718e0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004718e0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  _DAT_004be110 = param_1;
  uVar3 = __alldiv(DAT_004be108,DAT_004be10c,param_1,(int)param_1 >> 0x1f);
  DAT_004e894c = (undefined4)((ulonglong)uVar3 >> 0x20);
  DAT_004e8948 = (undefined4)uVar3;
  uStack_8 = 0x471931;
  __chkesp();
  return;
}

