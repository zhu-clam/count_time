#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <unistd.h>
#include <linux/if_tun.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <linux/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <pthread.h>



#define RD_file0 "./txt/0/1.txt"
#define RD_file1 "./txt/1/1.txt"
#define RD_file2 "./txt/2/1.txt"
#define RD_file3 "./txt/3/1.txt"

#define CR_file0 "./txt/0/2.txt"
#define CR_file1 "./txt/1/2.txt"
#define CR_file2 "./txt/2/2.txt"
#define CR_file3 "./txt/3/2.txt"

#define FI_file0 "./txt/0/3.txt"
#define FI_file1 "./txt/1/3.txt"
#define FI_file2 "./txt/2/3.txt"
#define FI_file3 "./txt/3/3.txt"


pthread_t   read_file0_p;
pthread_t   read_file1_p;
pthread_t   read_file2_p;
pthread_t   read_file3_p;

static int FLAG_RD2 = 0;
static int FLAG_WR3 = 0;

/*
* https://www.cnblogs.com/yinbiao/p/11190336.html
* read "0/boya_detect.txt" file and operation it.
*/
void read_file0(void *data_ptr)
{
	/*step1. open file0. */ 
	int ret;
	//char file_init = '2';
	char file_buf;	
	int es_fd = -1;

	/* detect file 1.txt is exist */
	while(1) {
		if (access(RD_file0, F_OK) == 0)
	    {
	        printf(" %s exists.\n",RD_file0);
			break;
	    }
	}

	/*Create file 2.txt */
	open(CR_file0, O_CREAT | O_TRUNC | O_RDWR, 0600);
	while(1) {
		if (access(CR_file0, F_OK) == 0)
		{	
			#ifndef WITH_ATOMIC
				FLAG_RD2++;
			#else			
				__sync_add_and_fetch(&FLAG_RD2, 1);
			#endif				
			break;
		}
		else { 
			open(CR_file0, O_CREAT | O_TRUNC | O_RDWR, 0600);
		}
	}
	

	/*step3. cycle check file 3.txt is exist*/
	while(1) {
		if (access(FI_file0, F_OK) == 0)
	    {
	        printf(" %s exists.\n",FI_file0);
			#ifndef WITH_ATOMIC
			FLAG_WR3++;
			#else			
			__sync_add_and_fetch(&FLAG_WR3, 1);
			#endif				
			break;
	    }
	}	
	
	return ;
}


/*
* https://www.cnblogs.com/yinbiao/p/11190336.html
* read "0/boya_detect.txt" file and operation it.
*/
void read_file1(void *data_ptr)
{
	/*step1. open file0. */ 
	int ret;
	//char file_init = '2';
	char file_buf;	
	int es_fd = -1;

	/* detect file 1.txt is exist */
	while(1) {
		if (access(RD_file1, F_OK) == 0)
	    {
	        printf(" %s exists.\n",RD_file1);
			#ifndef WITH_ATOMIC
			FLAG_RD2++;
			#else			
			__sync_add_and_fetch(&FLAG_RD2, 1);
			#endif				
			break;
	    }
	}

	/*Create file 2.txt */
	open(CR_file1, O_CREAT | O_TRUNC | O_RDWR, 0600);
	while(1) {
		if (access(CR_file1, F_OK) == 0)
		{	
		#ifndef WITH_ATOMIC
				FLAG_RD2++;
		#else			
				__sync_add_and_fetch(&FLAG_RD2, 1);
		#endif				
			break;
		}
		else { 
			open(CR_file1, O_CREAT | O_TRUNC | O_RDWR, 0600);
		}
	}

	/*step3. cycle check file 3.txt is exist*/
	while(1) {
		if (access(FI_file1, F_OK) == 0)
	    {
	        printf(" %s exists.\n",FI_file1);
			#ifndef WITH_ATOMIC
			FLAG_WR3++;
			#else			
			__sync_add_and_fetch(&FLAG_WR3, 1);
			#endif				
			break;
	    }
	}	
	
	return ;
}




/*
* https://www.cnblogs.com/yinbiao/p/11190336.html
* read "0/boya_detect.txt" file and operation it.
*/
void read_file2(void *data_ptr)
{
	/*step1. open file0. */ 
	int ret;
	//char file_init = '2';
	char file_buf;	
	int es_fd = -1;

	/* detect file 1.txt is exist */
	while(1) {
		if (access(RD_file2, F_OK) == 0)
	    {
	        printf(" %s exists.\n",RD_file2);
			#ifndef WITH_ATOMIC
			FLAG_RD2++;
			#else			
			__sync_add_and_fetch(&FLAG_RD2, 1);
			#endif				
			break;
	    }
	}

	/*Create file 2.txt */
//	open(CR_file2, O_CREAT | O_TRUNC | O_RDWR, 0600);
	open(CR_file2, O_CREAT | O_TRUNC | O_RDWR, 0600);
	while(1) {
		if (access(CR_file2, F_OK) == 0)
		{	
			#ifndef WITH_ATOMIC
				FLAG_RD2++;
			#else			
				__sync_add_and_fetch(&FLAG_RD2, 1);
			#endif				
			break;
		}
		else { 
			open(CR_file2, O_CREAT | O_TRUNC | O_RDWR, 0600);
		}
	}

	/*step3. cycle check file 3.txt is exist*/
	while(1) {
		if (access(FI_file2, F_OK) == 0)
	    {
	        printf(" %s exists.\n",FI_file2);
			#ifndef WITH_ATOMIC
			FLAG_WR3++;
			#else			
			__sync_add_and_fetch(&FLAG_WR3, 1);
			#endif				
			break;
	    }
	}	
	
	return ;
}


/*
* https://www.cnblogs.com/yinbiao/p/11190336.html
* read "0/boya_detect.txt" file and operation it.
*/
void read_file3(void *data_ptr)
{
	/*step1. open file0. */ 
	int ret;
	//char file_init = '2';
	char file_buf;	
	int es_fd = -1;

	/* detect file 1.txt is exist */
	while(1) {
		if (access(RD_file3, F_OK) == 0)
	    {
	        printf(" %s exists.\n",RD_file3);
			#ifndef WITH_ATOMIC
			FLAG_RD2++;
			#else			
			__sync_add_and_fetch(&FLAG_RD2, 1);
			#endif				
			break;
	    }
	}

	/*Create file 2.txt */
//	open(CR_file3, O_CREAT | O_TRUNC | O_RDWR, 0600);
	open(CR_file3, O_CREAT | O_TRUNC | O_RDWR, 0600);
	while(1) {
		if (access(CR_file3, F_OK) == 0)
		{	
		#ifndef WITH_ATOMIC
				FLAG_RD2++;
		#else			
				__sync_add_and_fetch(&FLAG_RD2, 1);
		#endif				
			break;
		}
		else { 
			open(CR_file3, O_CREAT | O_TRUNC | O_RDWR, 0600);
		}
	}

	/*step3. cycle check file 3.txt is exist*/
	while(1) {
		if (access(FI_file3, F_OK) == 0)
	    {
	        printf(" %s exists.\n",FI_file3);
			#ifndef WITH_ATOMIC
			FLAG_WR3++;
			#else			
			__sync_add_and_fetch(&FLAG_WR3, 1);
			#endif				
			break;
	    }
	}	
	
	return ;
}


int check_file_exist() 
{
	int ret;
	char file_buf;	
	int es_fd0,es_fd1,es_fd2,es_fd3;
	
	//read file to get value until its become 1
	es_fd0=open(file0,O_RDONLY);
	if (es_fd0<0)
	{		
		printf("check file %s isnot exist\n",file0);
		return 0;
	}
	while(1) {	
		lseek(es_fd0, 0, SEEK_SET);//每次只读首个字符.
		ret = read(es_fd0,&file_buf,sizeof(file_buf));
		/*step3. when file_buf is '1' write 2 to file,than set FLAG_RD2*/	
		if(file_buf == '1')
		{
			printf("file %s is alread %c\n ", file0,file_buf);
			memset(&file_buf,0,sizeof(file_buf));
			break;
		}
	}
	
	es_fd1=open(file1,O_RDONLY);
	if (es_fd1<0)
	{
		printf("check file %s isnot exist\n",file1);
		close(es_fd0);
		return 0;
	}
	while(1) {	
		lseek(es_fd1, 0, SEEK_SET);//每次只读首个字符.
		ret = read(es_fd1,&file_buf,sizeof(file_buf));
		/*step3. when file_buf is '1' write 2 to file,than set FLAG_RD2*/	
		if(file_buf == '1')
		{
			printf("file %s is alread %c\n ", file1,file_buf);
			memset(&file_buf,0,sizeof(file_buf));
			break;
		}
	}	
	
	es_fd2=open(file2,O_RDONLY);
	if (es_fd2<0)
	{
		printf("check file %s isnot exist\n",file2);
		close(es_fd0);
		close(es_fd1);
		return 0;
	}
	while(1) {	
		lseek(es_fd2, 0, SEEK_SET);//每次只读首个字符.
		ret = read(es_fd2,&file_buf,sizeof(file_buf));
		/*step3. when file_buf is '1' write 2 to file,than set FLAG_RD2*/	
		if(file_buf == '1')
		{
			printf("file %s is alread %c\n ", file2,file_buf);
			memset(&file_buf,0,sizeof(file_buf));
			break;
		}
	}		
	
	es_fd3=open(file3,O_RDONLY);
	if (es_fd3<0)
	{
		printf("check file %s isnot exist\n",file3);
		close(es_fd0);
		close(es_fd1);
		close(es_fd2);
		return 0;
	}
	while(1) {	
		lseek(es_fd3, 0, SEEK_SET);//每次只读首个字符.
		ret = read(es_fd3,&file_buf,sizeof(file_buf));
		/*step3. when file_buf is '1' write 2 to file,than set FLAG_RD2*/	
		if(file_buf == '1')
		{
			printf("file %s is alread %c\n ", es_fd3,file_buf);
			memset(&file_buf,0,sizeof(file_buf));
			break;
		}
	}	
	
	return 1;
}


//statistic boya algorithm spend time for run program.
/*
* 方案一、 使用标志位的方式,来通知主线程开始计时.
*          当读取文件值为1时,给标志位+1.标志位等于4时,满足条件.则开始计时
* 
* Advantage & disadvantage
* 优点: 思路清晰,编码简单,容易实现.
* 缺点: 在多线程编程中,没有对标志位 FLAG_RD2 保护,不能确保对其原子操作.
* 换言之, 在多线程时,由于程序运行中变量缓存机制.FLAG_RD2 的值并非实时的,同一时间对 FLAG_RD2++的操作,
* 原本为(FLAG_RD2+2) 但结果却是(FLAG_RD2+1)的错误可能.
*
* 改进方案、 对标志位进行原子操作,即多线程编程中,对共享代码段互斥执行.
* 1. Linux 用户层多线程无锁化原子操作; 实现多线程共享区互斥
*  https://blog.csdn.net/shemangui/article/details/50444583?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-3.nonecase
*
* 2. Linux 用户层多线程 加锁互斥.
* 将多线程无锁化原子函数 vs 普通线程锁 效率和用法usage 进行对比. (原子操作效率更高,耗时更短.)
*    线程锁？？ 知识点,的运用.
*/
#define FILE_NUMBER 2
int main(int argc, char** argv)
{

	struct timeval t_start,t_end;
	float duration_ms;
	int ret;

	printf("waiting for file be created\n ");
	/*waiting for file be created*/
	#if 0
	while(1) {
		ret = check_file_exist();
		if(ret)
			break;	
	}
	#endif
	
	printf("ep has alread created boya_detect.txt file...\n ");	
    /*1.first to create four thread.*/
	//pthread_create(&read_file0_p,NULL,(void *)&read_file0,NULL);
	pthread_create(&read_file1_p,NULL,(void *)&read_file1,NULL);
	pthread_create(&read_file2_p,NULL,(void *)&read_file2,NULL);
	//pthread_create(&read_file3_p,NULL,(void *)&read_file3,NULL);

	printf("create four thread ok!\n ");
	/*2. judgement flag and count detect time*/
    while(1) {
		if(FLAG_RD2 == FILE_NUMBER)
		{
			
			/*starting count time*/
			printf("starting count time\n ");
			//char ch = getchar();
			gettimeofday(&t_start, NULL);
			while(1) {
				if (FLAG_WR3 == FILE_NUMBER) 
				{
					/*end to count time*/
					gettimeofday(&t_end, NULL);
					duration_ms=(t_end.tv_sec - t_start.tv_sec)*1000+(t_end.tv_usec - t_start.tv_usec)/1000;
					printf("finish count duration_ms=%.2f[ms]\n",duration_ms);
					//pthread_join(read_file0_p, NULL);
					pthread_join(read_file1_p, NULL);
					pthread_join(read_file2_p, NULL);
					//pthread_join(read_file3_p, NULL);
					exit(0);
					//return;
				}
			}	
		}

	}

}
























