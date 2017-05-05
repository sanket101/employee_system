#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include<windows.h>
#include<math.h>

/** List of Global Variable */
COORD coord = {0,0}; /// top-left corner of window

void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/** Main function started */

int main()
{
    char another, choice;
    float percent;
    int found,i,j,k,pos,count,maxhrs,sum,max,t,K,P,nofempP,exist,flag,pointer=0,counter=0;
    char temp[50],empname[50],projectname[100];
    char a[10][50];
    int b[10];

    /** structure that represent a employee */
    struct emp
    {
        char name[50]; ///name of employee
        char project[100];///project name
        int nofhrs;///number of hrs
        char address[200];///employee address
        char phone[15];///phone number
        float bs; /// basic salary of employee
    }temp1;
    struct emp e[10]; /// structure array creation
    struct emp l1[2]; /// structure array creation - list 1
    struct emp l2[2]; /// structure array creation- list 2
    struct emp l3[4]; /// structure array creation - list 3
    for(i=0;i<10;i++)
    {
        e[i].name[0]='\0';
        e[i].project[0]='\0';
        e[i].nofhrs=0;
        e[i].address[0]='\0';
        e[i].phone[0]='\0';
        e[i].bs=0;
    }
    for(i=0;i<2;i++)
    {
        l1[i].name[0]='\0';
        l1[i].project[0]='\0';
        l1[i].nofhrs=0;
        l1[i].address[0]='\0';
        l1[i].phone[0]='\0';
        l1[i].bs=0;
    }
    for(i=0;i<2;i++)
    {
        l2[i].name[0]='\0';
        l2[i].project[0]='\0';
        l2[i].nofhrs=0;
        l2[i].address[0]='\0';
        l2[i].phone[0]='\0';
        l2[i].bs=0;
    }
    for(i=0;i<4;i++)
    {
        l3[i].name[0]='\0';
        l3[i].project[0]='\0';
        l3[i].nofhrs=0;
        l3[i].address[0]='\0';
        l3[i].phone[0]='\0';
        l3[i].bs=0;
    }
    i=0;
    /// infinite loop continues untile the break statement encounter
    while(1)
    {
        system("cls"); ///clear the console window
        gotoxy(30,4); /// move the cursor to postion 30, 10 from top-left corner
        printf("a. Add Record"); /// option for add record
        gotoxy(30,6);
        printf("b. Number of active records"); /// option for showing existing record
        gotoxy(30,8);
        printf("c. Modify Records"); /// option for editing record
        gotoxy(30,10);
        printf("d. Delete Records"); /// option for deleting record
        gotoxy(30,12);
        printf("e. List full/empty"); /// exit from the program
        gotoxy(30,14);
        printf("f. Maximum number of hours"); /// exit from the program
        gotoxy(30,16);
        printf("g. Top most working employee");
        gotoxy(30,18);
        printf("h. Find Kth topmost project");
        gotoxy(30,20);
        printf("i. Least popular project");
        gotoxy(30,22);
        printf("j. List Union");
        gotoxy(30,24);
        printf("k. List Intersection");
        gotoxy(30,26);
        printf("l. List Difference");
        gotoxy(30,28);
        printf("m. Exit");
        gotoxy(30,30);
        printf("Your Choice: "); /// enter the choice 1, 2, 3, 4, 5
        fflush(stdin); /// flush the input buffer
        choice  = getche(); /// get the input from keyboard
        switch(choice)
        {
        case 'a':  /// if user press 1
            system("cls");
            another = 'y';
            i=pointer;
            while(another == 'y' && i<10)  /// if user want to add another record
            {
                exist=0;
                another = 'n';
                flag=0;
                while(flag==0)
                {
                    printf("\nEnter name: ");
                    gets(e[i].name);
                    for(j=0;j<strlen(e[i].name) && flag==0;j++)
                    {
                        if(e[i].name[j]>=48 && e[i].name[j]<=57)
                        {
                            flag=1;
                        }
                    }
                    if(flag==1)
                    {
                        printf("Enter valid name");
                        flag=0;
                    }
                    else
                    {
                        flag=1;
                    }
                }

                printf("\nEnter project name:");
                gets(e[i].project);
                for(j=0;j<i;j++)
                {
                    if(strcmp(e[j].name,e[i].name)==0 && strcmp(e[j].project,e[i].project)==0)
                    {
                        exist=1;
                    }
                }
                if(exist==1)
                {
                    printf("\nEntered record already exist");
                }
                else
                {
                    printf("\nEnter the number of hours spent on the project:");
                    scanf("%d",&e[i].nofhrs);
                    getchar();
                    printf("\nEnter the employee's address:");
                    gets(e[i].address);
                    flag=0;
                    while(flag==0)
                    {
                        printf("\nEnter mobile number: ");
                        gets(e[i].phone);
                        for(j=0;j<strlen(e[i].phone) && flag==0;j++)
                        {
                            if((e[i].phone[j]>=97 && e[i].phone[j]<=122)||(e[i].phone[j]>=65 && e[i].phone[j]<=90))
                            {
                                flag=1;
                            }
                        }
                        if(flag==1)
                        {
                            printf("Enter valid number");
                            flag=0;
                        }
                        else
                        {
                            flag=1;
                        }
                    }
                    printf("\nEnter basic salary: ");
                    scanf("%f",&e[i].bs);
                    printf("\nInformation successfully accepted");
                    i++;counter++;
                }
                printf("\nAdd another record(y/n):");
                another=getche();
                getchar();
            }
            if(i>=10)
            {
                found=0;
                for(i=0;i<10 && found==0;i++)
                {
                    if(e[i].bs==0)
                    {
                        found=1;
                        pos=i;
                    }
                }
                if(found==1)
                {
                    flag=0;
                    while(flag==0)
                    {
                        printf("\nEnter name: ");
                        gets(e[i].name);
                        for(j=0;j<strlen(e[i].name) && flag==0;j++)
                        {
                            if(e[i].name[j]>=48 && e[i].name[j]<=57)
                            {
                                flag=1;
                            }
                        }
                        if(flag==1)
                        {
                            printf("Enter valid name");
                            flag=0;
                        }
                        else
                        {
                            flag=1;
                        }
                    }
                    printf("\nEnter project name:");
                    gets(e[pos].project);
                    for(j=0;j<10 && j!=pos;j++)
                    {
                        if(strcmp(e[j].name,e[pos].name)==0 && strcmp(e[j].project,e[pos].project)==0)
                        {
                            exist=1;
                        }
                    }
                    if(exist==1)
                    {
                        printf("\nEntered record already exist");
                    }
                    else
                    {
                        printf("\nEnter the number of hours spent on the project:");
                        scanf("%d",&e[pos].nofhrs);
                        printf("\nEnter the employee's address:");
                        gets(e[pos].address);
                        printf("\nEnter phone number:");
                        gets(e[pos].phone);
                        printf("\nEnter basic salary: ");
                        scanf("%f",&e[pos].bs);
                        printf("\nInformation successfully accepted");counter++;
                    }

                }
                else
                {
                    printf("\nSorry,information cannot be accepted as storage capacity is full");
                }
                printf("\nPress n to return to home screen");
                another=getche();
            }
            pointer=i;
            if(another=='n')
            {
                break;
            }

        case 'b':
            system("cls");
            printf("Number of active records:%d\n",counter);
            if(counter==0)
            {
                printf("\nList is empty\n");
            }
            if(counter==10)
            {
                printf("list is full\n");
            }
            printf("Press B to return to home screen\n");
            another=getche();
            if(another=='b')
            {
                 break;
            }


        case 'c':  /// if user press 3 then do editing existing record
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the employee name to modify: ");
                gets(empname);
                printf("\nEnter project name:");
                gets(projectname);
                found=0;
                for(i=0;i<10 && found==0;i++)
                {
                    if(strcmp(e[i].name,empname) == 0 && strcmp(e[i].project,projectname)==0)  ///if entered name matches with that in file
                    {
                        found=1;
                        pos=i;
                    }
                }
                if(found==1)
                {
                        exist=0;
                        flag=0;
                        while(flag==0)
                        {
                            printf("\nEnter name: ");
                            gets(e[i].name);
                            for(j=0;j<strlen(e[i].name) && flag==0;j++)
                            {
                                if(e[i].name[j]>=48 && e[i].name[j]<=57)
                                {
                                    flag=1;
                                }
                            }
                            if(flag==1)
                            {
                                printf("Enter valid name");
                                flag=0;
                            }
                            else
                            {
                                flag=1;
                            }
                        }
                        printf("\nEnter project name:");
                        gets(e[i].project);
                        for(j=0;j<10 && j!=i;j++)
                        {
                            if(strcmp(e[j].name,e[i].name)==0 && strcmp(e[j].project,e[i].project)==0)
                            {
                                exist=1;
                            }
                        }
                        if(exist==1)
                        {
                            printf("\nEntered record already exist");
                        }
                        else
                        {
                            printf("\nEnter the number of hours spent on the project:");
                            scanf("%d",&e[i].nofhrs);
                            getchar();
                            printf("\nEnter the employee's address:");
                            gets(e[i].address);
                            printf("\nEnter phone number:");
                            gets(e[i].phone);
                            printf("\nEnter basic salary: ");
                            scanf("%f",&e[i].bs);
                            printf("\nInformation successfully modified");
                        }
                }
                 else
                {
                    printf("\nNo match found");
                }
                printf("\nModify another record(y/n)");
                another=getche();
            }
            break;
        case 'd':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of employee to delete: ");
                gets(empname);
                printf("\nEnter project name:");
                gets(projectname);
                found=0;
                for(i=0;i<10 && found==0;i++)
                {
                    if(strcmp(empname,e[i].name)==0 && strcmp(projectname,e[i].project)==0)
                    {
                        e[i].name[0]='\0';
                        e[i].project[0]='\0';
                        e[i].nofhrs=0;
                        e[i].address[0]='\0';
                        e[i].phone[0]='\0';
                        e[i].bs=0;
                        found=1;
                        printf("\nRecord deleted\n");counter--;
                    }
                }
                if(found==0)
                {
                    printf("No match found\n");
                }
                printf("Delete another record(y/n)");
                another=getche();
            }
            break;
        case 'e':
            system("cls");
            if(counter==0)
            {
                printf("List is empty\n");
            }
            else if(counter==10)
            {
                printf("List is full\n");
            }
            else{
                printf("List is partially filled\n");
            }
            printf("\nPress B to return to home screen");
            another=getche();
            if(another=='b')
            {
                 break;
            }
        case 'f':
            system("cls");
            another='y';
            while(another=='y')
            {
                printf("Enter the project name:\n");
                gets(projectname);
                maxhrs=0;
                for(i=0;i<10;i++)
                {
                    if(strcmp(projectname,e[i].project)==0)
                    {
                        if(maxhrs<e[i].nofhrs)
                        {
                            maxhrs=e[i].nofhrs;
                        }
                    }
                }
                printf("Highest number of hours spent:%d\n",maxhrs);
                printf("Name of employees spending maximum number of hours:\n");
                for(i=0;i<10;i++)
                {
                    if(maxhrs==e[i].nofhrs)
                    {
                        printf("%s",e[i].name);
                    }
                }
                printf("Check for another project(y/n):");
                another=getche();
                getchar();
            }
            break;
        case 'g':
            system("cls");
            maxhrs=0;
            sum=0;
            k=0;
            for(i=0;i<10;i++)
            {
                sum=e[i].nofhrs;
                for(j=0;j<10;j++)
                {
                    if(strcmp(e[i].name,e[j].name)==0 && i!=j)
                    {
                        sum=sum+e[j].nofhrs;
                    }
                }
                if(maxhrs<=sum)
                {
                    maxhrs=sum;
                    b[k]=i;
                    k++;
                }
            }
            printf("Name of employee spending maximum number of hours:\n");
            for(j=0;j<k;j++)
            {

                printf("%s  %d\n",e[b[j]].name,maxhrs);
            }
            printf("\nPress b to return to home screen");
            another=getche();
            if(another=='b')
            {
                 break;
            }
        case 'h':
            system("cls");
            k=1;
            strcpy(a[0],e[0].project);
            for(i=1;i<10;i++)
            {
                found=1;
                for(j=i-1;j>=0 && found==1;j--)
                {
                    if(strcmp(e[i].project,a[j])==0)
                    {
                        found=0;
                    }
                }
                if(found==1)
                {
                    strcpy(a[k],e[i].project);
                    k++;
                }
            }
            for(i=0;i<k;i++)
            {
                sum=0;
                count=0;
                for(j=0;j<10;j++)
                {
                    if(strcmp(a[i],e[j].project)==0)
                    {
                        sum+=e[j].nofhrs;
                        count++;
                    }
                }
                b[i]=sum/count;
            }
            for(i=0;i<k;i++)
            {
                for(j=0;j<k-1;j++)
                {
                    if(b[j]<b[j+1])
                    {
                        strcpy(temp,a[j]);
                        strcpy(a[j],a[j+1]);
                        strcpy(a[j+1],temp);
                        t=b[j];
                        b[j]=b[j+1];
                        b[j+1]=t;
                    }
                }
            }
            printf("Enter the value of K:\n");
            scanf("%d",&K);
            if(K>0 && K<=k)
            {
                printf("Kth projects are:\n");
                j=K-1;
                while(b[j]==b[K-1])
                {
                    printf("%s\n",a[j]);
                    j++;
                }
            }
            else
            {
                printf("Enter valid K\n");
            }
            printf("Press b to return to home screen");
            another=getche();
            if(another=='b')
            {
                break;
            }
        case 'i':
            system("cls");
            strcpy(a[0],e[0].project);
            k=1;
            for(i=1;i<10;i++)
            {
                found=1;
                for(j=i-1;j>=0 && found==1;j--)
                {
                    if(strcmp(e[i].project,a[j])==0)
                    {
                        found=0;
                    }
                }
                if(found==1)
                {
                    strcpy(a[k],e[i].project);
                    k++;
                }
            }
            printf("Enter K:\n");
            scanf("%d",&K);
            printf("Enter integer P:\n");
            scanf("%d",&P);
            printf("Name of project satisfying the given condition:\n");
            for(i=0;i<k;i++)
            {
                count=0;
                nofempP=0;
                for(j=0;j<10;j++)
                {
                    if(strcmp(a[i],e[j].project)==0)
                    {
                        count++;
                        if(e[j].nofhrs<P)
                        {
                            nofempP++;
                        }
                    }
                }
                percent=(1.0*K*count)/100;
                max=ceil(percent);
                if(nofempP>=max)
                {
                    printf("%s\n",a[i]);
                }
            }
            printf("Press b to return to home screen\n");
            another=getche();
            if(another=='b')
            {
                break;
            }
        case 'j':

             system("cls");
            another = 'y';i=0;

            while(another=='y' && i<2)  /// if user want to add records in list 1
            {
                another = 'n';
                printf("\nEnter name: ");
                gets(l1[i].name);
                printf("\nEnter project name:");
                gets(l1[i].project);
                printf("\nEnter the number of hours spent on the project:");
                scanf("%d",&l1[i].nofhrs);
                getchar();
                printf("\nEnter the employee's address:");
                gets(l1[i].address);
                printf("\nEnter phone number:");
                gets(l1[i].phone);
                printf("\nEnter basic salary: ");
                scanf("%f",&l1[i].bs);
                printf("\nInformation successfully accepted");
                i++;
                if(i<2)
                {
                    printf("\nAdd another %d record,press(y/n):",2-i);
                }
				if(i==2)
				{
					printf("  Enter n to Enter List 2\n");
				}
                 another=getche();
                 getchar();
            }


            another = 'y';i=0;

            while(another=='y' && i<2)  /// if user want to add records in list 2
            {   system("cls");
                another = 'n';
                printf("\nEnter name: ");
                gets(l2[i].name);
                printf("\nEnter project name:");
                gets(l2[i].project);
                printf("\nEnter the number of hours spent on the project:");
                scanf("%d",&l2[i].nofhrs);
                getchar();
                printf("\nEnter the employee's address:");
                gets(l2[i].address);
                printf("\nEnter phone number:");
                gets(l2[i].phone);
                printf("\nEnter basic salary: ");
                scanf("%f",&l2[i].bs);
                printf("\nInformation successfully accepted");
                i++;
                if(i<2)
                {
                    printf("\nAdd another %d record,press(y/n):",2-i);
                }
				if(i==2)
                {
                	printf("Press n to perform list union operation\n");
				}
                another=getche();
                getchar();
            }
			for(i=0;i<2;i++)
			{
				     strcpy(l3[i].name,l1[i].name);
					 strcpy(l3[i].project,l1[i].project);
					 l3[i].nofhrs=l1[i].nofhrs;
					 strcpy(l3[i].address,l1[i].address);
					 strcpy(l3[i].phone,l1[i].phone);
					 l3[i].bs=l1[i].bs;

			}
			int j=0,k=2;
            for(i=0;i<2;i++)
            {
                found=0;j=0;
            	while(j<2 && found==0)
            	{
            		if((strcmp(l1[j].name,l2[i].name)==0) && (strcmp(l1[j].project,l2[i].project)==0))
            		{
            			found=1;
					}
					else
					{
						found=0;
					}j++;
				}
				if(found==0)
				{
				     strcpy(l3[k].name,l2[i].name);
					 strcpy(l3[k].project,l2[i].project);
					 l3[k].nofhrs=l2[i].nofhrs;
					 strcpy(l3[k].address,l2[i].address);
					 strcpy(l3[k].phone,l2[i].phone);
					 l3[k].bs=l2[i].bs;
					  k++;
				   }
            }


            for(i=0;i<k-1;i++)
            {
                for(j=0;j<k-i-1;j++)
                {
                    if(strcmp(l3[j].name, l3[j+1].name)>0)
                    {
                        temp1=l3[j+1];
                        l3[j+1]=l3[j];
                        l3[j]=temp1;
                    }
                }
            }
            printf("\nIn lexicographical order: \n");i=0;
            for(i=0; i<k; i++)
            {
                printf("%s ",l3[i].name);
				printf("%s ",l3[i].project);
				printf("%d ",l3[i].nofhrs);
				printf("%s ",l3[i].address);
				printf("%s ",l3[i].phone);
				printf("%f\n",l3[i].bs);
            }
            printf("Press b to return to home screen\n");
            another=getche();
            if (another=='b')
            {
                break;
            }
        case 'k':
            system("cls");
            another = 'y';i=0;

            while(another=='y' && i<2)  /// if user want to add records in list 1
            {
                another = 'n';
                printf("\nEnter name: ");
                gets(l1[i].name);
                printf("\nEnter project name:");
                gets(l1[i].project);
                printf("\nEnter the number of hours spent on the project:");
                scanf("%d",&l1[i].nofhrs);
                getchar();
                printf("\nEnter the employee's address:");
                gets(l1[i].address);
                printf("\nEnter phone number:");
                gets(l1[i].phone);
                printf("\nEnter basic salary: ");
                scanf("%f",&l1[i].bs);
                printf("\nInformation successfully accepted");
                i++;
                printf("\nAdd another %d record,press(y/n):",2-i);
				if(i==2)
				{
					printf("  Enter n & Enter List 2\n");
				}
                 another=getche();
                 getchar();
            }


            another = 'y';i=0;

            while(another=='y' && i<2)  /// if user want to add records in list 2
            {   system("cls");
                another = 'n';
                printf("\nEnter name: ");
                gets(l2[i].name);
                printf("\nEnter project name:");
                gets(l2[i].project);
                printf("\nEnter the number of hours spent on the project:");
                scanf("%d",&l2[i].nofhrs);
                getchar();
                printf("\nEnter the employee's address:");
                gets(l2[i].address);
                printf("\nEnter phone number:");
                gets(l2[i].phone);
                printf("\nEnter basic salary: ");
                scanf("%f",&l2[i].bs);
                printf("\nInformation successfully accepted");
                i++;
                printf("\nAdd another %d record,press(y/n):",2-i);
				getchar();
				if(i==2)
                {
                	printf("  Enter n\n");
				}
                 another=getche();


            }

            j=0,k=0;
            for(i=0;i<2;i++)
            { found=0;j=0;
            	while(j<2 && found==0)
            	{
            		if((strcmp(l1[i].name,l2[j].name)==0) && (strcmp(l1[i].project,l2[j].project)==0))
            		{
            			found=1;
					}
					else
					{
						found=0;
					}j++;
				}
				if(found==1)
				{   if(l1[i].bs>l2[i].bs)
				   {
				     strcpy(l3[k].name,l1[i].name);
					 strcpy(l3[k].project,l1[i].project);
					 l3[k].nofhrs=l1[i].nofhrs;
					 strcpy(l3[k].address,l1[i].address);
					 strcpy(l3[k].phone,l1[i].phone);
					 l3[k].bs=l1[i].bs;
					  k++;
				   }
				   else
				   {
				   	strcpy(l3[k].name,l2[i].name);
					 strcpy(l3[k].project,l2[i].project);
					 l3[k].nofhrs=l2[i].nofhrs;
					 strcpy(l3[k].address,l2[i].address);
					 strcpy(l3[k].phone,l2[i].phone);
					 l3[k].bs=l2[i].bs;
					  k++;
				   }
				}
        	}
            i=0, j=0;
            for(i=0;i<k-1;i++)
            {
                for(j=0;j<k-i-1;j++)
                {
                    if(strcmp(l3[j].name, l3[j+1].name)>0)
                    {
                         temp1=l3[j+1];
                        l3[j+1]=l3[j];
                        l3[j]=temp1;
                    }
                }
            }
            printf("\nIn lexicographical order: \n");i=0;
            for(i=0; i<k; i++)
            {
                printf("%s ",l3[i].name);
				printf("%s ",l3[i].project);
				printf("%d ",l3[i].nofhrs);
				printf("%s ",l3[i].address);
				printf("%s ",l3[i].phone);
				printf("%f\n",l3[i].bs);
            }
            printf("Press b to return to home screen\n");
            another=getche();
            if (another=='b')
            {
                break;
            }
        case 'l':
            system("cls");
            another = 'y';i=0;

            while(another=='y' && i<2)  /// if user want to add records in list 1
            {
                another = 'n';
                printf("\nEnter name: ");
                gets(l1[i].name);
                printf("\nEnter project name:");
                gets(l1[i].project);
                printf("\nEnter the number of hours spent on the project:");
                scanf("%d",&l1[i].nofhrs);
                getchar();
                printf("\nEnter the employee's address:");
                gets(l1[i].address);
                printf("\nEnter phone number:");
                gets(l1[i].phone);
                printf("\nEnter basic salary: ");
                scanf("%f",&l1[i].bs);
                printf("\nInformation successfully accepted");
                i++;
                printf("\nAdd another %d record,press(y/n):",2-i);
				if(i==2)
				{
					printf("  Enter n & Enter List 2\n");
				}
                 another=getche();
                 getchar();
            }


            another = 'y';i=0;

            while(another=='y' && i<2)  /// if user want to add records in list 2
            {   system("cls");
                another = 'n';
                printf("\nEnter name: ");
                gets(l2[i].name);
                printf("\nEnter project name:");
                gets(l2[i].project);
                printf("\nEnter the number of hours spent on the project:");
                scanf("%d",&l2[i].nofhrs);
                getchar();
                printf("\nEnter the employee's address:");
                gets(l2[i].address);
                printf("\nEnter phone number:");
                gets(l2[i].phone);
                printf("\nEnter basic salary: ");
                scanf("%f",&l2[i].bs);
                printf("\nInformation successfully accepted");
                i++;
                printf("\nAdd another %d record,press(y/n):",2-i);getchar();
				if(i==2)
                {
                	printf("  Enter n\n");
				}
                 another=getche();


            }

            j=0,k=0;
            for(i=0;i<2;i++)
            { found=0;j=0;
            	while(j<2 && found==0)
            	{
            		if((strcmp(l1[i].name,l2[j].name)==0) && (strcmp(l1[i].project,l2[j].project)==0))
            		{
            			found=1;
					}
					else
					{
						found=0;
					}j++;
				}
				if(found==0)
				{
					 strcpy(l3[k].name,l1[i].name);
					 strcpy(l3[k].project,l1[i].project);
					 l3[k].nofhrs=l1[i].nofhrs;
					 strcpy(l3[k].address,l1[i].address);
					 strcpy(l3[k].phone,l1[i].phone);
					 l3[k].bs=l1[i].bs;
					  k++;

				}
        	}
            i=0, j=0;
            for(i=0;i<k-1;i++)
            {
                for(j=0;j<k-i-1;j++)
                {
                    if(strcmp(l3[j].name, l3[j+1].name)>0)
                    {
                        temp1=l3[j+1];
                        l3[j+1]=l3[j];
                        l3[j]=temp1;
                    }
                }
            }
            printf("\nIn lexicographical order: \n");i=0;
            for(i=0; i<k; i++)
            {
                printf("%s ",l3[i].name);
				printf("%s ",l3[i].project);
				printf("%d ",l3[i].nofhrs);
				printf("%s ",l3[i].address);
				printf("%s ",l3[i].phone);
				printf("%f\n",l3[i].bs);
            }
            printf("Press b to return to home screen\n");
            another=getche();
            if (another=='b')
            {
                break;
            }
        case 'm':
            exit(0); /// exit from the program
        }
    }
    return 0;
}
