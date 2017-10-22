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

//--------------------函数声明--------------------
void displayMenu();
int menuSelect();
Student* createNewNode();
void addNode();
void nodeErgodic();
int deleteNode();
void deleteinform(int flag);
void displayBeginAndEnd();
//--------------------函数声明--------------------

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
    printf("退出成功，再贱！\n");


    system("pause");
    return 0;
}

void displayMenu()
{
    printf("===================主菜单===================\n");
    printf("请输入功能键对应的数字进行操作：\n");
    printf("1、显示已输入的所有数据    2、建立数据    3、删除数据    4、退出\n");

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
        flag = 0;//不退出
        break;
    case 2:
        tempNode = createNewNode();
        addNode();
        displayBeginAndEnd();
        displayMenu();
        flag = 0;//不退出
        break;
    case 3:
        deleteinform(deleteNode());
        displayBeginAndEnd();
        displayMenu();
        flag = 0;//不退出
        break;
    case 4:
        flag = 1;//退出
        break;
    default:
        displayMenu();
        displayBeginAndEnd();
        flag = 0;//不退出
        break;
    }
    return flag;
}

Student* createNewNode()
{
    int ID = 0;
    char name[20] = { 0 };
    Student *tempPointer = (Student *)malloc(sizeof(Student));
    printf("请输入新的ID\n");
    scanf("%d", &ID);
    tempPointer->stuID = ID;
    printf("请输入新的Name(请以enter结束，中间不要插入空格)\n");
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
    printf("请输入要添加的位置（我劝你不要试图输入一个无效的数字）：\n");
    scanf("%d", &position);
    if (beginNode == NULL)       //判断此时链表中有无节点
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
            printf("输入的数字大于链表长度,在链表尾添加数据\n");
            position = -1;

        }
        else if (position < -1)
        {
            position = -1;
            printf("输入数字无效，在链表尾添加数据\n");
            switch (errInput)
            {
            case 0:
                printf("我都说了，不要试图输入一个无效的数字!\n");
                break;
            case 1:
                printf("又来？\n");
                break;
            case 2:
                printf("又来？你认真的？\n");
                break;
            case 3:
                printf("等我给这个狼牙棒施完法就来打爆你的狗头！\n");
                break;
            case 4:
                printf("我看你就是在刁难我胖虎！\n");
                break;
            case 5:
                printf("？？？？？？？？？？？？？？\n");
                break;
            case 6:
                printf("哇...你这个人有病还是怎样？\n");
                break;
            case 7:
                printf("你何苦嘛...\n");
                break;
            case 8:
                printf("你是觉得这样会触发什么隐藏剧情还是怎样？\n");
                break;
            case 9:
                printf("不会有什么超自然现象发生的...\n");
                break;
            case 10:
                printf("这又不是AI（冷笑）...\n");
                break;
            case 11:
                printf("你很闲吧...\n");
                break;
            case 12:
                printf("您高兴就好！\n");
                break;
            default:
                printf("叮咚叮咚！恭喜你触发了default路径\n");
                break;
            }
            errInput++;
            if (errInput == 13)
                errInput = 0;
        }
        switch (position)
        {
        case -1:
            //链表尾添加
            tempNode->nextNode = NULL;
            endNode->nextNode = tempNode;
            endNode = tempNode;
            nodeQuantity += 1;
            break;
        case 0:
            //链表头添加
            tempNode->nextNode = beginNode;
            beginNode = tempNode;
            nodeQuantity += 1;
            break;
        default:
            //从第position个节点后面添加
            for (i = 1; i < position; i++)
                tempPointerA = tempPointerA->nextNode;
            tempPointerB = tempPointerA->nextNode;
            tempNode->nextNode = tempPointerB;
            tempPointerA->nextNode = tempNode;
            break;
        }
        printf("添加成功，返回主菜单\n");
    }
}

void nodeErgodic()
{
    Student* ergodicStartPointer = beginNode;
    if (ergodicStartPointer == NULL)
        printf("链表中没有数据,返回主菜单\n");
    else
    {
        while (ergodicStartPointer != NULL)
        {
            printf("%d    %s    \n", ergodicStartPointer->stuID, ergodicStartPointer->stuName);
            ergodicStartPointer = ergodicStartPointer->nextNode;
        }
        printf("已输出所有数据，返回主菜单\n");
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
        printf("链表中没有节点可以删除，删除失败返回主菜单\n");
        return 0;
    }
    else
    {
        printf("你想删除第几个节点（奇奇怪怪的数字是不会生效的！）：\n");
        scanf("%d", &position);
        if (position > nodeQuantity)
        {
            printf("没有这么多节点！\n");
            return 0;
        }
        else if (position <= 0)
        {
            printf("这次绝不给你机会！\n");
            return 0;
        }
        else if (position == nodeQuantity && nodeQuantity == 1)
        {                        //这步必须提前独立出来，因为后面的for循环中position不能取1
            printf("居然要删除唯一一个节点...\n");
            free(beginNode);
            beginNode = NULL;
            endNode = NULL;
            return 1;
        }
        else
        {
            for (i = 1; i < position; i++)
            {
                if (i == position - 1)   //到要删除节点的前一个节点
                    tempPointerA = tempPointerB;
                tempPointerB = tempPointerB->nextNode;
            }
            if (position == nodeQuantity)
            {
                //删除最后一个节点

                tempPointerA->nextNode = NULL;
                endNode = tempPointerA;
                free(tempPointerB);
                return 1;

            }
            else
            {
                tempPointerA->nextNode = tempPointerB->nextNode;  //把要删除的节点的指针指向要删除节点的后一个节点
                free(tempPointerB);
                return 1;
            }
        }
    }
}

void deleteinform(int flag)
{
    if (flag == 1)
        printf("删除成功\n");
    else
        printf("删除失败\n");
}

void displayBeginAndEnd()
{
    printf("此时的链表头地址是：%p\n", beginNode);
    printf("此时的链表尾地址是：%p\n", endNode);
}
