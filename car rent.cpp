void cin_fix()
{
               cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');

cout<<"invalid input ";
usleep(500000);
system("cls");
}
void notifications (registration *registryinfo,vehicle *vehicle_info)
{
    label3:
        system("cls");
    title_printer("today's over dues are :");

    // current date/time based on current system
   time_t now = time(0);

   tm *ltm = localtime(&now);
   if (registry_no==1)
   {
    body_printer("no data");
    usleep(4000000);
    main();
    return;
   }

  for (int i=0;i<registry_no;i++)
  {
    if ((registryinfo[i].local_date.seconds_elapsed+(registryinfo[i].duration*86400))<now && registryinfo[i].return_check==0)
    {
      registry_table_printer(registryinfo[i]);

    }
  }
  label4:
  cout<<"please enter the id of the receipt you wish to process or enter 0 if to return to the home screen :";
  int receipt_id;
  cin>>receipt_id;
  if (receipt_id==0)
    {
        main();
        return ;
    }

       if (receipt_id<registry_no)
      {
          if ((registryinfo[receipt_id-1].local_date.seconds_elapsed+(registryinfo[receipt_id-1].duration*86400))<now && registryinfo[receipt_id-1].return_check==0)
      {
          int overdue=((vehicle_info[(registryinfo[receipt_id-1].car_id-1)].price)*(now-(registryinfo[receipt_id-1].local_date.seconds_elapsed+(registryinfo[receipt_id-1].duration*86400))))/86400;
     cout <<"\n \t \t \t ------------------------------------------------------------------------------ \n";
    cout<<"\t \t \t ### overdue = "<<overdue;
    cout <<"\n \t \t \t ------------------------------------------------------------------------------ \n";
body_printer("press 1 to process this receipt, or press any other key to return to the  notifications window");
char user_choice;
user_choice=getch();
if (user_choice==1)
{
registryinfo[receipt_id-1].return_check=1;
title_printer("transaction completed");
body_printer ("press 1,to go to the notifications window or press any other key to return to the home screen");
char user_choice2;
user_choice2=getch();
switch(user_choice2)
{
case '1':
    goto label3;
    break;
default :
    main();
    return;
}

}
else
    main();
    return;
      }
      else
{
body_printer("no overdue");
body_printer ("press 1,to go to the notifications window or press any other key to return to the home screen");
char user_choice3;
user_choice3=getch();
switch(user_choice3)
{
case '1':
    goto label3;
    break;
default :
    main();
    return ;
}

}
      }
      else
      {
          body_printer("invalid input please try again");
          goto label4;
      }
      }

