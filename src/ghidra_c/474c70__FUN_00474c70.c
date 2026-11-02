/* FUN_00474c70 @ 00474c70 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00474c70(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_150 [16];
  uint local_110;
  char local_10c;
  uint *local_108;
  uint local_104 [63];
  undefined4 uStack_8;
  
  puVar2 = local_150;
  for (iVar1 = 0x53; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00474a20();
  FUN_00497270((uint *)&DAT_004f57a0,(uint *)(&PTR_s__Drapeau_Drapeau_004bcdd8)[DAT_004e8914]);
  FUN_00474c50();
  local_108 = FUN_00498650((uint *)(&PTR_s__Drapeau_Drapeau_004bcdd8)[DAT_004e8914],'\\');
  FUN_00497270(local_104,(uint *)((int)local_108 + 1));
  iVar1 = _strncmp((char *)local_104,"Cinema",6);
  local_10c = (char)iVar1;
  if (DAT_004f1788 == 4) {
    local_10c = '\x01';
  }
  if (local_10c == '\0') {
    DAT_004f1765 = 0;
    local_110 = (uint)DAT_004f17ea;
    switch(local_110) {
    case 0:
      FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cc4);
      break;
    case 1:
      FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cc0);
      break;
    case 2:
      FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cbc);
      break;
    case 3:
      FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cb8);
      break;
    case 4:
      FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cb4);
      break;
    case 5:
      FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cb0);
      break;
    case 6:
      FUN_00497280((uint *)&DAT_004f57a0,(uint *)&DAT_004b3cac);
    }
  }
  uStack_8 = 0x474e67;
  __chkesp();
  return;
}

