/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "calcul.h"
#include <stdlib.h>

void
calculation_prog_1(char *host,int a,int b)
{
	CLIENT *clnt;
	int  *result_1;
	intpair  addd_1_arg;
	int  *result_2;
	intpair  mull_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULATION_PROG, CALCULATION_VERS1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	addd_1_arg.a=a;
	mull_1_arg.a=a;
	addd_1_arg.b=b;
	mull_1_arg.b=b;
	result_1 = addd_1(&addd_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("Addition:	%d\n",*result_1);	
	}
	result_2 = mull_1(&mull_1_arg, clnt);
	if (result_2 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("Multiplication:		%d\n",*result_2);	
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


void
calculation_prog_2(char *host,float a,float b)
{
	CLIENT *clnt;
	float  *result_1;
	floatpair  addd_2_arg;
	float  *result_2;
	floatpair  mull_2_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULATION_PROG, CALCULATION_VERS2, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	addd_2_arg.a=a;
	mull_2_arg.a=a;
	addd_2_arg.b=b;
	mull_2_arg.b=b;
	//printf("%f %f\n",addd_2_arg.a,addd_2_arg.b);	

	result_1 = addd_2(&addd_2_arg, clnt);

	if (result_1 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("Addition:	%f\n",*result_1);	
	}
	result_2 = mull_2(&mull_2_arg, clnt);
	if (result_2 == (float *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else{
		printf("Multiplication:		%f\n",*result_2);	
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}

int 
isFloat(char *s){

	int i=0;
	int l=0;
	char *x=s;

	l=strlen(x);
	for(i=0;i<l;i++){
		if((x[i]>=' ')&&(x[i]<'.')||(x[i]>='@')&&(x[i]<='~')){
			return 2;
		}
	}
	if(x[0]=='.'||x[l-1]=='.')
		return 2;
	for(i=0;i<l;i++){
		if(x[i]=='.'){
			return 0;
		}
	}
	return 1;
}

int
main (int argc, char *argv[])
{
	char *host;
	int a,b,flag1=0,flag2=0;
	float a1,b1;

	if (argc != 4) {
		printf ("usage: %s server_host num1 num2\n", argv[0]);
		exit (1);
	}
		
	host = argv[1];
	
	flag1=isFloat(argv[2]);
	flag2=isFloat(argv[3]);
	//printf("%d %d\n",flag1,flag2);	

	if((flag1!=2) || (flag2!=2)){
		if((flag1==1)&&(flag2==1)){
			if((a=atoi(argv[2]))==0 && *argv[2]!='0'){
				fprintf(stderr,"invalid value: %s\n",argv[2]);
				exit(1);
			}

			if((b=atoi(argv[3]))==0 && *argv[3]!='0'){
				fprintf(stderr,"invalid value: %s\n",argv[3]);
				exit(1);
			}
	
			printf("%d %d\n",a,b);
			calculation_prog_1 (host,a,b);
		}
		else if((flag1==0)&&(flag2==0)){
			if((a1=strtod(argv[2],NULL))==0 && *argv[2]!='0'){
				fprintf(stderr,"invalid value: %s\n",argv[2]);
				exit(1);
			}

			if((b1=strtod(argv[3],NULL))==0 && *argv[3]!='0'){
				fprintf(stderr,"invalid value: %s\n",argv[3]);
				exit(1);
			}
	
			printf("%f %f\n",a1,b1);

			calculation_prog_2 (host,a1,b1);
		}	
	}
	exit (0);
}
