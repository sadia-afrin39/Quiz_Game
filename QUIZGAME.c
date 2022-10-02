////BISMILLAHIR RAHMANIR RAHIM
//// QUIZ GAME
////Programming fundamental lab
//////Project for MD. MOSTAFIZUR RAHMAN SIR
//Sadia Afrin Tarin (CSE027)
//1st Year,1st Semester.....
//////Department of Computer Science & Engineering
/////University of Barishal.....


//#####################################
//#  *****   *    *  *****  *******   #
//#  *   *   *    *    *         *    #
//#  *   *   *    *    *       *      #
//#  *****   *    *    *     *        #
//#        * ******  *****  *******   #
//#         *                         #
//#####################################



#include<stdio.h>
#include<ctype.h>
#include<string.h>//toupper
#include<stdlib.h>//exlll
#include<time.h>//difftime




//***************************************
//*  h    h eeeeeee  l        ppppppp   *
//*  h    h e        l        p     p   *
//*  hhhhhh eeee     l        ppppppp   *
//*  h    h e        l        p         *
//*  h    h eeeeeee  lllllll  p         *
//*                                     *
//***************************************



void help(){

    system("cls");

    printf("This game is very easy to play.\nYou will be asked some questions.\n");

    printf("You have to choose the right answer among the four options provided.\n");

    printf("There are three levels in this game- EASY, MEDIUM & HARD. In each level there are 10 questions.\n");

    printf("You have to give at least 6 correct answer in each level to go to the next level.\n");

    printf("Your score will be calculated & displayed at the end.\n");

    printf("\nIf you secure highest score, your score will be recorded.\n");

    printf("Remember that the more quicker you give answer the more score you will secure.");

    printf("To go to the main menu press any key.\n\t\t****Best of Luck****\n");
}



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%  SSSSSS  CCCCC  OOOOOO  RRRRRR  EEEEEEE  %
//%  S       C      O    O  R    R  E        %
//%  SSSSSS  C      O    O  RRRRRR  EEEEE    %
//%       S  C      O    O  R       E        %
//%  SSSSSS  CCCCC  OOOOOO  R  R    EEEEEEE  %
//%                              R           %
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




void display_score(){
    char name[30];

    float scr;

    FILE *file;


    system("cls");


    file=fopen("score.txt","r");

    fscanf(file,"%s %f",&name,&scr);

    printf("\n\n\t %s has secured the highest score %.2f \n ",name,scr);


    fclose(file);

    getch();
}





void write_score(float score,char player[30]){

     float sc;

     char nm[30];

     FILE *file;


     system("cls");


     file=fopen("score.txt","r");

     fscanf(file,"%s %f",&nm,&sc);


     if(score>=sc){

        sc=score;

        fclose(file);


        file=fopen("score.txt","w");

        fprintf(file,"%s\n%.2f",player,sc);

        fclose(file);

     }
}



//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//&  *     *      *       *******  *    *   &
//&  **   **     * *         *     **   *   &
//&  * * * *    *   *        *     * *  *   &
//&  *  *  *   *******       *     *  * *   &
//&  *     *  *       *      *     *   **   &
//&  *     * *         *  *******  *    *   &
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&





int main()

{


    char choice,aww;

    float score=0;

    char player_name[30];

    time_t start_time,end_time;

    char str[200], str1[200], str2[200], ch;

    int ct = 0, ct1 = 0, ct2 = 0;

	FILE *fp, *fp1, *fp2;




    mainhome:


    system("cls");


    printf("\n\n\t\tEnter Your Name:");

    gets(player_name);


    system("cls");

    options:

    system("cls");

    printf("\t\t************************************\n");

    printf("\t\t************************************\n");

    printf("\t\tWelcome %s To Quiz Game\n",player_name);

    printf("\t\t************************************\n");

    printf("\t\t************************************\n\n\n");

    printf("\tWhat do you want to do?\n\t");

    printf("1.Start game\n\t2.High score\n\t3.Help\n\t4.Quit game\n");

    printf("Enter any of the above number to do your desired action\n");

   scan:

    scanf("%c",&choice);



    if (choice=='2'){

        display_score();

        goto mainhome;

      }



    else if(choice=='4'){

            exit (1);
    }



    else if (choice=='3'){

        help();

        getch();

        goto mainhome;

    }



    else if (choice=='1'){

        system("cls");


        home:

        system("cls");

        start_time=time(NULL);

        ct = 0;
        ct1 = 0;
        ct2 = 0;

        fp = fopen("Questions.txt", "r");

	    printf("\n\tWelcome to Easy Level");

	    printf("\n\t*********************\n\n");

	    while(fgets(str, 120, fp) != EOF){


		    if(str[0] == '#'){

			  break;

		      }

		    if(isdigit(str[0])){

			   if(ct > 0){

				  printf("\n\tEnter an option (a / b / c / d):  ");

				  while(1){

                      //gets(str2);

                      scanf("%s",str2);

                      if(strcmp(str2, "a") == 0 || strcmp(str2, "b") == 0 || strcmp(str2, "c") == 0 || strcmp(str2, "d") == 0){

						   fp1 = fopen("Answers.txt", "r");

						   while(fscanf(fp1, "%s", str1) != EOF){

							   continue;

						   }

						   fclose(fp1);

						   if(str1[ct - 1] == str2[0]){

                                ct2++;

                                ct1++;

                                printf("\n\tCorrect Answer!!\n\n");

						   }

                           else{

							  printf("\n\tIncorrect Answer!! Correct answer is: %c\n\n", str1[ct - 1]);
						   }

						   break;
					  }

					else{

						printf("\n\tInvalid input. Try again: ");
					}
				}

				ct++;
			}

			else{

				ct++;
			}

			if(ct == 11){

				if(ct1 < 6){

					break;
				}

				system("cls");

            printf("\n\n\t\tCongratulations..........\n\n\tYou have crossed EASY LEVEL.\n");

            printf("\n\tWelcome to Medium Level");

            printf("\n\t***********************\n\n");

            ct1 = 0;

			}


			if(ct == 21){

				if(ct1 < 6){

					break;
				}

				system("cls");

				printf("\n\n\t\tCongratulations..........\n\n\tYou have crossed MEDIUM LEVEL.\n");

				printf("\n\tWelcome to Hard Level");

				printf("\n\t*********************\n\n");

				ct1 = 0;
			}

			printf("\t%s", str);
		}


		else{


			printf("\t%s", str);
		}
	}

	fclose(fp);


     end_time=time(NULL);

     score=(float)ct2/ct*100-difftime(end_time,start_time)/3;


     if(score<=0) score=0;

     printf("\n\t###################");

     printf("\n\t#                 #");

     printf("\n\t#Your Score: %.2f#",score);

     printf("\n\t#                 #");

     printf("\n\t###################");



     if (score==100){

         printf("\n\n\tEXCELLENT!!! YOU ARE REALLY SO MUCH BRILLIANT. KEEP IT UP\n");
     }


     else if (score>=80 && score<100) {

             printf("\n\n\tVERY GOOD!!!YOU ARE QUITE BRILLIANT.\n");
     }


     else if (score>=50&&score<80){

             printf("\n\n\tGOOD!!! BUT YOU NEED TO KNOW MORE. KEEP TRYING\n");
     }


     else if (score>=30 && score<50){

            printf("\n\n\t NOT SATISFACTORY RESULT. WORK HARD.\n");
     }


     else{

      printf("\n\n\tYOU ARE VERY POOR IN G.K. BETTER LUCK NEXT TIME.\n");
     }

     puts("\n\n \t\tDO YOU WANT TO PLAY AGAIN?\n(Y/N)");

     if (toupper(getch())=='Y')  goto home;


     else
        {
         write_score(score,player_name);

         goto options;
       }

    }
    else {

            goto scan;
    }


    return 0;
}
