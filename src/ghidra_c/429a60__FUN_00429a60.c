/* FUN_00429a60 @ 00429a60 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00429a60(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (int *)FUN_00497d00("win\\config.txt","wt");
  if (local_8 != (int *)0x0) {
    FUN_00498130(local_8,(byte *)"; LUCKY LUKE Configuration Data\n\n");
    FUN_00498130(local_8,(byte *)"; Raster driver\n");
    FUN_00498130(local_8,(byte *)"Driver = %s\n\n");
    FUN_00498130(local_8,(byte *)
                         "; Raster driver instance (some drivers can enumerate more than one)\n");
    FUN_00498130(local_8,(byte *)"Instance = %d\n\n");
    FUN_00498130(local_8,(byte *)"; Game starting level\n");
    FUN_00498130(local_8,(byte *)"StartLevel = %d\n\n");
    FUN_00498130(local_8,(byte *)"; Character invincible during game (doesn\'t always work)\n");
    FUN_00498130(local_8,(byte *)"Invincible = %d\n\n");
    FUN_00498130(local_8,(byte *)
                         "; Whether to allow the mouse to initiate. Turn this off if entering\n");
    FUN_00498130(local_8,(byte *)"; DEBUG mode.\n");
    FUN_00498130(local_8,(byte *)"MouseOn = %d\n\n");
    FUN_00497b30(local_8);
    FUN_00428860();
  }
  local_8 = (int *)0x429ba3;
  __chkesp();
  return;
}

