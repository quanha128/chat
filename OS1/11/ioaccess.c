/*=========================================================
 userland I/O sample program.
   Copyright 2007 Y.Ebihara
   License GPL'd
see
  http://www.si-linux.co.jp/
  http://www.si-linux.co.jp/wiki/cat-inside/index.php?UserLandIO
and
  http://www.si-linux.co.jp/product/cat/
===========================================================*/

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


#define DEVNAME "/dev/mem"

int main(){
	int fd;
	unsigned long from,num,port;
	volatile unsigned char *iomap;
	printf("this is IOmemory test program 2007-01-22 Y.Ebihara\n");

	/* open physical memory device */
	fd=open(DEVNAME, O_RDWR);
	if(fd<=0){
		perror(DEVNAME);
		exit(1);
	}

	/* map physical memory device onto logical space */
	from = 0xa4000000;
	num    = 0x400;
	iomap = mmap(0, num, PROT_READ|PROT_WRITE, MAP_SHARED, fd, from);
	if(iomap < 0){
		perror(DEVNAME);
    	exit(1);
	}
	printf("IOmem mmaped at %p\n",iomap);

	port=0xa4000130;
	*(iomap + port - from) &= ~0x80;

 	/* unmap logical space */
	munmap(iomap,num);

	/* close the file */
	close(fd);
	return 0;
}

