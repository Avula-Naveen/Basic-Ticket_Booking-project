#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
typedef struct passdetails {
    char name[50];
    int flight_no;
    int num_of_seats;
}pd;
void login();
void list(void);
void booking(void);
void spficflight(int);
float charge(int,int);
void printticket(char name[],int,int,float);
int main(){
    
    int num;
    printf("\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n\t\t\t------------------------------------------------------------------------\n");
    printf("\n\t\t\t@@@@@                WELCOME TO AIR_LINE BOOKING                 @@@@@@@\n");
    printf("\n\t\t\t------------------------------------------------------------------------\n");
    printf("\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
    printf("\n\t\t\t                                                                        \n");
    printf("                                                                                \n");
    login();
    start:
    system("cls");
    printf("\n\t\t\t[1]TO View Flights list\n");
    printf("\n\t\t\t[2]To Book Ticket\n");
    printf("\n\t\t\t[3]exit\n");
    printf("\n\t\t\tenter your choice :  ");
    scanf("%d",&num);
    
        switch(num){
            case 1:
            list();
            printf("\nenter any key to go to Main Menu:");
            getch();
            break;
             case 2:
             booking();
             break;
            case 3:
             return(0);
             break;
            default:
            printf("enter valid number:");
        }
        goto start;

    return 0;
}
void list(void){
    system("cls");
    printf("--------------------------------------------------------------------------------------------------------------------------");
    printf("\n No: \tName                \t\tDestination               \t\tcharges      \t\tTime of depature");
    printf("\n--------------------------------------------------------------------------------------------------------------------------");
    printf("\n 1  \tspicejet          \t\tHyderbad To Delhi       \t\tRS:4999  \t\t     6:30 Am   ");
    printf("\n 2  \tIndiGo             \t\tBangalore To Hyderabad  \t\tRS:2499  \t\t     5:15 Pm   ");
    printf("\n 3  \tBritish Air ways   \t\tHyderbad To chennai     \t\tRS:1999  \t\t     5:45 Am   ");
    printf("\n 4  \tAir India          \t\tMadras To New delhi     \t\tRS:3599  \t\t     6:30 Am   ");
    printf("\n 5  \tTrujet             \t\tPune To chennai         \t\tRS:3299  \t\t     8:45 Am   ");
    printf("\n 6  \tEmirates           \t\tKochi To Ahmedabad      \t\tRS:2999  \t\t     2:30 pm   ");
    printf("\n 7  \tQATAR Air_lines    \t\tKolkata To Mumbai       \t\tRS:2499  \t\t     6:30 Am   ");
}

void booking(void){
    char confirm;
    char ch;
    int i=0;
    float charges;
    pd passdetails;
    FILE *fptr;
    fptr=fopen("pass_reservation.txt","a");
    system("cls");
    printf("\nenter your name:");
    fflush(stdin);
    gets(passdetails.name);
    printf("\nenter number of seats:");
    scanf("%d",&passdetails.num_of_seats);
    printf("\npress enter to view the flights list: ");
    getch();
    system("cls");
    list();
    printf("\nenter flight number :");
    start1:
    scanf("%d",&passdetails.flight_no);
    if(passdetails.flight_no>=1 && passdetails.flight_no<=7){
        charges=charge(passdetails.flight_no,passdetails.num_of_seats);
        printticket(passdetails.name,passdetails.num_of_seats,passdetails.flight_no,charges);
    }
    else{
        printf("\n\t\t\tInvalid flight number !!! enter again :");
        goto start1;
    }
    printf("\n\t\t\t confirm Ticket (y/n):");
    start:
    scanf("%c",&confirm);
    if(confirm =='y'){
        fprintf(fptr,"%s\t\t%d\t\t%d\t\t%d\t\t%f",&passdetails.name,passdetails.num_of_seats,passdetails.flight_no,charges);
        printf("\n\t\t\t*******************************************************************");
        printf("\n\t\t\t                                                                      ");
        printf("\n\t\t\t              Reservation is sucessfull                             ");
        printf("\n\t\t\t                      Thank you :)                                   ");
        printf("\\t\t\t                                                                      ");
        printf("\n\t\t\t**********************************************************************");
        printf("\n\t\t\tenter any key to go back to main menu :");
      }
       else if(confirm =='n'){
               printf("\n\t\t\tReservation is Canceled!\npress any key to go back ");
           }
       
      else{
         // printf("\nInvalid choice !! RE-enetr: ");
          goto start;
      }
      fclose(fptr);
      getch();

}
float charge(int flight_no,int num_of_seats){
    if(flight_no==1){
        return(4999*num_of_seats);
    }
    else if(flight_no==2){
        return(2499*num_of_seats);
    }
    else if(flight_no==3){
        return(1999*num_of_seats);
    }
    else if(flight_no==4){
        return(3599*num_of_seats);
    }
    else if(flight_no==5){
        return(3299*num_of_seats);
    }
    else if(flight_no==6){
        return(2999*num_of_seats);
    }
    else if(flight_no==7){
        return(2499*num_of_seats);
    }

}
void printticket(char name[],int num_of_seats,int flight_no,float charges){
    system("cls");
    printf("\n\t\t\t-----------------------------------------------------------");
    printf("\n\t\t\t                     Ticket                               ");
    printf("\n\t\t\t                Have a Great journey :)                  ");
    printf("\n\t\t\t-----------------------------------------------------------");
    printf("\n\t\t\tName:\t%s",name);
    printf("\n\t\t\tNumber of seats :%d",num_of_seats);
    printf("\n\t\t\tFlight number:\t%d",flight_no);
    spficflight(flight_no);
    printf("\n\t\t\tTotal charges:\t%f",charges);
    

}
void login(){
    
    char uname[10];
    char upass[10];
    // FILE *fptr;
    // fptr=fopen("pass_reservation.txt","r");
    start_1:
    printf("\n\t\t\t---------------------------------------");
    printf("\n\t\t\t          User Login                   ");
    printf("\n\t\t\t---------------------------------------");
    printf("\n\t\t\tEnter User_Name:");
    // fgets(uname,20,stdin);
    scanf("%s",&uname);
    printf("\n\t\t\tEnter Password:");
    // fgets(upass,20,stdin);
    scanf("%s",&upass);
    if(strcmp(uname,"user")==0 && strcmp(upass,"pass")==0){
    printf("\n\t\t\t**************************************");
    printf("\n\t\t\t                                      ");    
    printf("\n\t\t\t           Login Sucessful            ");
    printf("\n\t\t\t                                      ");
    printf("\n\t\t\t**************************************");
     printf("\n\t\t\tpress any key to contiune ");
    getch();
    }
   else{
    printf("\n\t\t\t#####  Login Failed ! enter correct user_name and password::  ####");
    printf("\n\t\t\tEnter any key to go back :  ");
    getch();
    goto start_1;
   }

}
void spficflight(int flight_no){
    if(flight_no==1){
        printf("\n\t\t\t\t\t\tFlight:spicejet");
        printf("\n\t\t\t\t\t\tDepature:Hyderbad To Delhi ");
        printf("\n\t\t\t\t\t\tTime_of_Depature:\t6:30 Am");
    }
     if(flight_no==2){
        printf("\n\t\t\t\t\tFlight:IndiGo");
        printf("\n\t\t\t\t\tDepature:Bangalore To Hyderabad");
        printf("\n\t\t\t\t\tTime_of_Depature:\t5:15 Pm");
    }
     if(flight_no==3){
        printf("\n\t\t\t\t\tFlight:British Air ways");
        printf("\n\t\t\t\t\tDepature:Hyderbad To chennai ");
        printf("\n\t\t\t\t\tTime_of_Depature:\t5:45 Am");
    }
     if(flight_no==4){
        printf("\n\t\t\t\t\tFlight:Air India");
        printf("\n\t\t\t\t\tDepature:Madras To New delhi");
        printf("\n\t\t\t\t\tTime_of_Depature:\t6:30 Am ");
    }
     if(flight_no==5){
        printf("\n\t\t\t\t\tFlight:Trujet");
        printf("\n\t\t\t\t\tDepature:Pune To chennai");
        printf("\n\t\t\t\t\tTime_of_Depature:\t8:45 Am");
    }
     if(flight_no==6){
        printf("\n\t\t\t\t\tFlight:Emirates");
        printf("\n\t\t\t\t\tDepature:Kochi To Ahmedabad");
        printf("\n\t\t\t\t\tTime_of_Depature:\t2:30 pm");
    }
     if(flight_no==7){
        printf("\n\t\t\t\t\tFlight:QATAR Air_lines");
        printf("\n\t\t\t\t\tDepature:Kolkata To Mumbai");
        printf("\n\t\t\t\t\tTime_of_Depature:\t6:30 Am");
    }
}
