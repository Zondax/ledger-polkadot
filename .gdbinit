# https://www.jetbrains.com/help/clion/configuring-debugger-options.html#gdbinit-lldbinit
#
# You need to create `$HOME/.gdbinit` with the following content:
# set auto-load local-gdbinit on
# add-auto-load-safe-path /

set architecture arm
handle SIGILL nostop pass noprint
add-symbol-file app/bin/app.elf 0x40000000
set backtrace limit 20
b *0x40000000
