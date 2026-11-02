/* FUN_0042b3c0 @ 0042b3c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042b3c0(void)

{
  HINSTANCE hInstance;
  int iVar1;
  undefined4 *puVar2;
  LPCSTR lpTemplateName;
  HWND hWndParent;
  code *lpDialogFunc;
  LPARAM dwInitParam;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  dwInitParam = 0;
  lpDialogFunc = FUN_0042ada0;
  lpTemplateName = (LPCSTR)0x76;
  hWndParent = DAT_004f5b78;
  hInstance = (HINSTANCE)FUN_00445840();
  DialogBoxParamA(hInstance,lpTemplateName,hWndParent,lpDialogFunc,dwInitParam);
  __chkesp();
  uStack_8 = 0x42b409;
  __chkesp();
  return;
}

