#include<stdio.h>
#include<stdlib.h>
#define SIZE 15
struct Automobile{
	
	char brand[30];
	char model[30];
	char color[30];
	int product_date;
	char fuel_type[30];
	char plate[15];
}automobile;

void deleteAutomobile(char plate[15]);
void registerAutomobile(struct Automobile atmb);

int main(){
	
	char delete[SIZE];
	int select;
	int i = 1;
	printf("***\tAutomobile Registration System V1.0\t***\n\n");
	
	while(i){
		
		printf("1.Register Automobile\n2.Update Automobile\n3.Show Automobile\n4.Delete Automobile\n5.Quit Program\n");
		scanf("%d",&select);
		
		switch(select){
			
			case 1:
			
				printf("Welcome Register Page\n");
				printf("Please enter brand:\n");
				scanf("%s",automobile.brand);
				printf("Please enter model:\n");
				scanf("%s",automobile.model);
				printf("Please enter automobile color:\n");
				scanf("%s",automobile.color);
				printf("Please enter product date:\n");
				scanf("%d",&automobile.product_date);
				printf("Please enter fuel type:\n");
				scanf("%s",automobile.fuel_type);
				printf("Please enter plate:\n");
				scanf("%s",automobile.plate);
				printf("\n\n");
				
				registerAutomobile(automobile);
				
				break;
			
			case 2:
				
				break;
			
			case 3:
				
				break;
			
			case 4:
				/* Buraya show edilecek */
				
				printf("Welcome Delete Page\n");
				printf("Please enter plate which automobile want to delete:\n");
				scanf("%s",delete);
				
				deleteAutomobile(delete);
				
				break;
				
			case 5:
				i = 0;
				break;
		}
	}
	
	return 0;
}

void registerAutomobile(struct Automobile atmb){
	
	FILE * fPointer;
	
	fPointer = fopen("automobiles.txt","a");
	
	fprintf(fPointer,"%s %s %s %d %s %s\n",atmb.brand,atmb.model,atmb.color,atmb.product_date,atmb.fuel_type,atmb.plate);
	
	fclose(fPointer);
	
	return;
}

void deleteAutomobile(char plate[15]){
	
	printf("%s\n",plate);
}
