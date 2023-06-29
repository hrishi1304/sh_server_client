#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "linkedlist.h"

struct node* start = NULL;
char buffer[200];

char * delete(int data)
{
	
	if(search(data) || start == NULL)
		return "\nNot Found\n";
        struct node* ptr;
        struct node* temp;
        ptr = start;
        temp = start;
        //temp = temp->next;
        if(start->data == data)
        {
                start = start->next;
		return "\nData Deleted\n";
        }
        while(temp->data!=data)
        {
                ptr = temp;
                temp = temp->next;
        }
        ptr->next = temp->next;
	return "\nData Deleted\n";
}

char * modify(struct node *n1)
{
        struct node* ptr;
        ptr = start;

	if(search(n1->data))
	{
		return "\n Not Found\n";
	}
        while(ptr->data != n1->data)
        {
                ptr = ptr->next;
        }
        strcpy(ptr->name, n1->name);
	ptr->m1.sci = n1->m1.sci;
	ptr->m1.eng = n1->m1.eng;
	ptr->m1.maths = n1->m1.maths;
	return "\nData Modified\n";
}

int search(int data)
{
        struct node* ptr;
        ptr = start;
	int flag = 1;

        while(ptr != NULL)
        {
		if(ptr->data == data)
		{
                	flag = 0;
			break;
		}
		ptr = ptr->next;
        }
        return flag;
}

char * searching(int data)
{
        struct node* ptr;
        ptr = start;

        while(ptr != NULL && ptr->data != data)
        {
                if(ptr->next == NULL)
                        break;
                ptr = ptr->next;
        }
        if(ptr != NULL && ptr->data == data)
        {
		sprintf(buffer,"\nMatch found:\n\n\nID      : %d\nNAME    : %s\nSCIENCE : %d\nENGLISH : %d\nMATHS   : %d\n",ptr->data,ptr->name,ptr->m1.sci,ptr->m1.eng,ptr->m1.maths);
		return buffer;
        }
        else
        {
                return "\nNot Found\n";
	}
}

char * insert(struct node *n1)
{
	if(!search(n1->data))
		return "\n Not Found\n";
        struct node* ptr = NULL;
        if(start == NULL)
        {
		printf("Inserting\n");
                ptr->next = NULL;
                strcpy(ptr->name, n1->name);
                ptr->data = n1->data;
		ptr->m1.sci = n1->m1.sci;
		ptr->m1.eng = n1->m1.eng;
		ptr->m1.maths = n1->m1.maths;
                start = ptr;
        }
        else
        {
                ptr = start;
                while(ptr->next != NULL)
                {
                        ptr = ptr->next;
                }
                struct node* new = malloc(sizeof(struct node));
                ptr->next = new;
                new->data = n1->data;
                strcpy(new->name, n1->name);
		new->m1.sci = n1->m1.sci;
                new->m1.eng = n1->m1.eng;
                new->m1.maths = n1->m1.maths;
                new->next=NULL;
        }
	return "\nData Inserted\n";
}
char * display()
{
	
        struct node* ptr;
        ptr = start;
	if(start == NULL)
	{
		return "\nList is empty\n";
	}
	sprintf(buffer," ");
        while(ptr != NULL)
        {
		sprintf(buffer+strlen(buffer),"\nID      : %d\nNAME    : %s\nSCIENCE : %d\nENGLISH : %d\nMATHS   : %d\n",ptr->data,ptr->name,ptr->m1.sci,ptr->m1.eng,ptr->m1.maths);
                ptr = ptr->next;
        }
	return buffer;
}



