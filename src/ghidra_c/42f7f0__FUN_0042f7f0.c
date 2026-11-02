/* FUN_0042f7f0 @ 0042f7f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042f7f0(byte *param_1)

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
  if ((param_1 != (byte *)0x0) && (DAT_004e846c != 0)) {
    if (param_1 == DAT_004e8468) {
      FUN_00480040((int)param_1,0xff,0,0);
    }
    else if ((*param_1 & 2) == 0) {
      FUN_00480040((int)param_1,0xff,0xff,0xff);
    }
    else {
      FUN_00480040((int)param_1,0xa0,0xa0,0xa0);
    }
  }
  uStack_8 = 0x42f88e;
  __chkesp();
  return;
}

