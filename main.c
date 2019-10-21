#include<stdio.h>
#include<stdlib.h>

struct Automobile{
	
	char brand[30];
	char model[30];
	char color[30];
	int product_date;
	char fuel_type[30];
	char plate[15];
};

int main(){
	
	int select;
	
	printf("***\tAutomobile Registration System V1.0\t***\n\n");
	
	while(1){
		
		printf("1.Register Automobile\n2.Update Automobile\n3.Show Automobile\n4.Delete Automobile\n5.Quit Program\n");
		scanf("%d",&select);
		
		if(select == 5){
			
			printf("Program is closing...");
			break;
		}
		else if(select == 1){
			
			/* Register kodları */
		}
		else if(select == 2){
			/* Update koldarı */
		}
		else if(select == 3){
			
			/* Show fonksiyonu */
		}
		else if(select == 4){
			
			/* Delete fonksiyonu */
		}
		else{
			printf("Please enter correct option.");
		}
	}
	
	return 0;
}

