#include<stdio.h>
#include<stdlib.h>
typedef struct PCB{
    int PID;
    char state;
    int priority;
    int runTime;
    int workTime;
    struct PCB *next;
}*process,ptr;

PCB *ready=NULL,*p;
int num;

void PCBsort(){
    PCB *first,*second;
    int flag=0;
	if((ready==NULL)||((p->priority)>(ready->priority))){
        p->next=ready;
        ready = p;
    }else{
        first=ready;
        second=first->next;
        while(second!=NULL){
            if((p->priority)>(second->priority)){
                p->next=second;
                first->next=p;
                second=NULL;
                flag=1;
            }else{
                first=first->next;
                second=second->next;
            }
        }
        if(flag==0)first->next=p;
    }
}

void inputProcess()
{
    int i;
    printf("����%d�����̵���Ϣ��PID������ʱ�䣩\n",num);
    for(i=0;i<num;i++){
        p=(PCB*)malloc(sizeof(PCB));
        scanf("%d%d",&p->PID,&p->runTime);
        p->priority=30-p->runTime;
        p->workTime=0;
        p->state='w';
        p->next=NULL;
        PCBsort();
    }
}

int space()
{
    int k=0;
    PCB* pr=ready;
    while(pr!=NULL){
        k++;
        pr=pr->next;
    }
    return k;
}

void showInfo(ptr *pr){
    printf("\nPID\t״̬\t���ȼ�\t����ʱ��\tʣ��ʱ��\n");
    printf("��������������������������������������������������������\n");
    printf(" %d\t",pr->PID);
    printf(" %c\t",pr->state);
    printf("%d\t",pr->priority);
    printf("%d\t\t",pr->runTime);
    printf("%d\t",pr->runTime-pr->workTime);
    printf("\n");
}

void priorityRun()
{
    int len,h=0;
    char ch;
    inputProcess();
    len=space();
    while((len!=0)&&(ready!=NULL))
    {
        ch=getchar();
        h++;
        printf("\n ���д���:%d \n",h);
        p=ready;
        ready=p->next;
        p->next=NULL;
        p->state='R';
        PCB* pr;
        showInfo(p);
        pr=ready;
        while(pr!=NULL){
            showInfo(pr);
            pr=pr->next;
        }
        (p->workTime)++;
        if(p->workTime==p->runTime){
            printf("\n ����%d �ѽ�����\n",p->PID);
            free(p);
        }
        else{
            p->priority-=3;
            p->state='w';
            PCBsort();
        }
        printf("\n ����һ������ ......");
    }
    printf("\n\n �����Ѿ���� .\n");
    ch=getchar();
}

int main()
{
    printf("�������������������������������������ȼ������㷨����������������������������������\n");
    printf("���������Ŀ��");
    scanf("%d",&num);
    priorityRun();
}
