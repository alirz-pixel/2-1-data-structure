#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int vertex; // ����Ǿ��ִ� Vertex�� ��ȣ�� ��Ÿ����
    struct node* next;

} Node;

#define MAXVERTEX 10

/* List of user-defined functions */
int initializeGS(Node** h);
int insertVertex(Node* h, int key);
int insertEdge(Node* h, int fir_Vertex, int sec_Vertex);
void nodeInsert(Node* headIndex, Node* insertNode);
void printG(Node* h); // headIndex


int main(void)
{
    printf("[----- [�ֹ���] [2020039004] -----]\n");

    Node* headNode = NULL;

	char command;
	int key, sec_Key;

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
                printf("Your Key(0~%d) = ", MAXVERTEX);
                scanf("%d", &key);
                insertVertex(headNode, key);
                break;
                
            case 'e': case 'E':
                printf("input Vertex 1(0~%d) : ", MAXVERTEX);
                scanf("%d", &key);
                printf("input Vertex 2(0~%d) : ", MAXVERTEX);
                scanf("%d", &sec_Key);
                insertEdge(headNode, key, sec_Key);
                break;

            case 'd': case 'D':
                break;

            case 'b': case 'B':
                break;

            case 'p': case 'P':
                printG(headNode);
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
    initialize �ϱ� ���� �Լ�
    */

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
 
    // headNode�� vertex���� 0�̸� ���� �߰����� ���� vertex�� ����ϸ�
    // headNode�� vertex���� 1�̸� �߰��� vertex�� ����Ѵ�.
    for (int i = 0; i < MAXVERTEX; i++)
    {
        (*h)[i].vertex = 0;  // ������ vertex�� �׷����� ���� �߰����� �ʾ����Ƿ� 0���� �ʱ�ȭ���ش�.
        (*h)[i].next = NULL; // ������ vertex�� ����� vertex�� ���� ������ next�� NULL�� �ʱ�ȭ���ش�.
    }

    return 1;
}

int insertVertex(Node* h, int key)
{
    /*
      �׷����� vertex�� �߰��ϱ� ���� �Լ�
    */

    if (h == NULL)
    {
        printf("\n Error! : initializeGS�� ����� ����Ǿ����� Ȯ���� �ּ���!\n");
        return -1;
    }


    if (!(0 <= key && key < MAXVERTEX))
    {
        printf("\n Error! : 0 ~ 9������ ���� �Է����ּ���.\n");
        return -1;
    }

    if (h[key].vertex == 1)
    {
        printf("\n Error! : �̹� �߰��Ǿ��ִ� Vertex�Դϴ�.\n");
        return -1;
    }

    printf("\n Vertex[%d] �� �߰��Ǿ����ϴ�.\n", key);
    h[key].vertex = 1; // vertex�� �߰������Ƿ� headNode�� vertex���� 1�� ������ش�.
    return 1;
}

int insertEdge(Node* h, int fir_Vertex, int sec_Vertex)
{
    /*
      �� vertex�� �����ϱ� �����ϱ� ���� �Լ��Դϴ�.

      1. �켱 main�Լ����� �����ϰ� ���� �� ���� vertex�� �Է¹޽��ϴ�.
      2. �� ��, �پ��� ��ó���� ���� ���� ������ ��½�ŵ�ϴ�.
         (2-1. initializeGS�� ����� ���� ���� ���)
         (2-2. 0~9������ ���� �Է����� ���� ���)
         (2-3. �ڱⰣ���� ����� �ϴ� ���)
         (2-4. �߰��Ǿ� ���� ���� vertex�� �����Ϸ��� ���)
         (2-5. ���� ������ ����� �ϴ� ���)

      3. ó������ �Է¹��� fir_Vertex�� sec_Vertex�� �����մϴ�.
      4. �� ��°�� �Է¹��� sec_Vertex�� fir_Vertex�� �����մϴ�.
    */
    

//----------------------�پ��� ��ó��----------------------

    if (h == NULL) // initializeGS�� ����� ������� ���� ���
    {
        printf("\n Error! : initializeGS�� ����� ����Ǿ����� Ȯ���� �ּ���!\n");
        return -1;
    }
    
    if (!(0 <= fir_Vertex && fir_Vertex < MAXVERTEX) || !(0 <= sec_Vertex && sec_Vertex < MAXVERTEX))
    {
        printf("\n Error! : 0 ~ %d������ ���� �Է����ּ���.\n", MAXVERTEX);
        return -1;
    }

    if (fir_Vertex == sec_Vertex) // �ڱⰣ���� ����� �ϴ°��
    {
        printf("\n Error! : �� ���α׷��� �ڱⰣ���� ������� �ʽ��ϴ�.\n");
        return -1;
    }
    
    if (h[fir_Vertex].vertex == 0 || h[sec_Vertex].vertex == 0) // vertex�� �߰��Ǿ� ���� ���� ���
    {
        if (h[fir_Vertex].vertex == 0)
            printf("\n Error! : �׷����� [vertex %d]��(��) �߰��Ǿ� ���� �ʽ��ϴ�.\n", fir_Vertex);
        else
                printf("\n Error! : �׷����� [vertex %d]��(��) �߰��Ǿ� ���� �ʽ��ϴ�.\n", sec_Vertex);
        return 1;
    }

    // ���߰����� ����� �ϴ��� Ȯ���ϴ� �ڵ�
    Node* searchNode = h[fir_Vertex].next;
    while (searchNode != NULL) // h[fir_Vertex]�� ����Ʈ ������ �ϳ��� �˻��ϵ��� �ݺ��� ����
    {
        // fir_Vertex�� sec_Vertex�� �̹� ����Ǿ� �ִ� ���
        if (searchNode->vertex == sec_Vertex)
        {
            printf("\n Error! : �� ���α׷��� ���߰����� ������� �ʽ��ϴ�.\n");
            return -1;
        }

        searchNode = searchNode->next;
    }

//--------------------------------------------------------


//--------------�� Vertex�� �����ϱ� ���� �ڵ�--------------

    // �켱 fir_Vertex���� sec_Vertex�� ����
    Node* firstNode = (Node*)malloc(sizeof(Node));
    if (firstNode == NULL) // �����Ҵ��� ����� ���� ���� ���
    {
        printf("\n Error! : �����Ҵ��� ����� ������� �ʾҽ��ϴ�.\n");
        return -1;
    }
    firstNode->vertex = sec_Vertex; // fir_Vertex���� sec_Vertex�� ����
    firstNode->next = NULL;

    // fir_Vertex���� sec_Vertex�� �����ϱ� ���� h[fir_Vertex]�� firstNode ����
    nodeInsert(&h[fir_Vertex], firstNode);


    // �� ��, sec_Vertex���� fir_Vertex�� ����
    Node* secondNode = (Node*)malloc(sizeof(Node));
    if (secondNode == NULL) // �����Ҵ��� ����� ���� ���� ���
    {
        printf("\n Error! : �����Ҵ��� ����� ������� �ʾҽ��ϴ�.\n");
        return -1;
    }
    secondNode->vertex = fir_Vertex; // sec_Vertex���� fir_Vertex�� ����
    secondNode->next = NULL;
    
    // sec_Vertex���� fir_Vertex�� �����ϱ� ���� h[sec_Vertex]�� secondNode ����
    nodeInsert(&h[sec_Vertex], secondNode);

//--------------------------------------------------------

    return 1;
}

void nodeInsert(Node* headIndex, Node* insertNode)
{
    /*
      ����忡 ����Ʈ ��带 ������� �Լ��Դϴ�.
    */
    Node* previous = headIndex;
    Node* searchNode = headIndex->next;

    while (searchNode != NULL) // searchNode�� NULL�� ������ �ݺ�
    {
        // ������������ ��带 �ֱ� ���� if���� �����
        if(insertNode->vertex < searchNode->vertex)
            break;

        previous = searchNode;
        searchNode = searchNode->next;
    }

    // insertNode�� �����ϴ� �ڵ�
    insertNode->next = searchNode;
    previous->next = insertNode;
}

void printG(Node* h)
{
    /*
      insert �Ǿ��ִ� vertex��
      �� vertex�� ����Ǿ� �ִ� vertex�� ȭ�鿡 ����ϴ� �Լ�
    */
    printf ("\n---PRINT\n");

    if (h == NULL)
    {
        printf("�μ��� �׸��� �����ϴ�.\n");
        return;
    }


    Node* p = NULL; // ����� vertex�� ã������ ����
    int cnt = 0;    // vertex�� ������ �˱� ���� ����

    for (int i = 0; i < MAXVERTEX; i++)
    {
        if (h[i].vertex == 1) // vertex�� �߰��Ǿ� �ִٸ� 
        {
            p = h[i].next;    // ����� vertex�� ã������ p�� h[i].next�� �����Ѵ�.

            printf(" ( Vertex %d :", i);
            while(p != NULL)  // [vertex i]�� ����� vertex�� ���� ������ �ݺ�
            {
                printf(" [%d] ->", p->vertex);
                p = p->next;
            }
            printf(" ) \n");

            cnt++;
        }
    }
    printf("\n  items = %d\n", cnt);
}