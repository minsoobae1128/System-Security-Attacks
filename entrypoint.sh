#!/bin/bash
# Auto-enable full ASLR on container start.
# Requires the container to be started with --privileged
# (otherwise /proc/sys is read-only).

if echo 2 | sudo tee /proc/sys/kernel/randomize_va_space > /dev/null 2>&1; then
    echo "[+] ASLR enabled: $(cat /proc/sys/kernel/randomize_va_space) (full)"
else
    echo "[!] Could not enable ASLR — container not started with --privileged." >&2
fi

exec "$@"
