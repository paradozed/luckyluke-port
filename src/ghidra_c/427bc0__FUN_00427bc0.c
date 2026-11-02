/* FUN_00427bc0 @ 00427bc0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00427bc0(undefined4 *param_1)

{
  uint *_Str1;
  DWORD dwMessageId;
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  DWORD dwLanguageId;
  CHAR *lpBuffer;
  DWORD nSize;
  char *_Str2;
  va_list *Arguments;
  undefined4 local_154 [16];
  CHAR local_114 [4];
  uint local_110 [65];
  uint local_c;
  uint local_8;
  
  puVar4 = local_154;
  for (iVar3 = 0x54; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (DAT_004e8314 == (undefined *)0x0) {
    _Str2 = "3DFX.W3X";
    _Str1 = FUN_004b2410(param_1 + 0xb);
    iVar3 = _strcmp((char *)_Str1,_Str2);
    if (iVar3 == 0) {
      FUN_00497690((undefined4 *)&DAT_004f7d60,param_1,0x140);
      DAT_004e8314 = &DAT_004f7d60;
      goto LAB_00427fda;
    }
  }
  FUN_00458ec0();
  FUN_00497270(local_110,(uint *)&DAT_004e56d0);
  FUN_00497280(local_110,(uint *)"\\drivers\\");
  FUN_00497280(local_110,param_1 + 0xb);
  FUN_00458ec0();
  FUN_00458ec0();
  LoadLibraryA((LPCSTR)local_110);
  DAT_004e830c = (HMODULE)__chkesp();
  if (DAT_004e830c == (HMODULE)0x0) {
    Arguments = (va_list *)0x0;
    nSize = 0;
    lpBuffer = local_114;
    dwLanguageId = 0x400;
    GetLastError();
    dwMessageId = __chkesp();
    FormatMessageA(0x1300,(LPCVOID)0x0,dwMessageId,dwLanguageId,lpBuffer,nSize,Arguments);
    __chkesp();
    FUN_00458ec0();
  }
  else {
    FUN_00458ec0();
    GetProcAddress(DAT_004e830c,"wxGetDriverInstances");
    DAT_004f7d44 = (code *)__chkesp();
    if (DAT_004f7d44 == (code *)0x0) {
      FreeLibrary(DAT_004e830c);
      __chkesp();
    }
    else {
      GetProcAddress(DAT_004e830c,"wxGetInstanceName");
      DAT_004f778c = (code *)__chkesp();
      if (DAT_004f778c == (code *)0x0) {
        FreeLibrary(DAT_004e830c);
        __chkesp();
      }
      else {
        GetProcAddress(DAT_004e830c,"RegisterWin3DXErrorFunc");
        DAT_004e8a1c = (code *)__chkesp();
        FUN_00458ec0();
        (*DAT_004e8a1c)(FUN_00458ec0);
        __chkesp();
        uVar1 = FUN_00445840();
        uVar2 = FUN_00445810();
        (*DAT_004f7d44)(&DAT_004e57d8,DAT_004e2b68,0,uVar2,uVar1);
        uVar1 = __chkesp();
        local_8 = CONCAT22(local_8._2_2_,(short)uVar1);
        FUN_00458ec0();
        local_c = CONCAT22(local_c._2_2_,DAT_004e2b68);
        while ((local_c & 0xffff) < (uint)DAT_004e2b68 + (local_8 & 0xffff)) {
          FUN_00497270(&DAT_004e57dc + (local_c & 0xffff) * 0x8a,param_1 + 0xb);
          (*DAT_004f778c)(&DAT_004e57d8 + (local_c & 0xffff) * 0x8a,_DAT_004e85ac);
          __chkesp();
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
        }
        DAT_004e2b68 = DAT_004e2b68 + (short)local_8;
        uVar1 = FUN_00445840();
        uVar2 = FUN_00445810();
        (*DAT_004f7d44)(&DAT_004e2b70,DAT_004e8300,1,uVar2,uVar1);
        uVar1 = __chkesp();
        local_8 = CONCAT22(local_8._2_2_,(short)uVar1);
        FUN_00458ec0();
        local_c = CONCAT22(local_c._2_2_,DAT_004e8300);
        while ((local_c & 0xffff) < (uint)DAT_004e8300 + (local_8 & 0xffff)) {
          FUN_00497270((uint *)(&DAT_004e2b74 + (local_c & 0xffff) * 0x228),param_1 + 0xb);
          (*DAT_004f778c)(&DAT_004e57d8 + (local_c & 0xffff) * 0x8a,_DAT_004e85ac);
          __chkesp();
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
        }
        DAT_004e8300 = DAT_004e8300 + (short)local_8;
        FUN_00458ec0();
        FreeLibrary(DAT_004e830c);
        __chkesp();
      }
    }
  }
LAB_00427fda:
  local_8 = 0x427fea;
  __chkesp();
  return;
}

