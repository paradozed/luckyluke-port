/* FUN_0043eeb0 @ 0043eeb0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043eeb0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_74 [16];
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar2 = local_74;
  for (iVar1 = 0x1c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00458ec0();
  if (DAT_004e850c == (int *)0x0) {
    FUN_00458ec0();
    (**(code **)(*DAT_004e8500 + 0xc))(DAT_004e8500,param_1 + 4,&DAT_004e850c,0);
    local_34 = __chkesp();
    if (local_34 == 0) {
      FUN_00458ec0();
      (**(code **)(*DAT_004e850c + 0x2c))(DAT_004e850c,&LAB_00492500);
      local_34 = __chkesp();
      if (local_34 == 0) {
        FUN_00458ec0();
        (**(code **)(*DAT_004e850c + 0x34))(DAT_004e850c,param_2,6);
        local_34 = __chkesp();
        if (local_34 == 0) {
          local_1c = 0x18;
          local_18 = 0x10;
          local_10 = 1;
          local_c = 0xfffffc18;
          local_8 = 1000;
          FUN_00458ec0();
          local_14 = 0;
          (**(code **)(*DAT_004e850c + 0x18))(DAT_004e850c,4,&local_1c);
          local_34 = __chkesp();
          if (local_34 == 0) {
            FUN_00458ec0();
            local_14 = 4;
            (**(code **)(*DAT_004e850c + 0x18))(DAT_004e850c,4,&local_1c);
            local_34 = __chkesp();
            if (local_34 == 0) {
              local_30 = 0x14;
              local_2c = 0x10;
              local_24 = 2;
              local_20 = 2000;
              FUN_00458ec0();
              FUN_00458ec0();
            }
            else {
              (**(code **)(*DAT_004e850c + 8))(DAT_004e850c);
              __chkesp();
              DAT_004e850c = (int *)0x0;
            }
          }
          else {
            (**(code **)(*DAT_004e850c + 8))(DAT_004e850c);
            __chkesp();
            DAT_004e850c = (int *)0x0;
          }
        }
        else {
          (**(code **)(*DAT_004e850c + 8))(DAT_004e850c);
          __chkesp();
          DAT_004e850c = (int *)0x0;
        }
      }
      else {
        (**(code **)(*DAT_004e850c + 8))(DAT_004e850c);
        __chkesp();
        DAT_004e850c = (int *)0x0;
      }
    }
  }
  local_8 = 0x43f13a;
  __chkesp();
  return;
}

