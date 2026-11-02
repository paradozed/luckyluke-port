/* FUN_004b1f90 @ 004b1f90 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl
FUN_004b1f90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = DAT_0050a718;
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    iVar2 = (*(code *)puVar1[2])(param_1,param_2,param_3,param_4);
    if (iVar2 != 0) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return iVar2;
}

