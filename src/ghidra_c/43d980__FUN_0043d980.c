/* FUN_0043d980 @ 0043d980 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043d980(int *param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_0043bc90(*param_1,1,0,0,param_2,0xf9,param_2,0,param_2 + '|',0xf9,param_2 + '|');
  FUN_0043bc90(*param_1,5,1,0xf9,0,0,0,0xf9,0x7c,0,0x7c);
  FUN_0043bc90(*param_1,2,1,0,0x80,9,0x80,0,0xfc,9,0xfc);
  FUN_0043c040(*param_1,4,0x62,0x3d,0x1e);
  FUN_0043c040(*param_1,0,0x62,0x3d,0x1e);
  FUN_0043c040(*param_1,3,0x62,0x3d,0x1e);
  uStack_8 = 0x43da73;
  __chkesp();
  return;
}

