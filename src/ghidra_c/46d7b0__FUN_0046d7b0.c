/* FUN_0046d7b0 @ 0046d7b0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0046d7b0(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_50 [16];
  uint local_10;
  int local_8;
  
  puVar4 = local_50;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = 1;
  _DAT_004f2398 = param_1;
  for (uVar2 = 0; uVar2 < 0x36; uVar2 = uVar2 + 1) {
    local_10 = (uint)(ushort)((ulonglong)((uint)uVar2 * 0x15) % 0x37);
    *(int *)(&DAT_004f22c0 + local_10 * 4) = local_8;
    local_8 = param_1 - local_8;
    param_1 = *(int *)(&DAT_004f22c0 + local_10 * 4);
  }
  for (uVar2 = 0; uVar2 < 4; uVar2 = uVar2 + 1) {
    for (uVar1 = 0; uVar1 < 0x37; uVar1 = uVar1 + 1) {
      *(int *)(&DAT_004f22c0 + (uint)uVar1 * 4) =
           *(int *)(&DAT_004f22c0 + (uint)uVar1 * 4) -
           *(int *)(&DAT_004f22c0 + ((uVar1 + 0x1f) % 0x37) * 4);
    }
  }
  DAT_004f23b4 = 0;
  DAT_004f23b6 = 0x1f;
  return;
}

