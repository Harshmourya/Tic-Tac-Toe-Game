#include<iostream>
using namespace std;

   char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
   int row,cloum;
   bool tie=false;
   char token='x';

    void start(){
        cout<<"\n\n";
    cout<<"\t      | "<<"     | "<<"\n  ";
    cout<< "\t "<<a[0][0]<<"    | "<<a[0][1]<<"    | "<<a[0][2];
    cout<<"\n\t______|"<<"______|"<<"______\n";
    cout<<"\t      | "<<"     | "<<"\n  ";
    cout<< "\t "<<a[1][0]<<"    | "<<a[1][1]<<"    | "<<a[1][2];
    cout<<"\n\t______|"<<"______|"<<"______\n";
    cout<<"\t      | "<<"     | "<<"\n  ";
    cout<< "\t "<<a[2][0]<<"    | "<<a[2][1]<<"    | "<<a[2][2];
    cout<<"\n\t      | "<<"     | "<<"\n  ";
    }

    void function2(){
        int digit;
        if (token=='x')
        {
          cout<<"\n \tfirst player chance ";
          cin>>digit;  
        }
         if (token=='0')
        {
          cout<<"\n \tsecond player chance ";
          cin>>digit;  
        }

        if (digit ==1)
        {
            row=0;cloum=0;
        }
        if (digit ==2)
        {
            row=0;cloum=1;
        }
        if (digit ==3)
        {
            row=0;cloum=2;
        }
        if (digit ==4)
        {
            row=1;cloum=0;
        }
        if (digit ==5)
        {
            row=1;cloum=1;
        }
        if (digit ==6)
        {
            row=1;cloum=2;
        }
        if (digit ==7)
        {
            row=2;cloum=0;
        }
        if (digit ==8)
        {
            row=2;cloum=1;
        }
        if (digit ==9)
        {
            row=2;cloum=2;
        }
        else if (digit<1 || digit>9)
        {
            cout<<"\tINVALID CASE \n";
        }

        if (token =='x' && a[row][cloum]!='x' && a[row][cloum]!='0')
        {
            a[row][cloum]='x';
            token='0'; 
        }

        else if (token =='0' && a[row][cloum]!='x' && a[row][cloum]!='0')
        {
            a[row][cloum]='0';
            token='x'; 
        }
        else{
            cout<<"\tN0 EMPTY SPACE \n";
            function2();
            start();
        }
    }

    bool function3(){
        for (int  i = 0; i < 3; i++)
        {
           if (a[i][0]==a[i][1] && a[i][0]==a[i][2] || a[0][i]==a[1][i] && a[0][i]==a[2][i])
           {
            return true;
           }

           if (a[0][0]==a[1][1] && a[1][1]==a[2][2] || a[0][2]==a[1][1] && a[1][1]==a[2][0])
           {
            return true;
           }
           
        }

        for (int i = 0; i <3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
               if (a[i][j]!='x' && a[i][j]!='0')
               {
               return false;
               }               
            }
        }
        tie=true;
        return false;        
    }

    int main(){
        system("cls");
    cout<<"\n\n\n\n \t\tTIC TEC TEO \n\n\n";        

    while (!function3())
    {    
        start();
        function2();
        function3();
    }
    if (token=='x' && tie==false)
    {
        start();
        cout<<"\n\n\n\tsecond player win \n";
    }
    else if (token=='0' && tie ==false)
    {
        start();
        cout<<"\n\n\n\tfirst player win \n";
    }
    else
    {
        cout<<" DRAW \n";
    } 
 
    }