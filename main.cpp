#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;
char passphrase[]="8385";
void gotoxy(int i,int j)
 { int o=0,p=0;
    for(;p<=j;p++)
      { cout<<"\n";
      } 
    for(;o<=i;o++)
      {cout<<" ";
      }

  }
  
int counter=0;
int counter2=0;
int cart[10];
class product
{
	char name[50];
	char category;
	int id;
	float price;
public:
	product()
		{ category='A'; id=0;}
	char retcateg()
		{ return category; }
	int retid()
		  { 
		  	return id; }
	 float retp()
		  { return price; }
	void input()
	{
	system("cls"); 
	 gotoxy(75,5);
     cout<<"**********************************";
     gotoxy(75,1);
	 cout<<"Categories:";
	 gotoxy(75,1);
     cout<<"**********************************";
	 			gotoxy(75,1);
				cout<<"A. Clothing and Fashion";
				gotoxy(75,1);
				cout<<"B. Electronics";
				gotoxy(75,1);			
				cout<<"C. Furniture & Home Decor";
				gotoxy(75,1);
				cout<<"D. Books & Stationery";
				gotoxy(75,1);
				cout<<"E. Games, Music & Entertainment.";
	gotoxy(75,1);
	cout<<"Select category: ";
	cin>>category;
	gotoxy(75,3);
	cout<<"Enter name of the product: ";
	char abc[2];
	gets(abc);
	gets(name);
	gotoxy(75,1);
	cout<<"Enter price: ";
	cin>>price;
	counter++;        //try with :: for global if error occurs
	id=counter;
	gotoxy(75,3);
	cout<<"Product Added. ";
	gotoxy(75,3);
	cout<<"Press any Key to continue....";
	getch();
  }

  void display()
  { 
  gotoxy(75,1);
  cout<<"*********************";
  gotoxy(75,1);
  cout<<"PRODUCT : ";
  gotoxy(75,1);
  cout<<"*********************";
  
  switch(category)
  {
		case 'A':    gotoxy(75,1);
		
		             cout<<"Category : Clothing and Fashion\n";
						break;

		case 'B': gotoxy(75,1);
		          cout<<"Category : Electronics\n";
						break;

		case 'C': gotoxy(75,1);
		          cout<<"Category : Furniture & Home Decor\n";
						break;

		case 'D': gotoxy(75,1);
		           cout<<"Category : Books & Stationery\n";
						break;

		case 'E': gotoxy(75,1);
		           cout<<"Category : Games, Music & Entertainment\n";
						break;
		default:    gotoxy(75,3);
		            cout<<"Wrong Choice";
	}
	gotoxy(75,1);
	cout<<id<<") ";
    puts(name);
    gotoxy(75,1);
    cout<<"Rs."<<price;
    
  }

};

class buyer
{
	char name[20];
	char address[30];
	int id;
	char pass[50];
public:
	
	int retid(){
		return id;
	}
	char *retpass(){
		return (char *)pass;
	}
	void input()
	{
		system("cls");
		gotoxy(75,5);
		cout<<"*********************";
		gotoxy(75,1);
		cout<<"New User";
		gotoxy(75,1);
		cout<<"*********************";
		gotoxy(75,3);
		cout<<"Enter name: ";
		char abc[2];
		gets(abc);
		gets(name);
		gotoxy(75,1);
		cout<<"Enter Shipping Address: ";
		gets(address);
		gotoxy(75,1);
		cout<<"Enter the pin: ";
		cin>>pass;
		counter2++;
		id=counter2;
		gotoxy(75,1);
		cout<<"Profile added successfully.";
		gotoxy(75,3);
	    cout<<"Press Any key to continue...";
		getch();	
		
	}

	void display()
	{
		gotoxy(75,1);
		cout<<id<<") ";
		cout<<"Name: ";
		puts(name);
		//cout<<endl<<"Shipping Address: ";
		//puts(address);

	}
	
	void checkout(){
		gotoxy(75,2);
		cout<<"Thank you for your purchase : ";
		puts(name);
		gotoxy(75,1);
		cout<<"Your order will be delivered in 3-5 bussiness days to : ";
		puts(address);
	}



};

void input_b()
{

	ofstream f1("Buyer.dat", ios::binary | ios::app);
	buyer s;
	s.input();
	f1.write( (char*)&s, sizeof(s) );
	f1.close();

}


void display_b()
{   system("cls");
	ifstream f1("Buyer.dat", ios::binary);
	buyer s;
	f1.read( (char*)&s, sizeof(s) );
	
		gotoxy(75,5);
		cout<<"********************************";
		gotoxy(75,1);
		cout<<"Profile : ";
		gotoxy(75,1);
		cout<<"********************************";
	do{
		s.display();
		cout<<endl;
		f1.read( (char*)&s, sizeof(s) );
	  }while(f1);
		f1.close();

}
int password2(int b)
{ 
	char pass[50];
	ifstream f1("Buyer.dat", ios::binary);
	buyer s;
	f1.read( (char*)&s, sizeof(s) );
		do{
		if(s.retid()==b)
		{
			strcpy(pass,s.retpass());
			break;
		}
		cout<<endl;
		f1.read( (char*)&s, sizeof(s) );
	  }while(f1);
		f1.close();
     char ch[10];
     char a;
     int i;
     again:
     system("cls");
     gotoxy(75,10);
     cout<<"Authentication required to proceed!!!!!";
     gotoxy(75,3);
     cout<<"Enter The Pin : ";
     for(i=0;i<4;i++)
     {
       ch[i]=getch();
       cout<<'*';
     }
     ch[i]='\0';
     if(strcmp(ch,pass)==0)
     {
    gotoxy(75,5);
	cout<<"Authentication Completed Successfully....";
	getch();
	return 1;
     }
     else
     {
     	gotoxy(75,4);
	cout<<"Wrong Password Entered,Try Again...";
	gotoxy(75,2);
	cout<<"If you want to try again,press 0..";
	cin>>a;
	if(a=='0')
	goto again;

	else
	{
	  gotoxy(75,2);
	  cout<<"Authentication Failed....";
	  return -1;
	}
      }
}

void checkdisplay(int b)
{   
//	system("cls");
	ifstream f1("Buyer.dat", ios::binary);
	buyer s;
	f1.read( (char*)&s, sizeof(s) );
	
//		gotoxy(75,5);
//		cout<<"*******";
//		gotoxy(100,1);
//		cout<<"Profile : ";
//		gotoxy(75,1);
//		cout<<"*******";
	while(f1){
		if(s.retid()==b)
		s.checkout();
		cout<<endl;
		f1.read( (char*)&s, sizeof(s) );
	  }
		f1.close();

}

void add_p()
{
	ofstream f1("Product.dat", ios::binary | ios::app);
	product s;
	s.input();
	f1.write( (char*)&s, sizeof(s) );
	f1.close();

}

void search_p(char cat)
{   system("cls");
	cout<<endl;
	ifstream f1("Product.dat", ios::binary);
	product s;
	f1.read( (char*)&s, sizeof(s) );
	do{
		if(s.retcateg()==cat)
		 {	s.display();
		cout<<endl;}
		f1.read( (char*)&s, sizeof(s) );
	  }while(f1);
	  f1.close();


}
float disp(int n)
{    system("cls");
	gotoxy(75,5);
	cout<<"*********************";
	gotoxy(93,1);
	cout<<"Your purchase:";
	gotoxy(75,1);
	cout<<"*********************";
	 gotoxy(75,2);
	 cout<<"Number of products bought = "<<n<<endl;
	 gotoxy(100,3);
	 cout<<"PRODUCT LIST : ";
	 gotoxy(99,1);
	 cout<<"----------------";
	 float sum=0;
	 int a;
	 product x;
	 ifstream f1("Product.dat", ios::binary) ;
	 for (int j=0;j<n;j++)
		  {
				a=cart[j];
				f1.seekg(0);
				f1.read( (char*)&x, sizeof(x) );
				do{
				  if(x.retid()== a)
				  {
				  
				  cout<<"\n\n\n";
				  x.display();
				  sum+=x.retp();
				  cout<<endl;
				  break;
				   }
				  f1.read( (char*)&x, sizeof(x) );
				  }while(f1);

			 }
	 f1.close();

	 return sum;

}
void intro()
{
 system("cls");
 gotoxy(76,10);
 cout<<"*****************************************************************";
 gotoxy(91,1);
 cout<<"WELCOME TO OUR E-COMMERCE PLATFORM ";
 gotoxy(76,1);
 cout<<"*****************************************************************";
 cout<<"\n\n\n";
 gotoxy(88,1);
 cout<<"===============================";
 gotoxy(93,1);
 cout<<"PROJECT MADE BY :: ";
 cout<<"\n";
 gotoxy(93,1);
 cout<<"PRAJJWAL KUMAR ";
 cout<<"\n";
 gotoxy(93,1);
 cout<<"PRABHSIMAR SINGH TANEJA ";
 gotoxy(88,1);
 cout<<"===============================";
 cout<<"\n\n\n";
 gotoxy(89,3);
 cout<<"DELHI TECHNOLOGICAL UNIVERSITY ";
 gotoxy(76,1);
 cout<<"==========================================================";
 gotoxy(106,3);
 cout<<" Press Any Key to continue...";
 getch();
}
int password()
{
     char ch[10];
     char a;
     int i;
     again:
     system("cls");
     gotoxy(75,10);
     cout<<"Authentication required to proceed!!!!!";
     gotoxy(75,3);
     cout<<"Enter The Password : ";
     for(i=0;i<4;i++)
     {
       ch[i]=getch();
       cout<<'*';
     }
     ch[i]='\0';
     if(strcmp(ch,passphrase)==0)
     {
    gotoxy(75,5);
	cout<<"Authentication Completed Successfully....";
	getch();
	return 1;
     }
     else
     {
     	gotoxy(75,4);
	cout<<"Wrong Password Entered,Try Again...";
	gotoxy(75,2);
	cout<<"If you want to try again,press 0..";
	cin>>a;
	if(a=='0')
	goto again;

	else
	{
	  cout<<"\n\tAuthentication Failed....";
	  return -1;
	}
      }
}

void counter_initialise()
{
		
	ifstream f1("Product.dat", ios::binary);
	product s;
	f1.read( (char*)&s, sizeof(s) );
		
	do{
		counter++;
		f1.read( (char*)&s, sizeof(s) );
	  }while(f1);
	  f1.close();
//	  counter++;
}
void counter2_initialise()
{
	
	ifstream f1("Buyer.dat", ios::binary);
	buyer s;
	f1.read( (char*)&s, sizeof(s) );
	do{
		counter2++;
		f1.read( (char*)&s, sizeof(s) );
	  }while(f1);
	  f1.close();
//	  counter2++;
}


int main()
{
	counter_initialise();
//	counter2_initialise();
	intro();
	int pin;
	system("cls");
	pin=password();
	if(pin==1){
	
	int c,i=0;
	float p=0;
	do{
	system("cls");
	gotoxy(75,10);
	cout<<"********************************";
	gotoxy(84,1);
	cout<<"LOGIN";
	gotoxy(75,1);
	cout<<"********************************";
	gotoxy(75,2);
	cout<<"1) Create New Profile";
    gotoxy(75,1);
	cout<<"2) Select Existing Profile";
	gotoxy(75,1);
	cout<<"3) EXIT";
	gotoxy(75,2);
	cout<<"********************************";
	gotoxy(75,5);
	cout<<"Enter your choice : ";
	cin>>c;
	if(c==1)
		input_b();
	else if(c==2)
		display_b();
	else if(c==3)
	{
	  exit(0);	
    }
	else cout<<"Wrong input!";
	} while (c!=2);
	int b;
	gotoxy(75,2);
	cout<<"Choose profile: ";
	cin>>b;
	int pin2=password2(b);
	if(pin2==1){
	system("cls");
	char choice;
	do{
	system("cls");	
	gotoxy(75,10);
	cout<<"******************************************";
	gotoxy(95,1);
	cout<<"MENU";
	gotoxy(75,1);
	cout<<"******************************************";
	gotoxy(75,2);
	cout<<"1. BUY ";
	gotoxy(75,1);
	cout<<"2. SELL ";
	gotoxy(75,1);
	cout<<"3. Exit";
	gotoxy(75,3);
	cout<<"Enter your choice : ";
	cin>>c;

	if(c==2)
		add_p();

	else if(c==1)
		{ 
		do{
		system("cls");
		gotoxy(75,10);
       	cout<<"*********************";
       	gotoxy(75,1);
		cout<<"Categories:";
		gotoxy(75,1);
	    cout<<"*********************";
	    gotoxy(75,2);
					  cout<<"A. Clothing and Fashion\n";
		gotoxy(75,1);		
					  cout<<"B. Electronics\n";
		gotoxy(75,1);		
					  cout<<"C. Furniture & Home Decor\n";
		gotoxy(75,1);		
					  cout<<"D. Books & Stationery\n";
		gotoxy(75,1);		
					  cout<<"E. Games, Music & Entertainment.\n\n";
					  char ch;
					  gotoxy(75,3);
					  cout<<"Enter Your Choice : ";
					  cin>>ch;
			 search_p(ch);
			 int x;
			 gotoxy(75,1);
			 cout<<"Select the product you want to buy: ";
			 cin>>x;
			 cart[i]=x;
			 i++;

		

		gotoxy(75,1);
		cout<<"Do you want to buy more (y/n) : ";
		cin>>choice;
        }while(choice=='y'||choice=='Y');
        
		system("cls");
		p=disp(i);
    	gotoxy(75,1);
		cout<<"Your total amount is Rs."<<p;
		gotoxy(75,1);
		checkdisplay(b);
		gotoxy(75,1);
		cout<<"Press any key to continue....";
		getch();
		
      }
  
	} while (c!=3);
}
	system("cls");
	gotoxy(75,5);
	cout<<"****************************************";
	gotoxy(90,1);
	cout<<"THANK YOU!!";
	gotoxy(75,1);
	cout<<"****************************************";
}

}
