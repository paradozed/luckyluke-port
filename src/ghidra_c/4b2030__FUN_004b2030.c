/* FUN_004b2030 @ 004b2030 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_004b2030(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((int)param_1 + param_2 + -0xc);
  *param_1 = puVar1;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 1;
  *(undefined1 *)((int)param_1 + 10) = 0;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *puVar1 = 0;
  puVar1[1] = param_1;
  *(undefined1 *)(puVar1 + 2) = 1;
  *(undefined1 *)((int)puVar1 + 10) = 1;
  *(undefined1 *)((int)puVar1 + 0xb) = 0;
  return;
}

