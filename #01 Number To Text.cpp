#include<iostream>
#include<string>
using namespace std;

unsigned long long ReadNumber(){

     unsigned long long num =0;

    cout<<"Enter a Number ? ";
    cin>>num;

    return num;
}
string NumberToText(unsigned long long num){

    if(num==0)
    {
        return "";
    }
    if(num>=1 && num <=19)
    {
        string arr[]={ "", "One" , "Two" , "Three" , "Four" ,"Five" ,"Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thriteen",
        "Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        return arr[num]+" ";
    }
    if(num>=20 && num <=99){
        string arr[] = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
        return arr[num/10] + " " +NumberToText(num%10); 
    }
    if(num>=100 && num<=199){
        return "One hundred " + NumberToText(num%100);
    }
    //251
    if(num>=200 && num <=999){
        string arr[]={"","One" , "Two" , "Three" , "Four" ,"Five" ,"Six","Seven","Eight","Nine"};
        return NumberToText(num/100)+"Hundred "+NumberToText(num%100);
    }
    if(num>=1000 && num<=1999){
        return "One Thousand "+ NumberToText(num%1000);
    }//50000 ->50 ->5
    if(num>=2000 && num<=999999){
        return NumberToText(num/1000)+"Thousands "+ NumberToText(num%1000) ;
    }
    if(num>=1000000 && num<=1999999){
        return "One Million "+NumberToText(num%1000000);
    }
    if(num>=2000000 && num <=99999999){
        return NumberToText(num/1000000) + "Millions " + NumberToText(num%1000000);  
    }
    if(num>=1000000000 && num <=1999999999){
        return "One Billion "+NumberToText(num%1000000000);
    } else {
        return NumberToText(num/1000000000)+ "Billions "+NumberToText(num%1000000000);
    }
}
int main(){
    cout<<NumberToText(ReadNumber());
    return 0;
}

