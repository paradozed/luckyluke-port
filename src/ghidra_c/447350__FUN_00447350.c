/* FUN_00447350 @ 00447350 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_00447350(int param_1,byte param_2,undefined1 param_3,char param_4,undefined2 param_5,
            short param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 != 0) && (iVar1 = FUN_00446540(param_1,param_2), iVar1 != 0)) {
    *(char *)(iVar1 + 0x27) = (char)(((int)param_4 << 8) / DAT_004be3cc);
    *(undefined1 *)(iVar1 + 0x26) = param_3;
    *(short *)(iVar1 + 0x22) = (short)(((int)param_6 << 8) / DAT_004be3cc);
    *(undefined2 *)(iVar1 + 0x20) = param_5;
  }
  local_8 = 0x4473d5;
  __chkesp();
  return;
}

