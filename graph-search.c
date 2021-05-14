#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int vertex; // ����Ǿ��ִ� Vertex�� ��ȣ�� ��Ÿ����
    struct node* next;

} Node;

#define MAXVERTEX 10

/* List of user-defined functions */
int initializeGS(Node** h);


int main(void)
{
    printf("[----- [�ֹ���] [2020039004] -----]\n");

    Node* headNode = NULL;

	char command;
	int key;

    do{
        printf("\n\n");
        printf("----------------------------------------------------------------\n");
        printf("                     Graph Searches\n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Graph     = z                                       \n");
        printf(" Insert Vertex        = v          Insert Edge           = e    \n");
        printf(" Depth First Search   = d          Breath First Search   = b    \n");
        printf(" Print Graph          = p          Quit                  = q    \n");
        printf("----------------------------------------------------------------\n");
        
        printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
            case 'z': case 'Z':
                initializeGS(&headNode);
                break;

            case 'v': case 'V':
                break;
                
            case 'e': case 'E':
                break;

            case 'd': case 'D':
                break;

            case 'b': case 'B':
                break;

            case 'p': case 'P':
                break;

            case 'q': case 'Q':
                break;

            default:
                printf("\n       >>>>>   Concentration!!   <<<<<     \n");
                break;
        }
    }while(command != 'q' && command != 'Q');
}


int initializeGS(Node** h)
{
    /*
    freeGS�� �����Ǹ� �߰��� �����Դϴ�.
    if (*h != NULL)
        freeGS(*h);
    */

    /* crete a head node */
    // headnode�� �迭�� NULL�� �ʱ�ȭ �ؾ� �Ǳ� ������ calloc���� �����Ҵ�
    (*h) = (Node*)calloc(MAXVERTEX, sizeof(Node)); 
    if ((*h) == NULL)
    {
        printf("Error! : �����Ҵ��� ����� ������� �ʾҽ��ϴ�.\n");
        return -1;
    }
 
    // headNode�� vertex���� -2�̸� ���� �߰����� ���� vertex�� ����ϸ�
    // headNode�� vertex���� -1�̸� �߰��� vertex�� ����Ѵ�.
    for (int i = 0; i < MAXVERTEX; i++)
    {
        (*h)[i].vertex = -2; // ���� �߰����� ���� vertex�� �ʱ�ȭ ���ش�.
        (*h)[i].next = NULL;
    }

    return 1;
}