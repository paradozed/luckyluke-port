/* FUN_004140f0 @ 004140f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004140f0(undefined4 param_1,void *param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4c [16];
  undefined4 local_c;
  undefined4 local_8;
  
  puVar4 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_c = **(undefined4 **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  uVar2 = 0;
  do {
    if (4 < uVar2) {
LAB_00414176:
      local_8 = 0x414183;
      __chkesp();
      return;
    }
    if (*(int *)(&DAT_004f1798 + (uint)uVar2 * 4) == 0) {
      DAT_004f16a8 = 1;
      *(undefined4 *)(&DAT_004f1798 + (uint)uVar2 * 4) = local_c;
      goto LAB_00414176;
    }
    uVar2 = uVar2 + 1;
  } while( true );
}

