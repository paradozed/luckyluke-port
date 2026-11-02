/* FUN_0040ac10 @ 0040ac10 */
/* decompiled from Lucky.exe (Game.run) */


undefined2 FUN_0040ac10(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004f2594 == '\0') {
    uVar1 = 0;
  }
  else {
    DAT_004f23f8 = FUN_00462f20;
    uVar1 = DAT_004f5554;
  }
  return uVar1;
}

