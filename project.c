#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct book_node{
	int ISBN;
	char BookName[50];
	char BorrowerName[50];
	char field[20];
	date dueDate;
	int borrowed;
	struct book_node* next;
	struct book_node* prev;
}book;

typedef struct datenode{
	int year;
	int month;
	int day;
}date;

book* head=NULL;
book* tail=NULL;

//1. functions prototypes

void menu();
void displaybooks();
struct book_node* create_node(int,char*,char*,char*,date,int);
void insert_node(struct book_node*);
void swap(struct book_node*,struct book_node*);
void printinfo(struct book_node*);
//Search
struct book_node*searchby_Field(struct book_node*,int);
struct book_node*searchby_ISBN(struct book_node*,int);
struct book_node*searchby_BorrowerName(struct book_node*, char*);
struct book_node*searchby_DueDate(struct book_node*,date);
//Update
void updatebook(struct book_node*,int );

int searchby_ISBN(ISBN);
int count_digits (int n,int i);
void bubblesort();
int mycompare(char* str1,char* str2);
char* lower(char* str);

//2. main function

int main(){
	book* newbook;
	FILE*in,*out;
	char ans,ans2,c;
	int num,flag=0,i,ISBN,borrowed;
	char BookName[50],BorrowerName[50], field[20];
	date dueDate;
	
	in=fopen("myfile.txt","r");
	if(in==NULL){
		printf("No file existing.Please enter the three books:\n");
	for(i=0;i<3;i++){
		printf("\nPlease enter the book %d:\n",i+1);
		printf("\nyou want to add a book. enter the new book's ISBN: ");
				while(!scanf("%d",&ISBN)){
					fflush(stdin);
					printf("Invalid input Please enter another one: ");
				}
				fflush(stdin);
				newbook=searchby_ISBN(ISBN);
				while(newbook){
					printf("\nThe book already exists. Please enter another one: "); 
					scanf("%d",&ISBN);
					newbook=searchby_ISBN(ISBN);
					fflush(stdin);
				}
				printf("Please enter the name of the book: ");
				scanf("%s",name);
				fflush(stdin);
				printf("Please enter the field: ");
				scanf("%s",field);
				fflush(stdin);
				printf("Please enter the date: ");
				while(!scanf("%s",&date)){
					fflush(stdin);
					printf("Invalid input Please enter another one: ");
				}
				fflush(stdin);
				printf("Please enter the mileage: ");
				while(!scanf("%lf",&mileage)){
					fflush(stdin);
					printf("Invalid input Please enter another one: ");
				}
				fflush(stdin);
				printf("Please enter the cost: ");
				while(!scanf("%lf",&cost)){
					fflush(stdin);
					printf("Invalid input Please enter another one: ");
				}
				fflush(stdin);
				newbook=create_node(ID,ISBN,model,year,mileage,cost);
				insert_node(newbook);
		}
	}
	else{
		while(fgets(line, 100, in)!=NULL ){
			sscanf(line,"%d %s %s %d %lf %c%lf", &ID, ISBN, model, &year, &mileage,&c, &cost);
			insert_node(create_node(ID, ISBN, model, year, mileage, cost));
			
		}
	}

	
			
	
	
	do{
	menu();
	scanf("%c",&ans);
	while(getchar()!='\n'){
		fflush(stdin);
		printf("\nInvalid input Please try again: ");
		scanf("%c",&ans);
		
	}
		 
	fflush(stdin);
	
	switch(ans){
		case'1':displaybooks();
				break;
		case'2':printf("\nyou want to add a book. enter the new book's ID: ");
				while(!scanf("%d",&ID)){
					fflush(stdin);
					printf("Invalid input Please enter another one: ");
				}
				fflush(stdin);
				newbook=searchbyID(ID);
				while(newbook){
					printf("\nthis ID is Invalid or already exists Please enter another one: "); 
					scanf("%d",&ID);
					newbook=searchbyID(ID);
					fflush(stdin);
				}
				printf("Please enter the ISBN of the book: ");
				scanf("%s",ISBN);
				fflush(stdin);
				printf("Please enter the model: ");
				scanf("%s",model);
				fflush(stdin);
				printf("Please enter the year: ");
				while(!scanf("%d",&year)){
					fflush(stdin);
					printf("Invalid input Please enter another one: ");
				}
				fflush(stdin);
				printf("Please enter the mileage: ");
				while(!scanf("%lf",&mileage)){
					fflush(stdin);
					printf("Invalid input Please enter another one: ");
				}
				fflush(stdin);
				printf("Please enter the cost: ");
				while(!scanf("%lf",&cost)){
					fflush(stdin);
					printf("Invalid input Please enter another one: ");
				}
				fflush(stdin);
				newbook=create_node(ID,ISBN,model,year,mileage,cost);
				insert_node(newbook);
				printf("\nyour book has been successfully added\n");
				break;
				
		case'3':printf("\n\n------------------\n"
					   "1.update cost  \n"
    				   "2.update mileage     \n");
	 			printf("your choice: ");
 				scanf("%c",&ans2);
 				fflush(stdin);
 				while(ans2!='1' && ans2!='2'){
 					printf("\nInvalid input Please enter a new number: ");
 					scanf("%c",&ans2);
 					fflush(stdin);
 				}
				printf("\nPlease enter the ID of the book you want to update: ");
				scanf("%d",&ID);
				fflush(stdin);
				newbook=searchbyID(ID);
				while(!newbook){
					printinfo(newbook);
					printf("\nPlease enter another ID: ");
					scanf("%d",&ID);
					fflush(stdin);
					newbook=searchbyID(ID);
				}
				printinfo(newbook);
				updatebook(newbook,ans2);
				printf("\nyour book has been successfully updated\n");
				break;
		
		case'4':printf("\nPlease enter the ID of the book you want to delete: ");
				scanf("%d",&ID);
				fflush(stdin);
				newbook=searchbyID(ID);
				while(!newbook){
					printinfo(newbook);
					printf("\nPlease enter another ID: ");
					scanf("%d",&ID);
					fflush(stdin);
					newbook=searchbyID(ID);
				}
				deletebook(newbook);
				printf("\nyour book has been succesfully removed\n");
				break;
				
		case'5':printf( "\n\n-------------------------------------------\n"
					    "5.1 Search by ISBN "
						"5.2 Search by field "
						"5.3 Search for Borrowed books by dueDate"
						"5.4 Search for Borrowed Books by a BorrowerName\n");
  				printf("\nyour choice: ");
  				scanf("%c",&ans2);
  				fflush(stdin);
  				while(ans2!='1' && ans2!='2' && ans2!='3'&& ans2!='4'){
 					printf("\nInvalid input Please enter a new number: ");
 					scanf("%c",&ans2);
 					fflush(stdin);
 				}
 				
			 	switch(ans2){
					case'1':printf("\nPlease enter the ISBN: ");
							scanf("%s",ISBN);
							fflush(stdin);
							newbook=NULL;
							while(1){
								newbook=searchby_ISBN(newbook,ISBN);
								if(newbook==NULL)
								break;
								printinfo(newbook);
								flag=1;
							}
							if(!flag)
								printf("\nThe book is not found.\n");
							flag=0;	
							break;
							
					case'2':printf("\nPlease enter the field: ");
							scanf("%s",field);
							fflush(stdin);
							newbook=NULL;
							while(1){
								newbook=searchby_Field(newbook,field);
								if(newbook==NULL)
								break;
								printinfo(newbook);
								flag=1;
							}
							if(!flag)
								printf("\nThe book is not found.\n");
							flag=0;	
							break;
					case'3':printf("\nPlease enter the dueDate in this format dd-mm-yyyy: ");
							scanf("%s",dueDate);
							fflush(stdin);
							newbook=NULL;
							while(1){
								newbook=searchby_DueDate(newbook,dueDate);
								if(newbook==NULL)
								break;
								printinfo(newbook);
								flag=1;
							}
							if(!flag)
								printf("\nThe book is not found.\n");
							flag=0;	
							break;
					case'4':printf("\nPlease enter the Borrower's name: ");
							scanf("%s",borrowername);
							fflush(stdin);
							newbook=NULL;
							while(1){
								newbook=searchby_BorrowerName(newbook,borrowername);
								if(newbook==NULL)
								break;
								printinfo(newbook);
								flag=1;
							}
							if(!flag)
								printf("\nThe book is not found.\n");
							flag=0;	
							break;
							
							
				}
				break;
				case'6': break;
				default: printf("\nInvalid input\n");
		}
	}while(ans!='7');
	bubblesort();
	printf("Thank you very much, Your file has been saved. Have a nice day :)\n");
	out=fopen("output.txt","w");
	newbook=head;
		while(newbook){
			fprintf(out,"%d\t%s\t%s\t%d\t%.2lf\t$%.2lf\n",newbook->ID,newbook->ISBN,newbook->model,newbook->year,newbook->mileage,newbook->cost);
			newbook=newbook->next;
		}
	
	return 0;
}






//3.functions definition

void menu(){
	printf("\n--------------------------\n"
	       "1.Display books            \n"
		   "2.Insert a book            \n"
		   "3.Update a book Status      \n"
		   "4.Delete a book            \n"
		   "5.Search for a book        \n"
		   "6.Exit                    \n"
		   "--------------------------\n");

	printf("----> Please Enter Your Choice: ");
}

void displaybooks(){
	int i;
	book_node* node;
	node=head;
	if(node==NULL)
		printf("\nthere is no books to display\n");
	else{
		printf("\n%cISBN %cName        %cField       %cStatus    %cBorrower Name    %cDue Date      \n",(char)179,(char)179,(char)179,(char)179,(char)179,(char)179);
		printf("%c----------%c------------%c------------%c--------%c------------%c----------\n",(char)195,(char)197,(char)197,(char)197,(char)197,(char)197);}
	while(node){	
  		printf("%c%d",(char) 179,node->ID);
  		for(i=0;i<10-count_digits(node->ID,1);i++)
  			printf(" ");
  		printf("%c%s",(char) 179,node->ISBN);
  		
 		for(i=0;i<12-strlen(node->ISBN);i++)
  			printf(" ");
		printf("%c%s",(char) 179,node->model);
		
		for(i=0;i<12-strlen(node->model);i++)
			printf(" ");
		printf("%c%d",(char) 179,node->year);
		
		printf("    %c%.2f",(char) 179,node->mileage);
		
		for(i=0;i<9-count_digits(node->mileage,1);i++)
			printf(" ");
        printf("%c$%.2f\n",(char) 179,node->cost);
		node=node->next;
}
}


struct book_node*create_node(int ID, char* ISBN,char* model,int year,double mileage,double cost){
	book_node* newnode;
	newnode=(struct book_node*)malloc(sizeof(struct book));
	newnode->ID=ID;
	strcpy(newnode->ISBN,ISBN);
	strcpy(newnode->model,model);
	newnode->year=year;
	newnode->mileage=mileage;
	newnode->cost=cost;
	newnode->next=NULL;
	return newnode;
}


void insert_node(struct book_node* node){
	node->next=head;
	head=node;
}
	
void swap(struct book_node* node1,struct book_node* node2){
	struct book temp;
	struct book_node*temp1 , *temp2;
	temp1=(struct book_node*)malloc(sizeof(struct book));
	temp2=(struct book_node*)malloc(sizeof(struct book));

	temp1->next=node1->next;
	temp2->next=node2->next;
	
	temp=*node1;
	*node1=*node2;
	*node2=temp;
	
	node1->next=temp1->next;
	node2->next=temp2->next;
	
}

void printinfo(struct book_node* node){
	int i;
	if(node==NULL)
		printf("no such book exists\n");
	else{
	printf("\n%d     %s",node->ID,node->ISBN);
  		
 		for(i=0;i<10-strlen(node->ISBN);i++)
  			printf(" ");
		printf("%s",node->model);
		
		for(i=0;i<10-strlen(node->model);i++)
			printf(" ");
		printf("%d",node->year);
		
		printf("       %.2f       $%.2f\n",node->mileage,node->cost);
	}
}


struct book_node*searchbyID(int ID) {
	struct book_node* node;
	node=head;
	while(node){
		if(node->ID==ID)
			return node;
		node=node->next;
	}
	return NULL;
}

void updatebook(struct book_node* newbook,char ans){
	double cost;
	double mileage;
	switch(ans){
		case'1':printf("\nPlease enter the new cost: ");
				scanf("%lf",&cost);
				fflush(stdin);
				newbook->cost=cost;
				break;
				
		case'2':printf("\nPlease enter the new mileage: ");
				scanf("%lf",&mileage);
				fflush(stdin);
				newbook->mileage=mileage;
				break;
				
	}

}

void deletebook(struct book_node* newbook){
	int ID;
	if(newbook->ID==head->ID)
	head=head->next;
	else{
	ID=head->ID;
	swap(newbook,head);
	head=head->next;
	while(head->ID!=ID)
		swap(head,head->next);
	}
}

int count_number(){
	struct book_node* book;
	int cnt=0;
	book=head;
	while(book){
		book=book->next;
		cnt++;
	}
	return cnt;
}

int count_digits (int n,int i){
	if(n%i==n)
		return 0;
	return 1+count_digits (n,i*10);
}

void bubblesort(){
	int i,j;
	struct book_node* book=head;
	for(i=count_number();i>0;i--){
		book=head;
		for(j=0;j<i-1;j++){
			if(book->ID > book->next->ID)
				swap(book,book->next);
			book=book->next;
		}
	}
}


struct book_node*searchbyISBN(struct book_node* book, char* ISBN){
	int flag=1;
	char temp[50];
	
	if(book==NULL){
		book=head;
		flag=0;
	}
	if(book->next==NULL)
		return NULL;
	
	while(book){
		if(flag){
			book=book->next;
			flag=0;
		}
		strcpy(temp,book->ISBN);
		if(mycompare(temp,ISBN))
			return book;
		if(book)
		book=book->next;
	}
	return NULL;
}

struct book_node* searchbyyear(struct book_node* book, int year){
	int flag=1;
	if(book==NULL){
		book=head;
		flag=0;
	}
	
	if(book->next==NULL)
		return NULL;
	
	while(book){
		if(flag){
			book=book->next;
			flag=0;
		}
		if(book->year==year)
			return book;
		if(book)
		book=book->next;
	}
	return NULL;
}	

int mycompare(char* str1,char* str2){
	int flag=0;

	if (strlen(str1)==strlen(str2)){
		str1=lower(str1);
		str2=lower(str2);
		flag=strcmp(str1,str2);
		if (flag==0)
			return 1;
	}
	return 0;
}


char* lower(char* str){
int i;
for(i=0;i<strlen(str);i++){
if(isupper(str[i]))
str[i]=(int)str[i]+32;
}
return str;
}
