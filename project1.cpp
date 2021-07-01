 
 #include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
void login();
void registration();
void forgot();


   main(){
   

    int choice;
    cout << "######################### LOGIN #####################\n";
    cout << "1.login\n";
    cout << "2.register\n";
	cout<<"3.forgot password";
	cout << "\nenter your choice:";
    cin >> choice;

    switch(choice)
    {
        case 1:
        login();
        break;

        case 2:
        registration();
        break;
        
        case 3:
        	forgot();
        	break;
        
        default:
        cout << "invalid selection\n";
        break;
        main();
    }
}

    void registration()
         {
        string reguser,regpass,regemail,regconfirm;
        system("cls");
        cout << "enter the user name:\n";
        cin >> reguser;
        cout << "enter the email:\n";
        cin >> regemail;
        cout << "enter the password:\n";
        cin >> regpass;
         cout << "confirm password:\n";
        cin >> regconfirm;
         
         if(regpass != regconfirm){
         	cout<<"passwords do not match!";
		 }else{
        ofstream reg("database.txt", ios::app);
        
      
        
        reg << reguser << ' ' << regemail << ' '<< regpass <<endl;
        system("cls");
        cout << "registration is succesfull!\n";
        main();
       }
    }

    void login(){

        int exists;
        string user,pass,u,p;
        system("cls");
        cout << "enter the username:";
        cin >> user; 
        cout << "enter the password:";
        cin >> pass;

        ifstream input("database.txt");

        while(input >> u >> p)
        {
            if(u == user && p == pass)
            {
                exists = 1;
            }
        }

        input.close();
        if(exists == 1)
        {
            cout << "hello, " << user << " welcome back!";
            cin.get();
            cin.get();
            main();
        }
        else{
            cout << "sorry ,login error!";
            cin.get();
            cin.get();
            main();
        }
    }
    
    void forgot(){
    	int ch;
    	system("cls");
    	cout<<"1.search by username";
    	cout<<"\n2.search yor account by email";
    	cout<<"\n3.main menu";
    	cout<<"\nenter your choice:";
    	cin>>ch;
    	
    	switch(ch){
    		case 1:
    			{
				
    			int ex = 0;
    			string searchuser,su,sp;
    			cout<<"enter your username";
    			cin>>searchuser;
    			
    			ifstream searchu("database.txt");
    			while(searchu >> su >> sp){
    				if(su == searchuser)
    				{
    					ex = 1;
    					break;
					}
				}
				searchu.close();
				if(ex == 1){
					cout<<"account found!\n";
					cout<<"your account password is:"<<sp;
					cin.get();
					cin.get();
					main();	
				}
				else{
					cout<<"sorry!account not found\n";
					cin.get();
					cin.get();
					main();
				}
				break;
			}
				case 2:
					{
					
					int exi = 0;
					string searchemail,su2,se2;
					cout<<"enter your email:";
					cin>>searchemail;
					
					
					ifstream searche("database.txt");
					while(searche >> su2 >> se2)
					{
						if(se2 == searchemail){
							exi =1;
						}
					 } 
					searche.close();
					if(exi == 1){
						cout<<"account found!\n";
						cout <<"your username is:\n"<<se2;
						cout << "your password is:"<<su2;
						cin.get();
						cin.get();
						main();
					}
					break;}
					case 3:
						{
						
						main();
						break;}
						default:
							{
							
							cout<<"wrong choice!press any key to continue";
							cin.get();
							cin.get();
							forgot();
				}
					
					 }
				}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    


