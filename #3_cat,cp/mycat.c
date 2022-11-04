/**
 * mycat.c	: cat command program
 * @author	: Minji Kim
 * @email	: 32200588@dankook.ac.kr
 * @version	: 1.0
 * @data	: 2022.11.03
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define MAX_BUF 64

int main(int argc, char *argv[]){
	int fd, read_size, write_size;
	char buf[MAX_BUF];

	if(argc != 2) {
		printf("잘못된 사용법입니다. (사용법 : %s 파일이름)\n", argv[0]);
		exit(-1);
	}
	fd = open(argv[1], O_RDONLY);
	if(fd<0) {
		printf("해당 파일 %s가 존재하지 않습니다. (ERRNO : %d)\n", argv[1], errno);
		exit(-1);
	}
	while(1) {
		read_size = read(fd, buf, MAX_BUF);
		if(read_size == 0)
			break;
		write_size = write(STDOUT_FILENO, buf, read_size);
	}
	close(fd);
	return 0;
}
