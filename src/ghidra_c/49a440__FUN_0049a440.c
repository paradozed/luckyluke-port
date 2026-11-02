/* FUN_0049a440 @ 0049a440 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_0049a440(void)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  undefined4 local_8;
  
  local_8 = 0xfffffffe;
  iVar1 = FUN_0049bc20();
  if (iVar1 < 0) {
    local_8 = 0xfffffffc;
  }
  BVar2 = HeapValidate(DAT_0050a29c,0,(LPCVOID)0x0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    if (DVar3 == 0x78) {
      DAT_004e8c68 = 0x78;
      DAT_004e8c64 = 0x28;
    }
    else {
      local_8 = 0xfffffffc;
    }
  }
  return local_8;
}

