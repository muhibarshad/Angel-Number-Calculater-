#include<iostream>
#include<cstring>
#include<cctype>
#include<iomanip>
using namespace std;

void menu();
void calculate_by_name();
void calculate_by_birth_date();
string tolowerString(string &);
int sumArr(int [], const int);
int convert_number_single(int );
void printIntArray(int [], const int);

int main()
{
    menu();
    return 0;
}

string tolowerString(string &name)
{
    string lower_string;
    for(int i =0;name[i]!='\0';i++){
        if(name[i]!=' ')
        lower_string += towlower(name[i]);
    }
    return lower_string;
}
int sumArr(int arr[], const int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
void printIntArray(int arr[], const int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"\n";
    }
}
int convert_number_single(int sum_val)
{
    int num = sum_val;
    int singal_digit =0;
    bool flag =false;
    while(flag == false)
    {
        int rem = 0;
        rem = num % 10;
        singal_digit+=rem;
        if(num == 0)
        flag =true;
        num = num /10;
     
    }
    return singal_digit;
}
void calculate_by_name()
{
    string name;
    string original_name;
    cout<<"Enter your name : \n";
    cin.ignore();
    getline(cin, name);
    original_name= name;

    //Coverting the string into without spaces lowercase string 
    name = tolowerString(name);

    //Copying the string into char_Arr
    int str_size = name.length();
    char str_name[str_size];
    strcpy(str_name, name.c_str());

    //Intializing the basic_alphabets_data
    int cross_num_Arr[str_size]{0};
    int sum_Val=0;
    char alphabets[26]={
    'a','b','c','d','e','f'
    ,'g','h','i','j','k'
    ,'l','m','n','o','p','q'
    ,'r','s','t','u','v','w',
    'x','y','z'};

    //Calculating the values of character to its crossponding element and Add them 
    for(int i=0;str_name[i]!='\0';i++)
    {
        bool flag = false;
        int j=0;
        while(flag==false)
        {
            if(str_name[i]==alphabets[j]){
                flag=true;
                cross_num_Arr[i]=j+1;
            }
            j++;
        }
    }
    sum_Val=sumArr(cross_num_Arr, str_size);

    //Now make it single with, by adding reminders
    int angeal_num_by_name= convert_number_single(sum_Val);
    cout<<"Angel Number of "<<original_name<<" = "<<angeal_num_by_name<<"\n";
}
void calculate_by_birth_date()
{
    int date, mon, year;
    cout<<"Enter the year :\n";
    cin>>year;
    cout<<"Enter the month number \n";
    cin>>mon;
    cout<<"Entre the date number \n";
    cin>>date;
    int arr[3]={convert_number_single(date), convert_number_single(mon), convert_number_single(year)};
    int angeal_num_by_dateOfBirth = arr[0]+arr[1]+arr[2];
    angeal_num_by_dateOfBirth=convert_number_single(angeal_num_by_dateOfBirth);
    cout<<"Angel Number by your date of birth "<<date<<"-"<<mon<<"-"<<year<<" = "<<angeal_num_by_dateOfBirth<<"\n";
}
void menu()
{
    int n=0;
    cout<<left;
    cout<<setw(5)<<" Calculate your Angle Number :\n";
    cout<<"Enter the 1 to calculate by name: \n";
    cout<<"Enter the 2 to calculate by birth date: \n";
    cin>>n;
    switch(n){
        case 1:
        {
            calculate_by_name();
            break;
        }
        case 2:
        {
            calculate_by_birth_date();
            break;
        }
    }
}