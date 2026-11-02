/* FUN_00474f00 @ 00474f00 */
/* decompiled from Lucky.exe (Game.run) */


undefined * __cdecl FUN_00474f00(undefined2 param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [17];
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  switch(param_1) {
  case 2:
    puVar1 = PTR_s_abilene_004be118;
    break;
  case 3:
    puVar1 = PTR_s_abi_boss_004be11c;
    break;
  default:
    puVar1 = (undefined *)0x0;
    break;
  case 5:
    puVar1 = PTR_s_train1_004be120;
    break;
  case 7:
    puVar1 = PTR_s_train2_004be124;
    break;
  case 9:
    puVar1 = PTR_s_pueblos_004be128;
    break;
  case 10:
    puVar1 = PTR_s_galerie_004be12c;
    break;
  case 0xb:
    puVar1 = PTR_s_butter_004be130;
    break;
  case 0xd:
    puVar1 = PTR_s_desert_004be138;
    break;
  case 0xf:
    puVar1 = PTR_s_saloon_004be13c;
    break;
  case 0x11:
    puVar1 = PTR_s_chute_004be140;
    break;
  case 0x12:
    puVar1 = PTR_s_wagon_004be144;
    break;
  case 0x14:
    puVar1 = PTR_s_bucheron_004be148;
    break;
  case 0x15:
    puVar1 = PTR_s_buche2_004be14c;
    break;
  case 0x16:
    puVar1 = PTR_s_buche3_004be150;
    break;
  case 0x17:
    puVar1 = PTR_s_dalton1_004be154;
    break;
  case 0x18:
    puVar1 = PTR_s_dalton2_004be158;
  }
  return puVar1;
}

