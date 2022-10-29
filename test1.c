#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

#define  true 1;
#define false 0;


struct traindetails{

        char trainname[20] ;
        char traintime[20];
        char journeyduration[20];
        int fare ;
        int trainnumber;
};

typedef struct mynode {
	char name[20];
	char gen[6];
	int age;
	struct mynode* link;
} Node;

Node * head=NULL;
Node * tail=NULL ;

_Bool authenticateuser(int uid){
    int a[]={2345,3447,5330,9866,8162};
    for(int i=0;i<5;i++){
        if(a[i]==uid){
            return true ;
        }
    }
    return false;
}

_Bool check(char source[],char destination[]){
   // char places[][20]={"Kashi","Ayodhya","Manali","Shimla","Jalandhar","Amritsar","Pune","Mumbai"} ;
   if(strcmp(source,"Kashi")==0&&strcmp(destination,"Ayodhya")==0||strcmp(source,"Manali")==0&&strcmp(destination,"Shimla")==0||strcmp(source,"Jalandhar")==0&&strcmp(destination,"Amritsar")==0||strcmp(source,"Pune")==0&&strcmp(destination,"Mumbai")==0){
        return true;
    }
    return false ;
}

int main() {
    int role;
    printf("\nEnter your role :\n1. Admin\n2. User\nChoose : ");
    scanf("%d",&role);
    if(role==1){
        printf("                        Welcome to the Admin login page. Please enter your username and password");
        int password;
        char name[10];
        //Given username {dogesh}
        printf("\nEnter Username: ");
        scanf("%s",&name);
        //Given password 123
        printf("\nEnter password: ");
        scanf("%d",&password);
        int adminoperation;
        if(strcmp("dogesh",name)==0 && password== 123){
            
            printf("Please enter the operation you want to perform:\n1:To add a new source and destination \n2:To remove a source and destination and the train running on the route\n");
            scanf("%d",&adminoperation) ;
            if(adminoperation==1){
                int i;
                char array[3][1000];
                printf("Enter the source and destination : ");
                for (i = 0; i < 3; i++)
                    scanf("%s", array[i]);
                printf("The updated source and destination are:\n\n(1) KASHI TO AYODHYA\n(2) PUNE TO MUMBAI\n(3) JALANDHAR TO AMRITSAR \n(4) MANALI TO SHIMLA \n(5) ");
                for (i = 0; i < 3; i++)
                    printf("%s ", array[i]);
                }
                
            else if (adminoperation==2){
                char remove[20];
                printf("Enter the source and destination to remove : ");
                scanf("%s",remove);
                printf("The updated source and destination are:\n\n(1) KASHI TO AYODHYA\n(2) PUNE TO MUMBAI\n(3) MANALI TO SHIMLA\n");
                }
            else{
                printf("\n\nEnter a correct username or password.");
                }
            }
            }
    else if (role==2){
    printf("\033[0;36m");
    int uid;
    printf("Enter the UID for authenticatation : ");
    printf("\033[0m");
    scanf("%d",&uid);
    _Bool checkers=authenticateuser(uid);
    while(!checkers){
            int i=0;
        for(;i<3;i++){
            printf("\033[0;31m");
            printf("Invalid User\n");
            printf("\033[0m");
            scanf("%d",&uid);
            checkers=authenticateuser(uid);
        }
        if(i==3){
            printf("\033[0;33m");
            printf("Maximum login attempts reached .Please try another session");
            printf("\033[0m");
            return 0 ;
        }
    }
    printf("\033[0;34m");
    printf("\nAuthenticating user\n");
    sleep(1);
    int n;
    for(n=1;n<4;n++){
        printf(".");
        sleep(1);
    }
    sleep(1);
    printf("\n\nChecking database\n");
    
    int m;
    for(m=1;m<4;m++){
        printf(".");
        sleep(1);
    }
    sleep(2);
    printf("\033[0m");
    printf("\033[0;32m");
    printf("\n\nUser Authentication Successful : Please continue to book your ticket :\n");
    printf("\033[0m");
    char source[20] ;
    char destination[20];
    printf("\nWe offer the following touring destinations \n(1) KASHI TO AYODHYA\n(2) PUNE TO MUMBAI\n(3) JALANDHAR TO AMRITSAR \n(4) MANALI TO SHIMLA :)");
    printf("\033[0;31m");
    printf("\n\nOrigin: ");
    printf("\033[0m");
    scanf("%s",&source);
    printf("\033[0;31m");
    printf("\nDestination: ");
    printf("\033[0m");
    scanf("%s",&destination);
    _Bool checking=check(source,destination) ;
    while(!checking){
        printf("\033[0;31m");
        printf("Enter a valid source and destination.\nSource:");
        printf("\033[0m");
        scanf("%s",&source);
        printf("\033[0;31m");
        printf("\nDestination : ");
        printf("\033[0m");
        scanf("%s",&destination);
        checking=check(source,destination);
    }
    struct traindetails t1 ;
    if(strcmp(source,"Kashi")==0){
        strcpy(t1.trainname,"SHIVGANGA~EXPRESS");
        strcpy(t1.traintime,"15:30\t\t\t-\t\t\t19:35");
        strcpy(t1.journeyduration,"\n\t\t3Hours ~ 5Minutes ");
        t1.fare=1200;
        t1.trainnumber=15478;

    } else if(strcmp(source,"Pune")==0){
        strcpy(t1.trainname,"JAN~SHATABDI~EXPRESS");
        strcpy(t1.traintime,"18:15-20:14");
        strcpy(t1.journeyduration,"2Hours7Minutes");
        t1.fare=1200;
        t1.trainnumber=15478;
    } else if(strcmp(source,"Jalandhar")==0){
        strcpy(t1.trainname,"GareebrathExpress");
        strcpy(t1.traintime,"18:15-20:14");
        strcpy(t1.journeyduration,"2Hours7Minutes");
        t1.fare=1200;
        t1.trainnumber=15478;
    } else if(strcmp(source,"Manali")==0){
        strcpy(t1.trainname,"ABC");
        strcpy(t1.traintime,"18:15-20:14");
        strcpy(t1.journeyduration,"2Hours7Minutes");
        t1.fare=1200;
        t1.trainnumber=15478;
    }


    int numpassengers;
    //Node * head=NULL ;
    //Node * tail=NULL ;
    printf("\033[0;35m");
    printf("Enter the number of person : ");
    printf("\033[0m");
    scanf("%d",&numpassengers);
    char name[10],gender[10];
    int age ;

      //  Node * newptr=NULL;
      FILE *fp;
    while(numpassengers>0){
        printf("\033[0;33m");
        printf("\nName : ");
        scanf("%s",&name);
        printf("Gender:");
        scanf("%s",&gender);
        printf("Age : ");
        printf("\033[0m");
        scanf("%d",&age);
        fp = fopen("userdata","a");
        fprintf(fp,"\n%s %s %d",name,gender,age);
        fclose(fp);
        

        Node *newptr = (Node*)malloc(sizeof(Node));
        strcpy(newptr->name, name);
        strcpy(newptr->gen, gender);
        newptr->age = age;
        if (head == NULL){
            head=newptr;
            tail=newptr;
         }else{
            tail->link=newptr;
            tail=newptr;
        }
        numpassengers-- ;
    }

        //function to print the ticket :-
    printf("\033[1;36m");
    printf("\n            YOUR BOOKING HAS BEEN DONE SUCCESSFULLY !!! \n            PLEASE DOWNLOAD AND SAVE YOUR TICKET \n\n");
    printf("\033[0m");
    printf("\033[1;31m");
    printf("             Train Details and Duration\n");
    printf("\033[0m");
    printf("%s (%d%d) \n",t1.trainname,t1.trainnumber);
    printf("%s            %s\n",t1.traintime,t1.journeyduration);
    printf("%s                 %s",source,destination);
    printf("\n____________________________________________________________________\n");
    printf("____________________________________________________________________\n");
    printf("\033[1;33m");
    printf("\n            PASSENGER INFORMATION\n");
    printf("\033[0m");

    Node * temp=head ;
	while(temp!=NULL) {
		printf("%s",temp->name);
		printf("\n");
		printf("%d",temp->age);
		printf("\t|\t");
		printf("%s",temp->gen);
		temp=temp->link;
		printf("\n********************\n");
        
	}
    
    printf("____________________________________________________________________\n");
    printf("____________________________________________________________________\n");
    printf("\033[1;35m");
    printf("            PAYMENT DETAILS \n");
    printf("\033[0m");
    printf("Base Fare :   \t  \t %d\n",t1.fare);
    int i=84;
    printf("Convenience Fee and GST: %d\n",i);
    printf("Total Fare  :  \t\t %d",i+t1.fare);
    }
    else{
    printf("\nEnter a given number to choose a role.");}
}



