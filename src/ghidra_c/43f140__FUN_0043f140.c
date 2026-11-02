/* FUN_0043f140 @ 0043f140 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043f140(undefined4 param_1,undefined4 param_2)

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
  if ((DAT_004e850c == (int *)0x0) &&
     ((DAT_004e8500 != (int *)0x0 || (local_8 = FUN_0043ebc0(param_2), local_8 == 0)))) {
    FUN_00458ec0();
    (**(code **)(*DAT_004e8500 + 0x10))(DAT_004e8500,4,FUN_0043eeb0,param_1,1);
    local_8 = __chkesp();
    if ((local_8 == 0) && (DAT_004e850c != (int *)0x0)) {
      FUN_00458ec0();
      (**(code **)*DAT_004e850c)(DAT_004e850c,&DAT_004b9850,&DAT_004e8510);
      local_8 = __chkesp();
      if (local_8 == 0) {
        FUN_00458ec0();
      }
      else {
        (**(code **)(*DAT_004e850c + 8))(DAT_004e850c);
        __chkesp();
        DAT_004e850c = (int *)0x0;
      }
    }
  }
  local_8 = 0x43f261;
  __chkesp();
  return;
}

