/* FUN_004750b0 @ 004750b0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004750b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_14c [16];
  uint local_10c;
  int local_108;
  uint local_104 [63];
  undefined4 uStack_8;
  
  puVar2 = local_14c;
  for (iVar1 = 0x52; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00473af0();
  DAT_004f2c6c = DAT_004f2800;
  FUN_00497270((uint *)&DAT_004f57a0,
               (uint *)(&PTR_s__Abilene_Abilene_004be210)
                       [(byte)(&DAT_004be224)[(uint)DAT_004f16c8 * 2]]);
  FUN_00474c50();
  DAT_004e8976 = (&DAT_004be225)[(uint)DAT_004f16c8 * 2];
  if ((DAT_004e859c != 0) || (DAT_004e8584 != 0)) {
    FUN_00497270((uint *)&DAT_004f57a0,(uint *)(&PTR_s__Drapeau_Drapeau_004bcdd8)[_DAT_004bcec8]);
    DAT_004e8976 = (&DAT_004be22c)[_DAT_004bcec8];
    local_108 = _DAT_004bcec8 + -2;
    switch(_DAT_004bcec8) {
    case 2:
      DAT_004f16c8 = 0;
      break;
    case 0xf:
      DAT_004f16c8 = 1;
      break;
    case 0x12:
      DAT_004f16c8 = 2;
      break;
    case 0x17:
      DAT_004f16c8 = 3;
    }
  }
  DAT_004e8975 = 1;
  DAT_004e8985 = 0;
  DAT_004e8984 = 1;
  local_10c = (uint)DAT_004f16c8;
  switch(local_10c) {
  case 0:
    FUN_00497270(local_104,(uint *)PTR_s_IMAGE_ABILENE_TIM_004be1fc);
    DAT_004e8914 = 2;
    break;
  case 1:
    FUN_00497270(local_104,(uint *)PTR_s_IMAGE_SALOON_TIM_004be200);
    DAT_004e8914 = 0xf;
    break;
  case 2:
    FUN_00497270(local_104,(uint *)PTR_s_IMAGE_WAGON_TIM_004be204);
    DAT_004e8914 = 0x12;
    break;
  case 3:
    FUN_00497270(local_104,(uint *)PTR_s_IMAGE_DALTON_TIM_004be208);
    DAT_004e8914 = 0x17;
    break;
  default:
    FUN_00497270(local_104,(uint *)PTR_s_IMAGE_BLEVEL_TIM_004be258);
  }
  DAT_004f16c8 = DAT_004f16c8 + 1;
  if (DAT_004e8588 != 0) {
    FUN_0043fe80();
    FUN_00474c50();
    FUN_00449840(local_104,'\x01');
  }
  uStack_8 = 0x4752e3;
  __chkesp();
  return;
}

