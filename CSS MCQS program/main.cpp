#include<iostream>
#include<conio.h>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include"Questions.h"

using namespace std;

int ran(int i);
void show(const vector<Questions> &questions, int random);
char my_answer();
void check(const vector<Questions> &answers,int random,char ans);

//global variables
unsigned int correct_answer{0};
int lives{3};



//Driver code
int main(){
	srand(time(0));


	vector<Questions> questions=question_vec(); //vector of questions

	int total_questions=size(questions)-1;

	string player=welcome(); //name of the player and welcome msg
	instructions();


	 //for loop for asking i number of question

	for(int i=10;i>=1;i--){
		int random_num{ran(total_questions)}; //gives a random number in the range of 1 to total_questions available
		total_questions--;

		show(questions,random_num);//shows the question and its options
		check(questions,random_num,my_answer()); //asks the user for answer and check if its right or wrong


		cout<<"Press any key to continue"<<endl;
		cout<<"      "<<endl;
		getch();
		system("cls"); //to clear the console


		questions.erase(questions.begin()+random_num); //removes the asked questions so that they dont repeat


		if(lives<1){ //condition to check if the user has run out of lives
			cout<<"You have run out of Lives \n Press any key to continoue"<<endl;
			getch();
			break;
		}

	}

	//shows how many correct answer the user has given
	cout<<player<<" Total correct answers you have given are "<<correct_answer<<endl;
	cout<<"Press any key to continoue ";
	getch();
	system("cls");
	credits();



	return 0;

}





//functions definitions start from here

//ran function to get random number
int ran(int i){
  return (rand() % i) + 1;
}

//function to display the question and its options
void show(const vector<Questions> &questions,int random){
	static unsigned int q_no{1}; //to show the number of questions

	Questions ques{(questions.at(random))};
	cout<<"Q No: "<<q_no<<": "<<ques.question<<endl;
	cout<<"Options are:"<<endl;
	cout<<"     "<<endl;
	q_no++;

	//this here display all avaliable options for the question
	cout<<ques.choices<<endl;
	cout<<"    "<<endl;
}


//function asks the user for their answer
char my_answer(){
	string ans;
	cout<<"Enter your answer ";
	cin>>ans;


	while(ans!="a" && ans!="b" && ans!="c" && ans!="d"){
		cout<<"Please enter a valid option "<<endl;
		cout<<"Enter your answer ";
		cin>>ans;
	}

	char user_answer=tolower(ans[0]); //user might enter uppercase letter to solve this

	return user_answer;
}


//functions check if the user asnwered option is correct or not
void check(const vector<Questions> &answers,int random,char ans){

	char correct_ans= (answers.at(random)).ans;
	if(ans==correct_ans){
		cout<<"correct answer "<<endl;
		cout<<"      "<<endl;
		correct_answer++;
	}

	else{
		cout<<"Wrong answer "<<endl;
		cout<<"Correct answer is "<<correct_ans<<endl;
		cout<<"    "<<endl;
		lives--;
		cout<<"You have "<<lives<<" chances left "<<endl;
	}

}



