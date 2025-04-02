#include <iostream>
#include <cstdio>
using namespace std;

bool leapyr(int a){
	if (a%4 == 0){
		if (a%400 == 0 || a%100 != 0){
			return true;
		}
	}else{
		return false;
	}
}

int day_date(int date, int month, int user_year){
	//creating a copy for the year 
	int year= user_year;

	//initialising odd days
	int odd_days=0;

	//creating an array for the month code
	int month_code[]={3,0,3,2,3,2,3,3,2,3,2,3};
	if (leapyr(year) == true){
		month_code[1] += 1;
	}

	//since the year we take as the input is not completed, we the previous year for calculation
	year = year-1;

	//every 400 days have 0 odd days
	int yr_pt1, yr_pt2;
	yr_pt1= year%400; //taking modulus by dividing by 400

	year=(year-yr_pt1);

	//we check different cases
	if (yr_pt1 >300){
		yr_pt2=yr_pt1%300;
		odd_days+=1; //every 300 days have 1 odd day
	}
	else if (yr_pt1>200 && yr_pt1 <300){
		yr_pt2=yr_pt1 %200;
		odd_days+=3; //every 200 days have 3 odd days
	}
	else if (yr_pt1 > 100 && yr_pt1 <200){
		yr_pt2= yr_pt1 %100;
		odd_days+=5; //every 100 days have 5 odd days
	}
	else{
		yr_pt2 = yr_pt1; 
	}

	//calculating the number of leap years in the remaining part of the year
	int leap = yr_pt2/4;

	int leap_odd = leap*2; //every leap year has 2 odd days

	//we calculate the number of years that are not leap year
	int ordinary_yrs = yr_pt2 - leap; //every ordinary year has 1 odd day

	int odd = (leap_odd + ordinary_yrs);
	odd_days = odd_days+ odd; //total odd days calculated on the basis of the year

	for (int j=0; j < (month-1) ; j++){
		odd_days = odd_days + month_code[j]; //adding odd days for each month

	}
	return odd_days + date; //adding odd days for the date 
}

int main(){
	//taking user input
	int date,month,user_year;
	cin>>date;
	cin>>month;
	cin>>user_year;

	//calling the function
	int fn = day_date(date,month,user_year);

	//we will find the remainder by taking modulus from 7 
	int result = fn%7;
	printf("the date %i\n",date);
	printf("month %i\n", month);
	printf("year %i\n ", user_year);

	//on the basis of remainder, we will tally with the day code hence getting the final result!
	if (result==1){
		cout<<"falls on monday";
	}if (result==2){
		cout<<"falls on tuesday";
	}if (result==3){
		cout<<"falls on wednesday";
	}if (result==4){
		cout<<"falls on thursday";
	}if (result==5){
		cout<<"falls on friday";
	}if (result==6){
		cout<<"falls on saturday";
	}if (result==0){
		cout<<"falls on sunday";
	}
	return 0;	
}