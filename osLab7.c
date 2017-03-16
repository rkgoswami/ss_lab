#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define N 5
#define BUFFER 1
#define PERMS 0665

int *buffer;
int nextp=0,nextc=0;
int mutex,full,empty;

void producer()
{
//	int data;
	if(nextp==N)
		nextp=0;
	printf("\nEnter the data for producer to produce : ");
	scanf("%d",(buffer+nextp));
	nextp++;
}

void consumer()
{
	int g;
	if(nextc==N)
		nextc=0;
	g=*(buffer+nextc++);
	printf("\nData consumed : %d",g);
}

void sem_op(int id,int value)
{
	struct sembuf op;
	int v;
	op.sem_num=0;
	op.sem_op=value;
	op.sem_flg=SEM_UNDO;
	
	if((v=semop(id,&op,1))<0)
		printf("\nError in executing semaphore operation");

}

void sem_create(int semid,int initval)
{
	int semval;
	union semun
	{
	  int val;
	  struct semid_ds *buf;
	  unsigned short *array;
	}s;
	
	s.val=initval;
	if((semval=semctl(semid,0,SETVAL,s))<0)
		printf("\nError in executing semctl");
}
void sem_wait(int id)
{
	sem_op(id,-1);
	
}
void sem_signal(int id)
{
	sem_op(id,1);
}


int main()
{

	int shmid;
	pid_t pid;
	
	if((shmid=shmget(1002,BUFFER,IPC_CREAT|PERMS))<0)
	{
		printf("\nUnable to access the shared memory");
		exit(1);
	}
	
	if((buffer=(int*)shmat(shmid,(char*)0,0))==(int*)-1)
	{
		printf("\nShared memory allocation error");
		exit(1);
	}
	
	if((mutex=semget(IPC_PRIVATE,1,PERMS|IPC_CREAT))==-1)
	{
		printf("\nUnable to create mutex semaphore");
		exit(1);
	}
	
	if((empty=semget(IPC_PRIVATE,1,PERMS|IPC_CREAT))==-1)
	{
		printf("\nUnable to create empty semaphore");
		exit(1);
	}
	
	if((full=semget(IPC_PRIVATE,1,PERMS|IPC_CREAT))==-1)
	{
		printf("\nUnable to create full semaphore");
		exit(1);
	}
	
	sem_create(mutex,1);
	sem_create(empty,N);
	sem_create(full,0);
	
	if((pid=fork())<0)
	{
		printf("\nError in process creation");
		exit(1);
	}
	else if(pid>0)
	{
		//producer
		for(int i=0;i<N;++i)
		{
			sem_wait(empty);
			sem_wait(mutex);
			producer();
			sem_signal(mutex);
			sem_signal(full);
		}
	}
	else if(pid==0)
	{
		//consumer
		for(int i=0;i<N;++i)
		{
			sem_wait(full);
			sem_wait(mutex);
			consumer();
			sem_signal(mutex);
			sem_signal(empty);
		}
		printf("\n");
	}
	return 0;
	
}

