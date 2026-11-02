/* FUN_00405350 @ 00405350 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00405350(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_254 [16];
  int local_214;
  CHAR local_210 [256];
  undefined4 local_110;
  uint local_10c [64];
  undefined4 uStack_c;
  int local_8;
  
  puVar2 = local_254;
  for (iVar1 = 0x94; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_110 = 1;
  _DAT_004d1dc8 = 0;
  DAT_004e85b8 = (uint)DAT_004e8914;
  FUN_00497080((undefined1 *)local_10c,0x4b3a60);
  local_214 = DAT_004e8914 - 1;
  switch(local_214) {
  case 0:
    FUN_00497280(local_10c,(uint *)"cinema\\option\\option.cod");
    break;
  case 1:
    FUN_00497280(local_10c,(uint *)"abilene\\abilene.cod");
    break;
  case 2:
    FUN_00497280(local_10c,(uint *)"abi_boss\\abi_boss.cod");
    break;
  case 3:
    FUN_00497280(local_10c,(uint *)"cinema\\gare\\gare.cod");
    break;
  case 4:
    FUN_00497280(local_10c,(uint *)"train\\train1.cod");
    break;
  case 5:
    FUN_00497280(local_10c,(uint *)"cinema\\train\\train1.cod");
    break;
  case 6:
    FUN_00497280(local_10c,(uint *)"train\\train2.cod");
    break;
  case 7:
    FUN_00497280(local_10c,(uint *)"cinema\\train\\train2.cod");
    break;
  case 8:
    FUN_00497280(local_10c,(uint *)"pueblos\\pueblos.cod");
    break;
  case 9:
    FUN_00497280(local_10c,(uint *)"galerie\\galerie.cod");
    break;
  case 10:
    FUN_00497280(local_10c,(uint *)"butter\\butter.cod");
    break;
  default:
    goto LAB_0040563f;
  case 0xc:
    FUN_00497280(local_10c,(uint *)"indien\\indien.cod");
    break;
  case 0xd:
    FUN_00497280(local_10c,(uint *)"cinema\\desert\\desert.cod");
    break;
  case 0x10:
    FUN_00497280(local_10c,(uint *)"chute\\chute.cod");
    break;
  case 0x11:
    FUN_00497280(local_10c,(uint *)"wagon\\wagon.cod");
    break;
  case 0x14:
    FUN_00497280(local_10c,(uint *)"bucheron\\buche2.cod");
    break;
  case 0x16:
    FUN_00497280(local_10c,(uint *)"dalton\\daltoncity.cod");
    break;
  case 0x18:
    FUN_00497280(local_10c,(uint *)"option\\password.cod");
    break;
  case 0x1a:
    FUN_00497280(local_10c,(uint *)"bonus\\tir.cod");
    break;
  case 0x1b:
    FUN_00497280(local_10c,(uint *)"bonus\\brasdfer.cod");
  }
  _DAT_004d1dc8 = FUN_00465720((LPCSTR)local_10c);
  local_8 = _DAT_004d1dc8;
  if (_DAT_004d1dc8 == 0) {
    wsprintfA(local_210,"File not found: %s",local_10c);
    __chkesp();
    MessageBoxA((HWND)0x0,local_210,"Lucky Luke Error",0);
    __chkesp();
    FUN_00496ef0(0xffffffff);
  }
LAB_0040563f:
  uStack_c = 0x40564f;
  __chkesp();
  return;
}

