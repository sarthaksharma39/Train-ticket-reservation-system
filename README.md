#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define  true 1;
#define false 0;

struct traindetails {

        char trainname[10] ;
        char traintime[10];
        char journeyduration[15];
        int fare ;
        int trainnumber;
        int distancebetweenstations;
} ;
typedef struct mynode {
	char name[10];
	char gen[6];
	int age;
//	long long mobilenumber;
	//char address[20] ;
	struct mynode* link;
} Node;

Node * head=NULL;
Node * tail=NULL ;
_Bool authenticateadmin(int adminpassword) {
   if(adminpassword=7376728){
        return true ;
    }
    return false;
}
char source[10] ;
char destination[10];
_Bool authenticateuser(int uid){
    int a[7]={2345,3447,5330,9866,8162,9033,2684};
    for(int i=0;i<7;i++){
        if(a[i]==uid){
            return true ;
        }
    }
    return false;
}
int numDestinations=4;
char s[][10]={"Kashi","Manali","Jalandhar","Pune"};
char d[][10]={"Ayodhya","Shimla","Amritsar","Mumbai"};
void add(char newsource[],char newdestination[]){

        strcpy(s[numDestinations],newsource);
        strcpy(d[numDestinations],newdestination);
        printf("New source and destination added succesfully") ;
        numDestinations++;


}
_Bool check(char source[],char destination[]){
    _Bool o1=false;
    _Bool o2=false;
    for(int x=0;x<=numDestinations;x++){
        if(strcmp(source,s[x])==0){
            o1=true;
        }
    }
    for(int x=0;x<=numDestinations;x++){
        if(strcmp(source,s[x])==0){
            o2=true;
        }
    }
    if(o1&&o2){
        return true ;
    }else{
        return false ;
    }


}


int main() {
	printf("\t\t=================================================\n");
	printf("\t\t||                                               ||\n");
	printf("\t\t||       -----------------------------           ||\n");
	printf("\t\t||      TRAIN TICKET RESERVATION SYSTEM          ||\n");
	printf("\t\t||        -----------------------------          ||\n");
	printf("\t\t||                                               ||\n");
	printf("\t\t||                                               ||\n");
	printf("\t\t||                                               ||\n");
	printf("\t\t||                  MADE BY                      ||\n");
	printf("\t\t||           |  SARTHAK SHARMA  |                ||\n");
	printf("\t\t||                                               ||\n");
	printf("\t\t=================================================\n\n\n");
   int choice ;
    printf("Are you a user or an admin:\n1:Admin:\n");
    printf("2:User:\n");
    scanf("%d",&choice);
    if(choice==1){
        printf("                        Welcome to the ADMIN login page.Please enter  Admin-Id and password\n");
        int password;
        char name[20];
        printf("Enter Admin-Id : \n");

        scanf("%s",&name);
        printf("Enter Admin Password : ");
        scanf("%d",&password);
        if(authenticateadmin(password)){
            int adminoperation;
            printf("Please enter the operation you want to perform:\n1:To add a new source and destination and\n2:To remove a source and destination and the train running on the route\n");
            scanf("%d",&adminoperation) ;
            if(adminoperation==1){
                char news[10],newd[10];
                printf("new source : ");
                scanf("%s",&news) ;
                printf("new destination:");
                scanf("%s",&newd) ;
                add(news,newd);
                printf("\nThe updated source and destination are:\n");
                for(int h=0;h<numDestinations;h++){
                    printf("%s to %s\n",s[h],d[h]);
                }

                return 0 ;

            }
        }else{
                return 0;
            }



    }

    int uid;
    printf("Enter your user id number to authenticate : ");
    scanf("%d",&uid);
    _Bool checkers=authenticateuser(uid);
    int i=1;
    while(!authenticateuser(uid)){
        if(i==3){
                printf("Maximum login attempts reached .Please try another session");
                return 0 ;
        }
            printf("Invalid User\nPlease enter a valid user id\n");
            printf("Enter your user id number to authenticate : ");
            scanf("%d",&uid);
            checkers=authenticateuser(uid);
        i++;

    }
    printf("Authenticating user....");
    sleep(2);
    printf("\nChecking database...");
    sleep(2);
    printf("\nUser Authentication Successful\nPlease continue to book your ticket :\n");
    sleep(2);
  //  char source[9] ;
    //char destination[9];
   // printf("\nWe offer the following touring destinations\n);
    for(int h=0;h<numDestinations;h++){
        printf("%s to %s\n",s[h],d[h]);
    }
    printf("Enter your source station :");
    scanf("%s",&source);
    printf("Enter your destination station :");
    scanf("%s",&destination);
    _Bool checking=check(source,destination) ;
    while(!checking){
        printf("Enter a valid source and destination\nEnter your source station :");

        scanf("%s",&source);
        printf("Enter your destination station :");
        scanf("%s",&destination);
        checking=check(source,destination);
    }
    struct traindetails t1 ;
    if(strcmp(source,"Kashi")==0){
        strcpy(t1.trainname,"SHIVGANGAEXPRESS");
        strcpy(t1.traintime,"15:30-19:35");
        strcpy(t1.journeyduration,"3Hours5Minutes");
        t1.fare=2330;
        t1.trainnumber=15478;
        t1.distancebetweenstations=1275;

    } else if(strcmp(source,"Pune")==0){
        strcpy(t1.trainname,"JANSHATABDIEXPRESS");
        strcpy(t1.traintime,"18:15-20:14");
        strcpy(t1.journeyduration,"2Hours7Minutes");
        t1.fare=1200;
        t1.trainnumber=15478;
        t1.distancebetweenstations=2245;
    } else if(strcmp(source,"Jalandhar")==0){
        strcpy(t1.trainname,"GareebrathExpress");
        strcpy(t1.traintime,"18:15-20:14");
        strcpy(t1.journeyduration,"2Hours7Minutes");
        t1.fare=1200;
        t1.trainnumber=15478;
        t1.distancebetweenstations=1684;

    } else if(strcmp(source,"Manali")==0){
        strcpy(t1.trainname,"ABC");
        strcpy(t1.traintime,"18:15-20:14");
        strcpy(t1.journeyduration,"2Hours7Minutes");
        t1.fare=1200;
        t1.trainnumber=15478;
        t1.distancebetweenstations=1824;

    }


    int numpassengers;
    //Node * head=NULL ;
    //Node * tail=NULL ;
    printf("Enter the number of tickets you want to book : ");
    scanf("%d",&numpassengers);
    char name[20];
    char gender[6];
    int age ;
    int mobilenum ;
    char add[20];
    int k=1;
 	FILE *fp;
    fp=fopen("traindata.txt","w");
    int v=1;
    while(numpassengers>0){

        printf("PASSENGER %d DETAILS :\n",k);
        printf("Name : ");
        scanf("%s",&name);
        printf("Gender:");
        scanf("%s",&gender);
        printf("Age : ");
        scanf("%d",&age);
       // printf("Mobile Number : ");
       // scanf("%d",&mobilenum);
      //  printf("Address : ") ;
      //  scanf("%s",&add);
      fprintf(fp,"\nPassenger %d details\n",v);
      fprintf(fp,"Name :%s\n",&name);
       fprintf(fp,"Age : %d\n",age);
       fprintf(fp,"Gender :%s\n",&gender);

       // fprintf(fp,"Mobile Num:%s\n",mobilenum);
//        fprintf(fp,"Address ":%s\n",add);
        Node *newptr = (Node*)malloc(sizeof(Node));
        strcpy(newptr->name, name);
        strcpy(newptr->gen, gender);

       // strcpy(newptr->address,add);
       // newptr->mobilenumber=mobilenum ;
        newptr->age = age;
        if (head == NULL){
            head=newptr;
            tail=newptr;
         }else{
            tail->link=newptr;
            tail=newptr;
        }
        numpassengers-- ;
        k++;
        v++;
    }

    fclose(fp);
    printf("\n            YOUR BOOKING HAS BEEN DONE SUCCESSFULLY !!!\n            PLEASE DOWNLOAD AND SAVE YOUR TICKET \n\n");
    printf("***********************************************************************************************************\n");
    printf("***********************************************************************************************************\n");
    printf("             Train Details and Duration                     \n");
    printf("    %s        (%d)\n",t1.trainname,t1.trainnumber);
    printf("%s            %s\n",t1.traintime,t1.journeyduration);
    printf("%s                 %s\n",source,destination);
    printf("____________________________________________________________________________________________________________\n");
    printf("____________________________________________________________________________________________________________\n");
    printf("\n            PASSENGER INFORMATION\n");


    Node * temp=head ;
	while(temp!=NULL) {
		printf("%s",temp->name);
		printf("\n");
		printf("%d",temp->age);
		printf("|");
		printf("%s",temp->gen);
		temp=temp->link;

		printf("\n***********\n");
	}

    printf("____________________________________________________________________\n");
    printf("____________________________________________________________________\n");
    printf("PAYMENT DETAILS \n");
    printf("Base Fare       %d\n",t1.fare);
    int r=84;
    printf("Convenience Fee and GST       %d\n",i);
    printf("Total Fare       %d\n",i+t1.fare);
    printf("***********************************************************************************************************\n");
    printf("***********************************************************************************************************\n");
}
