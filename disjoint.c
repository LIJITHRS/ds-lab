
#include <stdio.h>
struct DisjSet {
 int parent[10];
 int rank[10];
 int n;
}dis;

	 void makeSet()
	 {
	 for (int i = 0; i < dis.n; i++) { dis.parent[i] = i;
	 dis.rank[i]=0;
 		}
 		}
 	void displaySet()
 	{ 
 	printf("\nParent Array\n"); 
 	for (int i = 0; i < dis.n; i++) 
 	{ 
 	printf("%d ",dis.parent[i]); 
 	} 
 	printf("\nRank Array\n"); 
 	for (int i = 0; i < dis.n; i++)
 
	{
 	printf("%d ",dis.rank[i]);
 	}
	 printf("\n");
	 }
	 int find(int x)
	 {
	 if (dis.parent[x] != x) {
	 dis.parent[x] = find(dis.parent[x]); }
	 return dis.parent[x];
	 }
	 void Union(int x, int y)
	 {
	 int xset = find(x);
	 int yset = find(y);
	 if (xset == yset)
	 return;
	 if (dis.rank[xset] < dis.rank[yset]) { dis.parent[xset] = yset;
	 dis.rank[xset]=-1;
	 }
	 else if (dis.rank[xset] > dis.rank[yset]) { dis.parent[yset] = xset;
	 dis.rank[yset]=-1;
	 }
	 else {
	 dis.parent[yset] = xset;
	 dis.rank[xset] = dis.rank[xset] + 1; dis.rank[yset]=-1;
	 }
	 }

int main()
{ 
	int n,x,y;
 	printf("How many elements ?");
 	scanf("%d",&dis.n);
 	makeSet();
 	int ch,wish;
		do
		 {
		 printf("\n___MENU_\n");
		 printf("1. Union \n2.Find\n3.Display\n"); printf("enter choice\n");
		 scanf("%d",&ch);
		 switch(ch)
		 {
		 case 1: printf("Enter elements to perform union"); scanf("%d %d",&x,&y);
		 Union(x, y);
		 break;
		 
		 case 2: printf("Enter elements to check if connected components"); scanf("%d %d",&x,&y);
		 if (find(x) == find(y))
		 printf("Connected components\n") ;
		 
		 else
		 printf("Not onnected components \n") ;
		 break;
		 
		 case 3: displaySet();
		 break;
		 }
		 printf("\nDo you wish to continue ?(1/0)\n");
		 scanf("%d",&wish);
		 }while(wish==1);
		 return 0;
		}
Conversation opened. 1 read message.

Skip to content
Using Gmail with screen readers
Enable desktop notifications for Gmail.
   OK  No, thanks
7 of 411
Disjoint set_Bitstring_DS_Labs
Inbox

TESSA DAVIS <tessadavist@gmail.com>
Attachments
Fri, 17 Nov, 14:19 (3 days ago)
to me


 2 attachments
  • Scanned by Gmail
#include<stdio.h>
#include<stdlib.h>

struct node{
   struct node *rep;
   struct node *next;
   int data;
}*heads[50],*tails[50];

static int countRoot=0;

void makeSet(int x)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->rep=new;
	new->next=NULL;
	new->data=x;
	heads[countRoot]=new;
	tails[countRoot++]=new;
}

struct node* find(int a){
	int i;
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	for(i=0;i<countRoot;i++){
		tmp=heads[i];
		while(tmp!=NULL){
		if(tmp->data==a)
		return tmp->rep;
		tmp=tmp->next;
		}
 	}
	return NULL;
}

void unionSets(int a,int b){
	int i,pos,flag=0,j;
	struct node *tail2=(struct node *)malloc(sizeof(struct node));
	struct node *rep1=find(a);
	struct node *rep2=find(b);
	if(rep1==NULL||rep2==NULL){
		printf("\nElement not present in the DS\n");
		return;
	}
	if(rep1!=rep2){
		for(j=0;j<countRoot;j++){
			if(heads[j]==rep2){
				pos=j;
				flag=1;
				countRoot-=1;
				tail2=tails[j];
				for(i=pos;i<countRoot;i++){
					heads[i]=heads[i+1];
					tails[i]=tails[i+1];
				}
			}
			if(flag==1)
				break;
		}
		for(j=0;j<countRoot;j++){
			if(heads[j]==rep1){
				tails[j]->next=rep2;
				tails[j]=tail2;
				break;
			}
		}
		while(rep2!=NULL){
		rep2->rep=rep1;
		rep2=rep2->next;
		}
	}
}

int search(int x){
	int i;
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	for(i=0;i<countRoot;i++){
		tmp=heads[i];
		if(heads[i]->data==x)
			return 1;	
		while(tmp!=NULL){
			if(tmp->data==x)
				return 1;	
			tmp=tmp->next;
		}
	}
	return 0;
}


void main(){
int choice,x,i,j,y,flag=0;
	
	do{
		
		printf("\n.......MENU.......\n\n1.Make Set\n2.Display set representatives\n3.Union\n4.Find Set\n5.Exit\n");
	
		printf("Enter your choice :  ");
		scanf("%d",&choice);
		
		switch(choice){
		case 1:	
			printf("\nEnter new element : ");
			scanf("%d",&x);
			if(search(x)==1)
				printf("\nElement already present in the disjoint set DS\n");
			else
				makeSet(x);
			break;
		case 2:
			printf("\n");
			for(i=0;i<countRoot;i++)
				printf("%d ",heads[i]->data);
			printf("\n");
			break;
		case 3:
			printf("\nEnter first element : ");
			scanf("%d",&x);
			printf("\nEnter second element : ");
			scanf("%d",&y);
			unionSets(x,y);
			break;
		case 4:
			printf("\nEnter the element");
			scanf("%d",&x);
			struct node *rep=(struct node *)malloc(sizeof(struct node));
			rep=find(x);
			if(rep==NULL)
			printf("\nElement not present in the DS\n");
			else
			printf("\nThe representative of %d is %d\n",x,rep->data);
			break;
		case 5:
			exit(0);
		default: 
			printf("\nWrong choice\n");
			break;
		}
	}
	while(1);

}
disjoint.c
Displaying disjoint.c.
