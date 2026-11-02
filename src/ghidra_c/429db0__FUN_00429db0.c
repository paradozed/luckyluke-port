/* FUN_00429db0 @ 00429db0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00429db0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  char *local_20;
  char *local_1c;
  char *local_18;
  char *local_14;
  char *local_10;
  char *local_c;
  char *local_8;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_20 = "win\\readme_e.txt";
  local_1c = "win\\readme_f.txt";
  local_18 = "win\\readme_g.txt";
  local_14 = "win\\readme_s.txt";
  local_10 = "win\\readme_i.txt";
  local_c = "win\\readme_u.txt";
  local_8 = "win\\readme_b.txt";
  FUN_00498260(1,(uint *)"c:\\windows\\notepad.exe","c:\\windows\\notepad.exe");
  local_8 = (char *)0x429e26;
  __chkesp();
  return;
}

