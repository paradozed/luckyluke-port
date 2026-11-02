/* FUN_0041d0e0 @ 0041d0e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041d0e0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004e866c != '\x01') {
    if (DAT_004f2b68 == 0) {
      sVar1 = FUN_004074b0(param_2,2);
      DAT_004f2b6c = DAT_004f2b6c + sVar1;
    }
    else {
      sVar1 = FUN_004074b0(param_2,2);
      DAT_004f2bec = DAT_004f2bec + sVar1;
      if (2000 < DAT_004f2bec) {
        DAT_004f2bec = 2000;
      }
      if (DAT_004f2bec < 0) {
        DAT_004f2bec = 0;
      }
    }
  }
  uStack_8 = 0x41d17d;
  __chkesp();
  return;
}

