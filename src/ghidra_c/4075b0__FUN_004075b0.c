/* FUN_004075b0 @ 004075b0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x004075ed) */

void __cdecl FUN_004075b0(int param_1,char *param_2,DWORD param_3,LONG param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_004ae070(param_1,param_4,0);
  FUN_004ae020(param_1,param_2,param_3);
  local_8 = 0x407606;
  __chkesp();
  return;
}

