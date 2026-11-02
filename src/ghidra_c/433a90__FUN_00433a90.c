/* FUN_00433a90 @ 00433a90 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00433a90(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_14c [16];
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 uStack_8;
  
  puVar2 = local_14c;
  for (iVar1 = 0x52; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_00442670('\x01');
  if (iVar1 == 0) {
    FUN_004339d0();
  }
  iVar1 = FUN_004427e0("Target Directory",(LPBYTE)&local_108);
  if (iVar1 == 0) {
    FUN_00442770();
    FUN_004339d0();
  }
  SetCurrentDirectoryA((LPCSTR)&local_108);
  __chkesp();
  local_10c = _strlen((char *)&local_108);
  if (*(char *)((int)&local_10c + local_10c + 3) != '\\') {
    *(undefined1 *)((int)&local_108 + local_10c) = 0x5c;
    *(undefined1 *)((int)&local_108 + local_10c + 1) = 0;
  }
  FUN_00497280(&local_108,(uint *)"Lucky.exe");
  FUN_00442770();
  FUN_00498cf0(&local_108,(char *)&local_108);
  uStack_8 = 0x433b7f;
  __chkesp();
  return;
}

