
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;


struct pathloss {                        // define structure

	double A; double  B; double  C; double PL; double  D;
};


int main()
{
	int count = 0; int count1 = 0; int count2 = 0;  double a, b, c, pl, sum = 0, min, max;  double countall = 0; double r = 0; int coun = 1;
	char form[20]; char fom[20];
	
	printf("enter the name of the file.\n ");    

	scanf(" %s", form);

	FILE* fd;                 //  define reading file

	if ((fd = fopen(form, "r")) == NULL) { printf("not correct "); }      


	fscanf(fd, " %d ", &count);                //  to read the first item and detrmine the number of all values
	pathloss* ar = new pathloss[count];        // define array 
	
	printf(" what the name of the output file \n ");
	scanf("%s", fom);

	FILE* fc;           // define writing file

	if ((fc = fopen(fom, "w")) == NULL) printf(" not correct");
	fprintf(fc, "%s         %s            %s          %s       %s \n", "Carrier_Frequency", "Distance", "Base_Station_Height", "Mobile_Station_Height", "Path Loss");  // print the table titles



	while (count1 < count) {       //  reading the values from reading file
	
		fscanf(fd, "%lf  %lf %lf  %lf ", &ar[count1].A, &ar[count1].B, &ar[count1].C, &ar[count1].D);


		c = 44.9 - (6.55 * log10(ar[count1].C));

		b = ((1.1 * log10(ar[count1].A) - 0.7) * (ar[count1].D)) - (1.56 * log10(ar[count1].A)) + 0.8;

		a = 69.55 + (26.16 * log10(ar[count1].A)) - (13.82 * log10(ar[count1].C)) - b;

		pl = a + c * log10(ar[count1].B);
		ar[count1].PL = pl; count1++; a = 0;b = 0;c = 0;

	}                                    //  printing the  values  on file

	while (count2 < count) {
		fprintf(fc, "   %lf            %lf                %lf                     %lf   ", ar[count2].A, ar[count2].B, ar[count2].C, ar[count2].D);


		if (ar[count2].A < 150 || ar[count2].A > 1500) {
			fprintf(fc, "     %s\n", "     not valid ");
		}
		else {
			fprintf(fc, "            %lf\n ", ar[count2].PL);
			sum += (ar[count2].PL);
			if (coun == 1) {
				min = ar[count2].PL;
				max = ar[count2].PL;
				coun++;
			}
			if (ar[count2].PL > max) max = ar[count2].PL;  // detrmie the max value 
			if (ar[count2].PL < min) min = ar[count2].PL;   // detrmie the min value 


			countall++;
		} // end elsr


		count2++;


	}   // end while 

	r = sum / countall;     // the avarge
	fprintf(fc, "\n % s : \n the avarage pl= %lf db  \n the max pl = %lf db  \n the min pl = %lf db \n  ", "summary", r, max, min);

	fclose(fd); fclose(fc);
}
