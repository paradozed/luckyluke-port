/* FUN_0045e280 @ 0045e280 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045e280(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_0043fa80(DAT_004e875c);
  FUN_0043fa80(DAT_004e8760);
  FUN_0043fa80(DAT_004e8754);
  FUN_0043fa80(DAT_004e8758);
  FUN_0043fa80(DAT_004e8764);
  FUN_0043fa80(DAT_004e8768);
  FUN_0043fa80(DAT_004e876c);
  FUN_0043fa80(DAT_004e8770);
  DAT_004e875c = (void *)FUN_0043f950((uint *)&DAT_004b80a0);
  DAT_004e8760 = (void *)FUN_0043f950((uint *)&DAT_004b8098);
  DAT_004e8754 = (void *)FUN_0043f950((uint *)&DAT_004b8090);
  DAT_004e8758 = (void *)FUN_0043f950((uint *)"Right");
  if (DAT_004e8750 == 0) {
    FUN_0043f9c0((int)DAT_004e875c,1,200,0xffff);
    FUN_0043f9c0((int)DAT_004e8760,1,0xd0,0xffff);
    FUN_0043f9c0((int)DAT_004e8754,1,0xcb,0xffff);
    FUN_0043f9c0((int)DAT_004e8758,1,0xcd,0xffff);
  }
  else {
    FUN_0043f9c0((int)DAT_004e875c,1,0x22,0xffff);
    FUN_0043f9c0((int)DAT_004e8760,1,0x2f,0xffff);
    FUN_0043f9c0((int)DAT_004e8754,1,0x2e,0xffff);
    FUN_0043f9c0((int)DAT_004e8758,1,0x30,0xffff);
  }
  FUN_0043f9c0((int)DAT_004e875c,2,0,0xffff);
  FUN_0043f9c0((int)DAT_004e8760,2,1,0xffff);
  FUN_0043f9c0((int)DAT_004e8754,2,2,0xffff);
  FUN_0043f9c0((int)DAT_004e8758,2,3,0xffff);
  DAT_004e8764 = (void *)FUN_0043f950((uint *)&DAT_004b8080);
  DAT_004e8768 = (void *)FUN_0043f950((uint *)"Speed up");
  DAT_004e876c = (void *)FUN_0043f950((uint *)&DAT_004b806c);
  DAT_004e8770 = (void *)FUN_0043f950((uint *)"Drop dynamite");
  DAT_004e877c = FUN_0043f950((uint *)"View/hide score bar");
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    FUN_0043f9c0((int)DAT_004e8768,1,
                 *(undefined4 *)
                  (&DAT_004bdcfc +
                  *(int *)(&DAT_004bdd1c + local_8 * 0x10) * 4 + DAT_004e8750 * 0x10),
                 1 << ((byte)local_8 & 0x1f));
    FUN_0043f9c0((int)DAT_004e876c,1,
                 *(undefined4 *)
                  (&DAT_004bdcfc +
                  *(int *)(&DAT_004bdd20 + local_8 * 0x10) * 4 + DAT_004e8750 * 0x10),
                 1 << ((byte)local_8 & 0x1f));
    FUN_0043f9c0((int)DAT_004e8764,1,
                 *(undefined4 *)
                  (&DAT_004bdcfc +
                  *(int *)(&DAT_004bdd24 + local_8 * 0x10) * 4 + DAT_004e8750 * 0x10),
                 1 << ((byte)local_8 & 0x1f));
    FUN_0043f9c0((int)DAT_004e8770,1,
                 *(undefined4 *)
                  (&DAT_004bdcfc +
                  *(int *)(&DAT_004bdd28 + local_8 * 0x10) * 4 + DAT_004e8750 * 0x10),
                 1 << ((byte)local_8 & 0x1f));
  }
  local_8 = 0x45e5f4;
  __chkesp();
  return;
}

