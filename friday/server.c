#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "linkedlist.h"

/**
 * @brief Demonstrates the usage of ftok to generate a key for creating a shared memory segment.
 */

int main()
{
	//variable declaration
	int shmid;
	key_t sh_key = ftok(".", 'A');// generating key for shared memory and assigning it to sh_key
	struct node *n1;

	
	//
	if((shmid = shmget(sh_key, sizeof(n1), IPC_CREAT | 0666)) == -1)
	{
		printf("\nShared memory not created\n");
		exit(1);
	}

	//
	n1 = (struct node *)shmat(shmid, NULL, 0);
	if(n1 == (struct node *) - 1)
	{
		printf("\nAttachment Issue\n");
		exit(1);
	}

	//
	while(1)
	{
		while(n1->sh_stat != 0)
		{
			sleep(1);
		}

		switch (n1->choice) 
		{
    			case OPERATION_INSERT:
        			// Perform insert operation
				insert(n1);
        		break;
    			case OPERATION_MODIFY:
        			// Perform modify operation
				modify(n1);
				printf("\nData Updated\n");
        		break;
    			case OPERATION_DELETE:
        			// Perform delete operation
				delete(n1->data);
				printf("\nData deleted\n");
        		break;
    			case OPERATION_SEARCH:
        			// Perform search operation
				searching(n1->data);
        		break;
    			case OPERATION_DISPLAY:
        			// Perform display operation
				display();
        		break;
    			case OPERATION_CLOSE:
        			// Perform close operation
				shmdt(n1);
				shmctl(shmid, IPC_RMID, NULL);
				exit(0);
        		break;
    			default:
        			// Handle unknown operation
				printf("\nInvalid choice\n");
        		break;
		}
		n1->sh_stat = 1;
	}
	return 0;
}





