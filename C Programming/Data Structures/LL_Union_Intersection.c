#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
typedef struct node NODE;

NODE* insert(NODE*head,int item){
    NODE*new=(NODE*)malloc(sizeof(NODE));
    new->data=item;
    new->link=NULL;
    if(head==NULL)
          head=new;
    else{
        NODE*temp=head;
        while(temp->link!=NULL)
             temp=temp->link;
        temp->link=new;
    }
    return head;
}
NODE* Union(NODE*temp1,NODE*temp2){
    NODE *head3=NULL;
    while(temp1!=NULL){
        head3=insert(head3,temp1->data);
        temp1=temp1->link;
    }
    while(temp2!=NULL){
        int f=1;
        temp1=head3;// temp is at the first node
        while(temp1!=NULL){
            if(temp1->data==temp2->data)            
                f=0;
            temp1=temp1->link;//check all the elements of temp1 with the 1st element of temp2
        }
        if(f==1)
           head3=insert(head3,temp2->data);
        temp2=temp2->link;
    }
    return head3;
}
NODE* inter(NODE*temp1,NODE*temp2){   
    NODE *head4=NULL;
    while(temp2!=NULL){
        int f=0;
        NODE*temp=temp1;
        while(temp!=NULL){
            if(temp->data==temp2->data)            
                f=1;
            temp=temp->link;//checking all elements matching temp2 in the first list
        }
        if(f==1)
           head4=insert(head4,temp2->data);
        temp2=temp2->link;
    }
    return head4;
    
}
void disp(NODE*temp){
    if(temp==NULL){
        printf("Empty\n");return;
    }
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->link;
    }
}
void main(){
    NODE *head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL;
    int i,n1,n2,item;
    printf("Enter limit of list 1\n");
    scanf("%d",&n1);
  
    printf("\nEnter items of list 1\n");
    for(i=0;i<n1;i++){
        printf("enter element %d:  ",i+1);
        scanf("%d",&item);
        head1=insert(head1,item);
    }
      printf("Enter limit of list 2\n");
    scanf("%d",&n2);
     printf("\nEnter items of list 2\n");
    for(i=0;i<n2;i++){
        printf("enter element %d:  ",i+1);
        scanf("%d",&item);
        head2=insert(head2,item);
    }
    printf("\nLIST 1\n");
    disp(head1);
    printf("\nLIST 2\n");
    disp(head2);
    printf("\nintersection\n");
    head3=inter(head1,head2);
    disp(head3);
    printf("\nunion\n");
    head4=Union(head1,head2);
    disp(head4);
}