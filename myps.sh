# Copy source files to /usr
cp -R usr /

# Compile and install the new syscall.
cd /usr/src/minix/servers/pm && make && make install
cd /usr/src/releasetools && make hdboot
cd /usr/src/lib/libc && make && make install
