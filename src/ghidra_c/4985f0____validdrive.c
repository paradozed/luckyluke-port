/* __validdrive @ 004985f0 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __validdrive
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2005 Debug, Visual Studio 2008 Debug */

int __cdecl __validdrive(uint param_1)

{
  int iVar1;
  UINT UVar2;
  char local_c [8];
  
  if (param_1 == 0) {
    iVar1 = 1;
  }
  else {
    local_c[0] = (char)param_1 + '@';
    local_c[1] = 0x3a;
    local_c[2] = 0x5c;
    local_c[3] = 0;
    UVar2 = GetDriveTypeA(local_c);
    if ((UVar2 == 0) || (UVar2 == 1)) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}

