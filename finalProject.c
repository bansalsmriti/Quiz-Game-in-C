#define _GNU_SOURCE
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#define QNO 30
#define totques 10
#define size 200

void show_record();
void reset_score();
void help();
void edit_score(float , char []);
void asked(char option[size], const char option1[size], const char option2[size],
	const char option3[size], const char option4[size],const char correct[size], const char category[size],FILE * fp,float *);
void Display();

int main()
    {
     int countr,r,r1,count,i,n,level,flag=0;
     float score=0.0;
     char choice,result;
     char playername[20];
     char text[size],option1[size], option2[size], option3[size], option4[size], option[size], correct[size], category[size];
	 char empty[256][256];
	int j,k;
	int arr[QNO],x,loc;
	time_t t;
	char line[256];
     mainhome:
     system("cls");
     printf("\t\t\tC PROGRAM QUIZ GAME\n");
     printf("\n\t\t________________________________________");

     printf("\n\t\t\t   WELCOME ");
     printf("\n\t\t\t      to ");
     printf("\n\t\t\t   THE GAME ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\t\t > Press S to start the game");
     printf("\n\t\t > Press V to view the highest score  ");
     printf("\n\t\t > Press R to reset score");
     printf("\n\t\t > press H for help            ");
     printf("\n\t\t > press Q to quit             ");
     printf("\n\t\t________________________________________\n\n");
     choice=toupper(getch());
     if (choice=='V')
	{
	show_record();
	goto mainhome;
	}
     else if (choice=='H')
	{
	help();getch();
	goto mainhome;
	}
	else if (choice=='R')
	{reset_score();
	getch();
	goto mainhome;}
	else if (choice=='Q')
	exit(1);
    else if(choice=='S')
    {
     system("cls");
     score=0.0;
     if(flag==0)
     {
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\tResister your name: ");
	fflush(stdin);
     gets(playername);
     flag=1;
	 }
	system("cls");
    
    printf("\n ------------------  Welcome %s to C Program Quiz Game --------------------------",playername);
    printf("\n\n Rules of the game are: ");
    printf("\n -------------------------------------------------------------------------");
    printf("\n >> You will be asked a total of 10 questions. For each right answer, you will be awarded 4 marks!");
    printf("\n "  );  
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the right option.");
    printf("\n    ");
    printf("\n >> No negative marking for wrong answers!");
    printf("\n\n\t!!!!!!!!!!!!! ALL THE BEST !!!!!!!!!!!!!");
    printf("\n\n\n Which level do you want to play?\n");
    printf("\n1. Easy");
    printf("\n2. Medium");
    printf("\n3. Hard");
    printf("\n\n Press 1/2/3  to start the game!\n");
    printf("\n Press any other key to return to the main menu!");
    scanf("%d",&level);
    if (level==1)
		{
		    goto home1;
        }
    else if(level==2)
    {
    	goto home2;
	}
	else if(level==3)
	{
		goto home3;
	}
	else
		{
			system("cls");
        goto mainhome;
       }
       
     home1:
     system("cls");
     count=0;
     FILE * fp;
    FILE * output;
    fp = fopen("Quiz1.txt","r");
    output = fopen("NewText.txt","w");
    if(fp == NULL)
    {
    	printf("\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n");
	}
	if(output == NULL)
	{
		printf("\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n");
	}
	k = 0;
	
	for (i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}

	for (j = 0; j < totques; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;

		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
		fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)
		{
			fgets(line,sizeof(line),fp);	
			if(i==1)
			{
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  fprintf(output,"Q%d) %s",j+1,line);
			  	
			}
			
				if(i==2)
				{
					fputs(line,output);	
				}
				
				if(i == 3)
			strncpy(option1,line,30);
			
				if(i == 4)
			strncpy(option2,line,30);
			
				if(i == 5)
			strncpy(option3,line,30);
			
				if(i == 6)
			strncpy(option4,line,30);	
	 	
			if (i >1&&i<=7)
			{
				printf("%s",line);
				
			}
			if (i == 8)
			strncpy(correct,line,30);	
				
			if (i == 9)
			strncpy(category,line,30);
		}

		
		asked(option, option1, option2, option3, option4, correct, category,output,&score);
		
		if(j!=9)
		{
			
		if (arr[loc] + 10 < arr[3 * (j + 1)])
		  {  
			for (i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
			fgets(empty[k],sizeof(empty[k]),fp);
				k++;
			}
		  }
		}
		
		
		system("cls");
	}
	
	fprintf(output," \n\n You got total %0.2f out of 40 \n",score);
	fclose(fp);
	fclose(output);
	
	printf("\n\n\n\n\n\nYou scored %0.2f out of 40\n",score);
	printf("\n\n\n\n\nEnter R to see the result\n");
	printf("\nPress any key to go the main menu!  ");
	fflush(stdin);
	scanf("%c",&result);

	if(result=='r' || result=='R')
	{
		system("cls");
		output = fopen("Newtext.txt","r");
		
		while(fgets(line,sizeof(line),output))
		{
			printf(" %s",line);
		}

		fclose(output);
	system("pause");
	}
	
	edit_score(score,playername);
		goto mainhome;
		system("cls");
		
		
		
		     home2:
     system("cls");
     count=0;
    
    fp = fopen("Quiz2.txt","r");
    output = fopen("NewText.txt","w");
    if(fp == NULL)
    {
    	printf("\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n");
	}
	if(output == NULL)
	{
		printf("\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n");
	}


	k = 0;
	
	for (i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}

	for (j = 0; j < totques; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;

		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
		fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)
		{
			fgets(line,sizeof(line),fp);	
			if(i==1)
			{
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  fprintf(output,"Q%d) %s",j+1,line);
			  	
			}
			
				if(i==2)
				{
					fputs(line,output);	
				}
				
				if(i == 3)
			strncpy(option1,line,30);
			
				if(i == 4)
			strncpy(option2,line,30);
			
				if(i == 5)
			strncpy(option3,line,30);
			
				if(i == 6)
			strncpy(option4,line,30);	
	 	
			if (i >1&&i<=7)
			{
				printf("%s",line);
				
			}
			if (i == 8)
			strncpy(correct,line,30);	
				
			if (i == 9)
			strncpy(category,line,30);
		}

		
		asked(option, option1, option2, option3, option4, correct, category,output,&score);
		
		if(j!=9)
		{
			
		if (arr[loc] + 10 < arr[3 * (j + 1)])
		  {  
			for (i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
			fgets(empty[k],sizeof(empty[k]),fp);
				k++;
			}
		  }
		}
		
		
		system("cls");
	}
	fprintf(output," \n\n You got total %0.2f out of 40 \n",score);
	fclose(fp);
	fclose(output);

	printf("\n\n\n\n\n\nYou scored %0.2f out of 40\n",score);
	printf("\n\n\n\n\nEnter R to see the result\n");
	printf("\nPress any key to go the main menu!  ");
	fflush(stdin);
	scanf("%c",&result);

	if(result=='r' || result=='R')
	{
		system("cls");
		output = fopen("Newtext.txt","r");
		
		while(fgets(line,sizeof(line),output))
		{
			printf(" %s",line);
		}

		fclose(output);
	system("pause");
	}
	
	
	edit_score(score,playername);
		goto mainhome;
		system("cls");
		
		
		
		     home3:
     system("cls");
     count=0;
     
    fp = fopen("Quiz3.txt","r");
    output = fopen("NewText.txt","w");
    if(fp == NULL)
    {
    	printf("\n\n\n \t\t\t Quiz File Can't Be OPENED \t\t\t \n\n\n");
	}
	if(output == NULL)
	{
		printf("\n\n\n \t\t\t NewText File Can't Be CREATED \t\t\t \n\n\n");
	}


	k = 0;
	
	for (i = 0; i < 30; i++)
	{
		arr[i] = 10 * i + 1;
	}

	for (j = 0; j < totques; j++)
	{
		srand((unsigned)time(&t));
		x = rand() % 3;
		loc = (3 * j) + x;

		for (i = arr[3 * j]; i < arr[loc]; i++)
		{
		fgets(empty[k],sizeof(empty[k]),fp);
			k++;
		}

		for (i = 1; i <= 10; i++)
		{
			fgets(line,sizeof(line),fp);	
			if(i==1)
			{
			  printf("\n\n\n\n\n\nQ%d) %s",j+1,line);
			  fprintf(output,"Q%d) %s",j+1,line);
			  	
			}
			
				if(i==2)
				{
					fputs(line,output);	
				}
				
				if(i == 3)
			strncpy(option1,line,30);
			
				if(i == 4)
			strncpy(option2,line,30);
			
				if(i == 5)
			strncpy(option3,line,30);
			
				if(i == 6)
			strncpy(option4,line,30);	
	 	
			if (i >1&&i<=7)
			{
				printf("%s",line);
				
			}
			if (i == 8)
			strncpy(correct,line,30);	
				
			if (i == 9)
			strncpy(category,line,30);
		}

		
		asked(option, option1, option2, option3, option4, correct, category,output,&score);
		
		if(j!=9)
		{
			
		if (arr[loc] + 10 < arr[3 * (j + 1)])
		  {  
			for (i = arr[loc] + 10; i < arr[3 * (j + 1)]; i++)
			{
			fgets(empty[k],sizeof(empty[k]),fp);
				k++;
			}
		  }
		}
		
		
		system("cls");
	}
	fprintf(output," \n\n You got total %0.2f out of 40 \n",score);
	fclose(fp);
	fclose(output);

	printf("\n\n\n\n\n\nYou scored %0.2f out of 40\n",score);
	printf("\n\n\n\n\nEnter R to see the result\n");
	printf("\nPress any key to go the main menu!  ");
	fflush(stdin);
	scanf("%c",&result);

	if(result=='r' || result=='R')
	{
		system("cls");
		output = fopen("Newtext.txt","r");
		
		while(fgets(line,sizeof(line),output))
		{
			printf(" %s",line);
		}

		fclose(output);
	system("pause");
	}


		edit_score(score,playername);
		goto mainhome;
		system("cls");
		
}
	/*score:
    system("cls");

	score=countr*100000;
	if(score>0.00 && score<1000000)
	{
	   printf("\n\n\t\t**************** CONGRATULATIONS *****************");
	     printf("\n\t You won $%.2f",score);goto go;}

	 else if(score==1000000.00)
	{
	    printf("\n\n\n \t\t**************** CONGRATULATIONS ****************");
	    printf("\n\t\t\t\t YOU ARE A MILLIONAIRE!!!!!!!!!");
	    printf("\n\t\t You won $%.2f",score);
	    printf("\t\t Thank You!!");
	}
	 else
{
	 printf("\n\n\t******** SORRY YOU DIDN'T WIN ANY CASH ********");
	    printf("\n\t\t Thanks for your participation");
	    printf("\n\t\t TRY AGAIN");goto go;}

	go:
	puts("\n\n Press Y if you want to play next game");
	puts(" Press any key if you want to go main menu");
	if (toupper(getch())=='Y')
		goto home;
	else
		{
		edit_score(score,playername);
		goto mainhome;
		}*/
	}

void asked(char option[size], const char option1[size], const char option2[size], const char option3[size], const char option4[size],
	 const char correct[size], const char category[size],FILE * fp,float *score)
	{
		printf("Your Option : ");
		scanf("%str",&option[0]);
		option[1] = '\0';
		strupr(option);
		
			char correctanswer[size];
			char wronganswer[size];
			
			fprintf(fp,"%s \n",category);
			
		if (option[0] == correct[0])
		{
			if (option[0] == option1[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option1);
			if (option[0] == option2[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option2);
			if (option[0] == option3[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option3);
			if (option[0] == option4[0])
				fprintf(fp," \nYou entered correct answer : %s  \n ", option4);
				
				*score += 4;
				
			fprintf(fp," \n You are awarded 4 mark for this correct answer \n ");
		}
		else
		{
		
			if (correct[0] == option1[0])
				strncpy(correctanswer, option1,24);
			if (correct[0] == option2[0])
				strncpy(correctanswer, option2,24);
			if (correct[0] == option3[0])
				strncpy(correctanswer, option3,24);
			if (correct[0] == option4[0])
				strncpy(correctanswer, option4,24);
			
			correctanswer[24] = '\0';
		
			if (option[0] == option1[0])
				strncpy(wronganswer, option1,24);
			if (option[0] == option2[0])
				strncpy(wronganswer, option2,24);
			if (option[0] == option3[0])
				strncpy(wronganswer, option3,24);
			if (option[0] == option4[0])
				strncpy(wronganswer, option4,24);

			wronganswer[24] = '\0';
			
			fprintf(fp," You entered     : %s \n", wronganswer);
			fprintf(fp," Correct answer  : %s \n", correctanswer);
			fprintf(fp," \n You are awarded 0 marks for this wrong answer \n ");
		}
		
			fprintf(fp,"\n -----------------------------------------------------------------------------\n");		
			fprintf(fp," -----------------------------------------------------------------------------\n");	
	}

void show_record()
    {system("cls");
	char name[20];
	float scr;
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&name,&scr);
	printf("\n\n\t\t*************************************************************");
	printf("\n\n\t\t %s has secured the Highest Score %0.2f",name,scr);
	printf("\n\n\t\t*************************************************************");
	fclose(f);
	getch();}

void reset_score()
    {system("cls");
    float sc;
	char nm[20]="";
	FILE *f;
	/*f=fopen("score.txt","r");
	fscanf(f,"%s%f",&nm,&sc);
	fclose(f);*/
	f=fopen("score.txt","w");
	sc=0;
	fprintf(f,"%s",nm);
    fclose(f);
	}

void help()
	{system("cls");
    printf("\n\n                              HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n ......................... C program Quiz Game...........");
    printf("\n >> There are three levels in the game, EASY, MEDIUM AND HARD");
    printf("\n >> Each level has a total of 10 questions.");
    printf("\n    For each right answer, 4 marks are awarded.");
    printf("\n >> No negative marking for wrong answers");
    printf("\n >> You can play any level any number of times.");
    printf("\n >> You will be given 4 options and you have to press A, B ,C or D for the");
    printf("\n    right option");

	printf("\n\n\t*********************BEST OF LUCK*********************************");
	printf("\n\n\t*****C PROGRAM QUIZ GAME is developed by Smriti Bansal********");}

void edit_score(float score, char plnm[20])
	{system("cls");
	float sc;
	char nm[20];
	FILE *f;
	f=fopen("score.txt","r");
	fscanf(f,"%s%f",&nm,&sc);
	if (score>=sc)
	{ fclose(f);
	  f=fopen("score.txt","w");
	  fprintf(f,"%s\n%.2f",plnm,score);
	  fclose(f);
	}
	else
		fclose(f);
   }
