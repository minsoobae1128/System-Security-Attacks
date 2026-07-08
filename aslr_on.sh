#!/bin/bash
# Enable full ASLR inside the container.
# Requires the container to be started with --privileged
# (otherwise /proc/sys is read-only).
#
# NOTE: kernel.randomize_va_space is a host-wide setting; changing it
# here affects the host kernel as well.

if [ ! -w /proc/sys/kernel/randomize_va_space ]; then
    echo "[!] /proc/sys/kernel/randomize_va_space is not writable."
    echo "    Start the container with: docker run --privileged ..."
    exit 1
fi

echo 2 | sudo tee /proc/sys/kernel/randomize_va_space > /dev/null
val=$(cat /proc/sys/kernel/randomize_va_space)
echo "[+] ASLR set to $val (2 = full ASLR: stack, libs, heap, mmap)"
