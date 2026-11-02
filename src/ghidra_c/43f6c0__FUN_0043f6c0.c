/* FUN_0043f6c0 @ 0043f6c0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x0043f747) */

void FUN_0043f6c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [12];
  undefined4 uStack_18;
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while( true ) {
    (**(code **)(*DAT_004e8510 + 100))(DAT_004e8510);
    __chkesp();
    (**(code **)(*DAT_004e850c + 0x24))(DAT_004e850c,0x50,&DAT_004f5ac0);
    local_8 = __chkesp();
    if (local_8 == 0) break;
    local_8 = 0x8007001e;
    (**(code **)(*DAT_004e850c + 0x1c))(DAT_004e850c);
    __chkesp();
  }
  uStack_18 = 0x43f75b;
  __chkesp();
  return;
}

