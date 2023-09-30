#include<bits/stdc++.h>
using namespace std;
int md(pair<int,int> start,pair<int,int> end){
    int i=start.first -end.first;
    int j=start.second -end.second;
    if(i<0){
        i*=-1;
    }
    if(j<0){
        j*=-1;
    }
    return i+j;
}
void printTicket(string b,string d,string date,int cost,int c,int s){
    cout<<"Beginning City : "<<b<<endl;
    cout<<"Destination City : "<<d<<endl;
    cout<<"Date : "<<date<<endl;
    cout<<"Cost of Ticket :Rs. "<<cost<<endl;
    cout<<"Coach No. : "<<c<<endl<<"Seat No. : "<<s;
}
class passenger{
    string name,userN,pass;
    public:
    passenger(string name,string userN,string pass){
        this->name=name;
        this->userN=userN;
        this->pass=pass;
    }
    string getusern(){
        return userN;
    }
    string getpass(){
        return pass;
    }
};
class train{
    pair<int,int> start,end;
    string date;
    public:
    vector<pair<int,int>> bookedT;
    train(pair<int,int> start,pair<int,int> end,string date,vector<pair<int,int>> bookedT){
        this->start=start;
        this->end=end;
        this->date=date;
        this->bookedT=bookedT;
    }
    pair<int,int> getstart(){
        return start;
    }
     pair<int,int> getend(){
        return end;
    }
    string getdate(){
        return date;
    }
};
class city{
string cityN;
int xcoord;
int ycoord;
public:
city(string cityN,int xcoord,int ycoord){
    this->cityN=cityN;
    this->xcoord=xcoord;
    this->ycoord=ycoord;
}
string getcityn(){
    return cityN;
}
int getx(){
    return xcoord;
}
int gety(){
    return ycoord;
}
};
int main(){
    cout<<"Welcome to IRCTC !\n";
passenger p1("eena","e","11");
passenger p2("bena","b","22");
passenger p3("deka","d","33");
vector<passenger> pv={p1,p2,p3};
    int a,flag1=0,flag2=0;
    string name,userN,pass;
    cout<<"For New user,Press 1 / For Existing user,Press 2\n";
    cin>>a;
    if(a==1){
        cout<<"Enter Name,Username and Password\n";
        cin>>name>>userN>>pass;
        passenger pnew(name,userN,pass);
        pv.push_back(pnew);
        cout<<"Signed up successfully\n";
    }
    int i;
    while(flag1==0){
    cout<<"Enter Username and Password for login\n";
    cin>>userN>>pass;
    for( i=0;i<pv.size();i++){
        if(userN==pv[i].getusern() && pass==pv[i].getpass()){
            flag1=1;
            cout<<"Logged in Successfully\n";
            break;
        }
    }
    if(flag1==0){
        cout<<"Invalid username or password\n";
    }
    }
passenger pc(pv[i]);
city Kanpur("Kanpur",10,10);
city Jaipur("Jaipur",20,20);
city Mumbai("Mumbai",30,30);
city Goa("Goa",40,40);
city C[4]={Kanpur,Jaipur,Mumbai,Goa};
train t1({10,10},{20,20},"1stMay",{{1,1},{1,2},{1,3},{1,4},{2,1},{2,2},{2,3},{2,4}});
train t2({10,10},{40,40},"2ndMay",{{2,4},{2,1}});
train t3({40,40},{30,30},"3rdMay",{{1,1},{1,2},{1,3},{1,4},{2,1},{2,2},{2,3},{2,4}});
train t4({20,20},{40,40},"4thMay",{{1,1},{2,2},{1,2},{2,1}});
train T[4]={t1,t2,t3,t4};
string date,Tdate;
pair<int,int> start,end;
string b,d;
cout<<"Enter Beginning city and Destination city\n";
cin>>b>>d;
int j;
while(flag2==0 || flag2==1){
    flag2=0;
cout<<"Enter Date of Journey\n";
cin>>date;
for(int i=0;i<4;i++){
    if(b==C[i].getcityn()){
        start.first=C[i].getx();
        start.second=C[i].gety();
    }
    if(d==C[i].getcityn()){
        end.first=C[i].getx();
        end.second=C[i].gety();
    }
}
cout<<"Please enter Today's Date\n";
cin>>Tdate;
if(Tdate==date){
    cout<<"Sorry, the Ticket cannot be booked on the same date as of the Journey.";
    return 0;
}

for(j=0;j<4;j++){
    if(T[j].getstart()==start && T[j].getend()==end ){
        flag2=1;

        break;
    }
}
if(flag2==0){
    cout<<"Sorry,no Train travels between the mentioned Locations.\n ";
    return 0;
}
if( T[j].getdate()==date){
    flag2=2;
}
if(flag2==2){
    cout<<"1 Train found!\n";
}
if(flag2==1){
    cout<<"Sorry,No such Train found. Try another Date for same Locations.\n";

}
}
train tc(T[j]);
vector<pair<int,int>> btc=tc.bookedT;
vector<pair<int,int>> availT;
int g;
for( int c=1;c<=2;c++){
    for( int s=1;s<=4;s++){
         g=1;
        for(int z=0;z<btc.size();z++){
        if(c==btc[z].first && s==btc[z].second){
     g=0;
        break;
        }
    }
    if(g==1){
        availT.push_back({c,s});
    }
}
}
if(availT.size()==0){
    cout<<"Sorry,No seats available.";
    return 0;
}
cout<<"The available seats are listed below :\n";
for(int i=0;i<availT.size();i++){
    cout<<i+1<<") ("<<availT[i].first<<","<<availT[i].second<<")\n";
}
cout<<"Enter the serial no. corresponding to your preferred seat\n";
cin>>g;
int c=availT[g-1].first;
int s=availT[g-1].second;
int final;
int cost=md(tc.getstart(),tc.getend());
cout<<"The cost of ticket for this journey is Rs."<<cost<<endl;
cout<<"Do you want to book the ticket?\nPress 1 for YES and 0 for NO.\n";
cin>>final;
if(final==0){
    cout<<"Thank You.";
    return 0;
}
cout<<"Ticket booked Successfully!\nPress 1 to print the ticket\n";
cin>>final;
if(final==1){
printTicket(b,d,tc.getdate(),cost,c,s);
}
}
