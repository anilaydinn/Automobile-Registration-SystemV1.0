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

void deleteAutomobile(char plate_id[15]);
void registerAutomobile(struct Automobile *a);
void updateAutomobile(struct Automobile *b);
void showAutomobiles();

int main(){
    
    int select;
    int i = 1;
    char plt[15];
    int numberOfCar;
    
    printf("*\tAutomobile Registration System V1.0\t***\n\n");
    
    while(i){
        
        printf("1.Register Automobile\n2.Update Automobile\n3.Show Automobile\n4.Delete Automobile\n5.Quit Program\n");
        scanf("%d",&select);
        printf("\n");
        
        switch(select){
                
            case 1:
                
                printf("Please enter how many cars register:\n");
                scanf("%d",&numberOfCar);
                
                struct Automobile *a = (struct Automobile*)malloc(sizeof(struct Automobile)*numberOfCar);
                
                for(i = 0; i < numberOfCar; i++){
                    
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
                printf("Welcome Delete Page\n");
                struct Automobile *b = malloc(sizeof(struct Automobile));
                printf("Please enter plate which automobile want to update:\n");
                scanf("%s", b->plate);
                printf("Please enter brand:\n");
                scanf("%s", b->brand);
                printf("Please enter model:\n");
                scanf("%s", b->model);
                printf("Please enter automobile color:\n");
                scanf("%s", b->color);
                printf("Please enter product date:\n");
                scanf("%s", b->product_date);
                printf("Please enter fuel type:\n");
                scanf("%s", b->fuel_type);
                
                updateAutomobile(b);
                break;
                
            case 3:
                
                showAutomobiles();
                printf("\n");
                break;
                
            case 4:
                
                printf("Welcome Delete Page\n");
                printf("Please enter plate which automobile want to delete:\n");
                scanf("%s",plt);
                deleteAutomobile(plt);
                
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

void deleteAutomobile(char plate_id[15]){
    
    FILE *fAutomobiles = fopen("automobiles.txt","r");
    FILE *fTemp = fopen("temp.txt","w");

    struct Automobile *b = (struct Automobile*)malloc(sizeof(struct Automobile)* 1);
    
    while (!feof(fAutomobiles)) {
        fscanf(fAutomobiles,"%s %s %s %s %s %s\n",b -> brand,b -> model,b -> color,b -> product_date,b -> fuel_type,b -> plate);
        
        if(strcmp(b->plate, plate_id) == 0) {
            continue;
        } else {
            fprintf(fTemp,"%s %s %s %s %s %s\n",b -> brand,b -> model,b -> color,b -> product_date,b -> fuel_type,b -> plate);
        }
    }
    fclose(fAutomobiles);
    fclose(fTemp);
   
   
	fAutomobiles = fopen("automobiles.txt","w");
    fTemp = fopen("temp.txt","r");
    
    while(!feof(fTemp)){
    	fscanf(fTemp,"%s %s %s %s %s %s\n",b -> brand,b -> model,b -> color,b -> product_date,b -> fuel_type,b -> plate);
    	fprintf(fAutomobiles,"%s %s %s %s %s %s\n",b -> brand,b -> model,b -> color,b -> product_date,b -> fuel_type,b -> plate);
	}
    fclose(fAutomobiles);
    fclose(fTemp);
	}

void updateAutomobile(struct Automobile *automobile){
    
    FILE *fAutomobiles = fopen("automobiles.txt","r");
    FILE *fTemp = fopen("temp.txt","w");

    fclose(fTemp);
    fTemp = fopen("temp.txt", "a");
    
    
    struct Automobile *b = (struct Automobile*)malloc(sizeof(struct Automobile)* 1);
    
    while (!feof(fAutomobiles)) {
        fscanf(fAutomobiles,"%s %s %s %s %s %s\n",b -> brand,b -> model,b -> color,b -> product_date,b -> fuel_type,b -> plate);
        
        if(strcmp(b->plate, automobile->plate) == 0) {
            fprintf(fTemp,"%s %s %s %s %s %s\n",automobile -> brand,automobile -> model,automobile -> color,automobile -> product_date,automobile -> fuel_type,automobile -> plate);
        } else {
            fprintf(fTemp,"%s %s %s %s %s %s\n",b -> brand,b -> model,b -> color,b -> product_date,b -> fuel_type,b -> plate);
        }
    }
    
    fclose(fAutomobiles);
    fclose(fTemp);
 
	fAutomobiles = fopen("automobiles.txt","w");
    fTemp = fopen("temp.txt","r");
    
    while(!feof(fTemp)){
    	fscanf(fTemp,"%s %s %s %s %s %s\n",b -> brand,b -> model,b -> color,b -> product_date,b -> fuel_type,b -> plate);
    	fprintf(fAutomobiles,"%s %s %s %s %s %s\n",b -> brand,b -> model,b -> color,b -> product_date,b -> fuel_type,b -> plate);
	}
    fclose(fAutomobiles);
    fclose(fTemp);
    
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
