﻿#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
  stat("text1", &stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
  stat("text2", &stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){
  time1 = localtime(&stat1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
	time2 = localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
	printf("size compare\n");
	if ((int)stat1.st_size > (int)stat2.st_size)
	{
		printf("text1 is bigger\n");
	}
	else if ((int)stat1.st_size < (int)stat2.st_size)
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
	printf("block compare\n");
	if ((int)stat1.st_blocks > (int)stat2.st_blocks)
	{
		printf("text1 is bigger\n");
	}
	else if ((int)stat1.st_blocks < (int)stat2.st_blocks)
	{
		printf("text2 is bigger\n");
	}
	else
	{
		printf("sizes are equal\n");
	}
	printf("\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
	printf("date compare \n");
	if (time1->tm_mon <= time2->tm_mon && time1->tm_mday < time2->tm_mday)
		printf("text 1's Modified date is earier than text 2\n");
	else if (time1->tm_mon == time2->tm_mon && time1->tm_mday == time2->tm_mday)
		printf("text 1's Modified date is the same as text 2 \n");
	else
		printf("text 2's Modified date is earier than text 1\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
	int text1_time = time1->tm_hour * 60 + time1->tm_sec;
	int text2_time = time2->tm_hour * 60 + time2->tm_sec;

	printf("time compare \n");
	if (text1_time < text2_time)
		printf("text 1's Modified time is earier than text 2\n");
	else if (text1_time = text2_time)
		printf("text 1's Modified time is the same as text 2 \n");
	else
		printf("text 2's Modified time is earier than text 1\n");
}
