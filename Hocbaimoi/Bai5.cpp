
#include <iostream>
using namespace std;
int main(){
//1. if
    int n = 200;
if((n>100) && (n%2==0)){
    cout<<"so chan"<<endl;
}
cout<<"100 khong lon hon 50"<<endl;
int a = 0;
if(a){
    cout<<"a khac 0"<<endl;
}
cout<<"a bang 0"<<endl;
//else
int b;
cout<<"Nhap b: ";
cin>>b;
if((b%2==0)){
cout<<"so chan"<<endl;
}
else{
    cout<<"so le"<<endl;
}

int c;
cout<<"Nhap c: ";
cin>>c;
if(c==1){
    cout<<"chu nhat"<<endl;
}
else if(c==2){
    cout<<"Thu 2"<<endl;
}
else if(c==3){
    cout<<"Thu 3"<<endl;
}
else if(c==4){
    cout<<"Thu 4"<<endl;
}
else if(c==5){
    cout<<"Thu 5"<<endl;
}
else if(c==6){
    cout<<"Thu 6"<<endl;
}
else if(c==7){
    cout<<"Thu 7"<<endl;
}
else{
    cout<<"khong phai ngay trong tuan"<<endl;
}
//Thực hiện tiếp
if((c==1) || (c==3) || (c==5) || (c==7) || (c==8) || (c==10) || (c==12)){
    cout << "Thang co 31 ngay"<<endl;
}
else if((c==4) || (c==6) || (c==9) || (c==11)){
    cout << "Thang co 30 ngay"<<endl;
}
else{
    cout << "Khong phai thang trong nam"<<endl;
}
}