/* FUN_00493040 @ 00493040 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00493040(int *param_1,char param_2,char param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((((param_1 != (int *)0x0) &&
       ((param_2 == '\0' || (cVar1 = FUN_004928f0(param_1,param_2), cVar1 != '\0')))) &&
      ((param_3 == '\0' || (cVar1 = FUN_00492c90(param_1,param_3), cVar1 != '\0')))) &&
     (param_4 != 0)) {
    FUN_00492e50(param_1,param_4);
  }
  uStack_8 = 0x4930dd;
  __chkesp();
  return;
}

