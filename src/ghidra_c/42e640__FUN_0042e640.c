/* FUN_0042e640 @ 0042e640 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042e640(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  byte *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004bc738 != 0) {
    if (DAT_004e8914 == 0x18) {
      (*DAT_005089e8)();
      iVar1 = __chkesp();
      if (iVar1 == 0) {
        local_8 = (byte *)FUN_0042cb20((uint *)"GRLUM01",0);
        if (local_8 != (byte *)0x0) {
          FUN_0047f2d0(local_8);
        }
        local_8 = (byte *)FUN_0042cb20((uint *)"GRLUM02",0);
        if (local_8 != (byte *)0x0) {
          FUN_0047f2d0(local_8);
        }
        local_8 = (byte *)FUN_0042cb20((uint *)"GRLUM03",0);
        if (local_8 != (byte *)0x0) {
          FUN_0047f2d0(local_8);
        }
      }
    }
    DAT_004bc738 = 0;
    if ((DAT_004e8914 == 0xf) &&
       (local_8 = (byte *)FUN_0042cb20((uint *)"SA_MURS",0), local_8 != (byte *)0x0)) {
      FUN_00497690((undefined4 *)&DAT_004e8380,(undefined4 *)local_8,0xe8);
      DAT_004e8378 = (byte *)FUN_0047d4e0((undefined4 *)local_8);
      FUN_0047f0f0(DAT_004e8378);
      FUN_00497690((undefined4 *)local_8,(undefined4 *)DAT_004e8378,0xe8);
      FUN_0042cf30((int)local_8,0xc);
      FUN_0042d040((int)local_8);
      FUN_0042d2a0((int)local_8);
      FUN_0047e4c0((int)local_8,0x2d);
      FUN_0047e4c0((int)local_8,0x2d);
      FUN_0047e4c0((int)local_8,0x44);
      FUN_0042d350((int)local_8);
    }
  }
  local_8 = (byte *)0x42e7e2;
  __chkesp();
  return;
}

