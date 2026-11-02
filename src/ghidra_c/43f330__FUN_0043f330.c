/* FUN_0043f330 @ 0043f330 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043f330(HWND param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004bcfd4 != 0) && (DAT_004e8514 == (int *)0x0)) {
    SetForegroundWindow(param_1);
    __chkesp();
    if ((DAT_004e8500 != (int *)0x0) || (local_8 = FUN_0043ebc0(param_2), local_8 == 0)) {
      FUN_00458ec0();
      (**(code **)(*DAT_004e8500 + 0xc))(DAT_004e8500,&DAT_004b9930,&DAT_004e8514,0);
      local_8 = __chkesp();
      if (local_8 == 0) {
        FUN_00458ec0();
        (**(code **)(*DAT_004e8514 + 0x2c))(DAT_004e8514,&LAB_00492590);
        local_8 = __chkesp();
        if (local_8 == 0) {
          FUN_00458ec0();
          (**(code **)(*DAT_004e8514 + 0x34))(DAT_004e8514,param_1,5);
          local_8 = __chkesp();
          if (local_8 == 0) {
            FUN_00458ec0();
            (**(code **)(*DAT_004e8514 + 0x1c))(DAT_004e8514);
            local_8 = __chkesp();
            if (local_8 != 0) {
              (**(code **)(*DAT_004e8514 + 8))(DAT_004e8514);
              __chkesp();
            }
          }
          else {
            (**(code **)(*DAT_004e8514 + 8))(DAT_004e8514);
            __chkesp();
          }
        }
        else {
          (**(code **)(*DAT_004e8514 + 8))(DAT_004e8514);
          __chkesp();
        }
      }
    }
  }
  local_8 = 0x43f4ef;
  __chkesp();
  return;
}

