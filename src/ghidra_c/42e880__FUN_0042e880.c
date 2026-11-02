/* FUN_0042e880 @ 0042e880 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042e880(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  undefined4 local_10;
  int *local_c;
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = FUN_0047e5b0(param_1,param_2,&local_c,&local_10);
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  local_14 = local_8 + -2;
  switch(local_14) {
  case 0:
    FUN_00458ec0();
    break;
  case 1:
    FUN_00458ec0();
    break;
  case 4:
    FUN_00458ec0();
    FUN_00458ec0();
    break;
  case 5:
    FUN_00458ec0();
    FUN_0047e750(param_1,*local_c);
    FUN_0047e750(param_1,*local_c);
    FUN_0047e750(param_1,*local_c);
    FUN_00458ec0();
    FUN_0047e750(param_1,local_c[1]);
    FUN_0047e750(param_1,local_c[1]);
    FUN_0047e750(param_1,local_c[1]);
    FUN_00458ec0();
    FUN_0047e750(param_1,local_c[2]);
    FUN_0047e750(param_1,local_c[2]);
    FUN_0047e750(param_1,local_c[2]);
    FUN_00458ec0();
    FUN_0047e750(param_1,local_c[3]);
    FUN_0047e750(param_1,local_c[3]);
    FUN_0047e750(param_1,local_c[3]);
    FUN_00458ec0();
  }
  local_8 = 0x42eab8;
  __chkesp();
  return;
}

