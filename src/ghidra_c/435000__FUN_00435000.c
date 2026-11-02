/* FUN_00435000 @ 00435000 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00435000(LPCSTR param_1,char *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined4 local_90 [16];
  void *local_50;
  char local_4c [32];
  char local_2c [32];
  uint local_c;
  undefined4 uStack_8;
  
  puVar5 = local_90;
  for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  puVar5 = &DAT_004b62e0;
  pcVar6 = local_4c;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pcVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    pcVar6 = pcVar6 + 4;
  }
  local_50 = (void *)FUN_00494840(0x3c);
  if (local_50 != (void *)0x0) {
    _memset(local_50,0,0x3c);
    *(undefined1 *)((int)local_50 + 1) = 1;
    uVar1 = FUN_00497d00(param_1,"rb");
    *(undefined4 *)((int)local_50 + 0x24) = uVar1;
    if (*(int *)((int)local_50 + 0x24) == 0) {
      FUN_00495280(local_50);
      DAT_004e84b0 = 1;
    }
    else {
      uVar2 = FUN_00498340(*(int **)((int)local_50 + 0x24));
      if (((uVar2 == 0x4b) && (uVar2 = FUN_00498340(*(int **)((int)local_50 + 0x24)), uVar2 == 0x58)
          ) && (uVar2 = FUN_00498340(*(int **)((int)local_50 + 0x24)), uVar2 == 0x50)) {
        uVar2 = FUN_00498340(*(int **)((int)local_50 + 0x24));
        if (uVar2 == 1) {
          FUN_004988b0(*(uint **)((int)local_50 + 0x24),5,0);
          *(undefined1 *)((int)local_50 + 0x28) = 0;
          uVar2 = FUN_00498340(*(int **)((int)local_50 + 0x24));
          if (uVar2 != 0) {
            FUN_004988b0(*(uint **)((int)local_50 + 0x24),5,0);
            FUN_004989e0(local_2c,0x20,1,*(int **)((int)local_50 + 0x24));
            sVar3 = _strlen(param_2);
            FUN_00435e10((int)local_2c,0x20,(int)param_2,sVar3);
            for (local_c = 0; (local_c < 0x20 && (local_2c[local_c] == local_4c[local_c]));
                local_c = local_c + 1) {
            }
            if (local_c != 0x20) {
              FUN_00497b30(*(int **)((int)local_50 + 0x24));
              FUN_00495280(local_50);
              DAT_004e84b0 = 4;
              goto LAB_00435302;
            }
            sVar3 = _strlen(param_2);
            *(char *)((int)local_50 + 0x28) = (char)sVar3;
            for (local_c = 0; local_c < *(byte *)((int)local_50 + 0x28); local_c = local_c + 1) {
              *(char *)((int)local_50 + local_c + 2) = param_2[local_c];
            }
            *(undefined1 *)((int)local_50 + local_c + 2) = 0;
          }
          FUN_004988b0(*(uint **)((int)local_50 + 0x24),0x25,0);
          FUN_004989e0((char *)((int)local_50 + 0x2c),4,1,*(int **)((int)local_50 + 0x24));
          FUN_004988b0(*(uint **)((int)local_50 + 0x24),*(int *)((int)local_50 + 0x2c),0);
          uVar2 = FUN_00498340(*(int **)((int)local_50 + 0x24));
          if (uVar2 == 0x49) {
            FUN_004989e0((char *)((int)local_50 + 0x30),2,1,*(int **)((int)local_50 + 0x24));
            *(int *)((int)local_50 + 0x2c) = *(int *)((int)local_50 + 0x2c) + 3;
          }
          else {
            FUN_00497b30(*(int **)((int)local_50 + 0x24));
            DAT_004e84b0 = 5;
          }
        }
        else {
          FUN_00497b30(*(int **)((int)local_50 + 0x24));
          FUN_00495280(local_50);
          DAT_004e84b0 = 3;
        }
      }
      else {
        FUN_00497b30(*(int **)((int)local_50 + 0x24));
        FUN_00495280(local_50);
        DAT_004e84b0 = 2;
      }
    }
  }
LAB_00435302:
  uStack_8 = 0x435312;
  __chkesp();
  return;
}

