/* FUN_0046ee90 @ 0046ee90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046ee90(uint param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_0046e8d0(param_1 & 0xffff);
  local_c = iVar1 + 0xc;
  local_10 = (uint)local_10._2_2_ << 0x10;
  while ((local_10 & 0xffff) < (uint)*(ushort *)(iVar1 + 2)) {
    *(undefined4 *)(local_c + (local_10 & 0xffff) * 0xc) = param_2;
    local_10 = CONCAT22(local_10._2_2_,(short)local_10 + 1);
  }
  local_8 = 0x46ef11;
  __chkesp();
  return;
}

