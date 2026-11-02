/* FUN_004331b0 @ 004331b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004331b0(char *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_288 [16];
  size_t local_248;
  char local_244 [19];
  undefined1 local_231;
  uint *local_214;
  CHAR local_210 [260];
  uint *local_10c;
  uint local_108 [64];
  undefined4 uStack_8;
  
  puVar3 = local_288;
  for (iVar2 = 0xa1; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  _memset(local_108,0,0x104);
  GetLogicalDriveStringsA(0x104,(LPSTR)local_108);
  __chkesp();
  local_10c = local_108;
  do {
    if (((char)*local_10c == '\0') && (*(char *)((int)local_10c + 1) == '\0')) goto LAB_004333a5;
    wsprintfA(local_210,"%s%s",local_10c,"CDINFO.FIL");
    __chkesp();
    GetDriveTypeA((LPCSTR)local_10c);
    iVar2 = __chkesp();
    if ((iVar2 == 5) && (local_214 = (uint *)FUN_00497d00(local_210,"rb"), local_214 != (uint *)0x0)
       ) {
      uVar1 = FUN_004989e0(local_244,1,0x13,(int *)local_214);
      if (uVar1 == 0x13) {
        local_231 = 0;
        iVar2 = _strcmp(local_244,"CD Information File");
        if (iVar2 == 0) {
          FUN_004988b0(local_214,2,1);
          local_248 = _strlen(param_1);
          uVar1 = FUN_004989e0(local_244,1,local_248,(int *)local_214);
          if (uVar1 == 0x1f) {
            local_244[local_248] = '\0';
            iVar2 = _strcmp(local_244,param_1);
            if (iVar2 == 0) {
              if (param_2 != (uint *)0x0) {
                FUN_00497270(param_2,local_10c);
              }
LAB_004333a5:
              uStack_8 = 0x4333b5;
              __chkesp();
              return;
            }
          }
        }
      }
      FUN_00497b30((int *)local_214);
    }
    do {
      uVar1 = *local_10c;
      local_10c = (uint *)((int)local_10c + 1);
    } while ((char)uVar1 != '\0');
  } while( true );
}

