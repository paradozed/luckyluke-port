/* FUN_0047ca90 @ 0047ca90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047ca90(int *param_1,short *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00482a90(param_2,(undefined4 *)&DAT_00508180);
  DAT_00508186 = (short)((int)(DAT_00508186 * 0x170 + (DAT_00508186 * 0x170 >> 0x1f & 0x1ffU)) >> 9)
  ;
  DAT_00508188 = (short)((int)(DAT_00508188 * 0x170 + (DAT_00508188 * 0x170 >> 0x1f & 0x1ffU)) >> 9)
  ;
  DAT_0050818a = (short)((int)(DAT_0050818a * 0x170 + (DAT_0050818a * 0x170 >> 0x1f & 0x1ffU)) >> 9)
  ;
  FUN_004823a0((undefined4 *)&DAT_00508180);
  FUN_00482760((undefined4 *)&DAT_00508180,param_1,&local_14);
  local_14 = -local_14;
  local_10 = -local_10;
  local_c = param_3 - local_c;
  FUN_00482a50(0x508180,&local_14);
  FUN_004824a0(0x508180);
  uStack_8 = 0x47cb7e;
  __chkesp();
  return;
}

