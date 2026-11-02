/* FUN_0045d3e0 @ 0045d3e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045d3e0(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_1 & 0xffff;
  if ((local_8 != 0) && (local_8 != 1)) {
    if (local_8 == 2) {
      FUN_00459800(param_2,(int *)&DAT_004bd940);
    }
    else {
      FUN_00497610((byte *)"Error: File %s, Line %d");
    }
  }
  local_8 = 0x45d458;
  __chkesp();
  return;
}

