/* FUN_00442670 @ 00442670 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00442670(char param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  REGSAM local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 == '\x01') {
    local_c = 0x20019;
  }
  else {
    if (param_1 != '\0') goto LAB_00442759;
    local_c = 0x20006;
  }
  RegOpenKeyExA((HKEY)0x80000002,"Software",0,local_c,&DAT_004e8554);
  local_8 = __chkesp();
  if (local_8 == 0) {
    RegOpenKeyExA(DAT_004e8554,"Infogrames",0,local_c,&DAT_004e8558);
    local_8 = __chkesp();
    if (local_8 == 0) {
      RegOpenKeyExA(DAT_004e8558,"Lucky Luke On The Daltons Trail",0,local_c,(PHKEY)&DAT_004e855c);
      __chkesp();
    }
  }
LAB_00442759:
  local_8 = 0x442766;
  __chkesp();
  return;
}

