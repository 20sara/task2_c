#include <stdio.h>
#include <string.h>
#include <stdbool.h>


struct Users
{
   char username[50];
   char password[50];
   char actived[50];
};


 typedef union check_active
    {

       struct 
      {
        char active[20];
      }act;

      //  struct 
      // {
      //   int active;
      //   int intactive;
      // }actint;

      // struct 
      // {
      //   int active;
      //   bool boolactive;
      // }actbool;
      
       
    } chk_act ;


 struct Users users[200];
 int num_user=0;

 //Registration


void Register_Users()
    {
        if (num_user >= 200) {
          printf("Maximum  users reached. Cannot register more users.\n");
          return;
    }
    
struct Users insertuser;
union check_active chk_act;

  char state;
         
    printf(" \n Registration:\n");

    printf("\nEnter UserName:  ");
    scanf("%s",insertuser.username);

     for (int i = 0 ; i < num_user ; i++) {
         if (strcmp(insertuser.username, users[i].username) == 0) {
            printf("Username already exists. Choose Other UserName.\n");
            return;
        }
    }

   
    printf("\nEnter password: ");
    scanf("%s",insertuser.password);

    printf("\nChoice Active: \n");
    printf("\n 1 | true- Active :  \n");
    printf("\n 0 | false- Not Active :  \n");
    printf("\n Enter active_state : ");
       // printf("\nEnter active_state t or f or 0 or 1 : ");
    scanf("%s", &state);

        switch (state) {
            case '1': 
            case 't':
            
              strcpy(chk_act.act.active,"true");
              strcpy(insertuser.actived,chk_act.act.active);
              //  printf("\nEnter active_state  0 or 1 : ");
              //  scanf("%d",chk_act.actint.intactive);
               break;

            case '0':
            case 'f':
               
                strcpy(chk_act.act.active,"false");
                strcpy(insertuser.actived,chk_act.act.active);
                // printf("\nEnter active_state true or false : ");
                //  scanf("%d",chk_act.actbool.active);
                 break;

            default:
             printf("Dont can enter any option \n ") ;   
            
        }

    // printf("\nEnter active_state true or false or 0 or 1 : ");
    // scanf("%d",chk_act.);

    users[num_user++] = insertuser;
    //num_user++;
    
    printf("\nRegistration Successfully \n");

    }


    //  Login

 void Login(){
     char user_name[50];
     char pass[50]; 
     bool state;

      struct Users insertuser;
      union check_active chk_act;

     printf("\nEnter UserName:  ");
     scanf("%s",user_name);
    
    printf("\nEnter password: ");
    scanf("%s",pass);

    // printf("\nEnter active_state  true or false : \n");
    // scanf("%d", state);


    for(int i=0 ; i<num_user ; i++){
        if ( strcmp(user_name,users[i].username) ==0 && strcmp(pass,users[i].password)==0) {
              strcpy( chk_act.act.active , "false");
            if (!strcmp(users[i].actived , chk_act.act.active) ){  
               printf("\n Sorry Login UnSuccessfully \n");
              
            }      
       else{
       
        printf("Login  Successfully  \n");
           
       }
            } 
        }
    
    } 
 
void main(){
    
    struct Users insertuser;
    union check_active chk_act;

    char choose;
     int x;

   while (choose != 'R' | 'L'){
   
        printf("R. Register\n");
        printf("L. Login\n");
    
        printf("Enter your choose: ");
        scanf("%s", &choose);

        switch (choose) {
            case 'R':
                 Register_Users();
                 break;

            case 'L':
                 Login();
                 break;
            
            default:
                 printf("you enter invaild option \n");
                 break;

        }
    } 

}



