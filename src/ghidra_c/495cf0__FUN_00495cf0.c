/* FUN_00495cf0 @ 00495cf0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00495cf0(undefined *param_1,undefined4 param_2)

{
  undefined4 *local_8;
  
  if ((DAT_004c6e88 & 1) != 0) {
    for (local_8 = DAT_004e8c50; local_8 != (undefined4 *)0x0; local_8 = (undefined4 *)*local_8) {
      if ((local_8[5] & 0xffff) == 4) {
        (*(code *)param_1)(local_8 + 8,param_2);
      }
    }
  }
  return;
}

