/**
 * mycp.c	: copy command programm
 * @author	: Minji Kim
 * @email	: 32200588@dankook.ac.kr
 * @version	: 1.0
 * @date	: 2022.11.04
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#define MAX_BUF 64

int main(int argc, char* argv[]) {
	int fd, fd1, read_size, write_size;
	char buf[MAX_BUF];
	int attribute = 0;
	struct stat fd_attribute;
	
	stat(argv[1], &fd_attribute);
	attribute = fd_attribute.st_mode;
	
	// 입력 형식이 잘못된 경우, 사용법 출력 후 종료
	if(argc != 3) {
		printf("잘못된 사용법입니다. (사용법 : %s 원본파일명 새로운파일명)\n", argv[0]);
		exit(-1);
	}
	
	fd = open(argv[1], O_RDONLY);
	// 복사하려는 파일이 없는 경우, 에러 출력 후 종료
	if(fd < 0) {
		printf("해당 파일 %s가 존재하지 않습니다. (ERRNO : %d)\n", argv[1], errno);
		exit(-1);
	}
	
	fd1 = open(argv[2], O_RDWR | O_CREAT | O_EXCL, attribute);
	// 만드려는 파일 이름이 중복일 경우, 에러 출력 후 종료
	if(fd1 < 0) {
		printf("파일 %s은 현재 디렉토리에 이미 존재하므로 생성할 수 없습니다.(ERRNO : %d)\n", argv[2], errno);
		exit(-1);
	}
	
	while(1) {
		read_size = read(fd, buf, MAX_BUF);
		if(read_size == 0)
			break;
		write_size = write(fd1, buf, read_size);
	}
	
	close(fd);
	close(fd1);
	return 0;
}
