/* FUN_0041fa80 @ 0041fa80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041fa80(char param_1,ushort param_2,ushort param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  ushort local_10 [2];
  ushort local_c [2];
  int local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((DAT_004bcfd0 != 0) && (param_1 != '\0')) {
    FUN_00420580(CONCAT31((int3)((uint)local_c >> 8),param_1),param_2,(uint)param_3,local_c,local_10
                );
    bVar1 = param_1 - 1;
    local_8 = *(int *)(&DAT_004d2390 + (uint)bVar1 * 0x10);
    *(ushort *)(&DAT_004d2398 + (uint)bVar1 * 0x10) = param_2;
    *(ushort *)(&DAT_004d239a + (uint)bVar1 * 0x10) = param_3;
    FUN_004935e0(local_8,1,local_c[0]);
    FUN_004935e0(local_8,2,local_10[0]);
  }
  local_8 = 0x41fb51;
  __chkesp();
  return;
}

