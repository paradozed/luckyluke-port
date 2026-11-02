/* FUN_00443350 @ 00443350 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00443350(LPCSTR param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00458ec0();
  local_8 = (int *)FUN_00442ae0(param_1);
  if (local_8 != (int *)0x0) {
    FUN_00458ec0();
    FUN_00442c20((int)local_8,&DAT_004b74b8,&DAT_004be3c8,1);
    FUN_00442c20((int)local_8,&DAT_004b74b0,&DAT_004be3cc,1);
    FUN_00442c20((int)local_8,"Record",&DAT_004e8584,1);
    FUN_00442c20((int)local_8,"Driver",s_3dfx_w3x_004bcecc,3);
    FUN_00442c20((int)local_8,"StartLevel",&DAT_004bcec8,1);
    FUN_00442c20((int)local_8,"Presentations",&DAT_004e8588,1);
    FUN_00442c20((int)local_8,"Instance",&DAT_004e858c,1);
    FUN_00442c20((int)local_8,"Windowed",&DAT_004e8590,1);
    FUN_00442c20((int)local_8,"AutoScreen",&DAT_004e8594,1);
    FUN_00442c20((int)local_8,"Invincible",&DAT_004e8598,1);
    FUN_00442c20((int)local_8,"PlayDemo",&DAT_004e859c,1);
    FUN_00442c20((int)local_8,"TextureBackgrounds",&DAT_004bcfcc,1);
    FUN_00442c20((int)local_8,"InterlaceOn",&DAT_004e85a0,1);
    FUN_00442c20((int)local_8,"BlitSelect",&DAT_004e85a8,1);
    FUN_00442c20((int)local_8,"StartSound",&DAT_004bcfd0,1);
    FUN_00442c20((int)local_8,"MouseOn",&DAT_004bcfd4,1);
    FUN_00442c20((int)local_8,"PriceLife",&DAT_004bcfd8,1);
    FUN_00442c20((int)local_8,"PricePassword",&DAT_004bcfdc,1);
    FUN_00442c20((int)local_8,"FontScaleX",&DAT_004bcfe0,1);
    FUN_00442c20((int)local_8,"FontScaleY",&DAT_004bcfe4,1);
    FUN_00458ec0();
    FUN_004430e0(local_8);
    FUN_00458ec0();
    FUN_004432b0(local_8);
  }
  local_8 = (int *)0x4435c6;
  __chkesp();
  return;
}

