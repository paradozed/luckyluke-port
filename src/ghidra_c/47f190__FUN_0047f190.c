/* FUN_0047f190 @ 0047f190 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047f190(byte *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (((*param_1 & 2) == 0) && (*(int *)(param_1 + 0xbc) != 0)) {
    FUN_00439c30(*(PVOID *)(param_1 + 0xbc));
    param_1[0xbc] = 0;
    param_1[0xbd] = 0;
    param_1[0xbe] = 0;
    param_1[0xbf] = 0;
    param_1[0xc0] = 0;
    param_1[0xc1] = 0;
    param_1[0xc2] = 0;
    param_1[0xc3] = 0;
    param_1[0x20] = 0;
    param_1[0x21] = 0;
    param_1[0x22] = 0;
    param_1[0x23] = 0;
    param_1[0x4c] = 0;
    param_1[0x4d] = 0;
    param_1[0x4e] = 0;
    param_1[0x4f] = 0;
    param_1[0x50] = 0;
    param_1[0x51] = 0;
    param_1[0x52] = 0;
    param_1[0x53] = 0;
  }
  if (*(int *)(param_1 + 0xc4) != 0) {
    FUN_004851b0((int)param_1);
    param_1[0xc4] = 0;
    param_1[0xc5] = 0;
    param_1[0xc6] = 0;
    param_1[199] = 0;
  }
  if (*(int *)(param_1 + 0xcc) != 0) {
    FUN_00485d70((int)param_1);
    param_1[0xcc] = 0;
    param_1[0xcd] = 0;
    param_1[0xce] = 0;
    param_1[0xcf] = 0;
  }
  FUN_0047f280((int)param_1);
  *param_1 = *param_1 & 0xfe;
  uStack_8 = 0x47f27b;
  __chkesp();
  return;
}

