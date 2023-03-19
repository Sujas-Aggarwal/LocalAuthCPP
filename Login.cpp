#include<iostream>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Game Id Creation
using namespace std;
bool Register();
bool Login();
bool Login(){
	bool success=0;
	//Login
		cout<< "Welcome Back";
		string password;
			
		bool loop=1;
		string id;
		while (loop){
		cout<< endl <<"Please Enter Your User Id Name\n";
		cin>> id;
		ifstream userFile("Users/"+id+".txt");
		if (userFile.good()){
			loop = 0;
		}
		else{
			string isTry;
			cout<< "Sorry But There is No Id With This Name\nWould You Like to Register or Try again? (Press R and T Respectively)\n";
			cin>> isTry;
			if (isTry=="R" || isTry == "r"){
				loop = 0;
				success = Register();
				return success;
			}
		}
	}
		bool loop2=1;
		int trials=3;
		while (loop2 && trials>0){
		
		cout<<"Enter Your Password\n";
		cin>> password;
		string oriPass;
		ifstream userFile("Users/"+id+".txt");
		getline(userFile,oriPass);
		if (password==oriPass){
			cout<<"Login Successful\n";
			loop2=0;
			success=1;
		}
		else{
			cout<<"Wrong Password,\nYou Have " << trials-1 << " Trials left.\n";
			trials--;
			success = 0;
		}
	}
	return success;
}

	bool Register(){
			string id;
			string password;
			string name;
			string confirmpass;
			bool success;
			cout<<"Enter Your Real Name\n";
			cin>>name;
			cout<<"Choose Your Game Name(Only lowercase allowed with no special characters)\n";
			bool loop3=1;
			
			while (loop3){
				
				cin>>id;
				ifstream userFile("Users/"+id+".txt");
				if (!userFile.good()){
					loop3=0; }
				else{
					cout<<"This Id is already Present, Choose another name\n";}
					
			}
			
			bool loop4=1;
			while (loop4){
			cout<<"Choose Your Password\n";
			cin>> password;
			cout<<"Confirm Password\n";
			cin>>confirmpass;
			if (confirmpass==password){
				time_t currentTime = time(NULL);
				cout<<"Account Created!\n";
				success=1;
				loop4=0;
				ofstream userFile("Users/"+id+".txt");
			userFile <<password<<endl<<name<<endl<<"Created on- " << ctime(&currentTime);
			}
			else{
				cout<<"Wrong Password, Try Again\n";
			}}
			return success;
	}


int main(){
	string isNew;
	bool active=0;
	cout<< "Are You A New Player? Yes or No\n";
	cin>> isNew;
	if (isNew=="NO" || isNew == "No" || isNew == "N" || isNew == "n" || isNew == "no"){
	active = Login();
	}
	else{
	active = Register();
	}
	if (active==0){
		cout<<"Access Denied";
	}
	else{
		cout<<"Access Granted";
	}
	cout<<"\n \n--------Press Any Key To Exit---------";
	string exit;
	cin>>exit;
return 0;}

