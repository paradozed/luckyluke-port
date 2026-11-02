/* FUN_00432b10 @ 00432b10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00432b10(char *param_1,uint *param_2)

{
  byte bVar1;
  undefined3 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_55c [16];
  uint local_51c;
  byte local_518;
  undefined3 uStack_517;
  byte *local_514;
  undefined4 *local_510;
  void *local_40c;
  undefined4 local_408;
  int local_8;
  
  puVar4 = local_55c;
  for (iVar3 = 0x156; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (param_1 != (char *)0x0) {
    FUN_00458ec0();
    local_510 = (undefined4 *)FUN_00435670(param_1,param_2);
    if (local_510 != (undefined4 *)0x0) {
      FUN_00458ec0();
      FUN_00497690(&local_408,local_510,0x400);
      FUN_00458ec0();
      local_40c = (void *)FUN_00494840(0x10000);
      if (local_40c == (void *)0x0) {
        FUN_00495280(local_510);
      }
      else {
        local_514 = (byte *)(local_510 + 0x100);
        FUN_00458ec0();
        local_8 = 0;
        while (local_8 < 0x10000) {
          bVar1 = *local_514;
          if (bVar1 < 0xc0) {
            *(byte *)((int)local_40c + local_8) = bVar1;
            local_8 = local_8 + 1;
            local_514 = local_514 + 1;
          }
          else {
            local_51c = CONCAT31(local_51c._1_3_,bVar1 + 0x40);
            bVar1 = local_514[1];
            local_514 = local_514 + 2;
            while ((local_51c & 0xff) != 0) {
              *(byte *)((int)local_40c + local_8) = bVar1;
              local_8 = local_8 + 1;
              local_51c = CONCAT31(local_51c._1_3_,(char)local_51c + -1);
            }
          }
          _local_518 = CONCAT31(uStack_517,bVar1);
        }
        FUN_00458ec0();
        (*DAT_004e8a80)(local_40c);
        __chkesp();
        FUN_00458ec0();
        for (local_8 = 10; local_8 < 0xf6; local_8 = local_8 + 1) {
          uVar2 = (undefined3)((uint)local_8 >> 8);
          (*DAT_005089ec)(local_8,CONCAT31(uVar2,*(undefined1 *)(&local_408 + local_8)),
                          CONCAT31(uVar2,*(undefined1 *)((int)&local_408 + local_8 * 4 + 1)),
                          *(undefined1 *)((int)&local_408 + local_8 * 4 + 2));
          __chkesp();
        }
        FUN_00458ec0();
        FUN_00495280(local_40c);
        FUN_00495280(local_510);
      }
    }
  }
  local_8 = 0x432d8b;
  __chkesp();
  return;
}

