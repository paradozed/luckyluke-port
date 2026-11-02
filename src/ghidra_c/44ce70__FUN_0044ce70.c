/* FUN_0044ce70 @ 0044ce70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0044ce70(short param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  ushort uVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 local_48 [16];
  undefined2 *local_8;
  
  puVar4 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar3 = param_1 + *(short *)(*(int *)(&DAT_004f2c64 + (uint)DAT_004e8612 * 4) + 0x3c);
  local_8 = (undefined2 *)(DAT_004e8820 + *(int *)(DAT_004e8820 + 4 + (uint)uVar3 * 4));
  *(ushort *)(*(int *)(&DAT_004f2c64 + (uint)DAT_004e8612 * 4) + 0x18) = uVar3;
  uVar6 = 0;
  uVar5 = 0;
  sVar1 = FUN_0044cfa0(local_8);
  FUN_004850b0(**(int **)(&DAT_004f2c64 + (uint)DAT_004e8612 * 4),(int)local_8,0,sVar1 + -1,uVar5,
               uVar6);
  FUN_0044cf60(**(int **)(&DAT_004f2c64 + (uint)DAT_004e8612 * 4),param_2,0);
  FUN_0044cfd0(**(int **)(&DAT_004f2c64 + (uint)DAT_004e8612 * 4),0);
  local_8 = (undefined2 *)0x44cf58;
  __chkesp();
  return;
}

