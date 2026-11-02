/* FUN_004060d0 @ 004060d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004060d0(int param_1)

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
  FUN_00443890();
  FUN_00458ec0();
  FUN_00422730(&DAT_004d1da8,param_1,3,FUN_00407610);
  FUN_00458ec0();
  FUN_00422730(&DAT_004d1da8,param_1,1,FUN_00407610);
  FUN_00458ec0();
  FUN_00422610(&DAT_004d1da8,param_1);
  FUN_00416040();
  DAT_004e898a = 0;
  DAT_004e8988 = 0;
  DAT_004f1765 = 0;
  DAT_004e8986 = 0;
  if ((DAT_004f17e8 == '\0') || (DAT_004f1780 == 0)) {
    if (DAT_004e8820 != (void *)0x0) {
      FUN_00458ec0();
      FUN_00465890(DAT_004e8820);
      DAT_004e8820 = (void *)0x0;
    }
    FUN_00458ec0();
    FUN_0044b9a0();
    FUN_00458ec0();
    FUN_0041ed10();
  }
  else {
    FUN_0041eeb0();
  }
  FUN_00458ec0();
  FUN_004451b0();
  uStack_8 = 0x406203;
  __chkesp();
  return;
}

