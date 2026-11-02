/* FUN_0045aae0 @ 0045aae0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045aae0(uint param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  uint local_10;
  uint local_c;
  undefined4 local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = CONCAT22(local_8._2_2_,*(short *)(param_2 + 8) * 8 + 0x30);
  local_c = local_c & 0xffff0000;
  local_10 = param_1 & 0xffff;
  if (1 < local_10) {
    if (local_10 == 2) {
      DAT_004e8718 = DAT_004e8718 ^ 1;
      if (DAT_004e8718 == 0) {
        FUN_00439c30(DAT_004f2ac0);
        FUN_00439c30(DAT_004f2ac4);
        FUN_00439c30(DAT_004f2ac8);
        FUN_00439c30(DAT_004f2abc);
        DAT_004f2ac4 = (undefined4 *)0x0;
        DAT_004f2ac0 = (undefined4 *)0x0;
        DAT_004f2ac8 = (PVOID)0x0;
        DAT_004f2abc = (PVOID)0x0;
        FUN_004713e0(DAT_004f1e24,DAT_004e86a4);
      }
      else {
        DAT_004f2ac0 = (undefined4 *)FUN_00439af0(0xfc0);
        DAT_004f2ac4 = (undefined4 *)FUN_00439af0(0xfc0);
        DAT_004f2ac8 = (PVOID)FUN_00439af0(0x548);
        DAT_004f2abc = (PVOID)FUN_00439af0(0x548);
        local_c = local_c & 0xffff0000;
        while ((local_c & 0xffff) < 0x90) {
          DAT_004f2ac0[(local_c & 0xffff) * 7] =
               DAT_004f2ac0[(local_c & 0xffff) * 7] & 0xffffff | 0x6000000;
          *(undefined1 *)((int)DAT_004f2ac0 + (local_c & 0xffff) * 0x1c + 7) = 0x4c;
          DAT_004f2ac0[(local_c & 0xffff) * 7 + 6] = 0x55555555;
          *(undefined1 *)(DAT_004f2ac0 + (local_c & 0xffff) * 7 + 1) = 0xff;
          *(undefined1 *)((int)DAT_004f2ac0 + (local_c & 0xffff) * 0x1c + 5) = 0xff;
          *(undefined1 *)((int)DAT_004f2ac0 + (local_c & 0xffff) * 0x1c + 6) = 0xff;
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
        }
        FUN_00497690(DAT_004f2ac4,DAT_004f2ac0,0xfc0);
        FUN_0045aa20();
        DAT_004e86a4 = (PVOID)FUN_004714a0(DAT_004f1e24);
        *(undefined2 *)((int)DAT_004e86a4 + 0xc) = 0x30;
        *(code **)((int)DAT_004e86a4 + 4) = FUN_0045a720;
        *(undefined1 *)((int)DAT_004e86a4 + 0x10) = 1;
        *(undefined1 *)((int)DAT_004e86a4 + 0x11) = 0;
        *(undefined4 *)((int)DAT_004e86a4 + 8) = 0;
      }
    }
    else {
      FUN_00497610((byte *)"Error: File %s, Line %d");
    }
  }
  local_8 = 0x45ad8a;
  __chkesp();
  return;
}

