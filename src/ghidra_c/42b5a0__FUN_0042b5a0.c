/* FUN_0042b5a0 @ 0042b5a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042b5a0(void)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_3d4 [16];
  undefined *local_394;
  uint local_390;
  CHAR local_38c [512];
  uint *local_18c;
  char local_188 [64];
  char local_148 [64];
  undefined4 local_108;
  int *local_8;
  
  puVar4 = local_3d4;
  for (iVar3 = 0xf4; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  pcVar1 = FUN_004987e0(local_188);
  pcVar2 = FUN_00498710(local_148);
  wsprintfA((LPSTR)&local_108,"c:\\Exception %s %s.TXT",pcVar2,pcVar1);
  __chkesp();
  while ((local_18c = FUN_00498650(&local_108,'/'), local_18c != (uint *)0x0 ||
         (local_18c = FUN_00498650(&local_108,':'), local_18c != (uint *)0x0))) {
    *(undefined1 *)local_18c = 0x2e;
  }
  local_108._1_1_ = 0x3a;
  local_8 = (int *)FUN_00497d00((LPCSTR)&local_108,"wt");
  if (local_8 != (int *)0x0) {
    FUN_00498130(local_8,(byte *)"INFORMATION\n\n");
    local_390 = DAT_004f7320;
    if (DAT_004f7320 < 0xc000008f) {
      if (DAT_004f7320 == 0xc000008e) {
        FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
      }
      else if (DAT_004f7320 < 0xc000001e) {
        if (DAT_004f7320 == 0xc000001d) {
          FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        }
        else if (DAT_004f7320 < 0x80000005) {
          if (DAT_004f7320 == 0x80000004) {
            FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
          }
          else if (DAT_004f7320 == 0x80000002) {
            FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
          }
          else if (DAT_004f7320 == 0x80000003) {
            FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
          }
        }
        else if (DAT_004f7320 == 0xc0000005) {
          FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        }
        else if (DAT_004f7320 == 0xc0000006) {
          FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        }
      }
      else {
        local_390 = DAT_004f7320 + 0x3fffffdb;
        switch(DAT_004f7320) {
        case 0xc0000025:
          FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
          break;
        case 0xc0000026:
          FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
          break;
        case 0xc000008c:
          FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
          break;
        case 0xc000008d:
          FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        }
      }
    }
    else {
      local_390 = DAT_004f7320 + 0x3fffff71;
      switch(DAT_004f7320) {
      case 0xc000008f:
        FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        break;
      case 0xc0000090:
        FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        break;
      case 0xc0000091:
        FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        break;
      case 0xc0000092:
        FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        break;
      case 0xc0000093:
        FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        break;
      case 0xc0000094:
        FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        break;
      case 0xc0000095:
        FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        break;
      case 0xc0000096:
        FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
        break;
      case 0xc00000fd:
        FUN_00498130(local_8,(byte *)"Exception Code: %s\n");
      }
    }
    if (DAT_004f7324 == 0) {
      local_394 = &DAT_004b5514;
    }
    else {
      local_394 = &DAT_004b5518;
    }
    FUN_00498130(local_8,(byte *)"Continuable Exception: %s\n");
    FUN_00498130(local_8,(byte *)"Address: 0x%x\n\n");
    FUN_00498130(local_8,(byte *)"REGISTER STATES\n\n");
    if ((DAT_004f7380 & 0x10004) == 0) {
      FUN_00498130(local_8,(byte *)"No segment register information\n");
    }
    else {
      FUN_00498130(local_8,(byte *)"GS: 0x%x\n");
      FUN_00498130(local_8,(byte *)"FS: 0x%x\n");
      FUN_00498130(local_8,(byte *)"ES: 0x%x\n");
      FUN_00498130(local_8,(byte *)"DS: 0x%x\n");
    }
    FUN_00498130(local_8,&DAT_004b3460);
    if ((DAT_004f7380 & 0x10002) == 0) {
      FUN_00498130(local_8,(byte *)"No integer register information\n");
    }
    else {
      FUN_00498130(local_8,(byte *)"EDI: 0x%x\n");
      FUN_00498130(local_8,(byte *)"ESI: 0x%x\n");
      FUN_00498130(local_8,(byte *)"EBX: 0x%x\n");
      FUN_00498130(local_8,(byte *)"EDX: 0x%x\n");
      FUN_00498130(local_8,(byte *)"ECX: 0x%x\n");
      FUN_00498130(local_8,(byte *)"EAX: 0x%x\n");
    }
    FUN_00498130(local_8,&DAT_004b3460);
    if ((DAT_004f7380 & 0x10001) == 0) {
      FUN_00498130(local_8,(byte *)"No control register information\n");
    }
    else {
      FUN_00498130(local_8,(byte *)"EBP: 0x%x\n");
      FUN_00498130(local_8,(byte *)"EIP: 0x%x\n");
      FUN_00498130(local_8,(byte *)"CS:  0x%x\n");
      FUN_00498130(local_8,(byte *)"ESP: 0x%x\n");
      FUN_00498130(local_8,(byte *)"SS:  0x%x\n");
      FUN_00498130(local_8,(byte *)"EFLAGS: 0x%x\n");
    }
    if (DAT_004e8318 != 0) {
      FUN_00498130(local_8,(byte *)"\nmemcpy() crash!\n");
      FUN_00498130(local_8,(byte *)"Information string...\n\n");
      FUN_00498130(local_8,&DAT_004f7660);
    }
    FUN_00497b30(local_8);
    wsprintfA(local_38c,
              "Lucky Luke detected an exception in LUCKY.EXE.\n\n   Time: %s\n   Date: %s\n   File: %s\n\nPlease provide this file along with LUCKY_DEBUG.TXT in your bug report. Have a nice day!\n"
              ,local_148,local_188,&local_108);
    __chkesp();
    MessageBoxA((HWND)0x0,local_38c,"Handled Exception!",0);
    __chkesp();
  }
  local_8 = (int *)0x42bcad;
  __chkesp();
  return;
}

