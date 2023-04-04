

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining global variables
int i,j,main_exit;

//declaring functions
void enquiry();
void menu();
void new_entry();
void edit();
void view_list();
void erase();
void see();
void sorter();
void closer();

//defining structures
struct date
  {
    int month,day,year;
  };
struct Room {
   char hostel_name[10];
   int room_number;
   int is_booked; // 0 for available, 1 for booked
};
struct 
   {
    char name[120];
    int age;
    char city[120];
    char mail_id[60];
    char room_no[8];
    char father_name[60];
    int father_phone_no[11];
    int phone_no[11];
    char hostel_id[10];
    struct date dob;
    struct Room;
    int rent_paid;
    int rent_rem; 
    }add,upd,check,rem,sort;

//main function

int main()
  {
    
    system("color 0b");
    pass();
    menu();
  return 0;
  }


//menu function

void menu()
{
  
  system("CLS");
   
    int choice;
    printf("\n");
    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2HOSTEL MANAGEMENT SYSTEM/xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    
	
	//printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
   
    printf("\n\n-------------------------------------------------------------\n");
    printf("\n \t\tWELCOME TO THE MAIN MENU ");
	printf("\n\n-------------------------------------------------------------\n");
    
	printf("\n\t\t1>> Enquiry  ");
    printf("\n\t\t2>> Enter new Student's data  ");
	printf("\n\t\t3>> Update information of existing account  ");
	printf("\n\t\t4>> Check the details of existing account  ");
	printf("\n\t\t5>> View all Students of a particlar Hostel  ");
	printf("\n\t\t6>> Removing existing account  ");
	printf("\n\t\t7>> View all students list  ");
	printf("\n\t\t8>> Exit");
	
    printf("\n\n-------------------------------------------------------------");	
	
	printf("\n\t\tn\n\n\n\t\t Enter your choice : ");
        scanf("%d",&choice);

    switch(choice)
    {
     	case 1:enquiry();
        break;
        
        case 2:new_entry();
        break;
        
        case 3:edit();
        break;
        
        case 4:see();
        break;
        
        case 5:sorter();
        break;
        
        case 6:erase();
        break;
  
        case 7:view_list();
        break;
  
        case 8:closer();
        break;
  
        default:menu();
    }
}
struct Room rooms[4][10]; // 4 hostels and each hostel has 10 rooms
void initialize_rooms() {
   int i,j,k,l;
   // BH-1
   for (i = 0; i < 10; i++) {
      rooms[0][i].room_number = i + 1;
      rooms[0][i].is_booked = 0; // available
      strcpy(rooms[0][i].hostel_name, "BH-1");
   }

   // BH-2
   for (j = 0; j < 10; j++) {
      rooms[1][j].room_number = j + 1;
      rooms[1][j].is_booked = 0; // available
      strcpy(rooms[1][j].hostel_name, "BH-2");
   }

   // BH-3
   for (k = 0; k < 10; k++) {
      rooms[2][k].room_number = k + 1;
      rooms[2][k].is_booked = 0; // available
      strcpy(rooms[2][k].hostel_name, "BH-3");
   }

   // GH-1
   for (l = 0; l < 10; l++) {
      rooms[3][l].room_number = l + 1;
      rooms[3][l].is_booked = 0; // available
      strcpy(rooms[3][l].hostel_name, "GH-1");
   }
}



//function to display all students of a hostel

void enquiry()
{
    system("CLS");

    //BH-1
    int bh1_booked;
    FILE *bh1_ptr = fopen("BH-1.dat", "r");
    if (bh1_ptr != NULL) {
        char buffer[255];
        while (fgets(buffer,sizeof(buffer), bh1_ptr) != NULL) {
            bh1_booked+1;
        }
		   fclose(bh1_ptr);
    }
    int bh1_available = 10 - bh1_booked;

    //BH-2
    int bh2_booked = 0;
    FILE *bh2_ptr = fopen("BH-2.dat", "r");
    if (bh2_ptr != NULL) {
        char buffer[255];
        while (fgets(buffer, 255, bh2_ptr) != NULL) {
            bh2_booked++;
        }
        fclose(bh2_ptr);
    }
    int bh2_available = 10 - bh2_booked;

    //BH-3
    int bh3_booked = 0;
    FILE *bh3_ptr = fopen("BH-3.dat", "r");
    if (bh3_ptr != NULL) {
        char buffer[255];
        while (fgets(buffer, 255, bh3_ptr) != NULL) {
            bh3_booked++;
        }
        fclose(bh3_ptr);
    }
    int bh3_available = 10 - bh3_booked;

    //GH-1
    int gh1_booked = 0;
    FILE *gh1_ptr = fopen("GH-1.dat", "r");
    if (gh1_ptr != NULL) {
        char buffer[255];
        while (fgets(buffer, 255, gh1_ptr) != NULL) {
            gh1_booked++;
        }
        fclose(gh1_ptr);
    }
    int gh1_available = 10 - gh1_booked;

    printf("\n\t\t\t\xB2\xB2\xB2 HOSTELS AVAILABILITY \xB2\xB2\xB2\xB2");
    printf("\n\n\tBH-1 => Booked Rooms: %d, Available Rooms: %d", bh1_booked, bh1_available);
    printf("\n\n\tBH-2 => Booked Rooms: %d, Available Rooms: %d", bh2_booked, bh2_available);
    printf("\n\n\tBH-3 => Booked Rooms: %d, Available Rooms: %d", bh3_booked, bh3_available);
    printf("\n\n\tGH-1 => Booked Rooms: %d, Available Rooms: %d", gh1_booked, gh1_available);

    int main_exit;
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d", &main_exit);

    if (main_exit == 1) {
        menu();
    } else if (main_exit == 0) {
        closer();
    } else {
        printf("\nInvalid input!\n");
        enquiry();
    }
}


void sorter()

{
    system("CLS");
    int choice=0,test=0;
    char hostel_name[10];

    printf("Enter the hostel name (BH-1, BH-2, BH-3, GH-1): ");
    scanf("%s", hostel_name);

    FILE *fp;
    fp = fopen("record.dat","r");

    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while(fscanf(fp,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid)!=EOF) {
        if(strcmp(add.hostel_name, hostel_name) == 0) {
            printf("%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
        }
    }

    fclose(fp);

    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1) {
        menu();
    } else if(main_exit==0) {
        closer();
    } else {
        printf("\nInvalid!\a");
        sorter();
    }
}


//new entry function

void new_entry()
{
    system("CLS");
    int choice;
    FILE *ptr,*hostel;

    ptr=fopen("record.dat","a+");
    hostel_id:

    printf("\t\t\t\xB2\xB2\xB2 ADD STUDENTS DATA  \xB2\xB2\xB2\xB2");
    printf("\nEnter your hostel_id:");
    scanf("%s",check.hostel_id);
    while(fscanf(ptr,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid)!=EOF)
    {
        if (strcmp(check.hostel_id,add.hostel_id)==0)
            {
             printf("Students hostel_id already in use!"); 
             goto hostel_id;
        }
    }

    strcpy(add.hostel_id,check.hostel_id);
    
    printf("\nEnter the name:");
    scanf("%s",&add.name);
    
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);

    printf("\nEnter the age:");
    scanf("%d",&add.age);

    printf("\nEnter the city:");
    scanf("%s",add.city);

    printf("\nEnter the phone number:");
    scanf("%s",&add.phone_no);

    printf("\n Enter your email id :");
    scanf("%s",add.mail_id);

    printf("\n Enter your Father's name:");
    scanf("%s",add.father_name);

    printf("\n Enter your Father's phone no.:");
    scanf("%s",&add.father_phone_no);

    printf("\n\n\n --------------Each Hostel contains 10 rooms--------------!!!!\n\n");

    printf("\n Enter your room no.:");
    scanf("%s",add.room_no);
    
    printf("\n Enter your hostel name from BH-1, BH-2, BH-3, GH-1 :");
    scanf("%s",add.hostel_name);
    
    printf("\n Enter Admission Date : ");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
	
    printf("\n Total Rent is:5000");
    
    printf("\n Amount of rent paid: ");
    scanf("%d" , &add.rent_paid);
    
    add.rent_rem = 5000 - add.rent_paid;
    
    printf("\n Your Remaining Rent Is : " , add.rent_rem);
    
    
	    fprintf(ptr,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);

    
	    //adding student hostel id. to hostels' list
    
	if(strcmp(add.hostel_name,"BH-1")==0)
         {
        hostel=fopen("BH-1.dat","a[11]");
        fprintf(hostel, "%s\n", add.hostel_id);
        fclose(hostel);
         }
    
  
      else if(strcmp(add.hostel_name,"BH-2")==0)
       {
        hostel=fopen("BH-2.dat","[11]");
        fprintf(hostel, "%s\n", add.hostel_id);
        fclose(hostel);
       }
    
      else if(strcmp(add.hostel_name,"BH-3")==0)
      {
        hostel=fopen("BH-3.dat","a[11]");
        fprintf(hostel, "%s\n", add.hostel_id);
        fclose(hostel);
     }
    
     else if(strcmp(add.hostel_name,"GH-1")==0)
     {
        hostel=fopen("GH-1.dat","[11]");
        fprintf(hostel, "%s\n",add.hostel_id);
        fclose(hostel);
     }
    
	
	fclose(ptr);
    
	printf("\nStudent Added Successfully!");
    add_invalid:
    
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)
      {
	     menu();
      }
	
	else if(main_exit==0)
      {
        closer();
      }
    
	else
        {
        printf("\nInvalid!\a");
          goto add_invalid;
        }
  }


//nsbfunction to view all students

void view_list()
{
    system("CLS");
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;

			printf("\n---------------------------------------------------------------------");
	  		printf("\nHOSTEL_ID NAME\t\tCity\t\tRENT PAID\tROOM NUMBER\n");
    		printf("\n----------------------------------------------------------------------");
    
    while(fscanf(view,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid)!=EOF)
       {
           printf("\n%s \t%s \t\t%s \t\t%d \t\t%s ",add.hostel_id,add.name,add.city,add.rent_paid,add.room_no);
           test++;
           printf("\n-----------+------------+-------------+----------------+------------");
       }
    fclose(view);

    if (test==0)
        {
            printf("\nNO RECORDS!!\n");
        }

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
        {
            menu();
        }
        else if(main_exit==0)
        {
            closer();
        }
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
//function to view all data of 1 student
void see()
{
    system("CLS");
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Hostel id.\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("\n\nEnter the hostel id:");
        scanf("%s",check.hostel_id);

        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid)!=EOF)
        {
            if(strcmp(add.hostel_id,check.hostel_id)==0)
            {
                test=1;

                printf("\nhostel_id : \t %s \n\n Name : %s \n\n DOB : %d/%d/%d  \n\n Age : %d  \n\n city : %s  \n\n Phone number : %s  \n\n E-Mail id : %s \n\n Father's name : %s \n\n Father's Phone No. : %s \n\n Room No : %s \n\n Hostel : %s \n\n Add.rent_paid : %d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
            }
        }
    }
  

    fclose(ptr);
     if(test!=1)
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto see_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
//function to update student info
void edit()
{
    system("CLS");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the hostel id of the student whose info you want to change:");
    scanf("%s",upd.hostel_id);
    while(fscanf(old,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid)!=EOF)

    {
        if (strcmp(add.hostel_id,upd.hostel_id)==0)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Phone\n\nEnter your choice(1 for room no. and 2 for phone ):");
            scanf("%d",&choice);

            if(choice==1)
                {printf("Enter the new room no.:");
                scanf("%s",upd.room_no);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, upd.room_no, add.hostel_name, add.rent_paid);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                    scanf("%d",&upd.phone_no);
                
                    fprintf(newrec,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, upd.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
                    printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
        printf("\nRecord not found!!\a\a\a");

    edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            edit();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }

}

//------------------------------------------------------------------------------------------------------------------
//cpfunction to delete records
void erase()
{
    system("CLS");
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the Hostel_id of student whose data you want to delete:");
    scanf("%s",rem.hostel_id);
    while (fscanf(old,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid)!=EOF)
   {
        if(strcmp(add.hostel_id,rem.hostel_id)!=0)
            fprintf(newrec,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);

        else
            {
              test++;
              printf("\nRecord deleted successfully!\n");
            }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
        printf("\nRecord not found!!\a\a\a");
    erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
}


//function displaying developer credits 1353functioncalls

void closer()
{
    system("CLS");
    printf("\n\n\n*THANK YOU*\n\n\n");
}

int pass(void)
{
   int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="Admin";
   char pass[10]="admin07";
    do
{
    system("cls");

    printf("\n  ***  LOGIN FORM  ***  \n\n\n");

    printf(" \n \n\n \t\t ENTER USERNAME:-");
    scanf("%s", &uname);

    printf(" \n\t\t ENTER PASSWORD:-");
    
	while(i<10)
    {
        pword[i]=getch();
        c=pword[i];
        if(c==13) break;
        else printf("*");
        i++;
    }
    pword[i]='\0';
    //char code=pword;
    i=0;
    //scanf("%s",&pword);
        if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
    {
    printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
    system("PAUSE");
    break;
    }
    else
    {
        printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
        system("PAUSE");
        a++;

        getch();

    }
}
    while(a<=2);
    if (a>2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();

        }
        system("cls");
}


