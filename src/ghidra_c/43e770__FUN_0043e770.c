/* FUN_0043e770 @ 0043e770 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043e770(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  char *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (char *)FUN_00435000("win\\graphics\\newmenu.kxp","lucky");
  FUN_00432510(local_8,(uint *)"woodtra.pcx",0,0,0);
  FUN_00432510(local_8,(uint *)"woodsal.pcx",0,0,0x80);
  FUN_00432510(local_8,(uint *)"woodtex.pcx",1,0,0);
  FUN_00432510(local_8,(uint *)"side.pcx",1,0,0x80);
  FUN_00432510(local_8,(uint *)"bark.pcx",2,0,0);
  FUN_00432510(local_8,(uint *)"trunktop.pcx",2,100,0);
  FUN_00435d90(local_8);
  (*DAT_004e8a24)(0,*DAT_004f58a4);
  __chkesp();
  (*DAT_004e8a24)(1,DAT_004f58a4[1]);
  __chkesp();
  (*DAT_004e8a24)(2,DAT_004f58a4[2]);
  __chkesp();
  local_8 = (char *)0x43e89e;
  __chkesp();
  return;
}

