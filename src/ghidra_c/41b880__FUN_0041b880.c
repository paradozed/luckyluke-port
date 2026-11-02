/* FUN_0041b880 @ 0041b880 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041b880(int param_1,short param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  undefined2 *local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = FUN_00407580(param_1);
  local_c = **(int **)(local_8 + 8);
  if (*(char *)(local_c + 1) == '\x05') {
    FUN_00485d00(local_c);
    *(undefined1 *)(local_8 + 0x14) = 0;
  }
  else if (*(char *)(local_c + 1) == '\a') {
    FUN_00485d00(local_c);
  }
  else {
    if (param_2 < 1) {
      local_10 = (undefined2 *)0x0;
    }
    else {
      local_10 = (undefined2 *)FUN_0046e8d0((int)param_2);
    }
    FUN_00485c00(local_c,local_10,'\x01');
  }
  local_8 = 0x41b92b;
  __chkesp();
  return;
}

