// Bus Reservation System - By Parva Kothari [23BIT0053]

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Function Prototypes

void sweeper();
void login(char **user);
void home();
void view1(int i);
void busroutes(int i);
void timer(int initial,int iter);
void cancel();
struct ticket *book();
int assign(char *bd,int r);
float biller(int type,int start,int stop);



// Global Variables (Bus Stops by Routes)

char *g1[12]={"Maheshwar","Indore","Dewas","Sehore","Bhopal","Vidisha",
                        "Sagar","Damoh","Bijawar","Chhatarpur","Shivpuri","Gwalior"};
char *g2[13]={"Ratlam","Ujjain","Dewas","Sehore","Bhopal","Raisen","Udaipura",
                        "Narsimhapur","Jabalpur","Murwara","Rewa","Sidhi","Singrauli"};
char *g3[10]={"Betul","Itarsi","Hoshangabad","Bhopal","Sarangpur",
                        "Rajgarh","Guna","Badarwas","Shivpuri","Gwalior"};
struct ticket *tnew;
int nop;

// Main Function


struct ticket{
    char name[20],boarding[15],destination[15];
    int route,b,d,date,shift,type,valid;
    float pay;
};
void main(){
    printf("\tWelcome to The Bus Reservation System");
    char **user;
    login(user);
    home();
}

// Accompanying Functions

void sweeper(){
    printf("\n\tPress any key to continue ...");
    getch();
    system("cls");
}
void login(char **user){
    user=(char **)malloc(3*sizeof(char *));
    for (int i=0;i<3;i++){
        user[i]=(char *)malloc(15*sizeof(char));
    }
    printf("\n\n\tLogin or Register to your account ---\n");
    printf("\nUsername : ");
    scanf("%s",user[0]);
    printf("Mobile No : ");
    scanf("%s",user[1]);
    printf("Password : ");
    scanf("%s",user[2]);
    printf("\n\n\tWelcome Back  %s\n\n",user[0]);
    sweeper();
}
void home(){
    fflush(stdin);
    fflush(stdout);
    int flag=2,choice;
    printf("\tWhat would you like to do ?\n\n");
    printf("\n[1] View Bus Types");
    printf("\n[2] View Bus Routes");
    printf("\n[3] Book Ticket");
    printf("\n[4] View Ticket");
    printf("\n[5] Cancel Ticket");
    printf("\n\n[0] Logout\n\n");
    printf("Your Choice  =>  ");
    scanf("%i",&choice);
    switch (choice){
    case 1:
        flag=0;
        view1(0);
        break;
    case 2:
        flag=0;
        busroutes(0);
        break;
    case 3:
        flag=0;
        tnew=book();
        break;
    case 4:
        flag=0;
        pger(tnew);
        break;
    case 5:
        flag=0;
        cancel(tnew);
        break;
    case 0:
        flag=1;
        break;
    default:
        printf("\n\tSomething went wrong ...");
        break;
    }
    if (flag==1) printf("\n\tThank You ...\n\n\n");
    else{
        sweeper();
        home();
    }
}
void view1(int i){
    int ch;
    printf("\n\n\t-- Bus Types -- \n");
    printf("\n[1] Seater Non AC");
    printf("\n[2] Seater AC");
    printf("\n[3] Sleeper AC\n\n");
    if (i==0){
        printf("[0] Go Back\n\n");
        printf("Choose to inquire prices  =>  ");
        scanf("%i",&ch);
        switch (ch){
        case 1:
            printf("\n\nTotal Seats - No. 48 \n");
            printf("Base Price -  Rs. 300\n");
            break;
        case 2:
            printf("\n\nTotal Seats - No. 48 \n");
            printf("Base Price -  Rs. 350\n");
            break;
        case 3:
            printf("\n\nTotal Seats - No. 16 \n");
            printf("Base Price -  Rs. 500\n");
            break;
        case 0:
            break;
        default:
            printf("\n\tSomething went wrong ...");
            break;
        }
    }
}
void busroutes(int i){
    int ch;
    printf("\n\n\t-- Bus Routes --\n");
    printf("\n[1] G1\tMaheshwar to Gwalior");
    printf("\n[2] G2\tRatlam to Singrauli");
    printf("\n[3] G3\tBetul to Gwalior\n\n");
     if (i==0){
        printf("[0] Go Back\n\n");
        printf("Choose Route  =>  ");
        scanf("%i",&ch);
        switch (ch){
        case 1:
            printf("\n\nStops - 12 \n\n");
            fflush(stdout);
            for (int p=0;p<12;p++) printf("%s\n",g1[p]);
            break;
        case 2:
            printf("\n\nStops - 13 \n\n");
            fflush(stdout);
            for (int p=0;p<12;p++) printf("%s\n",g2[p]);
            break;
        case 3:
            printf("\n\nStops - 10 \n\n");
            fflush(stdout);
            for (int p=0;p<12;p++) printf("%s\n",g3[p]);
            break;
        case 0:
            break;
        default:
            printf("\n\tSomething went wrong ...");
            break;
        }
    }
}
void timer(int initial,int iter){
    int hr=7,min=0;
    hr+=((initial*20)/60)+(iter*4);
    min+=(initial*20)%60;
    printf("%02d : %02d",hr,min);
}
void cancel(struct ticket *t){
    int c;
    char ch;
    printf("\n\n\t-- Cancel Ticket --\n");
    printf("\n[1] Partially");
    printf("\n[2] Completely");
    printf("\n[0] Go Back\n\n");
    printf("Choose  =>  ");
    scanf("%d",&c);
    printf("\n\n");
    switch (c){
    case 1:
        pger(t);
        printf("\n\n\tCancel by Passenger\n");
        printf("\nPassenger No  =>  ");
        scanf("%d",&c);
        ((t+c-1)->valid)=0;
         printf("\n\tCancelled Successfully !\n");
        break;
    case 2:
        pger(t);
        fflush(stdin);
        printf("\n\n\tCancel Completely\n");
        printf("\nAre you sure ? (Press 0 for Back/Any other for Yes)\n");
        scanf("%c",&ch);
        if (ch=='0') break;
        else{
            for (int j=0;j<nop;j++) ((t+j)->valid)=0;
            printf("\n\tCancelled Successfully !\n");
            break;
        }
    case 0:
        break;
    default:
        printf("\n\tSomething went wrong ...");
        break;
    }
}
struct ticket *book(){
    int n;
    printf("\n\n\tBooking Window\n");
    printf("\nNumber of Passengers  =>  ");
    scanf("%d",&n);
    struct ticket *t;
    t=(struct ticket *)calloc(n,sizeof(struct ticket));
    for (int x=0;x<n;x++){
        fflush(stdin);
        printf("\n\n\tPassenger ID %d\n",x+1);
        printf("\nName\t=>\t");
        gets((t+x)->name);
        view1(1);
        fflush(stdin);
        printf("\nBus Type\t=>\t ");
        scanf("%d",&(t+x)->type);
        busroutes(1);
        fflush(stdin);
        printf("Bus Route\t=>\tG ");
        scanf("%d",&(t+x)->route);
        fflush(stdin);
        printf("Boarding\t=>\t");
        gets((t+x)->boarding);
        ((t+x)->b)=assign((t+x)->boarding,(t+x)->route);
        printf("Destination\t=>\t");
        gets((t+x)->destination);
        ((t+x)->d)=assign((t+x)->destination,(t+x)->route);
        fflush(stdin);
        printf("Date (DDMMYYYY)\t=>\t");
        scanf("%d",&(t+x)->date);
        printf("\n\n\t-- Slots --\n");
        for (int p=0;p<4;p++){
            printf("\n[%d] ",p+1);
            timer((t+x)->b,p);
        }
        printf("\n\nSlot\t=>\t");
        scanf("%d",&(t+x)->shift);
        ((t+x)->shift)--;
        ((t+x)->valid)=1;
    }
    printf("\n\n\tThank You for Booking with Us !!!\n");
    nop=n;
    return t;
}
int assign(char *bd,int r){
   fflush(stdin);
    int b;
    if (r==1){
        for (int y=0;y<12;y++){
                if (strcmp(bd,g1[y])==0) b=y;
        }
    }
    else if (r==2){
            for (int y=0;y<13;y++){
                    if (strcmp(bd,g2[y])==0) b=y;
            }
    }
    else if (r==3){
            for (int y=0;y<10;y++){
                    if (strcmp(bd,g3[y])==0) b=y;
            }
    }
    else{
        printf("\n\tDid you enter the data correctly?\n");
    }
    return b;
}
float biller(int type,int start,int stop){
    int n;
    float billmult=1,bill;
    if (start==stop) printf("Error !!!");
    else{
        n=start-stop;
        n *= ((start-stop)>0)?(-1):1;
        if (n>5) billmult+=0.2;
        if (n>10) billmult+=0.3;
        if (n>15) billmult+=0.2;
        switch (type){
            case 1:
            bill=300.0*billmult*1.05;
            break;
            case 2:
            bill=350.0*billmult*1.08;
            break;
            case 3:
            bill=500.0*billmult*1.08;
            break;
        }
    }
    return bill;
}

// Seperate Function

void pger(struct ticket *t){
    printf("\n\n\tTicket - APPROVED\n\n\n");
    for (int i=0;i<nop;i++){
        if (((t+i)->valid)==1){
            printf("\tPassenger %d\n",i+1);
            printf("\nName\t\t-\t%s",(t+i)->name);
            printf("\nBus Type\t-\t");
            if (((t+i)->type)==1) printf("Seater Non AC");
            else if (((t+i)->type)==2) printf("Seater AC");
            else if (((t+i)->type)==3) printf("Sleeper AC");
            printf("\nBoarding\t-\t%s",(t+i)->boarding);
            printf("\nDestination\t-\t%s",(t+i)->destination);
            printf("\nRoute\t\t-\tG %d",(t+i)->route);
            printf("\nDeparture\t-\t%d\t",(t+i)->date);
            timer((t+i)->b,(t+i)->shift);
            printf("\nArrival\t\t-\t%d\t",(t+i)->date);
            timer((t+i)->d,(t+i)->shift);
            printf("\nFee to Pay (Cash/GST included)\t-\t%.2f\n\n",biller((t+i)->type,(t+i)->b,(t+i)->d));
        }
    }
}

// End of Code
