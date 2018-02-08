# Getting started

## Module documentation

    head kernel_module/modulename.c

Many of the modules have userland test scripts / executables with the same name as the module, e.g. form inside the guest:

    /modulename.sh
    /modulename.out

The sources of those tests will further clarify what the corresponding kernel modules does. To find them on the host, do a quick:

    git ls-files | grep modulename

## Rebuild

If you make changes to the kernel modules or most configurations tracked on this repository, you can just use again:

    ./build
    ./run

and the modified files will be rebuilt.

If you change any package besides `kernel_module`, you must also request those packages to be reconfigured or rebuilt with extra targets, e.g.:

    ./build -t linux-reconfigure -t host-qemu-reconfigure

Those aren't turned on by default because they take quite a few seconds.

## Filesystem persistency

The root filesystem is persistent across:

    ./run
    date >f
    sync
    poweroff

then:

    ./run
    cat f

This is particularly useful to re-run shell commands from the history of a previous session with `Ctrl + R`.

However, when you do:

    ./build

the disk image gets overwritten by a fresh filesystem and you lose all changes.

Remember that if you forcibly turn QEMU off without `sync` or `poweroff` from inside the VM, e.g. by closing the QEMU window, disk changes may not be saved.

## Message control

We use `printk` a lot, and it shows on the QEMU terminal by default. If that annoys you (e.g. you want to see stdout separately), do:

    dmesg -n 1

See also: <https://superuser.com/questions/351387/how-to-stop-kernel-messages-from-flooding-my-console>

You can scroll up a bit on the default TTY with:

    Shift + PgUp

but I never managed to increase that buffer:

- <https://askubuntu.com/questions/709697/how-to-increase-scrollback-lines-in-ubuntu14-04-2-server-edition>
- <https://unix.stackexchange.com/questions/346018/how-to-increase-the-scrollback-buffer-size-for-tty>

The superior alternative is to use text mode or a telnet connection.

## Text mode

Show serial console directly on the current terminal, without opening a QEMU window:

    ./run -n

To exit, just do a regular:

    poweroff

This mode is very useful to:

- get full panic traces when you start making the kernel crash :-) See also: <https://unix.stackexchange.com/questions/208260/how-to-scroll-up-after-a-kernel-panic>
- copy and paste commands and stdout output to / from host
- have a large scroll buffer, and be able to search it, e.g. by using GNU `screen` on host

If the system crashes and you can't can quit QEMU with `poweroff`, or if `poweroff` is just too slow for your patience, you can hard kill the VM with

    Ctrl-C X

or:

    Ctrl-C A
    quit

or on host:

    ./qemumonitor
    quit

or:

    echo quit | ./qemumonitor

See also:

- <http://stackoverflow.com/questions/14165158/how-to-switch-to-qemu-monitor-console-when-running-with-curses>
- <https://superuser.com/questions/1087859/how-to-quit-qemu-monitor>
- <https://superuser.com/questions/488263/problems-switching-to-qemu-control-panel-with-nographics>
- <https://superuser.com/questions/1087859/how-to-quit-the-qemu-monitor-when-not-using-a-gui/1211516#1211516>

Limitations:

-   TODO: Ctrl + C kills the emulator for some setups (TODO which what exactly?), and not sent to guest processes. See:

    - <https://github.com/cloudius-systems/osv/issues/49>
    - <https://unix.stackexchange.com/questions/167165/how-to-pass-ctrl-c-in-qemu>

    This is however fortunate when running QEMU with GDB, as the Ctrl + C reaches GDB and breaks.

-   Very early kernel messages such as `early console in extract_kernel` only show on the GUI, since at such early stages, not even the serial has been setup.

## Automatic startup commands

When debugging a module, it becomes tedious to wait for build and re-type:

    root
    /modulename.sh

every time.

Instead, you can add your test commands to:

    cp rootfs_overlay/etc/init.d/S98 rootfs_overlay/etc/init.d/S99
    vim S99
    ./build
    ./run

and they will be run automatically before the login prompt.

`S99` is a git tracked convenience symlink to the gitignored `rootfs_overlay/etc/init.d/S99`

Scripts under `/etc/init.d` are run by `/etc/init.d/rcS`, which gets called by the line `::sysinit:/etc/init.d/rcS` in `/etc/inittab`.

## Kernel version

We try to use the latest possible kernel major release version.

In QEMU:

    cat /proc/version

or in the source:

    cd linux
    git log | grep -E '    Linux [0-9]+\.' | head

Build configuration can be observed in guest with:

    zcat /proc/config.gz

or on host:

    cat buildroot/output.*~/build/linux-custom/.config

## QEMU GUI is unresponsive

Sometimes in Ubuntu 14.04, after the QEMU SDL GUI starts, it does not get updated after keyboard strokes, and there are artifacts like disappearing text.

We have not managed to track this problem down yet, but the following workaround always works:

    Ctrl + Shift + U
    Ctrl + C
    root

This started happening when we switched to building QEMU through Buildroot, and has not been observed on later Ubuntu.

Using text mode is another workaround if you don't need GUI features.

## Debug QEMU

When you start interacting with QEMU hardware, it is useful to see what is going on inside of QEMU itself.

This is of course trivial since QEMU is just an userland program on the host, but we make it a bit easier with:

    ./run -q

Then you could:

    b edu_mmio_read
    c

And in QEMU:

    /pci.sh

Just make sure that you never click inside the QEMU window when doing that, otherwise you mouse gets captured forever, and the only solution I can find is to go to a TTY with Ctrl + Alt + F1 and `kill` QEMU.

You can still send key presses to QEMU however even without the mouse capture, just either click on the title bar, or alt tab to give it focus.

## Clean the build

You did something crazy, and nothing seems to work anymore?

All builds are stored under `buildroot/`,

The most coarse thing you can do is:

    cd buildroot
    git checkout -- .
    git clean -xdf .

To only nuke one architecture, do:

    rm -rf buildroot/output.x86_64~

Only nuke one one package:

    rm -rf buildroot/output.x86_64~/build/<package>
