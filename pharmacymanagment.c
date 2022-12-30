#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>  



int main()
{
    FILE *fp, *ft; 
    char another, choice;

    
    struct med
    {
        char medicinename[40]; 
        int id,quantity; 
        char company[100],expiry[100];
		float price; 
    };

    struct med m ; 

    char medicinename[40]; 

    long int recsize; 

    
    fp = fopen("Medicine.txt","a+");
    if(fp == NULL)
    {   {
            printf("Connot open file");
            
			exit(1);
        }
    }
    system("Color 3F");
	printf("\n\n\n\n\t\t\t\t============="
		"============================="
		"===========");
	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
		"~~~~~");
	printf("\n\t\t\t\t==================="
		"============================="
		"=====");
	printf("\n\t\t\t\t[|:::>:::>:::>::> "
		"PHARMACY MANAGEMENT SYSTEM <::<:::<:::"
		"<:::|]\t");
	printf("\n\t\t\t\t==================="
		"============================="
		"=====");
	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
		"~~~");
	printf("\n\t\t\t\t====================="
		"==============================\n");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t"
		"\n\n\t\t\t\t");

	system("pause");

    
    recsize = sizeof(m);

   
    do 
    {

        system("cls"); 
        
        printf("1. Add Medicines \n"); 
        
        printf("2. Display Medicines \n"); 
      
        printf("3. Modify Medicines \n"); 
        
        printf("4. Delete Medicines \n"); 
       
        printf("5. Exit \n");
       
        printf("Enter your Choice: "); 
        fflush(stdin); 
        choice  = getche(); 
        switch(choice)
        {
        case '1':  
            system("cls");  
            fseek(fp,0,SEEK_END); 
            
            another = 'y';
            while(another == 'y')  
            {
                printf("\nEnter the Name of Medicine: ");
               fflush(stdin);
			    gets(m.medicinename);
                printf("\nEnter the name of company: ");
                fflush(stdin);
				gets(m.company);
                fflush(stdin);
				printf("\nEnter ID ");
                scanf("%d",&m.id);
                fflush(stdin);
				printf("\nEnter Expiry Date ");
                gets(m.expiry);
                printf("\nEnter Quantity ");
                fflush(stdin);
				scanf("%d",&m.quantity);
                printf("\nEnter the Price of Medicine: ");
                scanf("%f",&m.price);

                fwrite(&m,recsize,1,fp); 

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
        case '2':
            system("cls");  
            rewind(fp); 
            while(fread(&m,recsize,1,fp)==1)  
            {
                printf("\n%20s%12s%15d%17s%18d %2f",m.medicinename,m.company,m.id,m.expiry,m.quantity,m.price); 
            }
			getch();
            break;

        case '3': 
            system("cls");  
            another = 'y';
            while(another == 'y')
            {
                printf("Enter the medicine name to modify: ");
                scanf("%s",&medicinename);
                rewind(fp);
                while(fread(&m,recsize,1,fp)==1)  
                {
                    if(strcmp(m.medicinename,medicinename) == 0)  
                    {
                        printf("\nEnter new medicine :");
                        fflush(stdin);
                        gets(m.medicinename);
                        fflush(stdin);
                        printf("\nEnter new company name : ");
						gets(m.company);
                        fflush(stdin);
                        printf("\nEnter new expiry: ");
                        gets(m.expiry);
                        fflush(stdin);
                        printf("\nEnter new Quantity and price: ");
						scanf("%d%f",&m.quantity,&m.price);
						//scanf("%s%s%d%s%d%f",m.medicinename,m.company,m.id,m.expiry,m.quantity,m.price);
                        fseek(fp,-recsize,SEEK_CUR); 
                        fwrite(&m,recsize,1,fp); 
                        break;
                    }
                }
                printf("\nModify another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls"); 
            another = 'y';
            while(another == 'y')
            {
                printf("\nEnter name of Medicine to delete: ");
                scanf("%s",medicinename);
                ft = fopen("Temp.dat","wb");  
                rewind(fp); 
                while(fread(&m,recsize,1,fp) == 1)  
                {
                    if(strcmp(m.medicinename,medicinename) != 0)  
                    {
                        fwrite(&m,recsize,1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("Medicine.txt"); 
                rename("Temp.dat","Medicine.txt"); 
                fp = fopen("Medicine.txt", "a+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            fclose(fp);  
            exit(0); 
        }
    }while(choice!=5);
    return 0;

}



