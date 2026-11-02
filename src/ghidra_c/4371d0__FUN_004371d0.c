/* FUN_004371d0 @ 004371d0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004371d0(char param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined4 local_cc [16];
  int local_8c;
  uint local_88 [16];
  CHAR local_48 [64];
  char *local_8;
  
  puVar2 = local_cc;
  for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00497080(local_48,0x4b63b0);
  _DAT_004e84bc = 0xffffffff;
  local_8c = DAT_004e8914 - 2;
  switch(DAT_004e8914) {
  case 2:
    FUN_00497270(local_88,(uint *)"abilene.pcx");
    break;
  default:
    DAT_004e84b4 = 0;
    uVar3 = FUN_00497360();
    _DAT_004e84bc = (undefined4)uVar3;
    goto LAB_0043741d;
  case 5:
    FUN_00497270(local_88,(uint *)"train1.pcx");
    break;
  case 7:
    FUN_00497270(local_88,(uint *)"train2.pcx");
    break;
  case 9:
    FUN_00497270(local_88,(uint *)"pueblos.pcx");
    break;
  case 10:
    FUN_00497270(local_88,(uint *)"galerie.pcx");
    break;
  case 0xd:
    FUN_00497270(local_88,(uint *)"desert.pcx");
    break;
  case 0xf:
    FUN_00497270(local_88,(uint *)"saloon.pcx");
    break;
  case 0x11:
    FUN_00497270(local_88,(uint *)"chute.pcx");
    break;
  case 0x12:
    FUN_00497270(local_88,(uint *)"wagon.pcx");
    break;
  case 0x14:
    FUN_00497270(local_88,(uint *)"bucheron.pcx");
    break;
  case 0x17:
    FUN_00497270(local_88,(uint *)0x4b6328);
  }
  local_8 = (char *)FUN_00435000(local_48,"lucky");
  DAT_004e84b4 = FUN_00432e40(local_8,local_88,10);
  FUN_00435d90(local_8);
  FUN_004361f0(DAT_004e84b4,0x244,0x1a4);
  FUN_00436230(DAT_004e84b4,0x118,0x244);
  FUN_00436270(DAT_004e84b4,0x32);
  DAT_004e84b8 = param_1 != '\0';
  DAT_004bcb80 = 1;
  _DAT_004f5b70 = 0;
LAB_0043741d:
  local_8 = (char *)0x43742d;
  __chkesp();
  return;
}

