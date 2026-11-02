/* FUN_00422b50 @ 00422b50 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00422b50(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_80 [16];
  int local_40;
  undefined1 local_3c [52];
  undefined4 *local_8;
  
  puVar2 = local_80;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1[0x21] != 0) {
    local_8 = param_1;
    (*DAT_004e8a2c)(10,100,"Task::Show():  flags = %u",(int)*(char *)(param_1 + 0x20));
    __chkesp();
    (*DAT_004e8a2c)(10,0x6e,"id_task=%d",*local_8);
    __chkesp();
    (*DAT_004e8a2c)(10,0x78,"data_start=%u",*(undefined2 *)local_8[0x21]);
    __chkesp();
    (*DAT_004e8a2c)(10,0x82,"code_start=%u",*(undefined2 *)(local_8[0x21] + 2));
    __chkesp();
    (*DAT_004e8a2c)(10,0x8c,"virtual_start=%u",*(undefined2 *)(local_8[0x21] + 4));
    __chkesp();
    (*DAT_004e8a2c)(10,0x96,"virtual_nb=%u",*(undefined2 *)(local_8[0x21] + 6));
    __chkesp();
    (*DAT_004e8a2c)(10,0xa0,"conditions_start=%u",*(undefined2 *)(local_8[0x21] + 8));
    __chkesp();
    (*DAT_004e8a2c)(10,0xaa,"inti_state_nb=%u",*(undefined2 *)(local_8[0x21] + 10));
    __chkesp();
    (*DAT_004e8a2c)(10,0xb4,"code_end=%u",*(undefined2 *)(local_8[0x21] + 0xc));
    __chkesp();
    (*DAT_004e8a2c)(10,0xbe,"states_nb=%u",*(undefined2 *)(local_8[0x21] + 0xe));
    __chkesp();
    if (*(short *)local_8[0x21] != -1) {
      for (local_40 = 0; local_40 < 1; local_40 = local_40 + 1) {
        FUN_00497080(local_3c,0x4b4734);
        FUN_00477a80();
      }
    }
  }
  local_8 = (undefined4 *)0x422db0;
  __chkesp();
  return;
}

