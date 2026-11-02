/* FUN_004016a0 @ 004016a0 */
/* decompiled from Lucky.exe (Game.run) */


void __thiscall FUN_004016a0(void *this,undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [14];
  undefined4 uStack_18;
  int local_10;
  int local_c;
  void *local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = this;
  local_10 = AVIFileOpenA((int)this + 0xff8,param_2,0x10,0);
  local_c = local_10;
  if (local_10 < -0x7ffbbf92) {
    if (local_10 == -0x7ffbbf93) {
      FUN_00458ec0();
    }
    else if (local_10 == -0x7ffbfeac) {
      FUN_00458ec0();
    }
    else if (local_10 == -0x7ffbbf9a) {
      FUN_00458ec0();
    }
    else if (local_10 == -0x7ffbbf99) {
      FUN_00458ec0();
    }
  }
  else if (local_10 == -0x7ffbbf91) {
    FUN_00458ec0();
  }
  else if (local_10 == 0) {
    FUN_00401500(local_8,(int)local_8 + 0x6c);
    FUN_00458ec0();
    FUN_00458ec0();
    FUN_00458ec0();
    FUN_00458ec0();
    *(undefined4 *)((int)local_8 + 0xd8) = *(undefined4 *)((int)local_8 + 0x90);
    *(undefined4 *)((int)local_8 + 0xdc) = *(undefined4 *)((int)local_8 + 0x80);
    *(undefined4 *)((int)local_8 + 0xe0) = *(undefined4 *)((int)local_8 + 0x84);
    FUN_00458ec0();
    FUN_004018c0();
    cVar1 = FUN_00401a90(param_1);
    if (cVar1 != '\0') {
      *(undefined4 *)((int)local_8 + 0x60) = 0;
      *(undefined4 *)((int)local_8 + 100) = 0xffffffff;
      *(undefined4 *)((int)local_8 + 0x68) = 0;
    }
  }
  uStack_18 = 0x4018ad;
  __chkesp();
  return;
}

