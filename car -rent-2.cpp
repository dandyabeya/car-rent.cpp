using namespace std;
#include <iostream>
#include <cstdlib>
#include<conio.h>
#include<unistd.h>
#include<fstream>
#include<string>
#include<windows.h>
#include<limits>
#include<iomanip>
int vehicle_no=0,start=1,customer_no=0,registry_no=0,service_no=0,str;

//the following line is necessary for the
//  GetConsoleWindow() function to work!
//it basically says that you are running this
//  program on Windows 2000 or higher
#define _WIN32_WINNT 0x0500
COORD coord={0,0};void gotoxy(int x, int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
fstream file;

struct date
{
int year ;
int month ;
int day;
long int seconds_elapsed;
};


struct  service
{
 char *description=new char[str];
 float price;
 int id;

};
struct vehicle {
 char *name=new char[str];
 char *type=new char[str];
float price;
 char *plate_no=new char[str];
int availablity;
int id;

} ;

struct customer
{
 char *name=new char[str];
 int id;
long int phone_no;

};

struct registration
{
    int customer_id;
    int car_id;
   date local_date   ;
    int duration ;
    bool return_check;
    int receipt_id;
    float total_price ;

};

void customer_registration( );
registration registry(int customer_id,int vehicle_id,vehicle *vehicle_info);
void vehicle_registration();
int rent(customer *customer_info, vehicle *vehicle_info,registration *registry_info);
void customer_table_printer (customer customer_info);
void title_printer (string title);
void body_printer(string body);
void vehicle_table_printer (vehicle vehicle_info);
void registry_table_printer (registration registry_info);
void cin_fix();
void notifications (registration *registry_info,vehicle *vehicle_info);
main()
{
    if(start==1)
    {
        file.open("numbers.txt",ios::in);
        if (file.is_open())
        {
 file>>vehicle_no>>customer_no>>registry_no>> service_no;
 file.close();
        }
    }
    service *service_package;
    customer *customer_info;
    registration *registry_info;
    vehicle *vehicle_info;


service_package= new service [service_no+1];
customer_info=new customer [customer_no+1];
registry_info=new registration[registry_no+1];
vehicle_info=new vehicle [vehicle_no+1];


file.open("customer_info.txt",ios::in);
if (file.is_open())
{
   for (int i=1;i<=customer_no;i++ )
   {
       string id;
       string phone_no;
    file>>customer_info[i].name>>id>> phone_no;
    customer_info[i].id=stoi(id);
    customer_info[i].phone_no=stol(phone_no);

   }
   file.close();
}
file.open("vehicle_info.txt",ios::in);
if (file.is_open())
{

   for (int i=1;i<=vehicle_no;i++ )
   {
       string price,availablity,id;

    file>>vehicle_info[i].name>>vehicle_info[i].type>>price>>vehicle_info[i].plate_no>>availablity>>id;
   vehicle_info[i].price=stof(price);
    vehicle_info[i].availablity=stoi(availablity);
    vehicle_info[i].id=stoi(id);
   }
   file.close();
}
file.open("registry_info.txt");
if(file.is_open())
    {
for (int i=1;i<=registry_no;i++)
{
    string customer_id,car_id,duration,date_year,date_month,date_day,date_sec,return_check,receipt_id,total_price;
file>>customer_id>>car_id>>date_year>>date_month>>date_day>>date_sec>>duration>> return_check>>receipt_id>>total_price;
registry_info[i].customer_id=stoi(customer_id);
registry_info[i].car_id=stoi(car_id);
registry_info[i].local_date.year=stoi(date_year);
registry_info[i].local_date.month=stoi(date_month);
registry_info[i].local_date.day=stoi(date_day);
registry_info[i].local_date.seconds_elapsed=stol(date_sec);
registry_info[i].duration=stoi(duration);
registry_info[i].return_check=stoi(return_check);
registry_info[i].receipt_id=stoi(receipt_id);
registry_info[i].total_price=stof(total_price);
}
 file.close();
    }

    // Get the console handle
    HWND console = GetConsoleWindow();

    //MoveWindow(window_handle, x, y, width, height, redraw_window);
    MoveWindow(console, 300, 0, 1000, 800, TRUE);
    label:
    system ("cls");

    cout <<"\n\n\t\t\t#----------------------------------------------------------------------------- \n";
    cout <<"\t\t\t#                   car  rental service portal                               #\n"
         <<"\t\t\t#                                                                            #\n"
         <<"\t\t\t#----------------------------------------------------------------------------# \n";
    cout <<"\t\t\t#       press the corresponding number from  the following options:          #\n"
         <<"\t\t\t#----------------------------------------------------------------------------# \n";
    cout <<"\t\t\t#  1. view daily notifications                                               # \n"
         <<"\t\t\t#  2. register a new vehicle                                                 # \n"
         <<"\t\t\t#  3. register a new customer                                                #\n"
         <<"\t\t\t#  4. process a vehicle rent                                                 #\n"
         <<"\t\t\t#  5. add a service package                                                  #\n"
         <<"\t\t\t#  6.open receipt archive                                                    #\n"
         <<"\t\t\t#  7.open customer list archive                                              #\n"
         <<"\t\t\t#  8.open vehicle list archive                                               #\n"
         <<"\t\t\t#  9.to delete whole data                                                    #\n"
         <<"\t\t\t#  0.to exit                                                                 #\n"
         <<"\t\t\t#                                                                            #\n"
         <<"\t\t\t#///////////////////////////////////////////////////////////////////////////// \n" ;
 char user_choice;
 user_choice=getch();
 start=0;
 switch(user_choice)
 {
case '1':
notifications (registry_info,vehicle_info);
break;
case '2':
    vehicle_registration();
   main();
case '3':
    {
   customer_registration();


   main();
   break;}
case '4':
int status; //checks if the vehicle is reserved or rented
status=rent(customer_info,vehicle_info,registry_info);
switch (status)
{
    case 1 :
    vehicle_info[vehicle_no].availablity=0;
    case 2:
    vehicle_info[vehicle_no].availablity=2;
}
    main();
case '5':
    system("cls");
    label5:
    body_printer("enter the service description");
    cin>>service_package[service_no].description;
    if (cin.fail())
{
    cin_fix();
    goto label5;
}
label6:
    body_printer("enter the service percent reduction");
     cin>>service_package[service_no].price;
     if (cin.fail())
{
    cin_fix();
    goto label6;
}
    char flag;
    body_printer("press any key to return to the home screen");
    flag=getch();
     goto label;
    break;
case '6':

  {
      system("cls");
    title_printer("registry list");
    body_printer("choose a way to sort the list");
    body_printer("press 1,for newest  first");
    body_printer("press 2,for oldest first");
    char op;
    op=getch();
    switch(op)
    {
    case '1' :
{
system("cls");
 int count1=registry_no-1;
int count2=0;
    for(int i=1;i<=registry_no;i++)
    {
        for(int j=1;j<=registry_no;j++)
        {
            if ( registry_info[i].local_date.seconds_elapsed > registry_info[j].local_date.seconds_elapsed)
                count2++;
        }
        if (count2 >= count1)
        {

        registry_table_printer(registry_info[i]);
        count1--;
        }
    }

break; }


case '2':
    system("cls");
 int count1=registry_no-1;
int count2=0;
    for(int i=1;i<=registry_no;i++)
    {
        for(int j=1;j<=registry_no;j++)
        {
             if ( registry_info[i].local_date.seconds_elapsed < registry_info[j].local_date.seconds_elapsed)
                count2++;
        }
        if (count2 >= count1)
        {

        registry_table_printer(registry_info[i]);
        count1--;
        }
    }



    break; }
body_printer("press 1,to search");
  body_printer("press 2,to select registry");
  body_printer("press any key,to return to the starting screen");
char op1;
  op1=getch();
  switch (op1)
  {
  case '1':
  {
      system("cls");
body_printer("search with ");
body_printer(" 1, customer id ");
body_printer(" 2, vehicle id ");
char op2;
op2=getch();
system("cls");
label7:
body_printer("enter key word ");

switch(op2)
{
case '1':
    {
        int customer_id ;
        cin>>customer_id;
        if (cin.fail())
{
    cin_fix();
    goto label7;
}
        for (int i=1;i<=registry_no;i++)
        {
            if (registry_info[i].customer_id==customer_id)
                registry_table_printer(registry_info[i]);
        }
    break;}

case '2':
    {
        int vehicle_id ;
        cin>>vehicle_id;
        if (cin.fail())
{
    cin_fix();
    goto label7;
}
        for (int i=1;i<=registry_no;i++)
        {
            if (registry_info[i].car_id==vehicle_id)
                registry_table_printer(registry_info[i]);
        }
  break;  }
}

  }
case '2':
   {
       label8:
    body_printer("enter the corresponding id of the registry you want to select");
    body_printer(" or enter 0 to return to the starting screen");
    int id ;
    cin>>id;if (cin.fail())
{
    cin_fix();
    goto label8;
}
    if (id==0)
        main();
    system("cls");
body_printer("press 1,to delete this registry ");
body_printer("press any other key to return to the starting page");
   char op3;
   op3=getch();
   switch(op3)
   {

   case '1':
       {
    body_printer("deleted");
    usleep(500000);
    registry_no--;
    for (int i=id;i<=registry_no;i++)
    {
        registry_info[i]=registry_info[i+1];
    }
    file.open("registry_info.txt",ios::out);
for (int i=1;i<=registry_no;i++ )
         {

 file<<registry_info[i].customer_id<<" "<<registry_info[i].car_id<<" "<<registry_info[i].local_date.year<<" "<<registry_info[i].local_date.month<<" "<<registry_info[i].local_date.day<<" "<<registry_info[i].local_date.seconds_elapsed<<" "<<registry_info[i].duration<<" "<<registry_info[i].return_check<<" "<<registry_info[i].receipt_id<<" "<<registry_info[i].total_price;

         }
        file.close();
        main();
   }

default:
    main();
  }

break ;
 }

   default:
    main();
  }
  break;
  }
