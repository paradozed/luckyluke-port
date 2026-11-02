/* findenv @ 0049f210 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    _findenv
   
   Library: Visual Studio 2003 Debug */

int __cdecl findenv(uchar *param_1,size_t param_2)

{
  int iVar1;
  int *local_8;
  
  local_8 = DAT_004e8c8c;
  while( true ) {
    if (*local_8 == 0) {
      return -((int)local_8 - (int)DAT_004e8c8c >> 2);
    }
    iVar1 = __mbsnbicoll(param_1,(uchar *)*local_8,param_2);
    if ((iVar1 == 0) &&
       ((*(char *)(*local_8 + param_2) == '=' || (*(char *)(*local_8 + param_2) == '\0')))) break;
    local_8 = local_8 + 1;
  }
  return (int)local_8 - (int)DAT_004e8c8c >> 2;
}

