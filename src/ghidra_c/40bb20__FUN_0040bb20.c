/* FUN_0040bb20 @ 0040bb20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040bb20(int param_1,void *param_2)

{
  short sVar1;
  uint uVar2;
  void *this;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_870 [17];
  int local_82c;
  int local_828;
  undefined1 local_824;
  int local_40;
  int local_3c;
  byte *local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar4 = local_870;
  for (iVar3 = 0x21b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_40 = 0;
  local_824 = 0;
  sVar1 = FUN_004074b0(param_2,2);
  local_828 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_82c = 0;
  do {
    if (0xf9 < local_82c) {
LAB_0040bd9f:
      local_8 = 0x40bdaf;
      __chkesp();
      return;
    }
    if ((((*(int *)(&DAT_004f1e40 + local_82c * 4) != 0) &&
         ((*(ushort *)(*(int *)(&DAT_004f1e40 + local_82c * 4) + 0xe) & 4) != 0)) &&
        (*(int *)(*(int *)(&DAT_004f1e40 + local_82c * 4) + 8) != 0)) &&
       ((local_38 = (byte *)**(undefined4 **)(*(int *)(&DAT_004f1e40 + local_82c * 4) + 8),
        local_38 != (byte *)0x0 && ((*local_38 & 2) == 0)))) {
      FUN_00476fe0((int)local_38,&local_14);
      local_34 = *(int *)(local_828 + 0x90);
      local_30 = *(int *)(local_828 + 0x94);
      local_2c = *(undefined4 *)(local_828 + 0x98);
      local_24 = local_34 -
                 ((int)(DAT_004be3c8 * 0x18 + (DAT_004be3c8 * 0x18 >> 0x1f & 0x1ffU)) >> 9);
      local_20 = local_30 -
                 ((int)(DAT_004be3cc * 0x14 + (DAT_004be3cc * 0x14 >> 0x1f & 0xffU)) >> 8);
      local_18 = local_30 - ((int)(DAT_004be3cc * 4 + (DAT_004be3cc * 4 >> 0x1f & 0xffU)) >> 8);
      local_1c = local_34 +
                 ((int)(DAT_004be3c8 * 0x18 + (DAT_004be3c8 * 0x18 >> 0x1f & 0x1ffU)) >> 9);
      local_14 = (int)(local_14 * DAT_004be3c8 + (local_14 * DAT_004be3c8 >> 0x1f & 0x1ffU)) >> 9;
      local_10 = (int)(local_10 * DAT_004be3cc + (local_10 * DAT_004be3cc >> 0x1f & 0xffU)) >> 8;
      local_c = (int)(local_c * DAT_004be3c8 + (local_c * DAT_004be3c8 >> 0x1f & 0x1ffU)) >> 9;
      local_8 = (int)(local_8 * DAT_004be3cc + (local_8 * DAT_004be3cc >> 0x1f & 0xffU)) >> 8;
      local_40 = local_40 + 1;
      uVar2 = FUN_0040bac0(local_14,local_10,local_c,local_8,local_24,local_20,local_1c,local_18);
      if ((uVar2 & 0xff) != 0) {
        iVar3 = *(int *)(&DAT_004f1e40 + local_82c * 4);
        local_3c = iVar3;
        this = (void *)FUN_00409d00(param_1);
        FUN_00421ea0(this,iVar3);
        goto LAB_0040bd9f;
      }
    }
    local_82c = local_82c + 1;
  } while( true );
}

