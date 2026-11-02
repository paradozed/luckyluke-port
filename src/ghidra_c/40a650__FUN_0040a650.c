/* FUN_0040a650 @ 0040a650 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040a650(undefined4 param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  sVar2 = FUN_004074b0(param_2,3);
  (&DAT_004d1de8)[sVar2] = *(undefined4 *)(&DAT_004f1e40 + sVar1 * 4);
  uStack_8 = 0x40a6a1;
  __chkesp();
  return;
}

