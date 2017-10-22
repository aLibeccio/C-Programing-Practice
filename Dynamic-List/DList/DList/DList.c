#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student
{
    char stuName[20];
    int stuID;
    struct _Student *nextNode;

}Student;

Student *beginNode = NULL;
Student *endNode = NULL;
Student *tempNode = NULL;
int nodeQuantity;

int errInput = 0;       //for fun

//--------------------��������--------------------
void displayMenu();
int menuSelect();
Student* createNewNode();
void addNode();
void nodeErgodic();
int deleteNode();
void deleteinform(int flag);
void displayBeginAndEnd();
//--------------------��������--------------------

int main()
{
    printf("Hello World!"); //for test
    int flag;
    displayMenu();

    while (1)
    {
        flag = menuSelect();
        if (flag == 1)
            break;
    }
    printf("�˳��ɹ����ټ���\n");


    system("pause");
    return 0;
}

void displayMenu()
{
    printf("===================���˵�===================\n");
    printf("�����빦�ܼ���Ӧ�����ֽ��в�����\n");
    printf("1����ʾ���������������    2����������    3��ɾ������    4���˳�\n");

}

int menuSelect()
{
    int select;
    int flag;
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        nodeErgodic();
        displayBeginAndEnd();
        displayMenu();
        flag = 0;//���˳�
        break;
    case 2:
        tempNode = createNewNode();
        addNode();
        displayBeginAndEnd();
        displayMenu();
        flag = 0;//���˳�
        break;
    case 3:
        deleteinform(deleteNode());
        displayBeginAndEnd();
        displayMenu();
        flag = 0;//���˳�
        break;
    case 4:
        flag = 1;//�˳�
        break;
    default:
        displayMenu();
        displayBeginAndEnd();
        flag = 0;//���˳�
        break;
    }
    return flag;
}

Student* createNewNode()
{
    int ID = 0;
    char name[20] = { 0 };
    Student *tempPointer = (Student *)malloc(sizeof(Student));
    printf("�������µ�ID\n");
    scanf("%d", &ID);
    tempPointer->stuID = ID;
    printf("�������µ�Name(����enter�������м䲻Ҫ����ո�)\n");
    scanf("%s", name);
    strcpy_s(tempPointer->stuName, 20, name);
    return tempPointer;
}

void addNode()
{
    int position;
    int i;

    Student *tempPointerA = beginNode;
    Student *tempPointerB = beginNode;
    printf("������Ҫ��ӵ�λ�ã���Ȱ�㲻Ҫ��ͼ����һ����Ч�����֣���\n");
    scanf("%d", &position);
    if (beginNode == NULL)       //�жϴ�ʱ���������޽ڵ�
    {
        beginNode = tempNode;
        endNode = tempNode;
        nodeQuantity++;
        tempNode->nextNode = NULL;
    }
    else
    {
        if (position >= nodeQuantity + 1)
        {
            printf("��������ִ���������,������β�������\n");
            position = -1;

        }
        else if (position < -1)
        {
            position = -1;
            printf("����������Ч��������β�������\n");
            switch (errInput)
            {
            case 0:
                printf("�Ҷ�˵�ˣ���Ҫ��ͼ����һ����Ч������!\n");
                break;
            case 1:
                printf("������\n");
                break;
            case 2:
                printf("������������ģ�\n");
                break;
            case 3:
                printf("���Ҹ����������ʩ�귨��������Ĺ�ͷ��\n");
                break;
            case 4:
                printf("�ҿ�������ڵ������ֻ���\n");
                break;
            case 5:
                printf("����������������������������\n");
                break;
            case 6:
                printf("��...��������в�����������\n");
                break;
            case 7:
                printf("��ο���...\n");
                break;
            case 8:
                printf("���Ǿ��������ᴥ��ʲô���ؾ��黹��������\n");
                break;
            case 9:
                printf("������ʲô����Ȼ��������...\n");
                break;
            case 10:
                printf("���ֲ���AI����Ц��...\n");
                break;
            case 11:
                printf("����а�...\n");
                break;
            case 12:
                printf("�����˾ͺã�\n");
                break;
            default:
                printf("���˶��ˣ���ϲ�㴥����default·��\n");
                break;
            }
            errInput++;
            if (errInput == 13)
                errInput = 0;
        }
        switch (position)
        {
        case -1:
            //����β���
            tempNode->nextNode = NULL;
            endNode->nextNode = tempNode;
            endNode = tempNode;
            nodeQuantity += 1;
            break;
        case 0:
            //����ͷ���
            tempNode->nextNode = beginNode;
            beginNode = tempNode;
            nodeQuantity += 1;
            break;
        default:
            //�ӵ�position���ڵ�������
            for (i = 1; i < position; i++)
                tempPointerA = tempPointerA->nextNode;
            tempPointerB = tempPointerA->nextNode;
            tempNode->nextNode = tempPointerB;
            tempPointerA->nextNode = tempNode;
            break;
        }
        printf("��ӳɹ����������˵�\n");
    }
}

void nodeErgodic()
{
    Student* ergodicStartPointer = beginNode;
    if (ergodicStartPointer == NULL)
        printf("������û������,�������˵�\n");
    else
    {
        while (ergodicStartPointer != NULL)
        {
            printf("%d    %s    \n", ergodicStartPointer->stuID, ergodicStartPointer->stuName);
            ergodicStartPointer = ergodicStartPointer->nextNode;
        }
        printf("������������ݣ��������˵�\n");
    }
}

int deleteNode()
{
    int position;
    int i;
    Student *tempPointerA = beginNode;
    Student *tempPointerB = beginNode;
    if (nodeQuantity == 0)
    {
        printf("������û�нڵ����ɾ����ɾ��ʧ�ܷ������˵�\n");
        return 0;
    }
    else
    {
        printf("����ɾ���ڼ����ڵ㣨����ֵֹ������ǲ�����Ч�ģ�����\n");
        scanf("%d", &position);
        if (position > nodeQuantity)
        {
            printf("û����ô��ڵ㣡\n");
            return 0;
        }
        else if (position <= 0)
        {
            printf("��ξ���������ᣡ\n");
            return 0;
        }
        else if (position == nodeQuantity && nodeQuantity == 1)
        {                        //�ⲽ������ǰ������������Ϊ�����forѭ����position����ȡ1
            printf("��ȻҪɾ��Ψһһ���ڵ�...\n");
            free(beginNode);
            beginNode = NULL;
            endNode = NULL;
            return 1;
        }
        else
        {
            for (i = 1; i < position; i++)
            {
                if (i == position - 1)   //��Ҫɾ���ڵ��ǰһ���ڵ�
                    tempPointerA = tempPointerB;
                tempPointerB = tempPointerB->nextNode;
            }
            if (position == nodeQuantity)
            {
                //ɾ�����һ���ڵ�

                tempPointerA->nextNode = NULL;
                endNode = tempPointerA;
                free(tempPointerB);
                return 1;

            }
            else
            {
                tempPointerA->nextNode = tempPointerB->nextNode;  //��Ҫɾ���Ľڵ��ָ��ָ��Ҫɾ���ڵ�ĺ�һ���ڵ�
                free(tempPointerB);
                return 1;
            }
        }
    }
}

void deleteinform(int flag)
{
    if (flag == 1)
        printf("ɾ���ɹ�\n");
    else
        printf("ɾ��ʧ��\n");
}

void displayBeginAndEnd()
{
    printf("��ʱ������ͷ��ַ�ǣ�%p\n", beginNode);
    printf("��ʱ������β��ַ�ǣ�%p\n", endNode);
}
