#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <linkedlist.h>
#include <string.h>
/**
 * @brief Demonstrates the usage of ftok to generate a key for creating a shared memory segment.
 */

int main()
{
	char * buffer;
	key_t key1, key2;

	//Generating keys for shared memory
        key1 = ftok(".", 'A');
        key2 = ftok(".", 'B');
    	if (key1 == -1) 
	{
        	perror("Failed to generate key");
        	exit(1);
   	}

	if (key2 == -1) 
	{
        	perror("Failed to generate key");
        	exit(1);
   	}

    	// Create a shared memory segment
    	int shmid1, shmid2;
	shmid1 = shmget(key1, sizeof(struct node), IPC_CREAT | 0666);
	shmid2 = shmget(key2, 200, IPC_CREAT | 0666);
    	if (shmid1 == -1) 
	{
        	perror("Failed to create shared memory segment");
        	exit(1);
    	}

	if (shmid2 == -1) 
	{
        	perror("Failed to create shared memory segment");
        	exit(1);
    	}

    	// Attach to the shared memory segment
    	struct node * n1;
	
	n1 = (struct node*)shmat(shmid1, NULL, 0);
	buffer = (char *)shmat(shmid2, NULL, 0);
	
   	if (n1 == (struct node *)-1) 
	{
        	perror("Failed to attach to shared memory segment");
        	exit(1);
    	}

	if (buffer == (char *)-1) 
	{
        	perror("Failed to attach to shared memory segment");
        	exit(1);
    	}

	//Infinite loop
	while(1)
	{
		printf("\nServer Waiting\n");
		n1->sh_stat = 1;
		while(n1->sh_stat != 0)
		{
			sleep(1);
		}
		
		//switch-case for entered choice
		switch(n1->choice)
		{
			//INSERT = 0
			case OPERATION_INSERT:
				strcpy(buffer,insert(n1));
				printf("%s",buffer);
				break;

			//MODIFY = 1
			case OPERATION_MODIFY:
				strcpy(buffer,modify(n1));
				break;
			
			//DELETE = 2
			case OPERATION_DELETE:
				printf("\nDeleting node %d\n",n1->data);
				strcpy(buffer,delete(n1->data));
				printf("%s",buffer);
				break;

			//SEARCH = 3
			case OPERATION_SEARCH:
				strcpy(buffer,searching(n1->data));
				break;

			//DISPAY = 4
			case OPERATION_DISPLAY:
				strcpy(buffer,display());
				break;

			//CLOSE = 5
			case OPERATION_CLOSE:
				n1->sh_stat = -1;
				break;

			default:
				printf("\nInvalid choice\n");
				break;
		}
		
		//SYNCHONIZATION
		if(n1->sh_stat == -1)
		{
			break;
		}	
		n1->sh_stat = 1;
	}
	//Detaching the shared memory
	shmdt(n1);
	shmdt(buffer);

	//removing the shared memory
	shmctl(shmid1, IPC_RMID, NULL);
	shmctl(shmid2, IPC_RMID, NULL);

	return 0;
}
