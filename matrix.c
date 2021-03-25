#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    printf("[----- [�ֹ���]  [2020039004] -----]\n");

    int row, col;
    srand(time(NULL));

    printf("Input row and col : ");
    scanf("%d %d", &row, &col);
    int** matrix_a = create_matrix(row, col);
    int** matrix_b = create_matrix(row, col);
    int** matrix_a_t = create_matrix(col, row);

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;}

    do{
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch(command) {
        case 'z': case 'Z':
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;
        case 'p': case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A':
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S':
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T':
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M':
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    }while(command != 'q' && command != 'Q');

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
    /* check pre conditions */
    if (row <= 0 || col <= 0)
    {
        printf("Check the sizes of row and col!\n");
        return NULL;
    }

    int **matrix_create = (int**)malloc(row * sizeof(int*));

    /* check post conditions */
    if (matrix_create == NULL)
    {
        /* proper actions for unexpected conditions */
        printf("Insufficient memory!\n");
        return NULL;
    }

    for (int i = 0; i < row; i++)
    {
        matrix_create[i] = (int*)malloc(col * sizeof(int));

        if (matrix_create[i] == NULL)
        {
            /* proper actions for unexpected conditions */
            printf("Insufficient memory!\n");
            return NULL;
        }
    }

    return matrix_create;
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
    for(int i = 0; i < row; i++)         // 0 ~ row ��ŭ �ݺ��Ѵ�.          
    {
        for(int j = 0; j < col; j++)     // 0 ~ col ��ŭ �ݺ��Ѵ�.
            printf("%-4d", matrix[i][j]);// �ʵ� ���� 4ĭ Ȯ���ϰ�, ���� �����Ѵ�.

        printf("\n");
    }

    printf("\n");
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)   // 0 ~ row ��ŭ �ݺ��Ѵ�.
        free(matrix[i]);            // 2���� �迭�� ���� ���� �޸� ����

    free(matrix);                   // 2���� �迭�� ���� ���� �޸� ����
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{
    for(int i = 0; i < row; i++)        // 0 ~ row ��ŭ �ݺ��Ѵ�.
        for(int j = 0; j < col; j++)    // 0 ~ col ��ŭ �ݺ��Ѵ�.
            matrix[i][j] = rand() % 20; // ����� ���а��� 0 ~ 19������ ���� �������� �ο��Ѵ�.
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int** matrix_add = create_matrix(row, col);

    if (matrix_add == NULL) //����, �޸𸮰� ������ ���
    {
        /* proper actions for unexpected conditions */
        printf("�޸� �������� addition_matrix �Լ��� ������ �� �����ϴ�.\n");
        return -1;  //������ �߻������Ƿ� -1�� ��ȯ�Ѵ�.
    }

    for (int i = 0; i < row; i++)       // 0 ~ row ��ŭ �ݺ��Ѵ�.
        for (int j = 0; j < col; j++)   // 0 ~ col ��ŭ �ݺ��Ѵ�.
            matrix_add[i][j] = matrix_a[i][j] + matrix_b[i][j]; // ����� �տ��� �����ϴ� �ڵ�

    print_matrix(matrix_add, row, col); // ������ �������Ƿ� ������� ����Ʈ�Ѵ�.

    free_matrix(matrix_add, row, col);  // ������ ����Ǿ����Ƿ� �Ҵ��ߴ� �޸𸮸� �����Ѵ�.

    return 0;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{
    int** matrix_sub = create_matrix(row, col); // A - B ���� ����� ���� ���� ����

    if (matrix_sub == NULL) //����, �޸𸮰� ������ ���
    {
        /* proper actions for unexpected conditions */
        printf("�޸� �������� subtraction_matrix �Լ��� ������ �� �����ϴ�.\n");
        return -1;  //������ �߻������Ƿ� -1�� ��ȯ�Ѵ�.
    }

    for (int i = 0; i < row; i++)       // 0 ~ row ��ŭ �ݺ��Ѵ�.
        for (int j = 0; j < col; j++)   // 0 ~ col ��ŭ �ݺ��Ѵ�.
            matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j]; // ����� ���� ���� �����ϴ� �ڵ�

    print_matrix(matrix_sub, row, col); // ������ �������Ƿ� ������� ����Ʈ�Ѵ�.

    free_matrix(matrix_sub, row, col);  // ������ ����Ǿ����Ƿ� �Ҵ��ߴ� �޸𸮸� �����Ѵ�.
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{

}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{

}

