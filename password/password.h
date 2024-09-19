#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string>
#include<cstdlib>
#include<ctime >

using namespace std;

class password
{
  private:
  
  string real;
  public:
  password()
  {
    real= "digit_11";
  }
  //it checks either the user have entered the passcode correctly??
   bool authentication(char fake[], int n)
  {
    int check=0;
     if(n == real.length())
     {
       for(int pass = 0 ; pass<n ; pass++)
       {
         if(real[pass] == fake[pass])
         {
           check++;
         }
       }
     }

     if(check == n)
     return true;
     else
     return false;
  }
  // this is simple feature that allows user to show password into the user screen
 bool show()
  { 
   e: char pass[real.length()];
    char passs[real.length()];
   
    int length=real.length();
   
    for(int i=0; i<length; i++)
    {
        pass[i]='_';
    }
    int check=0;
    int word=0;
       cout<<"\033[0;0H";
        
         cout<<"\033[2J";
          cout<<" ENTER PIN: ";
         
            for(int k=0;k<length;k++)
        {
          cout<<" "<<pass[k]<<" ";
           
        }
          cout<<"\033[0G";
    
    while(  pass[word]=_getch())
    {
        
      cout<<" ENTER PIN: ";
       Beep(500,326);
      
      for(int k=0;k<(length) ; k++)
     {
     
      cout<<" "<<pass[k]<<" ";                 
    }
   if((word >= 0 &&  word<length-1))
   {
     // moves the cursor
     cout<<"\033[0G";
   }
   // conditiom for back space
   if( pass[word] == 8 && word>0)
   {
     word--;
   }
   else
    word++;
    if(word>=length)
    {
        break;
    }
   
    
    }
    cout<<endl;
    bool validity = authentication(pass , length);
   static int tries=0;
    if(!validity)
    {
      tries ++;
      if(tries <= 3)
       goto e;
        
    } 

  
     return validity;   
    }
    // that have functionality to hide the digits entered by user on the screen 
  bool hide()
  {
    // password option if user wants to hide
   e: char pass[real.length()];
    int length= real.length();
    char Hide[length];
    for( int j=0; j<length ; j++)
    {
        pass[j]= '-';
    }
    for( int hidden=0; hidden<length;hidden++)
    {
      Hide[hidden]='*';
    }
    int loop=0;
     //cout<<"\033[0G";
        cout<<"\033[0;0H"; // moves the cursor to the beginnig of line
         cout<<"\033[2J"; // clears screen
          cout<<" ENTER PIN: ";
         
            for(int k=0;k<length;k++)
        {
          cout<<" "<<pass[k]<<" ";
           
        }
          cout<<"\033[0G";
          while(  pass[loop]=_getch())
    {
        
      cout<<" ENTER PIN: ";
       Beep(500,326);
      for(int k=0;k<length ; k++)
      {
        if( k == loop)
        {
          cout<<" "<<pass[k]<<" ";
        }
        if(k < loop)
        {
          cout<<" "<<Hide[k]<<" ";
        }
      }
     //delay for second
     for(volatile int i=0;i<=500000000;i++)
      {}
//move curso 
cout<<"\033[0G";
//hide the characters
cout<<" ENTER PIN: ";
for(int i=0;i<=loop;i++)
{
  cout<<" "<<Hide[i]<<" " ;
}
   if(( loop >= 0 &&  loop<length-1))
   {
     // moves the cursor
     cout<<"\033[0G";
   }
   // conditiom for back space
   if( pass[loop] == 8 && loop>0)
   {
     loop--;
     pass[loop]='-';
   }
   else
    loop++;
    if( loop >=length)
    {
        break;
    }
   
    
    }
    cout<<endl;
    static int chance = 0;
      bool validity = authentication(pass , length);
    if(!validity)
    {
      chance++;
      if(chance<=3)
      goto e;
      else
       return validity;
    }

    return validity;
  }

  
  
// now I am trying to create a feature that generates (returns) the password automatically you can also provide no of digits else it will be 5
  string pass_generator(int digits = 5 )
  {
     string result(digits,' ');

    srand(time(nullptr));
     if( digits < 3 )
     {
       cout<<  " PIN should be >= 3 so now it's 5"<<endl;
       return pass_generator(  );
     }
     // one character is Alphabet , other  must be digit , and another must be special character
     // special characters 
     char special[4]={'@','$','!','*'};
     int special_number= rand() % 4;
     char aphas[26];
     int i=0;
     for(char alphabet = 'a' ; alphabet<='z' ; alphabet++)
     {
       aphas[i] =alphabet;
       i++;
     }
     int aphas_number = rand() % 26;
      step: int random_number = (rand() % digits) ;
       if(random_number > digits)
       {
         goto step;
       }
    
     result[random_number] = special[special_number];
     repeat:  int alpha_number = (rand() % digits) ;
     if( alpha_number == random_number)
     {
        goto repeat;
     }
    
      result[alpha_number] = aphas[aphas_number];

      // any third one must be digit
     again: int digit_number = (rand() % digits) ;
       
      if(  digit_number == alpha_number ||digit_number == random_number)
      {
          goto again;
      } 
      char no[10]= {'1','2','3','4','5','6','7','8','9','0'};
      int d= rand() % 10;
      result[digit_number] = no[d];
      
      // now declaring data to other characters in result string
      for(int pass = 0 ; pass < digits ; pass++)
      {
        if(pass != random_number && pass != digit_number && pass != alpha_number)
        {
         int majicno = rand() % 26;
         char majicchar = aphas[majicno];
          result[pass] = majicchar;
        }
        
      }
     
     return result;

  }
};
