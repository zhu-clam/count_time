#include <unistd.h>
#include <stdio.h>
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


#define file0 "./0/boya_detect.txt"
#define file1 "./1/boya_detect.txt"
#define file2 "./2/boya_detect.txt"
#define file3 "./3/boya_detect.txt"


pthread_t   read_file0_p;
pthread_t   read_file1_p;
pthread_t   read_file2_p;
pthread_t   read_file3_p;

static int FLAG_RD2 = 0;
static int FLAG_WR3 = 0;

/*
* read "0/boya_detect.txt" file and operation it.
*/
void read_file0(void *data_ptr)
{
	/*step1. open file0. */ 
	int ret;
	char file_init = '2';
	char file_buf;	
	int es_fd = -1;
	es_fd=open(file0,O_RDWR,0777);
	if (es_fd<0)
	{
		perror("open");
		return ;
	}

	printf("open %s ok es_fd = %d\n",file0,es_fd);
	/*step2. cycle read file to get file value.*/
	while(1) {	
		lseek(es_fd, 0, SEEK_SET);//每次只读首个字符.
		ret = read(es_fd,&file_buf,sizeof(file_buf));
		/*step3. when file_buf is '1' write 2 to file,than set FLAG_RD2*/
		if(file_buf == '1')
		{ 
			ret = write(es_fd,&file_init,sizeof(file_init));
			FLAG_RD2++;
			
			/*step4. when file_buf is '3' ,set FLAG_WR3 */
			while(1)
			{
				lseek(es_fd, 0, SEEK_SET);//每次只读首个字符.
				ret = read(es_fd,&file_buf,sizeof(file_buf));
				//printf("read file_buf:%c\n", file_buf);
				
				if(file_buf == '3' )
				{
					FLAG_WR3++;
					close(es_fd);
					return ;//exit(0)
				}				
			}
		}
	}
	
	return ;
}


/*
* read "1/boya_detect.txt" file and operation it.
*/
void read_file1(void *data_ptr)
{
	/*step1. open file0. */ 
	int ret;
	char file_init = '2';
	char file_buf;	
	int es_fd = -1;
	es_fd=open(file1,O_RDWR,0777);
	if (es_fd<0)
	{
		perror("open");
		return ;
	}
	
	printf("open %s ok es_fd = %d\n",file1,es_fd);
	/*step2. cycle read file to get file value.*/
	while(1) {	
		lseek(es_fd, 0, SEEK_SET);//每次只读首个字符.
		ret = read(es_fd,&file_buf,sizeof(file_buf));
		/*step3. when file_buf is '1' write 2 to file,than set FLAG_RD2*/
		if(file_buf == '1')
		{ 
			ret = write(es_fd,&file_init,sizeof(file_init));
			FLAG_RD2++;
			
			/*step4. when file_buf is '3' ,set FLAG_WR3 */
			while(1)
			{
				lseek(es_fd, 0, SEEK_SET);//每次只读首个字符.
				ret = read(es_fd,&file_buf,sizeof(file_buf));
				//printf("read file_buf:%c\n", file_buf);
				
				if(file_buf == '3' )
				{
					FLAG_WR3++;
					close(es_fd);
					return ;//exit(0)
				}				
			}
		}
	}
	
	return ;
}
/*
* read "2/boya_detect.txt" file and operation it.
*/
void read_file2(void *data_ptr)
{
	/*step1. open file0. */  
	int ret;
	char file_init = '2';
	char file_buf;	
	int es_fd = -1;
	es_fd=open(file2,O_RDWR,0777);
	if (es_fd<0)
	{
		perror("open");
		return ;
	}

	printf("open %s ok es_fd = %d\n",file2,es_fd);
	/*step2. cycle read file to get file value.*/
	while(1) {	
		lseek(es_fd, 0, SEEK_SET);//每次只读首个字符.
		ret = read(es_fd,&file_buf,sizeof(file_buf));
		/*step3. when file_buf is '1' write 2 to file,than set FLAG_RD2*/
		if(file_buf == '1')
		{ 
			ret = write(es_fd,&file_init,sizeof(file_init));
			FLAG_RD2++;
			
			/*step4. when file_buf is '3' ,set FLAG_WR3 */
			while(1)
			{
				lseek(es_fd, 0, SEEK_SET);//每次只读首个字符.
				ret = read(es_fd,&file_buf,sizeof(file_buf));
				//printf("read file_buf:%c\n", file_buf);
				
				if(file_buf == '3' )
				{
					FLAG_WR3++;
					close(es_fd);
					return ;//exit(0)
				}				
			}
		}
	}
	
	return ;
}
/*
* read "3/boya_detect.txt" file and operation it.
*/
void read_file3(void *data_ptr)
{
	/*step1. open file0. */    
	char file_init = '2';
	int ret;
	char file_buf;	
	int es_fd = -1;
	es_fd=open(file3,O_RDWR,0777);
	if (es_fd<0)
	{
		perror("open");
		return ;
	}

	printf("open %s ok es_fd = %d\n",file3,es_fd);
	/*step2. cycle read file to get file value.*/
	while(1) {	
		lseek(es_fd, 0, SEEK_SET);//每次只读首个字符.
		ret = read(es_fd,&file_buf,sizeof(file_buf));
		/*step3. when file_buf is '1' write 2 to file,than set FLAG_RD2*/
		if(file_buf == '1')
		{ 
			ret = write(es_fd,&file_init,sizeof(file_init));
			FLAG_RD2++;
			
			/*step4. when file_buf is '3' ,set FLAG_WR3 */
			while(1)
			{
				lseek(es_fd, 0, SEEK_SET);//每次只读首个字符.
				ret = read(es_fd,&file_buf,sizeof(file_buf));
				//printf("read file_buf:%c\n", file_buf);
				
				if(file_buf == '3' )
				{
					FLAG_WR3++;
					close(es_fd);
					return ;//exit(0)
				}				
			}
		}
	}
	
	return ;
}





//statistic boya algorithm time
int main(int argc, char** argv)
{

	struct timeval t_start,t_end;
	float duration_ms;

    /*1.first to create four thread.*/
	pthread_create(&read_file0_p,NULL,(void *)&read_file0,NULL);
	pthread_create(&read_file1_p,NULL,(void *)&read_file1,NULL);
	pthread_create(&read_file2_p,NULL,(void *)&read_file2,NULL);
	pthread_create(&read_file3_p,NULL,(void *)&read_file3,NULL);

	printf("create four thread ok!\n ");
	/*2. judgement flag and count detect time*/
    while(1) {
		if(FLAG_RD2 == 4)
		{
			
			/*starting count time*/
			printf("cstarting count time\n ");
			gettimeofday(&t_start, NULL);
			while(1) {
				if (FLAG_WR3 == 4) 
				{
					/*end to count time*/
					gettimeofday(&t_end, NULL);
					duration_ms=(t_end.tv_sec - t_start.tv_sec)*1000+(t_end.tv_usec - t_start.tv_usec)/1000;
					printf("finish count duration_ms=%.2f[ms]\n",duration_ms);
					return;
				}
			}	
		}

	}

}
























