/*#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef enum {
    OPERATION_INSERT,
    OPERATION_MODIFY,
    OPERATION_DELETE,
    OPERATION_SEARCH,
    OPERATION_DISPLAY,
    OPERATION_CLOSE
} Operation;

struct mark
{
    	int sci;
    	int eng;
    	int maths;
};

struct node
{
	Operation choice;
	int sh_stat;
    	int data;
    	char name[10];
    	struct mark m1;
    	struct node* next;
};


//extern struct node* start;

char * delete(int data);
char * modify(struct node * n1);
int search(int data);
char * searching(int data);
char * insert(struct node *n1);
char * display();

#endif*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @file linkedlist.h
 * @brief Header file containing declarations for a linked list implementation.
 */

/**
 * @brief Enumeration defining different operations for the linked list.
 */
typedef enum {
    OPERATION_INSERT,     /**< Insert operation */
    OPERATION_MODIFY,     /**< Modify operation */
    OPERATION_DELETE,     /**< Delete operation */
    OPERATION_SEARCH,     /**< Search operation */
    OPERATION_DISPLAY,    /**< Display operation */
    OPERATION_CLOSE       /**< Close operation */
} Operation;

/**
 * @struct mark
 * @brief Structure representing marks in different subjects.
 */
struct mark
{
        int sci;            /**< Marks in Science */
        int eng;            /**< Marks in English */
        int maths;          /**< Marks in Maths */
};

/**
 * @struct node
 * @brief Structure representing a node in the linked list.
 */
struct node
{
        Operation choice;   /**< Operation choice for the node */
        int sh_stat;        /**< Shared memory status */
        int data;           /**< Data of the node */
        char name[10];      /**< Name associated with the data */
        struct mark m1;     /**< Marks associated with the data */
        struct node* next;  /**< Pointer to the next node */
};

/**
 * @brief Deletes a node with the specified data from the linked list.
 *
 * @param data The data to be deleted.
 * @return char* Returns a message indicating the status of the deletion operation.
 */
char* delete(int data);

/**
 * @brief Modifies the data of a node in the linked list.
 *
 * @param n1 Pointer to the node containing the modified data.
 * @return char* Returns a message indicating the status of the modification operation.
 */
char* modify(struct node* n1);

/**
 * @brief Searches for a node with the specified data in the linked list.
 *
 * @param data The data to search for.
 * @return int Returns 0 if the node is found, 1 if not found.
 */
int search(int data);

/**
 * @brief Searches for a node with the specified data and returns its details.
 *
 * @param data The data to search for.
 * @return char* Returns the details of the node if found, or a "Not Found" message if not found.
 */
char* searching(int data);

/**
 * @brief Inserts a new node with the specified data into the linked list.
 *
 * @param n1 Pointer to the node containing the data to be inserted.
 * @return char* Returns a message indicating the status of the insertion operation.
 */
char* insert(struct node* n1);

/**
 * @brief Displays the details of all nodes in the linked list.
 *
 * @return char* Returns a message indicating the status of the display operation.
 */
char* display();

#endif


