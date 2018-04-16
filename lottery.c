#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
    int ticket[20][20];
	int i,j,k,n,a,win,pr[20];
void *f1();
	void *lottery();
        void *winner();
	pthread_t thread1,thread2,thread3;
pthread_mutex_t lock;
int main()
{
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
    printf("\nEnter thePriority\n");
    pthread_mutex_init(&lock,NULL);
    pthread_create(&thread1,NULL,f1,NULL);   
    pthread_create(&thread2,NULL,lottery,NULL);
    pthread_create(&thread3,NULL,winner,NULL);
    

     pthread_join(thread1,NULL); 
     pthread_join(thread2,NULL);
     pthread_join(thread3,NULL);
k=0;
for(i=0;i<n;i++)
{
	printf("\np[%d] \t\t ticket\n",i+1);
	for(j=0;j<pr[k];j++)
	{
		printf(" %d ",ticket[i][j]);		
	}
	k++;
}
printf("\n p[%d] is winner:   %d",a+1,win);
	return 0;
}
void *f1()
{
pthread_mutex_lock(&lock);
    for(i=0;i<n;i++)
    {
        printf("\n\nP[%d]\n",i+1);
        printf("Priority:");
        scanf("%d",&pr[i]);         
    }
 pthread_mutex_unlock(&lock);
}
void *lottery()
{
pthread_mutex_lock(&lock);
   k=0;
     for(i=0;i<n;i++)
     {
     	for(j=0;j<pr[k];j++)
     	{
     		ticket[i][j]=rand();
     		
		 }
		 k++;
}
 pthread_mutex_unlock(&lock);
}
void *winner()
{
pthread_mutex_lock(&lock);
win= ticket[a=rand()%(n)][rand()%n];
pthread_mutex_unlock(&lock);
}
