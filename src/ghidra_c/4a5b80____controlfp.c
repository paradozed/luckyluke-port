/* __controlfp @ 004a5b80 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __controlfp
   
   Library: Visual Studio 2003 Debug */

uint __cdecl __controlfp(uint _NewValue,uint _Mask)

{
  uint uVar1;
  
  uVar1 = FUN_004a5b30(_NewValue,_Mask & 0xfff7ffff);
  return uVar1;
}

