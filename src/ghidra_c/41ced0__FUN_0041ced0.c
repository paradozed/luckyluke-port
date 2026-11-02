/* FUN_0041ced0 @ 0041ced0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041ced0(undefined4 param_1,void *param_2)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [16];
  int local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (DAT_004e866c != '\x01') {
    sVar1 = FUN_004074b0(param_2,2);
    local_8 = (int)sVar1;
    switch(local_8) {
    case 0:
      if ((DAT_004f2458[4] & 8U) == 0) {
        if (DAT_004f2b65 != '\x03') {
          DAT_004f2c38 = FUN_00457510(*(int *)(*DAT_004f2458 + 0xe4));
        }
      }
      else {
        DAT_004f2c38 = *(int *)(*DAT_004f2458 + 0x94);
      }
      DAT_004f2b65 = '\0';
      DAT_004bc4ec = 20000;
      break;
    case 1:
      uVar2 = FUN_0041e3c0();
      if ((uVar2 & 0xff) == 0) {
        DAT_004f2b65 = '\x01';
      }
      else {
        DAT_004f2b65 = '\x02';
      }
      DAT_004bc4ec = 20000;
      break;
    case 3:
      if ((DAT_004f2b65 != '\0') && ((DAT_004f2458[4] & 8U) != 0)) {
        DAT_004f2c38 = *(int *)(*DAT_004f2458 + 0x94);
      }
      DAT_004f2b65 = '\x03';
      DAT_004bc4ec = 20000;
      break;
    case 4:
      DAT_004f2b65 = '\x04';
      DAT_004bc4ec = 8000;
    }
  }
  local_8 = 0x41d002;
  __chkesp();
  return;
}

