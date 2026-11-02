/* __set_errno @ 004ac290 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __set_errno
   
   Libraries: Visual Studio 2003 Debug, Visual Studio 2003 Release */

errno_t __cdecl __set_errno(int _Value)

{
  if (_Value == 1) {
    DAT_004e8c64 = 0x21;
  }
  else if ((1 < _Value) && (_Value < 4)) {
    DAT_004e8c64 = 0x22;
  }
  return _Value;
}

