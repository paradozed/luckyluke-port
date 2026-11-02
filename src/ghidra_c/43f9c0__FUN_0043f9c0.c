/* FUN_0043f9c0 @ 0043f9c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043f9c0(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  int local_c;
  undefined4 local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((param_1 != 0) && (puVar1 = (undefined1 *)FUN_00494c40(0x10,1), puVar1 != (undefined1 *)0x0))
  {
    *puVar1 = param_2;
    *(undefined4 *)(puVar1 + 4) = param_3;
    *(undefined4 *)(puVar1 + 8) = param_4;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    if (*(int *)(param_1 + 0x100) == 0) {
      *(undefined1 **)(param_1 + 0x100) = puVar1;
    }
    else {
      for (local_c = *(int *)(param_1 + 0x100); *(int *)(local_c + 0xc) != 0;
          local_c = *(int *)(local_c + 0xc)) {
      }
      *(undefined1 **)(local_c + 0xc) = puVar1;
    }
  }
  local_8 = 0x43fa76;
  __chkesp();
  return;
}

