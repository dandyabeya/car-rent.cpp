#include <iostream>
#include <cstdlib>
#include<conio.h>
#include<unistd.h>
#include<fstream>
#include<string>
#include<windows.h>
#include<limits>
#include<iomanip>
using namespace std;
int vehicle_no=0,start=1,customer_no=0,registry_no=0,service_no=0,str;

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

};
struct vehicle {
 char *name=new char[str];
 char *type=new char[str];
float price;
 char *plate_no=new char[str];
bool availablity;
int id=vehicle_no;

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
void customer_registration( )
{

char flag ='0';
    while (flag == '0')
    {

        system("cls");

        body_printer("enter the customer's name");
        string customer_name;
        cin >>customer_name;


        label1:
        body_printer("enter the customer's phone number");
        long int phone_number;
        cin>>phone_number;
        if (cin.fail())
        {
cin_fix();
goto label1;
      }
        int customer_id=customer_no;

customer_no++;
        file.open("customer_info.txt",ios::app);


            file<<customer_name <<" "<<customer_id<<" "<<phone_number<<" "<<endl;

        file.close();

         body_printer(" press 0 to continue registration ,or press any other key to return to the home screen ");
   flag=getch();
    }


    return;
}
float registry(registration *registry_info,int customer_id,int vehicle_id,vehicle *vehicle_info)
{
     // current date/time based on current system
   time_t now = time(0);

   tm *ltm = localtime(&now);
system("cls");
 registry_info[registry_no-1].customer_id=customer_id;
  registry_info[registry_no-1].car_id=vehicle_id;
    registry_info[registry_no-1].local_date.year=(1900 + ltm->tm_year);
    registry_info[registry_no-1].local_date.month=(1 + ltm->tm_mon);
    registry_info[registry_no-1].local_date.day=(ltm->tm_mday);
     registry_info[registry_no-1].local_date.seconds_elapsed=now;
    cout<<"enter the duration of the contract in days \n";
    cin>>registry_info[registry_no-1].duration;
     registry_info[registry_no-1].total_price=(registry_info[registry_no-1].duration*vehicle_info[vehicle_id-1].price);
    registry_info[registry_no-1].receipt_id=registry_no;
registry_no++;
return  registry_info[registry_no-1].total_price;

    }
void vehicle_registration(vehicle *vehicle_info)
{


    char flag ='0';
    while (flag == '0')
    {
        vehicle_no++;
        system("cls");
    body_printer("enter the vehicle's name ");

    char *word=new char[str];
  cin >>word;
  vehicle_info[vehicle_no-1].name=word;

body_printer("enter the vehicle's type (automobile,truck,motorbike,bus)");

 cin >>word;
  vehicle_info[vehicle_no-1].type=word;
 body_printer("enter the vehicle's price per day ");

    cin>>vehicle_info[vehicle_no-1].price;
    body_printer("enter the vehicle's plate no ");

   cin >>word;
  vehicle_info[vehicle_no-1].plate_no=word;
 body_printer("is the vehicle available for rent (enter 1 for yes,0 for no) ");
   cin>> vehicle_info[vehicle_no-1].availablity;

  vehicle_info[vehicle_no-1].id =vehicle_no;

    body_printer("press 0 to continue registration ,or press any other key to return to the home screen ");

   flag=getch();
    }

main();

return;
}
