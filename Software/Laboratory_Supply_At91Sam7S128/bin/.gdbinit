target remote localhost:3333
monitor reset
monitor sleep 500
monitor poll
monitor soft_reset_halt
monitor gdb_breakpoint_override enable
monitor mww 0xE0042004 0x00003C00
monitor soft_reset_halt