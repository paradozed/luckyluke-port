/* FUN_00452cc0 @ 00452cc0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00452cc0(short param_1,short param_2,short param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = (int)param_1;
  if ((((iVar1 < 0) || ((int)(uint)DAT_004e89f4 <= (int)param_1)) ||
      (iVar1 = (int)param_2, iVar1 < 0)) ||
     ((((int)(uint)DAT_004e89f6 <= (int)param_2 || (iVar1 = (int)param_3, iVar1 < 0)) ||
      ((int)(uint)DAT_004e89f8 <= (int)param_3)))) {
    iVar1 = CONCAT22((short)((uint)iVar1 >> 0x10),0xffff);
  }
  else {
    iVar1 = ((int)param_3 * (uint)DAT_004e89f6 + (int)param_2) * (uint)DAT_004e89f4 + (int)param_1;
  }
  return iVar1;
}

