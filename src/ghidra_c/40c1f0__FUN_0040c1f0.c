/* FUN_0040c1f0 @ 0040c1f0 */
/* decompiled from Lucky.exe (Game.run) */


ushort FUN_0040c1f0(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [16];
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = DAT_004f17ea;
  if (3 < DAT_004f17ea) {
    uVar1 = 0;
  }
  return uVar1;
}

