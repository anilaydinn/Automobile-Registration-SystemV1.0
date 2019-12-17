#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 15
struct Automobile{
	
	char brand[30];
	char model[30];
	char color[30];
	char product_date[15];
	char fuel_type[30];
	char plate[15];
};

void deleteAutomobile(char plate_id[15],int line_number);
void registerAutomobile(struct Automobile *a);
void showAutomobiles();

int main(){
	
	int select;
	int i = 1;
	char plt[15];
	int numberOfCar;
	
	printf("***\tAutomobile Registration System V1.0\t***\n\n");

	while(i){
		
		printf("1.Register Automobile\n2.Update Automobile\n3.Show Automobile\n4.Delete Automobile\n5.Quit Program\n");
		scanf("%d",&select);
		printf("\n");
		
		switch(select){
			
			case 1:
				
				printf("Please enter how many cars register:\n");
				scanf("%d",&numberOfCar);
				
				struct Automobile *a = (struct Automobile*)malloc(sizeof(struct Automobile)*numberOfCar);
				
				for(int i = 0; i < numberOfCar; i++){
					
				printf("Welcome Register Page\n");
				printf("Please enter brand:\n");
				scanf("%s",(a + i) -> brand);
				printf("Please enter model:\n");
				scanf("%s",(a + i) -> model);
				printf("Please enter automobile color:\n");
				scanf("%s",(a + i) -> color);
				printf("Please enter product date:\n");
				scanf("%s",(a + i) -> product_date);
				printf("Please enter fuel type:\n");
				scanf("%s",(a + i) -> fuel_type);
				printf("Please enter plate:\n");
				scanf("%s",(a + i) -> plate);
				printf("\n\n");
				
				registerAutomobile(a+i);
				}
				
				
				
				break;
			
			case 2:
				
				break;
			
			case 3:
				
				showAutomobiles();
				printf("\n");
				break;
			
			case 4:
				
				printf("Welcome Delete Page\n");
				printf("Please enter plate which automobile want to delete:\n");
				scanf("%s",plt);
				deleteAutomobile(plt,numberOfCar);
				
				break;
				
			case 5:
				i = 0;
				break;
		}
	}
	
	return 0;
}

void registerAutomobile(struct Automobile *a){
	
	FILE * fPointer;
	
	fPointer = fopen("automobiles.txt","a");
	
	fprintf(fPointer,"%s %s %s %s %s %s\n",a -> brand,a -> model,a -> color,a -> product_date,a -> fuel_type,a -> plate);
	
	fclose(fPointer);
	
	return;
}

void deleteAutomobile(char plate_id[15],int line_number){
	
	FILE * fPointer;
	FILE * fPointerNew;
	struct Automobile *b = (struct Automobile*)malloc(1*sizeof(struct Automobile));
	
	fPointer = fopen("automobiles.txt","r");
	fPointerNew = fopen("automobilesnew.txt","w");
	
	for(int i = 0; i < line_number; i++){
			
		fread(b,sizeof(struct Automobile),1,fPointer);
		printf("\n\n%s\n\n",b -> brand);
		
		if(!(strcmp((b) -> plate,plate_id) == 0)){
			
			fwrite(b,sizeof(struct Automobile),1,fPointerNew);
		}
	}
	
	fclose(fPointer);
	fclose(fPointerNew);
	
	return;
}

void showAutomobiles(){
	
	FILE * fPointer;
	
	fPointer = fopen("automobiles.txt","r");
	
	int ch = getc(fPointer);
	
	if(fPointer == NULL){
		
		printf("Could not open file.");
		return;
	}
	
	while(ch != EOF){
		
		putchar(ch);
		ch = getc(fPointer);
	}
}
