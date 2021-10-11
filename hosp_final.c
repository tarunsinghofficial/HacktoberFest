/*
Name:	Hospital Management System
Author:	Tejas A. Sheth
Version:	2.9			//(major change . minor edit )
Description:	
	create a new patients file, manage his/her appointment, keep a note of all specialists,
	tests provided by the hospital, final bill incured by a patient. 
			
v1.0 = refer hospital_demo1.c => created an admin,staff function and tried to get a log in id for both
v1.1 = created log in id for admin(static) and added fucntions like add_staff,delete_staff,etc
v1.2 = created the staff function which asked the staff to input any patients details and financial condition and medical background
v2.0 = revamped the whole code to make a different approach
v2.1 = added ambulance services function
v2.2 = added insurance function
v2.3 = added specialist charges and consultation charges
v2.4 = added a report function to generate an overview of the patients activity
v2.5 = added random function and files to the code, to generate an unique code each time executed				 	
v2.6 = added code to read data from the file using id
v2.7 = minor adjustments, font size, indentation in O/P,etc
v2.8 = added pending medical background function, still unfunctional...oopss!!!!
v2.9 = 

*/

// most imp part now pending is 
// DONE	=== adding a file to the code to store a patients data safely and accessing it whenever called upon.
// DONE	=== ### find how to extract line by line the contents of the file ###
// DONE	=== calculating final_bill with an 5% gst, displaying (patients personal details + medical background questionairre + government aid(y/n) + specialist visited + tests taken + FINAL BILL) 
// DONE	=== can also add specialist charges seperately.  !! 
// DONE	=== calculating the final report is a challenge...!!!
// DONE	=== insurance aahe ki nahi just...
// DONE	=== ambulance used or not...

// a code to print date and time automatically in the report and bill.
// link another code(.c file) which would generate the customer bill
// link the bank to this code for better transactions
// before that, update the bank.c to alow user-2-user transactions
// need to find a way to just extract a single line from a file using a code and modify the value for bank_transaction
// 
// 



#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#include<windows.h>
#include <stdbool.h>


//global variables
/*
float sub_total=0, cnslt_chrg=0, amb_chrg=0, total, grand_total;
char moretests;
char id[7];
char buffer[1000];
int test;

char name[1000], locality[1000], city[1000], state[1000], mno[1000], tele[1000], age[100];
char conf_sub_total[1000], conf_cnslt_chrg[1000], conf_total[1000], conf_grand_total[1000];
int num;

*/


//variables used for storing input and initialization
int lower=1,upper=300000,count=1;
char id[7];
int num;

char name[1000], locality[1000], city[1000], state[1000], mno[1000], tele[1000], age[100];

char a[10], b[10], c[10], d[10], e[10], f[10], g[10], h[10], i[10], j[10];

char buffer[1000];



//variables used for charges incured in hospital
float amb_chrg=0;
float cnslt_chrg=0;
float sub_total=0;
float total;
float conc_total;
float grand_total;

char conf_amb_chrg[1000];		//***************************************//
char conf_sub_total[1000];
char conf_cnslt_chrg[1000];
char conf_total[1000];
char conf_conc_total[1000];
char conf_grand_total[1000];



//used for loop iterations,
char amb;
int amb_typ;

int fc;
char insur;
int h_insur;

int sp;
char loadmore;

int test;
char moretests;



//function declarations
void hospital_mngmt();	//
void flow();			//
void p_new();			//new patient function
void pers_det();		//personal details of patient function
void dspy_persdet();	//DONE
void amb_srvs();		//ambulance services ****************************
void pat_medbg();		//patient medical background questionaire function
void dspy_pat_medbg();	//DONE
void pat_fc();			//patient financial condition and corresponding government aids available function
void specialist();		//specialists available in the hospital list function
void dspy_splst();		//UN-USED
void test_det();		//tests needed to perform and their prices function
void dspy_testdet();	//UN-USED
void bill();			//final bill generation function
void dspy_bill();		//UN-USED
void report();			//display per_det,pat_medbg,specialist,test_det,bill function
void random();			//function for genrating an id( random ) for user-identification


FILE *pat_data;

void random(int lower, int upper, int count)
{
	num = (rand()%(upper-lower+1))+lower;
	printf("\tYour Unique-ID is: %d \n",num);
}

void header()
{
	printf("\n\n\t\t\t\t***WELCOME TO XYZ HOSPITAL***\n");
	printf("\t\t\t\t\t\tPATIENT FIRST.\n");
	printf("\t\t\t\t\t\tAssuring.Advanced.Accessible.\n");
}

void intro()
{   printf("\t\tThe quality of care provided at A3 Hospital is tantamount to any other top-ranking hospitals in the world.\n");            
    printf("\t\t\tWe are equipped with the finest cardiac, cancer and paediatric care,\n");
    printf("\t\t\tas well as liver and kidney transplantation facility.\n");
    printf("\t\tWe are the regions first institution with an NABH accreditation by the Quality Council of India.\n");
}

void hospital_mngmt()
{
	
	intro();
	int lower=1,upper=300000,count=1;
//	char id[7];
	
	tryagain:
		srand(time(0));
		
		random(lower,upper,count);
		
		printf("\tRe-enter your Unique-ID: ");
		gets(id);
		pat_data=fopen(id,"a");

		if(pat_data!=NULL)
		{
			printf("\tFILE CREATED \n\n\tLOADING");
			
			system("pause");
			system("cls");
			flow();
			fclose(pat_data);
//			goto label1;
		}
		else
		{
			printf("\tFILE NOT FOUND...! \n\n");
			printf("\tLOADING");
			
			system("pause");
			system("cls");
			goto tryagain;
		}
			
		printf("\tLOADING");
		
		system("pause");
		system("cls");	
	//read file begins
	
	report();
}

void flow()			//flow of the program function
{
	p_new();
	printf("\t\t\t-X--X--X--X--X--X- \n\n");
	specialist();
	printf("\t\t\t-X--X--X--X--X--X- \n");
	printf("\t\t\t-X--X--X--X--X--X- \n\n");
	test_det();
	printf("\t\t\t-X--X--X--X--X--X- \n");
	printf("\t\t\t-X--X--X--X--X--X- \n");
	printf("\t\t\t-X--X--X--X--X--X- \n\n");
	bill();
	printf("\t\t\t-X--X--X--X--X--X- \n");
	printf("\t\t\t-X--X--X--X--X--X- \n");
	printf("\t\t\t-X--X--X--X--X--X- \n");
	printf("\t\t\t-X--X--X--X--X--X- \n\n");
}

void p_new()
{
	printf("\t\tEnter the Patient's Personal Details: \n\n");
	pers_det();
	printf("\t\tEnter the Patient's Medical History: \n\n");
	pat_medbg();	//need to check this section again.
	printf("\t\tDescribe the Patient's Financial Condition: \n\n");
	pat_fc();
}

void pers_det()				//this should be merged into a file and stored
{
//	char name,locality,city,state,mno,tele;
//	int age;
	
	printf("\tEnter First Name: \t");	
//	scanf("%s",&name);
	gets(name);
	printf("\tEnter Age(in years): \t");
//	scanf("%d",&age);
	gets(age);
	printf("\tEnter Residential Locality: \t");	
//	scanf("%s",&locality);	
	gets(locality);
	printf("\tEnter Residential City: \t");	
//	scanf("%s",&city);	
	gets(city);
	system("pause");
			system("cls");
	printf("\tEnter Residential State: \t");	
//	scanf("%s",&state);		
	gets(state);
	printf("\tEnter Contact Information :- \n");
	printf("\tMobile Number (Mandatory): \t");	
//	scanf("%s",&mno);
	gets(mno);
	printf("\tEnter Landline / Emergency Contact Number (Optional, enter '/' if N.A.): \t");
//	scanf("%s",&tele);
	gets(tele);
	printf("\n");
//data stored successfully..
	
	dspy_persdet();
	
	printf("\tLOADING");
	
	amb_srvs();
}

void dspy_persdet()
{
	fprintf(pat_data,"\t\t\t A) Personal Details ===>");
	fprintf(pat_data, "\n\n");
//	fprintf(pat_data, "\n");
	fprintf(pat_data,"\tFirst Name: ");
	fputs(name,pat_data);
	fprintf(pat_data, "\n");
	fprintf(pat_data,"\tAge: ");
	fputs(age,pat_data);
	fprintf(pat_data, "\n");
	fprintf(pat_data,"\tLocality: ");
	fputs(locality,pat_data);
	fprintf(pat_data, "\n");
	fprintf(pat_data,"\tCity: ");
	fputs(city,pat_data);
	fprintf(pat_data, "\n");
	fprintf(pat_data,"\tState: ");
	fputs(state,pat_data);
	fprintf(pat_data, "\n");
	fprintf(pat_data,"\tMobile Number: ");
	fputs(mno,pat_data);
	fprintf(pat_data, "\n");
	fprintf(pat_data,"\tTelephone Number: ");
	fputs(tele,pat_data);
	fprintf(pat_data, "\n\n");
//	fprintf(pat_data, "\n");

}

void amb_srvs()
{
//	char amb;
//	int amb_typ;
//	int amb_chrg=0;
// 	Types of EKAB ambulances. (A,B) Basic type of Ambulance; (C) Mobile Intensive Care Units; (D) Motorcycle ambulances; (E) Small vehicles for minor roads; 
	printf("\tIs the Patient brought to the Hospital in an Ambulance? (Y/N): ");
//	scanf("%c",&amb);
	scanf("%s",&amb);
	printf("\n");
	if(amb=='y' || amb=='Y')
	{
	ambulance:
		printf("\tWhich type of Ambulance was used? \n");
		printf("\t0. No Ambulance. \n");
		printf("\t1. Basic type of Ambulance. \n");
		printf("\t2. Mobile Intensive Care Unit Ambulance. \n");
		printf("\t3. Motorcycle Ambulance. \n");
		printf("\t4. Small vehicle for Minor road Ambulance. \n");
		printf("\tEnter your Option:- ");
		scanf("%d",&amb_typ);
		printf("\n");
		
		switch(amb_typ)
		{
			case 0:
				printf("\tAmbulance Type: N.A. \n");
					fprintf(pat_data,"\tAmbulance Type: N.A.");
					fprintf(pat_data, "\n\n");
				printf("\n");
				break;
				
			case 1:
				printf("\tAmbulance Type: Basic. \n");
				printf("\tAmbulance Charge = Rs. 1500\n");
					fprintf(pat_data,"\tAmbulance Type: Basic.");
					fprintf(pat_data, "\n\n");
				amb_chrg=amb_chrg+1500;
				printf("\n");
				break;
			case 2:
				printf("\tAmbulance Type: Mobile Intensive Care Unit. \n");
				printf("\tAmbulance Charge = Rs. 3000\n");				
					fprintf(pat_data,"\tAmbulance Type: Mobile Intensive Care Unit.");
					fprintf(pat_data, "\n\n");
				amb_chrg=amb_chrg+3000;
				printf("\n");
				break;
			case 3:
				printf("\tAmbulance Type: Motorcycle. \n");
				printf("\tAmbulance Charge = Rs. 2750\n");
					fprintf(pat_data,"\tAmbulance Type: Motorcycle.");
					fprintf(pat_data, "\n\n");
				amb_chrg=amb_chrg+2750;
				printf("\n");
				break;
			case 4:
				printf("\tAmbulance Type: Small vehicle for Minor Road. \n");
				printf("\tAmbulance Charge = Rs. 4000\n");
					fprintf(pat_data,"\tAmbulance Type: Small vehicle for Minor Road.");
					fprintf(pat_data, "\n\n");
				amb_chrg=amb_chrg+4000;
				printf("\n");
				break;
			default:
				printf("\tWrong Input. \n");	
				printf("\n");
				goto ambulance;
		}	
	}
	else
	{
		printf("\tAmbulance Service Availed: NO. \n");
			fprintf(pat_data,"\tAmbulance Type: N.A.");
			fprintf(pat_data, "\n\n");
	}
	
	system("pause");
			system("cls");
	printf("\tAMBULANCE-CHARGE  = %f \n",amb_chrg);
	printf("\tConfirm ");
	gets(conf_amb_chrg);			//not printing, if written directly.
	printf("AMBULANCE-CHARGE = ");
	gets(conf_amb_chrg);
		fprintf(pat_data,"\tAMBULANCE-CHARGE = Rs. ");
		fputs(conf_amb_chrg,pat_data);
		fprintf(pat_data, "\n\n");
	printf("\n\n");
	
	printf("\tLOADING");
	
system("pause");
			system("cls");
}

void pat_medbg()
{
	
	printf("\tAnswer the Following Questions to the most of your Knowledge. \n");
	printf("\t01. Has you doctor ever said your blood pressure was too high or too low?(Y/N): ");
//	scanf("%s",&a);
	gets(a);
	printf("\n");
	printf("\t02. Do you have any known cardiovascular problems (abnormal ECG, previous heart attack, etc)?(Y/N): ");
//	scanf("%s",&b);
	gets(b);
	printf("\n");
	printf("\t03. Has your doctor ever told you that your cholesterol was too high?(Y/N): ");
//	scanf("%s",&c);
	gets(c);
	printf("\n");
	printf("\t04. Have you (or a family member) ever been told that you have diabetes?(Y/N): ");
//	scanf("%s",&d);
	gets(d);
	printf("\n");
	printf("\t05. Do you have any injuries or orthopedic problems (back, knees, etc)?(Y/N): ");
//	scanf("%s",&e);
	gets(e);
	printf("\n");
	printf("\t06. Do you have stisff or swollen joints?(Y/N): ");
//	scanf("%s",&f);
	gets(f);
	printf("\n");
	printf("\t07. Do you have tension or soreness in any area?(Y/N): ");
//	scanf("%s",&g);
	gets(g);
	printf("\n");
	printf("\t08. Are you taking any prescribed medications or dietary supplementation?(Y/N): ");
//	scanf("%s",&h);
	gets(h);
	printf("\n");
	printf("\t09. Do you ever have problems sleeping?(Y/N): ");
//	scanf("%s",&i);
	gets(i);
	printf("\n");
	system("pause");
			system("cls");
	printf("\t10. Have you ever been advised by a doctor, physician or specialist not to perform any type of exercise/activity?(Y/N): ");	
//	scanf("%s",&j);
	gets(j);
	printf("\n");
	
	dspy_pat_medbg();
	
	printf("\tLOADING");
	
	
}
	
void dspy_pat_medbg()
{
	fprintf(pat_data,"\t\t\t B) Medical Background ===>");					
	fprintf(pat_data,"\n\n");
	
	fprintf(pat_data,"\t01. Has you doctor ever said your blood pressure was too high or too low? : ");
	fputs(a,pat_data);
	fprintf(pat_data, "\n");

	fprintf(pat_data,"\t02. Do you have any known cardiovascular problems (abnormal ECG, previous heart attack, etc)? : ");
	fputs(b,pat_data);
	fprintf(pat_data, "\n");
	
	fprintf(pat_data,"\t03. Has your doctor ever told you that your cholesterol was too high? : ");
	fputs(c,pat_data);
	fprintf(pat_data, "\n");

	fprintf(pat_data,"\t04. Have you (or a family member) ever been told that you have diabetes? : ");
	fputs(d,pat_data);
	fprintf(pat_data, "\n");
	
	fprintf(pat_data,"\t05. Do you have any injuries or orthopedic problems (back, knees, etc)?: ");
	fputs(e,pat_data);
	fprintf(pat_data, "\n");
	
	fprintf(pat_data,"\t06. Do you have stiff or swollen joints? : ");
	fputs(f,pat_data);
	fprintf(pat_data, "\n");
	
	fprintf(pat_data,"\t07. Do you have tension or soreness in any area? : ");
	fputs(g,pat_data);
	fprintf(pat_data, "\n");
	
	fprintf(pat_data,"\t08. Are you taking any prescribed medications or dietary supplementation? : ");
	fputs(h,pat_data);
	fprintf(pat_data, "\n");
	
	fprintf(pat_data,"\t09. Do you ever have problems sleeping? : ");
	fputs(i,pat_data);
	fprintf(pat_data, "\n");
	
	fprintf(pat_data,"\t10. Have you ever been advised by a doctor, physician or specialist not to perform any type of exercise/activity? : ");
	fputs(j,pat_data);
	fprintf(pat_data, "\n\n");
}

void pat_fc()			//need the same for this function as well..like for pat_medbg
{
	int fc;
	
		fprintf(pat_data,"\t\t\t C) Financial Condition & Insurance ===>");					
		fprintf(pat_data,"\n\n");
	
	g_aid:
		printf("\tSelect the Patient's Apprx. Annual Income Range(in Rs.) \n");
		printf("\t1. <=1,00,000 \n");
		printf("\t2. 1,00,001 - 5,00,000 \n");
		printf("\t3. 5,00,001 - 10,00,000 \n");
		printf("\t4. >=10,00,001 \n");
		printf("\tChoose appropriate Income Bracket :- ");
		scanf("%d",&fc);
		printf("\n");
	
		switch(fc)
		{
			case 1:
				printf("\tGovernment Aid available upto Rs. 2,50,000 \n");
					fprintf(pat_data,"\tGovernment Aid: Rs. 2,50,000.");
					fprintf(pat_data, "\n");
				printf("\n");
				break;
			case 2:
				printf("\tGovernment Aid available upto Rs. 2,00,000 \n");
					fprintf(pat_data,"\tGovernment Aid: Rs. 2,00,000.");
					fprintf(pat_data, "\n");
				printf("\n");
				break;
			case 3:
				printf("\tGovernment Aid available upto Rs. 1,00,000 \n");
					fprintf(pat_data,"\tGovernment Aid: Rs. 1,00,000.");
					fprintf(pat_data, "\n");
				printf("\n");
				break;
			case 4:
				printf("\tNot eligible for any benefits under Government Scheme \n");
					fprintf(pat_data,"\tGovernment Aid: N.A.");
					fprintf(pat_data, "\n");
				printf("\n");
				break;
			default:
				printf("\tWrong Input \n");
				printf("\n");
				goto g_aid;
	}
	
	printf("\tLOADING");
	
	
	char insur;
	int h_insur;
	
	printf("\tDoes the Patient have a Health Insurance Policy?(Y/N): ");
	scanf("%s",&insur);
	if(insur=='y' || insur=='Y')
	{
		//mediclaim, critical illness cover, hospital cash plan, and personal accident insurance.
	insurance:
		printf("\tSelect which Health Insurance Policy the Patient has.. \n");
		printf("\t1. MediClaim Policy. \n");
		printf("\t2. Critical Illness Cover. \n");
		printf("\t3. Hospital Cash Plan. \n");
		printf("\t4. Personal Accident Insurance. \n");
		printf("\tEnter your Option:- ");
		scanf("%d",&h_insur);
		printf("\n");
		
		switch(h_insur)
		{
			case 1:
				printf("\tHealth Insurance Policy: MediClaim Policy. \n");
					fprintf(pat_data,"\tHealth Insurance Policy: MediClaim Policy.");
					fprintf(pat_data, "\n\n");
				printf("\n");
				break;
			case 2:
				printf("\tHealth Insurance Policy: Critical Illness Cover. \n");
					fprintf(pat_data,"\tHealth Insurance Policy: Critical Illness Cover.");
					fprintf(pat_data, "\n\n");
				printf("\n");
				break;
			case 3:
				printf("\tHealth Insurance Policy: Hospital Cash Plan. \n");
					fprintf(pat_data,"\tHealth Insurance Policy: Hospital Cash Plan.");
					fprintf(pat_data, "\n\n");
				printf("\n");
				break;
			case 4:
				printf("\tHealth Insurance Policy: Personal Accident Insurance. \n");
					fprintf(pat_data,"\tHealth Insurance Policy: Personal Accident Insurance.");
					fprintf(pat_data, "\n\n");
				printf("\n");
				break;
			default:
				printf("\tWrong Input. \n");
				printf("\n");
				goto insurance;		
		}
	}
	else
	{
		printf("\tHealth Insurance Policy: N.A. \n");
			fprintf(pat_data,"\tHealth Insurance Policy: N.A.");
			fprintf(pat_data, "\n\n");
		printf("\n");
	}
	
	printf("\tLOADING");
	
}

void specialist()
{
//	float cnslt_chrg=0;
	
	int sp;
	fprintf(pat_data,"\t\t\t D) Specialist Consulted ===>");
	fprintf(pat_data, "\n\n");
	
	refer:
		printf("\tWhich Specialist would you like to Consult..\n");
		printf("\t  :Specialists:/ Room No.\n");
		printf("\t1.General Physician / 201,202 \n");
		printf("\t2.E.N.T / 302 \n");
		printf("\t3.Cardiologist / 509 \n");
		printf("\t4.Dermatologist / 406 \n");
		printf("\t5.Gastroenterologist / 308 \n");
		printf("\t6.Pediatrician / 207 \n");
		printf("\t7.EYE Specialist / 102 \n");
		printf("\t8.Nephrologist / 109 \n");
		printf("\t9.General Surgeon / 407,408,412,413 \n");
		printf("\t10.Accupuncturist / 119,123 \n");
		printf("\tEnter your Preference :- ");
		scanf("%d",&sp);
		printf("\n");
	
		switch(sp)
		{																
			case 1:
				printf("\tReferring to : General Physician \n");
				printf("\tVisit Room No. : 201,202 \n");
				printf("\tConsulting Charge @ Rs. 250 \n");
					fprintf(pat_data,"\tReferring to: General Physician.");
					fprintf(pat_data, "\n\n");
				cnslt_chrg=cnslt_chrg+250;
				printf("\n");
				break;
			case 2:
				printf("\tReferring to : E.N.T. \n");
				printf("\tVisit Room No. : 302 \n");
				printf("\tConsulting Charge @ Rs. 500 \n");
					fprintf(pat_data,"\tReferring to: E.N.T.");
					fprintf(pat_data, "\n\n");
				cnslt_chrg=cnslt_chrg+500;
				printf("\n");
				break;
			case 3:
				printf("\tReferring to : Cardiologist \n");
				printf("\tVisit Room No. : 509 \n");
				printf("\tConsulting Charge @ Rs. 350 \n");
					fprintf(pat_data,"\tReferring to: Cardiologist.");
					fprintf(pat_data, "\n\n");
				cnslt_chrg=cnslt_chrg+350;
				printf("\n");
				break;
			case 4:
				printf("\tReferring to : Dermatologist \n");
				printf("\tVisit Room No. : 406 \n");
				printf("\tConsulting Charge @ Rs. 250 \n");
					fprintf(pat_data,"\tReferring to: Dermatologist.");
					fprintf(pat_data, "\n\n");
				cnslt_chrg=cnslt_chrg+250;
				printf("\n");
				break;
			case 5:
				printf("\tReferring to : Gastroenterologist \n");
				printf("\tVisit Room No. : 308 \n");
				printf("\tConsulting Charge @ Rs. 300 \n");
					fprintf(pat_data,"\tReferring to: Gastroenterologist.");
					fprintf(pat_data, "\n\n");
				cnslt_chrg=cnslt_chrg+300;
				printf("\n");
				break;
			case 6:
				printf("\tReferring to : Pediatrician \n");
				printf("\tVisit Room No. : 207 \n");
				printf("\tConsulting Charge @ Rs. 200 \n");
					fprintf(pat_data,"\tReferring to: Pediatrician.");
					fprintf(pat_data, "\n\n");
				cnslt_chrg=cnslt_chrg+200;
				printf("\n");
				break;
			case 7:
				printf("\tReferring to : EYE Specialist \n");
				printf("\tVisit Room No. : 102 \n");
				printf("\tConsulting Charge @ Rs. 400 \n");
					fprintf(pat_data,"\tReferring to: EYE Specialist.");
					fprintf(pat_data, "\n\n");
				cnslt_chrg=cnslt_chrg+400;
				printf("\n");
				break;
			case 8:
				printf("\tReferring to : Nephrologist \n");
				printf("\tVisit Room No. : 109 \n");
				printf("\tConsulting Charge @ Rs. 500 \n");
					fprintf(pat_data,"\tReferring to: Nephrologist.");
					fprintf(pat_data, "\n\n");
				cnslt_chrg=cnslt_chrg+500;
				printf("\n");
				break;
			case 9:
				printf("\tReferring to : General Surgeon \n");
				printf("\tVisit Room No. : 407,408,412,413 \n");
				printf("\tConsulting Charge @ Rs. 750 \n");
					fprintf(pat_data,"\tReferring to: General Surgeon.");
					fprintf(pat_data, "\n\n");
				cnslt_chrg=cnslt_chrg+750;
				printf("\n");
				break;
			case 10:
				printf("\tReferring to : Accupuncturist \n");
				printf("\tVisit Room No. : 119,123 \n");
				printf("\tConsulting Charge @ Rs. 350 \n");
					fprintf(pat_data,"\tReferring to: Accupuncturist.");
					fprintf(pat_data, "\n\n");
				cnslt_chrg=cnslt_chrg+350;
				printf("\n");
				break;
			default:
				printf("\tWrong Input \n");
				printf("\n");
				goto refer;
		}
//	printf("Consulting Charges = %f \n",cnslt_chrg);

	printf("\tCONSULTING-CHARGES = %f \n",cnslt_chrg);
/*	printf("Confirm CONSULTING-CHARGES = ");
	gets(conf_cnslt_chrg);	
	*/
	printf("\tConfirm ");
	gets(conf_cnslt_chrg);			//not printing, if written directly.
	printf("CONSULTING-CHARGES = ");
	gets(conf_cnslt_chrg);	
		fprintf(pat_data,"\tCONSULTING-CHARGES = Rs. ");
		fputs(conf_cnslt_chrg,pat_data);
		fprintf(pat_data, "\n\n");
	printf("\n");

	printf("\tLOADING");
	

} 

void test_det()
{
//	float sub_total=0;
	
	printf("\tGo through ALL the tests suggested by your Specialist. \n");
	printf("\n");
		fprintf(pat_data,"\t\t\t E) Medical Test Carried ===>");
		fprintf(pat_data, "\n\n");
	
	do
	{
	test:
		printf("\t\t::ADDITIONAL SERVICES::\n");
		printf("\t\t    :TEST LIST:\n");
		printf("\t0. No Test = Rs. 00.00 \n");		
		printf("\t1.X-Ray = Rs. 300.00 \n");
		printf("\t2.Ultra-sound = Rs. 500.00 \n");
		printf("\t3.C.T.Scan = Rs.1800.00 \n");
		printf("\t4.TC,DC,HB = Rs.  90.00 \n");
		printf("\t5.Urine R/E = Rs.  80.00 \n");
		printf("\t6.Blood C/S = Rs. 250.00 \n");
		printf("\t7.Biliribin D/T = Rs. 200.00 \n");
		printf("\t8.Stool Test = Rs.  60.00 \n");
		printf("\t9.Sugar Test = Rs. 400.00 \n");	
		printf("\tEnter Appropriate Number According to the test suggested by your Specialist.. :- ");
		scanf("%d",&test);
		printf("\n");
		
		switch(test)
		{
			case 0:
				printf("\tNo Test Suggested \n");
					fprintf(pat_data,"\tTest Suggested: N.A.");
					fprintf(pat_data, "\n");
				printf("\n");
				break;
			case 1:
				printf("\tX-Ray Test @ Rs. 300.00 \n");
					fprintf(pat_data,"\tTest Suggested: X-Ray Test.");
					fprintf(pat_data, "\n");
				sub_total=sub_total+300;
				printf("\n");
				break;
			case 2:
				printf("\tUltra-Sound Test @ Rs. 500.00 \n");
					fprintf(pat_data,"\tTest Suggested: Ultra-Sound Test.");
					fprintf(pat_data, "\n");
				sub_total=sub_total+500;
				printf("\n");
				break;
			case 3:
				printf("\tC.T.Scan @ Rs.1800.00 \n");
					fprintf(pat_data,"\tTest Suggested: C.T.Scan.");
					fprintf(pat_data, "\n");
				sub_total=sub_total+1800;
				printf("\n");
				break;
			case 4:
				printf("\tTC,DC,HB @ Rs. 90.00 \n");
					fprintf(pat_data,"\tTest Suggested: TC,DC,HB.");
					fprintf(pat_data, "\n");
				sub_total=sub_total+90;
				printf("\n");
				break;
			case 5:
				printf("\tUrine R/E @ Rs. 80.00 \n");
					fprintf(pat_data,"\tTest Suggested: Urine R/E.");
					fprintf(pat_data, "\n");
				sub_total=sub_total+80;
				printf("\n");
				break;
			case 6:
				printf("\tBlood C/S @ Rs. 250.00 \n");
					fprintf(pat_data,"\tTest Suggested: Blood C/S.");
					fprintf(pat_data, "\n");
				sub_total=sub_total+250;	
				printf("\n");
				break;		
			case 7:
				printf("\tBiliribin D/T @ Rs. 200.00 \n");
					fprintf(pat_data,"\tTest Suggested: Biliribin D/T.");
					fprintf(pat_data, "\n");
				sub_total=sub_total+200;
				printf("\n");
				break;
			case 8:
				printf("\tStool Test @ Rs. 60.00 \n");
					fprintf(pat_data,"\tTest Suggested: Stool Test.");
					fprintf(pat_data, "\n");
				sub_total=sub_total+60;
				printf("\n");
				break;
			case 9:
				printf("\tSugar Test @ Rs. 400.00 \n");
					fprintf(pat_data,"\tTest Suggested: Sugar Test.");
					fprintf(pat_data, "\n");
				sub_total=sub_total+400;
				printf("\n");
				break;
			default:
				printf("\tWrong Choice \n");
				printf("\n");
				goto test;
		}
		
		printf("\tDo you have any other tests pending (Y/N) : ");
		scanf("%s",&moretests);
		printf("\n");
	}while(moretests=='Y' || moretests=='y');

		fprintf(pat_data, "\n");
	printf("\tMandatory Bed Charge = Rs. 150.00 \n");	
	printf("\tHospital Visiting Charge = Rs. 200.00 \n\n");
	printf("\tSub-Total = Additional Services + Ambulance Charges + Bed Charges + Visiting Charges\n\n");
	sub_total=sub_total+amb_chrg+(150+200);
	
/*	printf("\tCONSULTING-CHARGES = %f \n",cnslt_chrg);
	printf("Confirm CONSULTING-CHARGES = ");
	gets(conf_cnslt_chrg);	

	printf("\tConfirm ");
	gets(conf_cnslt_chrg);			//not printing, if written directly.
	printf("CONSULTING-CHARGES = ");
	gets(conf_cnslt_chrg);	
		fprintf(pat_data,"\tCONSULTING-CHARGES = Rs. ");
		fputs(conf_cnslt_chrg,pat_data);
		fprintf(pat_data, "\n");
	printf("\n");
*/	
	printf("\tSUB-TOTAL = %f \n",sub_total);
	printf("\tConfirm ");
	gets(conf_sub_total);			//not printing, if written directly.
	printf("SUB-TOTAL = ");
	gets(conf_sub_total);

/*	printf("\tConfirm SUB-TOTAL = ");	
	gets(conf_sub_total);
*/
	
		fprintf(pat_data,"\tSUB-TOTAL = Rs. ");
		fputs(conf_sub_total,pat_data);
		fprintf(pat_data, "\n\n");	
	printf("\n");
	
	printf("\tLOADING");
}

void bill()
{
		fprintf(pat_data,"\t\t\t F) Grand Total ===>");
		fprintf(pat_data, "\n\n");
	printf("\t\t\t***BILL***\n");
	printf("\tTotal = Sub-Total + Consulting Charges\n");
	total = (sub_total + cnslt_chrg);
	printf("\tTOTAL  = %f \n",total);
	printf("\tConfirm TOTAL = ");
	gets(conf_total);
		fprintf(pat_data,"\tTOTAL = Rs. ");
		fputs(conf_total,pat_data);
		fprintf(pat_data, "\n\n");
	printf("\n");
	printf("\tGovernment Taxes :- \n");
	printf("\tCgst=2.5%% \n");				//to display %, need to write %% ++or++ printf("%c",'%') ++or++ printf("%s",'%')
	printf("\tSgst=2.5%% \n");
	grand_total = (total) + (total*5)/100;
	printf("\tGRAND-TOTAL(incl. of all taxes)  = %f \n",grand_total);
	printf("\tConfirm GRAND-TOTAL(incl. of all taxes) = ");
	gets(conf_grand_total);
		fprintf(pat_data,"\tGRAND-TOTAL(incl. of all taxes) = Rs. ");
		fputs(conf_grand_total,pat_data);
		fprintf(pat_data, "\n\n");
	printf("\n");

	printf("\tLOADING");

}


void report()
{
	printf("\t\t\t***XYZ HOSPITAL***\n\n\n");
	
	printf("\t\t\t***PATIENT REPORT***\n\n");
	printf("\t\t\tPatient ID: %d\n\n",id);
	
	pat_data=fopen(id,"r");

	if(pat_data!=NULL)
	{
		printf("\tLOADING");
		while(fgets(buffer,100,pat_data)!=NULL)
		{
		printf("%s",buffer);
		}	
	}
	else
	{
		printf("\tLOADING");
		printf("\tOopss..! \n\tFile Not Found...!\n\n");
	}	
	
	printf("\t\t\tSTAY SAFE! EAT HEALTHY! BE HAPPY!\n");	
}

void main()
{
	hospital_mngmt();
}
