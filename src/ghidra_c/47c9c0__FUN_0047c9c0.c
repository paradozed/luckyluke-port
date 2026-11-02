/* FUN_0047c9c0 @ 0047c9c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047c9c0(short *param_1,short *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [17];
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  FUN_00482a90(param_2,(undefined4 *)&DAT_00508180);
  FUN_004823a0((undefined4 *)&DAT_00508180);
  FUN_00482a50(0x508180,&local_14);
  FUN_004824a0(0x508180);
  FUN_004826e0(param_1,&local_24);
  local_24 = -local_24;
  local_20 = -local_20;
  local_1c = param_3 - local_1c;
  FUN_00482a50(0x508180,&local_24);
  FUN_004824a0(0x508180);
  local_8 = 0x47ca88;
  __chkesp();
  return;
}

