/* FUN_00464bf0 @ 00464bf0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00464bf0(uint param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_0046d700();
  local_8 = (uint)(ushort)((ulonglong)(uVar1 & 0xffff) % 100);
  if ((int)(short)(&DAT_004e87ac)[(param_1 & 0xffff) * 10] < (int)local_8) {
    (&DAT_004e87ac)[(param_1 & 0xffff) * 10] =
         (&DAT_004e87ac)[(param_1 & 0xffff) * 10] +
         *(short *)(&DAT_004e87ae + (param_1 & 0xffff) * 0x14);
  }
  else if ((int)(uint)*(ushort *)(&DAT_004e87aa + (param_1 & 0xffff) * 0x14) <
           (int)(short)(&DAT_004e87ac)[(param_1 & 0xffff) * 10]) {
    (&DAT_004e87ac)[(param_1 & 0xffff) * 10] =
         *(undefined2 *)(&DAT_004e87aa + (param_1 & 0xffff) * 0x14);
  }
  local_8 = 0x464cd8;
  __chkesp();
  return;
}

