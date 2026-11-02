/* FUN_004860b0 @ 004860b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004860b0(int param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(param_1 + 0x10) = *(undefined1 *)param_2;
  *(undefined1 *)(param_1 + 0x11) = *(undefined1 *)(param_2 + 1);
  *(char *)(param_1 + 0x12) = (char)*param_2 + (char)param_2[2];
  *(undefined1 *)(param_1 + 0x13) = *(undefined1 *)(param_2 + 1);
  *(undefined1 *)(param_1 + 0x14) = *(undefined1 *)param_2;
  *(char *)(param_1 + 0x15) = (char)param_2[1] + (char)param_2[3];
  *(char *)(param_1 + 0x16) = (char)*param_2 + (char)param_2[2];
  *(char *)(param_1 + 0x17) = (char)param_2[1] + (char)param_2[3];
  return;
}

