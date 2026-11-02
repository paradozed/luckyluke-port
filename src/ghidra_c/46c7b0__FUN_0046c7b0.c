/* FUN_0046c7b0 @ 0046c7b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046c7b0(short param_1,undefined4 param_2)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined4 local_48 [16];
  undefined2 *local_8;
  
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = param_1 + (short)DAT_004f22a4[0xf];
  local_8 = (undefined2 *)(DAT_004e8820 + *(int *)(DAT_004e8820 + 4 + (uint)uVar2 * 4));
  *(ushort *)(DAT_004f22a4 + 6) = uVar2;
  uVar6 = 0;
  uVar5 = 0;
  sVar1 = FUN_0046c8b0(local_8);
  FUN_00484e30(*DAT_004f22a4,(int)local_8,0,sVar1 + -1,uVar5,uVar6);
  FUN_0046c870(*DAT_004f22a4,param_2,0);
  FUN_0046c8e0(*DAT_004f22a4,0);
  local_8 = (undefined2 *)0x46c867;
  __chkesp();
  return;
}

