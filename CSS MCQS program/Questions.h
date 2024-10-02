/*
 * Questions.h
 *
 *  Created on: Apr 25, 2022
 *      Author: Abdul Majeed Faraz
 */

#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include<vector>

using namespace std;

class Questions{
	public:
		string question;
		string choices;
		char ans;
	Questions(string q, string options, char correct);
};

Questions::Questions(string q, string options, char correct)
:question{q}, choices{options},ans{correct}{

}

//adding questions
vector<Questions> question_vec(){
	Questions Q0("NONE","NONE",'/');
	Questions Q1("Which is the world's largest continent?", "a: Asia \nb: Europe \nc: Antartica \nd: NOT",'a');
	Questions Q2("Largest country in the world by area is? ","a: China \nb: USA \nc: Russia \nd: India",'c');
	Questions Q3("How many bones does a human body have?" ,"a: 230 \nb: 206 \nc: 150 \nd: 199",'b');
	Questions Q4("Which bear lives in the artic? ","a: Sunbear \nb: Polar bear \nc: Grizzly bear \nd: NOT",'b');
	Questions Q5("Which Mughal Emporer built Taj Mahal? ","a: Akbar \n: Jahangir \nc: Shah Jahan \nd: Humanyun",'c');
	Questions Q6("Which province of Afghanistan is highest producer of opium ","a: Helmand \nb: Ghazni \nc: Kabul \nd: Laghman",'a');
	Questions Q7("Rainiest spot in the word ","a: Emei Shan \nb: San Antonio de Ureca \nc: Cherrapunji \nd: Mawsynram",'d');
	Questions Q8("Country with most natural gas reserves","a: Iran \nb: Qatar \nc: Russia \nd: USA",'c');
	Questions Q9("Most spoken language in the world","a: Arabic \nb: Chinese \nc: English \nd: French",'b');
	Questions Q10("First Railway line was laid in ","a: India \nb: USA \nc: England \nd: Japan",'c');
	Questions Q11("World freest economy in the world with lowest taxes","a: HongKong \nb: Taiwan \nc: China \nd: Japan",'a');
	Questions Q12("World largest producer of Uranium","a: Canada \nb: Australia \nc: Namibia \nd: Kazakhstan",'d');
	Questions Q13("World's largest paper producer","a: USA \nb: China \nc: Japan \nd: NOT",'b');
	Questions Q14("First muslim woman judge in America","a: Fatima Beevi \nb: Ayesha Malik \nc: Delaram Jahani \nd: Sheila Abdus-Salaam",'d');
	Questions Q15("Largest animal in the world","a: Polar Bear \nb: Elephant \nc: Blue Whale \nd: Colosal Squid",'c');

	vector<Questions> question{Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7,Q8,Q9,Q10,Q11,Q12,Q13,Q14,Q15};
	return question;
}

string welcome(){
	string Name;
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t    *************";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t    *TRIVIA GAME*";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t    *************";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t  ====================================";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t  =   Developed By :ASLA CREATORS    =";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t  ====================================";
		cout<<"\n\n";
		cout<<"\n \t\t\t\t\t\t\t\t\t      Please Enter Your Name : ";
		getline(cin,Name);
		cout<<"\n\n";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t       Welcome "<<Name<<"\n";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t This trivia game is for preparation of CSS exam";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t\t Enter Any key ko continoue ";
		getch();
		system("cls");
		return Name;

}

void instructions(){
	cout<<"\t \t \t \t \t \t \t INSTRUCTIONS \n \n";
	cout<<"\t \t \t \t \t \t \t 1: 10 Random question will be shown each time you start the program. \n \n";
	cout<<"\t \t \t \t \t \t \t 2: For each question 4 options will be give as a, b. c. d. \n \n";
	cout<<"\t \t \t \t \t \t \t 3: Type in the correct character as a,b,c,d makesure it is lowercase. \n \n";
	cout<<"\t \t \t \t \t \t \t 4: You will have 3 chances once you answer 3 questions wrong it will over for you. \n \n";
	cout<<"\t \t \t \t \t \t \t 5: In the end how many questions you asnwered correctly will be shown. \n \n";
	cout<<endl<<"\t \t \t \t \t \t \t Press any key to continoue ";
	getch();
	system("cls");
}

void credits(){
	cout<<"\t \t \t \t \t \t \t \t Credits \n \n";
	cout<<"\t \t \t \t \t \t \t \t Created by: \n \n";
	cout<<"\t \t \t \t \t \t \t \t 21CS018 \n \n";
	cout<<"\t \t \t \t \t \t \t \t 21CS016 \n \n";
	cout<<"\t \t \t \t \t \t \t \t 21CS090 \n \n";
	cout<<"\t \t \t \t \t \t \t \t 21CS116 \n \n";
	cout<<endl<<"\t \t \t \t \t \t \t \t Press any key to continoue ";
	getch();
	system("cls");
}



#endif /* QUESTIONS_H_ */
