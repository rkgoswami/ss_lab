// to display the file using stat system call

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc,char *argv[])
{
	struct stat file;
	int n;
	if(argc!=2)
	{
		printf("\nPass argument to cmd line\n");
		exit(-1);
	}
	
	//stat(char *filename's path ,struct stat* file)
	// Upon success completion zero will be returned
	if((n=stat(argv[1],&file))==-1)	//file not found if n=-1
	{
		perror(argv[1]);
		printf(": File not found\n");
	}
	
	// printing the detail of  file
	
	printf("\nUser Id : %d",file.st_uid);
	printf("\nGroup Id : %d",file.st_gid);
	printf("\nBlock size: %d",file.st_blksize);
	printf("\nNo. of Blocks allocated : %d",file.st_blocks);
	printf("\nInode No. : %d",file.st_ino);
	printf("\nLast accessed : %s",ctime(&(file.st_atime)));
	printf("\nLast modified : %s",ctime(&(file.st_mtime)));
	printf("\nFile size is %d bytes",file.st_size);
	printf("\nNo. of links : %d",file.st_nlink);
	printf("\nPermissions : ");
	
	
	printf((S_ISDIR(file.st_mode))?"d":"-");
	printf((file.st_mode & S_IRUSR)?"r":"-");
	printf((file.st_mode & S_IWUSR)?"w":"-");
	printf((file.st_mode & S_IXUSR)?"x":"-");
	printf((file.st_mode & S_IRGRP)?"r":"-");
	printf((file.st_mode & S_IWGRP)?"w":"-");
	printf((file.st_mode & S_IXGRP)?"x":"-");
	printf((file.st_mode & S_IROTH)?"r":"-");
	printf((file.st_mode & S_IWOTH)?"w":"-");
	printf((file.st_mode & S_IXOTH)?"x":"-");
	printf("\n");
	
	if(file.st_mode & S_IFREG)
		printf("\nFile type : Regular");
		
	if(file.st_mode & S_IFDIR)
		printf("\nFile Type : Directory");
	
	printf("\n");	
	return 0;
}
