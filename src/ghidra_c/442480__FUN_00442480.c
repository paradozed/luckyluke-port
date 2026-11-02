/* FUN_00442480 @ 00442480 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00442480(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  char *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
  DAT_004e8544 = FUN_00431fe0(local_8,(uint *)"lightg.pcx");
  DAT_004e8548 = FUN_00431fe0(local_8,(uint *)"lightr.pcx");
  FUN_00435d90(local_8);
  DAT_004e854c = DAT_004e8488;
  DAT_004e8550 = DAT_004e848c;
  local_8 = (char *)0x442508;
  __chkesp();
  return;
}

