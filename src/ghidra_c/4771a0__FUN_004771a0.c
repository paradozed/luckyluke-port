/* FUN_004771a0 @ 004771a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004771a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  undefined2 local_c;
  undefined4 local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004f175c = FUN_00446390(0x8c);
  local_8 = CONCAT22(local_8._2_2_,0xffe);
  local_c = FUN_004471b0(DAT_004f175c,0,0x40,0x200,0xc0,0xffe);
  FUN_00446d40(DAT_004f175c,(byte)local_c,0,0x40,0x200,0xc0,100,100,100);
  FUN_00447470(DAT_004f175c,(byte)local_c,2,'\x01');
  DAT_004e898a = 0;
  local_8 = 0x477253;
  __chkesp();
  return;
}

