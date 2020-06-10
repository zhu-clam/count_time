
#!/bin/bash
#shell中启动多线程
#每个线程读取文件的值,设置标志位,并写入文件的内容.
#
# main 主线程中,阻塞等待标志位,然后开始计时.

#知识点
# 1. shell 多线程编程.
# 2. shell 中计时函数.
# 3. shell 中循环等待读取文件的值.
# 4. shell 中的原子操作.

#2.计时函数
#!/bin/bash
#
#start_time=$(date +%s)
#sleep 1
#
#end_time=$(date +%s)
#
#cost_time=$[ $end_time-$start_time ]
#echo "build kernel time is $(($cost_time/60))min $(($cost_time%60))s"

FLAG_RD2=0
FLAG_WR3=0

do_read_file0() {

	while [ "1" = "1" ]
	do	
	   ssh -o "StrictHostKeyChecking no" root@10.254.10.101  "cat /root/0/boya_detect.txt" > boya_0_detect.txt
	   boya_0_val=$(cat boya_0_detect.txt)
	   if [ $boya_0_val = 1 ];then
			#((CHIP_VAL=CHIP_VAL+1))	
			FLAG_RD2=`expr $FLAG_RD2 + 1` #标志位加1.
			#写2.
			ssh -o "StrictHostKeyChecking no" root@10.254.10.101  "echo 2 > /root/0/boya_detect.txt"
			while [ "1" = "1" ]
			do
				ssh -o "StrictHostKeyChecking no" root@10.254.10.101  "cat /root/0/boya_detect.txt" > boya_0_detect.txt
				boya_0_val=$(cat boya_0_detect.txt)
				if [ $boya_0_val = 3 ];then
					FLAG_WR3=`expr $FLAG_WR3 + 1` #标志位加1.
					break;
				fi
			done
	   fi
	done
}


