/* FUN_0041c230 @ 0041c230 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041c230(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  int local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if ((DAT_004e866c != '\x01') || (sVar1 = FUN_004074b0(param_2,2), sVar1 == 10)) {
    sVar1 = FUN_004074b0(param_2,2);
    local_8 = (int)sVar1;
    switch(local_8) {
    case 0:
    case 1:
      PTR_FUN_004bd5d8 = FUN_00453590;
      sVar1 = FUN_004074b0(param_2,2);
      DAT_004f2b60 = (ushort)(sVar1 != 0);
      DAT_004f2bf8 = 0;
      DAT_004f2bc2 = FUN_004074b0(param_2,3);
      if (0x3ff < DAT_004f2bc2) {
        DAT_004f2bc2 = 0x3ff;
      }
      if (DAT_004f2bc2 < 0x80) {
        DAT_004f2bc2 = 0x80;
      }
      break;
    case 2:
    case 3:
    case 4:
    case 5:
      PTR_FUN_004bd5d8 = FUN_00453590;
      DAT_004f2bf8 = FUN_004074b0(param_2,2);
      DAT_004f2bc2 = FUN_004074b0(param_2,3);
      if (0x3ff < DAT_004f2bc2) {
        DAT_004f2bc2 = 0x3ff;
      }
      if (DAT_004f2bc2 < 0x80) {
        DAT_004f2bc2 = 0x80;
      }
      break;
    case 6:
      PTR_FUN_004bd5d8 = FUN_00453140;
      break;
    case 9:
      PTR_FUN_004bd5d8 = FUN_00455bd0;
      DAT_004f2bc2 = FUN_004074b0(param_2,3);
      break;
    case 10:
      uVar2 = FUN_004074b0(param_2,3);
      DAT_004e866c = (char)uVar2;
    }
  }
  local_8 = 0x41c3b2;
  __chkesp();
  return;
}

