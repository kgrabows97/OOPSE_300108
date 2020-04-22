#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<math.h>
using namespace std;

fstream file;
int choice;
int i=0;
string lines[10];
string line;
int tab[5];
int amount;
int amont;
int qu;
int mo;
int monies[6];
float price[5]={2.5,1.9,2.9,1.7,3};
float mani[6]={5,2,1,0.5,0.2,0.1};
int moneyadd[6]={0,0,0,0,0,0};
int clientmoney[6];
int *cma;
int *mon;
int *mos;
int *res;
int cal;
int cbd;

float sum;
float clsum;
float dif=0;

void start();
void list();
void chosen(int c);
void quantit(int q,int i);
void pay(int t,int b);
void doo();
void money();
void cash();
void cashback(int *cb);
void cba(int f);


void start(){

		i=0;
	file.open("file-copy.txt", ios::in | ios::out);
	if (file.is_open()){
		while(file>>line){
			stringstream value(line);
			if (value>>amount){
				tab[i]=amount;
				i++;}
				else {
				lines[i]=line;
				
				}
				
				if (line=="oneres"){
					tab[0]=10;
}				else if (line=="twores"){
					tab[1]=10;	
}				
				else if (line=="threres"){
					tab[2]=10;
				}
				else if (line=="fourres"){
					tab[3]=10;
				}
				else if (line=="fiveres"){
					tab[4]=10;
				}
				else {

				}
				
			}
		}
		file.close();
		i=0;
		file.open("bank.txt",ios::in | ios::out);
	if (file.is_open()){
		while(file>>line){
			stringstream value(line);
			if (value>>amount){
				monies[i]=amount;
				i++;}
}}file.close();
}
		
		
main(){
	start();
	file.close();
	list();


	
	return 0;
	
};
void list(){
cout << "Product Name         Quantity           Price [PLN]" <<endl;
for (i=0;i<=4;i++){
	cout << i+1 <<". " <<lines[i] << "  		 " << tab[i]  <<"  		  "<< price[i] <<endl;
};
cout<<"Which product do You choose? (1-5)"<<endl;
	cin>> choice;
	if(choice>>cbd){
	
	if(choice<=5){	
	chosen(choice);}
	else if(choice==9){
		money();
	}
	else if(choice==999){
		
	}
	else{
		cout<<"WRONG NUMBER!!!"<<endl;
		list();
	}}
	else{
		cout<<"Input a number!!!"<<endl;
	}
	
};
void chosen(int i){
	switch(i){
	case 1:{
		cout << "You chose: " << lines[i-1]<<" there are:" << tab[i-1] << " at a price of :" <<price[i-1] << " PLN a piece" <<endl;
		break;
	}
		case 2:{
		cout << "You chose: " << lines[i-1]<<" there are:" << tab[i-1] << " at a price of :" <<price[i-1] << " PLN a piece" <<endl;
		break;
	}
		case 3:{
		cout << "You chose: " << lines[i-1]<<" there are:" << tab[i-1] << " at a price of :" <<price[i-1] << " PLN a piece" <<endl;
		break;
	}
		case 4:{
		cout << "You chose: " << lines[i-1]<<" there are:" << tab[i-1] << " at a price of :" <<price[i-1] << " PLN a piece" <<endl;
		break;
	}
		case 5:{
		cout << "You chose: " << lines[i-1]<<" there are:" << tab[i-1] << " at a price of :" <<price[i-1] << " PLN a piece" <<endl;
		break;
	}
	}
	cout << " How many do You want?"<<endl;
	cin>>qu;
	quantit(qu,choice);
};

void quantit(int qu,int i){
	if (qu<=tab[i-1]){
		tab[i-1]=tab[i-1]-qu;
		pay(qu,i);
	}
	else{
		cout << "Too much!! Try again"<<endl;
		cin>>qu;
		quantit(qu,i);
		
	}
	
};

void doo(){
	file.open("file-copy.txt", ios::trunc | ios::out);
	if(file.is_open()){
		for (i=0; i<5 ;i++){
			file<<lines[i] <<"   ";
			file<<tab[i] << endl;
			
	}
		if (tab[0]==0){
			file << "oneres" << endl;
		}
		if (tab[1]==0){
			file << "twores" <<endl;
		}
		if (tab[2]==0){
			file << "threres"<< endl;
		}
		if (tab[3]==0){
			file << "fourres" << endl;
		}
		if (tab[4]==0){
			file << "fiveres" <<endl;
		}
	
	file.close();
	file.open("bank.txt",ios::in | ios::out);
	if (file.is_open()){
	for(i=0;i<=5;i++){
		monies[i]=monies[i]-moneyadd[i];
		file<< monies[i] <<"   ";
		
	}};
	
	
	
	
	
		list();
}}
void money(){
	for(i=0;i<6;i++){
	moneyadd[i]=0;	
	if(monies[i]==1){
	cout<< "There is : " << monies[i] <<"	"<< mani[i] << "PLN coin."<<endl;
	}else{
	cout<< "There are : " << monies[i] <<"	"<< mani[i] <<"PLN coins."<<endl;	
}}	for(i=0;i<6;i++){
	cout<< "How many "<< mani[i] <<"PLN coins are to be in the machine?" << endl;
	cin>>monies[i];
}

doo();
}
void pay(int t, int b){
	sum=t*price[b-1];
	cout <<"You have to pay :" << sum <<" PLN"<< endl;
		cash();
}

void cash(){
	moneyadd[0]=0;
	cma=&clientmoney[0];
	mos=&monies[0];
    cout<<"Paying:"<<endl;
    for(int i=0; i<6; i++){
        cout<<"Enter amount of "<<mani[i]<<"PLN coins: ";
        
        cin>>*cma;
        clsum=clsum+(mani[i]*(*cma));
    	*mos=*mos+*cma;
        cma++;
    	mos++;
    }
    cout<<clsum;
    dif=clsum-sum;	
	cout<<" \nYour rest adds up to: "<< dif <<"PLN \n";
	dif=clsum-sum;
    cashback(cma);
}
void cashback(int *cb){
	mon=&monies[0];
	cma=&clientmoney[0];
	if(dif>=5){
	res=max_element(mon,mon+5);
	}
	else if(dif<5 && dif>=2){
	res=max_element(mon+1,mon+5);
	}
	else if(dif<2 && dif>=1){
	res=max_element(mon+2,mon+5);
	}	
	else if(dif<1 && dif>=0.5){
	res=max_element(mon+3,mon+5);
	}
	else if(dif <0.5 && dif>=0.2){
	res=max_element(mon+4,mon+5);
	}
	else if(dif<0.2 && dif>=0.1){
	res=mon+5;
	}
	else if(dif<0){
		cout<<"Too small amount of money!!!"<<endl;
		cash();
	}	
			
	if(dif>0){
	for(i=0;i<=6;i++){
	if(*res==*mon){
		cba(i);
	}

	cma++;
	mon++;
	}

	}
	else{
	cout<<"REST:"<<endl;
	for(i=0;i<=5;i++){
		cout<< "Amount of "<< mani[i] << "PLN coins: " << moneyadd[i]<<endl;;
	}
		doo();	
		
			}
}


void cba(int f){
	int xd=0;
	int diff=0;
	int lol=0;
	dif=round(dif*10);
	dif=dif*0.1;
	xd=floor(dif/mani[f]);
	moneyadd[f]=xd;
	dif=(dif-(mani[f]*xd));	
	//cout <<" \n Rest Now :: "<<dif<<endl;
	

		cashback(cma);
	}
	
	

	
	
	

