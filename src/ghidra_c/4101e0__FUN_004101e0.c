/* FUN_004101e0 @ 004101e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004101e0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int *)(&DAT_004f1e40 + sVar1 * 4);
  if (local_8 != 0) {
    sVar1 = FUN_004074b0(param_2,3);
    if (sVar1 == 0) {
      *(undefined1 *)(local_8 + 0x14) = 0;
    }
    else {
      *(undefined1 *)(local_8 + 0x14) = 1;
    }
  }
  local_8 = 0x410243;
  __chkesp();
  return;
}

