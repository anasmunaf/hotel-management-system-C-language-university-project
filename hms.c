#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
void display();
void record();
void guest();
void bill();
void restaurant();
void staff();
void exitDisplay();
 // guest option
void guestDetails();
void guestCheckIn();
void guestCheckOut();
//guestDetails
void currentGuest();
void newGuest();
void deleteGuest();
//Bill option
void checkOutBill();
void billRecords();
void addStaff();
void searchStaff();
void showStaff();

void guestStaying();
void roomAvailable();
void guestleft();

struct Staff
{
	int staffId;
	char staffName[25];
	char gender[10];
	char position[25];
	int phoneNum;
	int age;
	int salary;
	int joinDate;
	char email[50];
	char adress[50];
};

int main()
{
	system("cls");
	printf(" -------------------------------------------------------------------------\n");
	printf("|                                                                    	 |\n");      
	printf("|                                                                    	 |\n");
	printf("|  O       O OOOOOO O        OOOOOOO    OOOOOO     OOO  OOO  OOOOOO   	 |\n");
	printf("|  O       O O      O       O          O       O   O  O O O  O        	 |\n");
	printf("|  O   O   O OOOO   O      O          O         O  O   O  O  OOOO    	 |\n");
	printf("|  O  O O  O O      O       O          O       O   O      O  O       	 |\n");
	printf("|  OOO   OOO OOOOOO OOOOOOO  OOOOOO0    OOOOOO     O      O  OOOOOO  	 |\n");
	printf("|                                                                    	 |\n");                       
	printf(" -------------------------------------------------------------------------\n");
 	printf("\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       --------------------------------        *\n");
	printf("\t\t*        WELCOME TO DHA HOTEL MANAGEMENT        *\n");
	printf("\t\t*       --------------------------------        *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*     Muhammad Anas | Md Usama | Haris Meer     *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*     CONTACT US:18-87454575552,112233445       *\n");
	printf("\t\t*************************************************\n\n\n");

	display();
	return 0;
}
void display()
{
	char num;
	printf("                                        ---------------------------------------\n");
	printf("                                             1 =>  Rooms And Records\n");
	printf("                                        ---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             2 =>  Guest \n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             3 =>  Customer Bill\n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             4 =>  Restaurant\n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             5 =>  Staff Members\n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             0 =>  Exit\n");
	printf("					---------------------------------------\n");
	fflush(stdin);
	printf("\nPRESS THE NUMBER FOR OPTIONS AVAILABLE.........\n");
	num=getch();
	system("cls");
	switch(num)
	{
		case 49:
		record();
		break;
		case 50:
		guest();
		break;
		case 51:
		bill();
		break;
		case 52:
		restaurant();
		break;
		case 53:
		staff();
		break;
		case 48:
		exitDisplay();
		default:
		display();
		break;
	}

}
void record()
{
	char num;
	printf("					---------------------------------------\n");
	printf("                                             1 =>  Availabile Rooms\n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             2 =>  Guest Staying\n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             3 =>  Guest Checked Out\n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             0 =>  Back\n");
	printf("					---------------------------------------\n");
	fflush(stdin);
	printf("\nPRESS THE NUMBER FOR OPTIONS AVAILABLE.........\n");
	num=getch();
	system("cls");
	switch(num)
	{
		case 49:
		roomAvailable();
		break;
		case 50:
		guestStaying();
		break;
		case 51:
		guestleft();
		break;
		case 48:
		display();
		default:
		record();
		break;
	}
}
void guestStaying()
{
	char str[300];
	int checkId=0,amount=0,payed=0,unpayed=0;
	FILE *guestList;
	guestList=fopen("check-in.txt","r");
	printf("Guest Id  Room          Stay        Date\n\n\n");
	while(fgets(str,300,guestList))
	{
		puts(str);
	}
	fclose(guestList);
	getch();
	system("cls");
	record();
}
void guestleft()
{
	char str[300];
	int checkId=0,amount=0,payed=0,unpayed=0;
	FILE *guestList;
	guestList=fopen("check-out.txt","r");
	printf("GuestID Room  Type Stay          Checked In                    Checked OUt\n\n\n");
	while(fgets(str,300,guestList))
	{
		puts(str);
	}
	fclose(guestList);
	getch();
	system("cls");
	record();	
}
void roomAvailable()
{
	int i=0,j=0,k=0;
	int single=0,doubleBed=0,deluxe=0,royal=0;
	int roomNum[10][10],roomBook[10][10];
	FILE *roomAvail;
	roomAvail=fopen("rooms.txt","r");

	for ( i = 0; i<10; ++i)
	{
		for ( j = 0; j<10; ++j)
		{
			fscanf(roomAvail,"%d %d",&roomNum[i][j],&roomBook[i][j]);
		}
	}

	for ( i = 0; i < 10; ++i)
	{
		for (j = 0; j < 4; ++j)
		{
			if (roomBook[i][j]==1)
				k++;
		}
	}
	single=k;
	k=0;
	for ( i = 0; i < 10; ++i)
	{
		for (j = 4; j < 7; ++j)
		{
			if (roomBook[i][j]==1)
				k++;
		}
	}
	doubleBed=k;

	k=0;

	for ( i = 0; i < 10; ++i)
	{
		for (j = 7; j < 9; ++j)
		{
			if (roomBook[i][j]==1)
				k++;
		}
	}

	deluxe=k;
	k=0;

	for (i = 0; i < 10; ++i)
	{
		if (roomBook[i][9]==1)
			k++;
	}
	royal=k;
	k=0;
	fclose(roomAvail);
	printf("Room Type             |                 Booked                  |            Empty\n\n\n");
	printf("Single Bed            |                    %d                   |               %d   \n\n\n",single,40-single );
	printf("Double Bed            |                    %d                   |               %d   \n\n\n",doubleBed,30-doubleBed );
	printf("Deluxe Room           |                    %d                   |               %d   \n\n\n",deluxe,20-deluxe );
	printf("Royal Stay            |                    %d                   |               %d   \n",royal,10-royal );

	getch();
	system("cls");
	record();

}
void guest()
{
	fflush(stdin);
	char num=0;
	printf("1. Guest Records\n"); 
	printf("2. Guest Check In \n");
	printf("3. Guest Check out\n");
	printf("0. Back\n");
	printf("\nPRESS THE NUMBER FOR EVERY OPTION.........\n");
	fflush(stdin);
	num=getch();
	system("cls");
	switch(num)
	{
		case 49:
		guestDetails();
		break;
		case 50:
		guestCheckIn();
		break;
		case 51:
		guestCheckOut();
		break;
		case 48:
		display();
		break;
		default:
		guest();
		break; 
	}
}
 // guest option
void guestDetails()
{
	fflush(stdin);
	char num=0;
	printf("1. Guest Details\n"); 
	printf("2. New Guest \n");
	printf("3. Delete Guest\n");
	printf("0. Back\n");
	printf("\nPRESS THE NUMBER FOR EVERY OPTION.........\n");
	fflush(stdin);
	num=getch();
	system("cls");
	switch(num)
	{
		case 49:
		currentGuest();
		break;
		case 50:
		newGuest();
		break;
		case 51:
		deleteGuest();
		break;
		case 48:
		display();
		break;
		default:
		currentGuest();
		break; 
	}
}

void guestCheckIn()
{
	fflush(stdin);
	int num=0,guestId=0,idCheck=0,roomType=0,stay=0,match=0,quantity=0;
	FILE *guestList,*roomList,*accounts;
	char repeat;
	int i=0,j=0,k=0,floor=0,number=0;
	int single=0,doubleBed=0,deluxe=0,royal=0;
	int roomNum[10][10],roomBook[10][10];
	time_t date;
	int amount=0,rent=0,payed=0,unpayed=0;
	guestList=fopen("guestDetails.txt","r");

	printf("Enter Guest ID: ");
	scanf("%d",&guestId);
	while(fscanf(guestList,"%d %*[^\n]",&idCheck)!=EOF)
	{
		if(idCheck==guestId)
			match=1;
	}
	fclose(guestList);
	if (match==0)
	{
		printf("Your Guest ID is not registered...\n");
	}
	if (match>0)
	{
		printf("Select the type of room:\n");
		printf("1.  Single Bed\n2.  Double Bed\n3.  Deluxe Room\n4.  Royal Stay\n");
		scanf("%d",&roomType);
		printf("Number of Rooms to Book:\n");
		scanf("%d",&quantity);
		printf("Number of booking days\n");
		scanf("%d",&stay);
		roomList=fopen("rooms.txt","r");
		for ( i = 0; i<10; ++i)
		{
			for ( j = 0; j<10; ++j)
			{
				fscanf(roomList,"%d %d",&roomNum[i][j],&roomBook[i][j]);
			}
		}

		for ( i = 0; i < 10; ++i)
		{
			for (j = 0; j < 4; ++j)
			{
				if (roomBook[i][j]==1)
					k++;
			}
		}
		single=k;
		k=0;
		for ( i = 0; i < 10; ++i)
		{
			for (j = 4; j < 7; ++j)
			{
				if (roomBook[i][j]==1)
					k++;
			}
		}
		doubleBed=k;

		k=0;

		for ( i = 0; i < 10; ++i)
		{
			for (j = 7; j < 9; ++j)
			{
				if (roomBook[i][j]==1)
					k++;
			}
		}

		deluxe=k;
		k=0;

		for (i = 0; i < 10; ++i)
		{
			if (roomBook[i][9]==1)
				k++;
		}
		royal=k;
		k=0;
		fclose(roomList);

		roomList=fopen("rooms.txt","w");
		guestList=fopen("check-in.txt","a+");
		accounts=fopen("bill.txt","a+");
		printf("Guest Id  Room  Type          Stay        Date\n\n\n");
		if(roomType==1)
		{
			if ((30-single)>=quantity)
			{
				for(k=1;k<=quantity;k++)
				{
					for(i=9;i>=0;i--)
					{
						for(j=0;j<4;j++)
						{
							if(roomBook[i][j]==0)
							{
								floor=i;
								number=j;
							}
						}
					}
					roomBook[floor][number]=1;
					time(&date);
					fprintf(guestList, "%d      %d      %d      %-5d %s",guestId,roomNum[floor][number],roomType,stay,ctime(&date));
					printf("%d      %d      single bed      %-5d %s",guestId,roomNum[floor][number],stay,ctime(&date));

				}
				for ( i = 0; i < 10; i++)
				{
					for(j=0;j<10;j++)
					{
						fprintf(roomList,"%-8d %d\n",roomNum[i][j],roomBook[i][j] );
					}
				}
				printf("Enter the Amount of Room per Night: ");
				scanf("%d",&rent);
				amount=rent*quantity*stay;
				amount+=(float)amount*0.13;
				printf("Amount of %d Single Bed Room of %d days + Taxes: %d\n",quantity,stay,amount);
				printf("Amount Customer Payed: ");
				scanf("%d",&payed);
				unpayed=amount-payed;
				printf("Remaining Amount: %d\n",unpayed);
				fprintf(accounts, "%d     %d     %d    %d\n",guestId,amount,payed,unpayed);
			}
			else
				printf("The Rooms are not Availabile\n");
		}		
		if(roomType==2)
		{
			if ((30-doubleBed)>=quantity)
			{
				for(k=1;k<=quantity;k++)
				{
					for(i=9;i>=0;i--)
					{
						for(j=4;j<7;j++)
						{
							if(roomBook[i][j]==0)
							{
								floor=i;
								number=j;
							}
						}
					}
					roomBook[floor][number]=1;
					time(&date);
					fprintf(guestList, "%d      %d      %d      %-5d %s",guestId,roomNum[floor][number],roomType,stay,ctime(&date));
					printf("%d      %d      Double       %-5d %s",guestId,roomNum[floor][number],stay,ctime(&date));

				}
				for ( i = 0; i < 10; i++)
				{
					for(j=0;j<10;j++)
					{
						fprintf(roomList,"%-8d %d\n",roomNum[i][j],roomBook[i][j] );
					}
				}
				printf("Enter the Amount of Room per Night: ");
				scanf("%d",&rent);
				amount=rent*quantity*stay;
				amount+=(float)amount*0.13;
				printf("Amount of %d Single Bed Room of %d days + Taxes: %d\n",quantity,stay,amount);
				printf("Amount Customer Payed: ");
				scanf("%d",&payed);
				unpayed=amount-payed;
				printf("Remaining Amount: %d\n",unpayed);
				fprintf(accounts, "%d     %d     %d    %d\n",guestId,amount,payed,unpayed);

			}
			else
				printf("The Rooms are not Availabile\n");			
		}		
		if(roomType==3)
		{
			if ((30-deluxe)>=quantity)
			{
				for(k=1;k<=quantity;k++)
				{
				for(i=9;i>=0;i--)
				{
					for(j=7;j<9;j++)
					{
						if(roomBook[i][j]==0)
						{
							floor=i;
							number=j;
						}
					}
				}
				roomBook[floor][number]=1;
					time(&date);
					fprintf(guestList, "%d      %d      %d      %-5d %s",guestId,roomNum[floor][number],roomType,stay,ctime(&date));
					printf("%d      %d       Deluxe      %-5d %s",guestId,roomNum[floor][number],stay,ctime(&date));
				}
				for ( i = 0; i < 10; i++)
				{
					for(j=0;j<10;j++)
					{
						fprintf(roomList,"%-8d %d\n",roomNum[i][j],roomBook[i][j] );
					}
				}
				printf("Enter the Amount of Room per Night: ");
				scanf("%d",&rent);
				amount=rent*quantity*stay;
				amount+=(float)amount*0.13;
				printf("Amount of %d Single Bed Room of %d days + Taxes: %d\n",quantity,stay,amount);
				printf("Amount Customer Payed: ");
				scanf("%d",&payed);
				unpayed=amount-payed;
				printf("Remaining Amount: %d\n",unpayed);
				fprintf(accounts, "%d     %d     %d    %d\n",guestId,amount,payed,unpayed);

			}
			else
				printf("The Rooms are not Availabile\n");			
		}		
		if(roomType==4)
		{
			if ((30-royal)>=quantity)
			{
				for(k=1;k<=quantity;k++)
				{
					for(i=9;i>=0;i--)
					{

						if(roomBook[i][9]==0)
						{
							floor=i;
							number=j;
						}
					
					}
					roomBook[floor][number]=1;
					time(&date);					
					fprintf(guestList, "%d      %d      %d      %-5d %s",guestId,roomNum[floor][number],roomType,stay,ctime(&date));
					printf("%d      %d      Royal      %-5d %s",guestId,roomNum[floor][number],stay,ctime(&date));
				}
				for ( i = 0; i < 10; i++)
				{
					for(j=0;j<10;j++)
					{
						fprintf(roomList,"%-8d %d\n",roomNum[i][j],roomBook[i][j] );
					}
				}
				printf("Enter the Amount of Room per Night: ");
				scanf("%d",&rent);
				amount=rent*quantity*stay;
				amount+=(float)amount*0.13;
				printf("Amount of %d Single Bed Room of %d days + Taxes: %d\n",quantity,stay,amount);
				printf("Amount Customer Payed: ");
				scanf("%d",&payed);
				unpayed=amount-payed;
				printf("Remaining Amount: %d\n",unpayed);
				fprintf(accounts, "%d     %d     %d    %d\n",guestId,amount,payed,unpayed);

			}
			else
				printf("The Rooms are not Availabile\n");			
		}	
		fclose(roomList);	
		fclose(guestList);
		fclose(accounts);
	}

	printf("Press 0 to go back: \n");
	printf("Press any key to Enter New detail:\n");
	fflush(stdin);
	repeat=getch();
	system("cls");
	switch(repeat)
	{
		case 48:
		guest();
		break;
		default:
		guestCheckIn();
		break;			
	}
}
void guestCheckOut()
{
	fflush(stdin);
	char repeat=0,date[50],str[200];
	int checkId=0,guestId=0,roomType=0,stay=0,room=0;
	int i=0,j=0,k=0,floor=0,num=0;
	int roomNum[10][10],roomBook[10][10];
	time_t now;
	int idCheck=0,match=0,match2=0;
	FILE *guestOut,*guestIn,*roomList,*guestList,*tempFile;
	guestList=fopen("guestDetails.txt","r");
	printf("Enter the Guest ID\n");
	scanf("%d",&guestId);
	printf("Guest-Id   Room   Stay   Check-in      Check-out\n\n");

	while(fscanf(guestList,"%d %*[^\n]",&idCheck)!=EOF)
	{
		if(idCheck==guestId)
			match=1;
	}
	fclose(guestList);
	if (match==0)
	{
		printf("Your Guest ID is not registered...\n");
	}
	if(match>0)
	{
		idCheck=0;
		guestIn=fopen("check-in.txt","r");
		while(fscanf(guestIn,"%d %*[^\n]",&idCheck)!=EOF)
		{
			if(idCheck==guestId)
				match2=1;
		}
		fclose(guestIn);
		if(match2==0)
			printf("Your Guest Id is has not checked In...\n");
		else
		{
			
			guestOut=fopen("check-out.txt","a+");
			guestIn=fopen("check-in.txt","r");
			roomList=fopen("rooms.txt","r");
			tempFile=fopen("backup.txt","w+");
			for ( i = 0; i<10; ++i)
			{
				for ( j = 0; j<10; ++j)
				{
					fscanf(roomList,"%d %d",&roomNum[i][j],&roomBook[i][j]);
				}
			}
			while((fscanf(guestIn,"%d %d %d %d",&checkId,&room,&roomType,&stay,date) && fgets(date,30,guestIn)) != 0)
			{

				if(guestId==checkId)
				{			
					time(&now);
					fprintf(guestOut,"%d    %d    %d    %d ",checkId,room,roomType,stay);
					fprintf(guestOut,"%s      %s",date,ctime(&now));
					printf("%d     %d     %d     %s     %s\n\n",checkId,room,stay,date,ctime(&now));
					floor=(room/100)-1;
					num=(room%100)-1;
					roomBook[floor][num]=0;	
				}
				else
				{
					fprintf(tempFile,"%d    %d    %d    %d ",checkId,room,roomType,stay);
					fprintf(tempFile,"%s\n",date);				
				}
			}

			rewind(tempFile);
			fclose(guestIn);
			fclose(guestOut);
			fclose(roomList);
			roomList=fopen("rooms.txt","w");
			for ( i = 0; i < 10; i++)
			{
				for(j=0;j<10;j++)
				{
					fprintf(roomList,"%-8d %d\n",roomNum[i][j],roomBook[i][j] );
				}
			}
			fclose(roomList);
			guestIn=fopen("check-in.txt","w");
			while(fgets(str,200,tempFile))
			{
				fprintf(guestIn,"%s",str);
			}
			fclose(guestIn);
			fclose(tempFile);
		}
	}		
	printf("Press 0 to go back: \n");
	printf("Press any key to Enter New detail:\n");
	fflush(stdin);
	repeat=getch();
	system("cls");
	switch(repeat)
	{
		case 48:
		guest();
		break;
		default:
		guestCheckOut();
		break;			
	}
}

//guest details
void currentGuest()
{
	char str[300];
	FILE *guestList;
	guestList=fopen("guestDetails.txt","r");
	printf("GuestID  Name                 	  Number		      Members\n\n\n");
	while(fgets(str,300,guestList))
	{
		puts(str);
	}
	getch();
	system("cls");
	guestDetails();
}	


void newGuest()
{
	fflush(stdin);
	char repeat;
	char guestName[100];
	int guestNumb=0,guestMember=0,guestId=1000;
	FILE *guestFile; 
	fflush(stdin);
	printf("Enter Guest Name: \n");
	gets(guestName);
	printf("Enter Guest Number: \n");
	scanf("%d",&guestNumb);
	printf("Enter Guest Members\n");
	scanf("%d",&guestMember);
	guestFile=fopen("guestDetails.txt","a+");
	while(fscanf(guestFile,"%d %*[^\n]",&guestId)!=EOF);
	guestId++;
	rewind(guestFile);
	fprintf(guestFile,"%d     %-25s      %-15d     %d\n",guestId,guestName,guestNumb,guestMember );
	fclose(guestFile);
	printf("Guest Id: %d\n",guestId);
	puts(guestName);
	printf("Guest Number: %d\n",guestNumb );
	printf("Guest Member: %d\n",guestMember );
	printf("Press 0 to go back: \n");
	printf("Press any key to Enter New detail:\n");
	fflush(stdin);
	repeat=getch();
	system("cls");
	switch(repeat)
	{
		case 48:
		guestDetails();
		break;
		default:
		newGuest();
		break;			
	}
}
void deleteGuest()
{
	fflush(stdin);
	char repeat,str[300];
	int guestId=0,checkId;
	int i=0,j=0;
	FILE *guestFile, *replaceFile;
	printf("Enter Guest ID to delete its records\n");
	scanf("%d",&guestId);
	guestFile=fopen("guestDetails.txt","r");
	replaceFile=fopen("backup.txt","w+");
	while(fscanf(guestFile,"%d %*[^\n]",&checkId)!=EOF)
	{
		i++;
		if(guestId==checkId)
			j=i;
	}
	i=1;
	rewind(guestFile);
	while(fgets(str,300,guestFile)!=NULL)
	{
		if(i!=j)
			fputs(str,replaceFile);
		i++;
	}
	rewind(replaceFile);
	fclose(guestFile);
	guestFile=fopen("guestDetails.txt","w");
	while(fgets(str,300,replaceFile)!=NULL)
	{
			fputs(str,guestFile);
	}	
	fclose(replaceFile);
	fclose(guestFile);
	printf("Press 0 to go back: \n");
	printf("Press any key to Enter New detail:\n");
	fflush(stdin);
	repeat=getch();
	system("cls");
		switch(repeat)
		{
			case 48:
			guestDetails();
			break;
			default:
			deleteGuest();
			break;			
		}
	
}

// display

void bill()
{
	char num;
	printf("					---------------------------------------\n");
	printf("                                             1 =>  Customer Check Out Bill \n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             2 =>  Records\n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             0 =>  Exit\n");
	printf("					---------------------------------------\n");
	printf("\n");
	printf("\nPRESS THE NUMBER FOR EVERY OPTION.........\n");
	num=getch();
	system("cls");
	switch(num)
	{

		case 49:
		checkOutBill();
		break;
		case 50:
		billRecords();
		break;
		case 48:
		display();
		break;
		default:
		bill();
		break;
	}
}
void checkOutBill()
{
	fflush(stdin);
	char repeat,str[200];
	int guestId=0,idCheck=0,match=0,match2=0;
	int checkId=0,amount=0,balnc=0,payed=0,unpayed=0;
	FILE *guestList,*guestIn,*accounts,*tempFile;
	printf("Enter the Guest ID\n");
	scanf("%d",&guestId);
	guestList=fopen("guestDetails.txt","r");
	while(fscanf(guestList,"%d %*[^\n]",&idCheck)!=EOF)
	{
		if(idCheck==guestId)
			match=1;
	}
	fclose(guestList);
	if (match==0)
	{
		printf("Your Guest ID is not registered...\n");
	}
	else
	{
		idCheck=0;
		guestIn=fopen("check-in.txt","r");
		while(fscanf(guestIn,"%d %*[^\n]",&idCheck)!=EOF)
		{
			if(idCheck==guestId)
				match2=1;
		}
		fclose(guestIn);
		if(match2==0)
			printf("Your Guest Id is has not checked In...\n");
		else
		{
			accounts=fopen("bill.txt","r");
			tempFile=fopen("backup.txt","w+");

			while(fscanf(accounts,"%d %d %d %d",&checkId,&amount,&payed,&unpayed) != EOF)
			{
				if(checkId==guestId)
				{
					if(unpayed>0)
					{
						printf("The Guest Id: %d\n", guestId);
						printf("The Total Amount was: %d\n", amount );
						printf("The payed Amount was: %d\n",payed );
						printf("The unpayed Amount is: %d\n",unpayed);
						printf("Enter the Amount to clear the balnance:\n");
						scanf("%d",&balnc);
						payed+=balnc;
						unpayed-=balnc;
						fprintf(tempFile, "%d     %d     %d    %d\n",guestId,amount,payed,unpayed);
					}
					else
					{
						printf("The Guest: %d has cleared all payments\n",guestId);
						fprintf(tempFile, "%d     %d     %d    %d\n",guestId,amount,payed,unpayed);
					}
				}
				else{
					fprintf(tempFile, "%d     %d     %d    %d\n",guestId,amount,payed,unpayed);
				}
			}
			fclose(accounts);
			rewind(tempFile);
			accounts=fopen("bill.txt","w");
			while(fgets(str,200,tempFile)!=NULL)
			{
				fputs(str,accounts);
			}
			fclose(accounts);

		}

	}
	printf("Press 0 to go back: \n");
	printf("Press any key to Enter New detail:\n");
	fflush(stdin);
	repeat=getchar();
	system("cls");
	switch(repeat)
	{
		case 48:
		bill();
		break;
		default:
		checkOutBill();
		break;			
	}

}
void billRecords()
{
	char str[200];
	int checkId=0,amount=0,payed=0,unpayed=0;
	FILE *accounts;
	accounts=fopen("bill.txt","r");
	printf("Guest ID           Amount             Payed            Remaining\n\n\n");
	while(fscanf(accounts,"%d %d %d %d",&checkId,&amount,&payed,&unpayed) != EOF)
	{
		printf("%d                 %d                 %d               %d\n\n",checkId,amount,payed,unpayed);	
	}
	getch();
	system("cls");
	bill();
}


void restaurant()
{

	FILE *menu;
	char str[1000];
	int qty,qty1,qty2,qty3,qty4=0,qty5=0;
	int choice = 1;
	int amount = 0;
	int a120 = 120, a150 = 150, a400 = 400, a500 = 500, a250 = 250, a300 = 300;
	int tamount = 0, t1amount = 0, t2amount = 0,t3amount = 0, t4amount = 0, t5amount = 0;
	int billID = 100;
	char name[20];
	system("cls");
	printf("                                        ---------------------------------------\n");
	printf("                                                    DHA RESTAURENT\n");
	printf("                                        ---------------------------------------\n\n");
	
	menu = fopen("menu.txt","r");
	
	
	while (fgets(str, 1000, menu) != NULL)
	{
        printf("%s", str);
	}
	printf("\n");
	fclose(menu);
	fflush(stdin);
	
	printf("\nEnter Customer Name: ");
	gets(name);
	
	while(choice!=0)
	{
		printf("\nEnter Item Number: ");
		scanf("%d",&choice);
		printf("Enter Qty: ");
		scanf("%d",&qty);
		if(choice == 1 ||choice == 3 ||choice == 29 ||choice == 30)
		{
			amount = a120 * qty;
			tamount = amount;
		}
		else if(choice == 2 ||choice == 4 ||choice == 5 || choice == 8 || choice == 11 || choice == 12 || choice == 13 || choice == 24 || choice == 25 || choice == 26 || choice == 28)
		{
			amount = (a150 * qty);
			t1amount = amount;
			qty1 = qty;
		}
		else if(choice == 6 ||choice == 7 ||choice == 27)
		{
			amount = (a250 * qty);
			t2amount = amount;
			qty2 = qty;
		}
		else if(choice == 9 ||choice == 14 ||choice == 15 || choice == 18 || choice == 19)
		{
			amount = (a400 * qty);
			t3amount = amount;
			qty3 = qty;
		}
		else if(choice == 10 ||choice == 22 ||choice == 23)
		{
			amount = (a500 *qty);
			t4amount = amount;
			qty4 = qty;
		}
		else if(choice == 20 ||choice == 17 || choice == 20 || choice == 21)
		{
			amount = (a300 * qty);
			t5amount = amount;
			qty5 = qty;
		}
	}
	amount = tamount + t1amount + t2amount + t3amount + t4amount + t5amount;
	
	printf("\nPress 1 to Print a bill & 0 to cancel: ");
	scanf("%d",&choice);
	if(choice == 1)
	{
		system("cls");
		printf("\n                          DHA RESTAURENT                                   ");
		printf("\n                  Khayban e Tufail DHA Phase VII                           "); 
		printf("\n                       Telp:(000)-123456789                                ");
		printf("\n                                                                           ");
		printf("\n                                                                           "); 
		printf("\nNo.Bill      : %d                       Date      :                        ",billID);  
		printf("\nCustomer Name: %s                       Customer ID :                      ",name);
		printf("\n-------------------------------------------------------------------------  ");
		printf("\nOrder                  Qty                Price             Total          ");
		printf("\n-------------------------------------------------------------------------  ");
		printf("\n                      %d                   %d               %d            ",qty,a120,tamount);         
		printf("\n                      %d                   %d               %d            ",qty1,a150,t1amount);         
		printf("\n                      %d                   %d               %d            ",qty2,a250,t2amount);         
		printf("\n                      %d                   %d               %d            ",qty3,a400,t3amount);         
		printf("\n                      %d                   %d               %d            ",qty4,a500,t4amount);         
		printf("\n                      %d                   %d               %d            ",qty5,a300,t5amount);         
		printf("\n                                                                           ");         
		printf("\n                                                                           ");         
		printf("\n-------------------------------------------------------------------------- "); 
		printf("\n					              SUB TOTAL: %d                   ",amount    );   
		printf("\n-------------------------------------------------------------------------- ");
		printf("\n                    **Thanks for Coming**                               \n ");  
	}
	
	
	else if(choice == 0)
	{
		printf("Enter 0 to go back");
		display();
	}
}

void staff()
{
	int num = 0;
	printf(".\n\n\n\n\n");
	printf("                                        ---------------------------------------\n");
	printf("                                             1 =>  Add New Employee\n");
	printf("                                        ---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             2 =>  Search Employee Detail \n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             3 =>  Show Employee List\n");
	printf("					---------------------------------------\n\n");
	printf("					---------------------------------------\n");
	printf("                                             0 =>  Back\n");
	printf("					---------------------------------------\n\n");
	
	printf("\nPRESS THE NUMBER FOR ANY OPTION.........\n");
	scanf("%d",&num);
	system("cls");
	switch(num)
	{
		case 1:
		addStaff();
		break;
		case 2:
		searchStaff();
		break;
		case 3:
		showStaff();
		break;
		case 0:
		display();
		break;
	}
}
void addStaff()
{
	struct Staff t;
	FILE *addStaff;
	FILE *record;
	int num = 0;
	int staffId = 1000;
	fflush(stdin);
	
	addStaff = fopen("telephon.txt", "a");
	
	printf(".\n\n");
	printf("                                        ---------------------------------------\n");
	printf("                                                   Add New Employee\n");
	printf("                                        ---------------------------------------\n\n");
	
	printf("\nName: ");
	scanf("%s",t.staffName);
	printf("\nAge: ");
	scanf("%d", &t.age);
	printf("\nGender: ");
	scanf("%s", t.gender);
	printf("\nPhone Number: ");
	scanf("%d", &t.phoneNum);
	printf("\nEmail Address: ");
	scanf("%s", t.email);
	printf("\nAddress: ");
	scanf("%s", t.adress);
	printf("\nPosition: ");
	scanf("%s", t.position);
	printf("\nJoin Date (dd:mm:yyyy): ");
	scanf("%d", &t.joinDate);
	printf("\nSalary: ");
	scanf("%d", &t.salary);
	fwrite(&t,sizeof(t),1,addStaff);
    fflush(stdin);
	
	
	//while(fscanf(addStaff,"%d %*[^\n]",&staffId)!=EOF);
	//staffId++;
	//rewind(addStaff);
	record = fopen("record.txt", "a");
	
	fprintf(record,"\n%d %s\t %d\t %s\t %d\t %s\t %s\t %s\t %d\t %d\t",staffId, t.staffName, t.age, t.gender, t.phoneNum, t.email, t.adress, t.position, t.joinDate, t.salary);
	
	fclose(record);
	fclose(addStaff);
	fflush(stdin);
	printf("\nEmplyee Added Successfully. Press 0 for back and 1 for new Employee\n");
	scanf("%d",&num);
	
	system("cls");
	
	switch(num)
	{
		case 0:
		staff();
		break;
	}
}
void searchStaff()
{
	struct Staff t;
	FILE *fp;
	int num = 0;
	char sname[10];
	int flag = 1;
	char str[1000];
	
	printf("                                        ---------------------------------------\n");
	printf("                                                   Search Employee Detail\n");
	printf("                                        ---------------------------------------\n\n");
	fp = fopen("telephon.txt", "r");
	        
    printf("Enter Employee Name to Search Profile: ");
    scanf("%s",sname);
		
    while(fread(&t,sizeof(t),1,fp))
    {
        if(strcmp(sname,t.staffName)==0)
        {
            printf("\nName: %s\nAge: %d\nGender: %s\nPhone Number: %d\nEmail: %s\nAddress: %s\nPosition: %s\nJoin Date: %d\nSalary: %d\n", t.staffName, t.age, t.gender, t.phoneNum, t.email, t.adress, t.position, t.joinDate, t.salary);
			printf("\nPress 0 to Go Back");
            getch();
            break;
        }
    }
        fclose(fp);
       
		scanf("%d",&num);
		system("cls");
		switch(num)
		{
			case 0:
			staff();
			break;
		}
}

void showStaff()
{
	 FILE *fp;
    char str[1000];
    int i = 0;
	int num = 0;
	
	printf("                                        ---------------------------------------\n");
	printf("                                                        Employee List\n");
	printf("                                        ---------------------------------------\n\n");
    fp = fopen("record.txt", "r");
	
	printf("Staff_ID   Name     Age   Gender   Phone Number     Email Adress     Position     Joining Date     Salary\n");
	
    while (fgets(str, 1000, fp) != NULL)
	{
        printf("%s", str);
	}
    fclose(fp);
	
	printf("\n\nEnter Any key to Exit and 0 for Back..");
	scanf("%d",&num);
	system("cls");
	
    switch(num)
	{
		case 0:
		staff();
		break;
	}
	
}

void exitDisplay()
{
	system("cls");
	printf(" -------------------------------------------------------------------------\n");
	printf("|                                                                    	 |\n");      
	printf("|                                                                    	 |\n");
	printf("|  OOOOOOO O   O  OOOOO  OO   O  O   O  O   O      OOO      O     O   	 |\n");
	printf("|     O    O   O  O   O  O O  O  O  O    O O     O     O    O     O      |\n");
	printf("|     O    OOOOO  OOOOO  O  O O  O O      O    O         O  O     O    	 |\n");
	printf("|     O    O   O  O   O  O    O  O  O     O      O     O    O     O      |\n");
	printf("|     O    O   O  O   O  O    O  O   O    O        OOO      OOOOOOO   	 |\n");
	printf("|                                                                    	 |\n");                       
	printf(" -------------------------------------------------------------------------\n");
 	printf("\t\t*************************************************\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       --------------------------------        *\n");
	printf("\t\t*              DHA HOTEL MANAGEMENT             *\n");
	printf("\t\t*       --------------------------------        *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*     Muhammad Anas | Md Usama | Haris Meer     *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*     CONTACT US:18-87454575552,112233445       *\n");
	printf("\t\t*************************************************\n\n\n");
	getch();
	exit(1);
}
