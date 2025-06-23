#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>

int security();
void admin();
void user();
void cd();
void voteCount();
void Winner();

struct candidate{
    char code2;
    char cn [50];
    int year;
    char faculty[5];
    char manifesto[50];
};
int voteCount1=0, voteCount2=0, voteCount3=0, voteCount4=0;
struct candidate cd1 ={'A',"SITI NURAIN BINTI RADUAN",3,"FKTEN","SUKA SAYA UNDILAH SAYA, TAK SUKA SAYA PANGKAH SAYA"};
struct candidate cd2 ={'B',"ARISA ZULAIKHA BINTI NOORHISYAM",2,"FKTM","MAHASISWA BERSATU, MENCAPAI IMPIAN"};
struct candidate cd3 ={'C',"SITI NUR FADHILAH BT SABARUDDIN",3,"FKTE","SUARA ANDA PENCETUS PERUBAHAN"};
struct candidate cd4 ={'D',"SHAFIFAH NURUL ALIA BINTI SYED HAMIDI",4,"FKTA","MEREALISASIKAN IMPIAN MAHASISWA UNIMAP"};

int main()
{
    while(1)
    {
       char mod;
            printf("\n============================================================================\n");
       printf("||                                                                        ||\n");
       printf("||                                                                        ||\n");
       printf("\n||\t\t\tPEMILIHAN MPP UNIMAP 2023/2024||");
       printf("\n||                                                                        ||");
       printf("\n||                                                                        ||");
 printf("\n============================================================================\n");
       printf("\n\n\t\t\t 1.Panel pelajar \n\t\t\t 2.Panel admin \n\t\t\t 3.Keluar \n\t\t\t Pilihan: ");
       scanf("%c",&mod);

       switch(mod)
       {
          case '1':
              user();
              break;
          case '2':
              admin();
              break;
          case '3':
              return 0;
          default:
              printf("\nPilihan tiada!");
              getch();
       }
    }
    return 0;
}
int security(){
    char username[15],password[6];
    printf("\nEnter username: ");
    scanf("%s",username);

    if((strcmp(username,"admin"))!=0)
      return 0;
    else{
      printf("Enter password: ");

      int i=0;
      for(i=0;i<6;i++){
          password[i]=getch();
          printf("%c",'*');
      }
      password[i] = '\0';
      if((strcmp(password,"unimap"))!=0)
          return 0;
    }
    return 1;
}
void admin(void)
{
    while(1){

        if(security()!=1){
            printf("\n Username atau Password salah \n");
            break;
        }

        printf("\n\nTelah berjaya log masuk(Tekan Enter)");
    getch();

        while(1)
        {
            char choice;
            printf("\n1.Senarai MPP\n2.Bilangan undian\n3.Keputusan\n4.Keluar\nPilihan:");
            scanf(" %c",&choice);

            switch(choice)
            {
                case '1':
                    cd();
                    break;
                case '2':
                    voteCount();
                    break;
                case '3':
                    Winner();
                    break;
                case '4':
                    return;
                    default:
                    printf("Pilihan tiada!");
          getch();
            }

        }
    }

};
void cd(void){
         printf("\n\nCANDIDATE: %c",cd1.code2);
         printf("\n\nNAME: %s",cd1.cn);
         printf("\nYEAR: %d",cd1.year);
         printf("\nFACULTY: %s",cd1.faculty);
         printf("\nSLOGAN: %s\n",cd1.manifesto);

         printf("\n\nCANDIDATE: %c",cd2.code2);
         printf("\n\nNAME: %s",cd2.cn);
         printf("\nYEAR: %d",cd2.year);
         printf("\nFACULTY: %s",cd2.faculty);
         printf("\nSLOGAN: %s\n",cd2.manifesto);

         printf("\n\nCANDIDATE: %c",cd3.code2);
         printf("\n\nNAME: %s",cd3.cn);
         printf("\nYEAR: %d",cd3.year);
         printf("\nFACULTY: %s",cd3.faculty);
         printf("\nSLOGAN: %s\n",cd3.manifesto);

         printf("\n\nCANDIDATE: %c",cd4.code2);
         printf("\n\nNAME: %s",cd4.cn);
         printf("\nYEAR: %d",cd4.year);
         printf("\nFACULTY: %s",cd4.faculty);
         printf("\nSLOGAN: %s\n",cd4.manifesto);
}
void user(void)
{
    int matricnum,i;
    char code;
      while(code){
        if(code == 'A')
           code = cd1.code2;
        else if(code == 'B')
           code = cd2.code2;
        else if(code == 'C')
            code = cd3.code2;
        else
            code = cd4.code2;
      }

    printf("\n\nEnter no matric : ");
    scanf("%d" ,&matricnum);

    printf("\n*******CALON-CALON YANG BERTANDING*******");

    cd();

    printf("\nEnter code: "); //user enter code to submit the voding
    scanf("%s" ,&code);

    switch(code){
       case 'A':
           printf("\nANDA TELAH MENGUNDI AIN SEBAGAI MPP!");
           voteCount1++; break;
       case 'B':
           printf("\nANDA TELAH MENGUNDI ARISA SEBAGAI MPP!");
           voteCount2++; break;
       case 'C':
           printf("\nANDA TELAH MENGUNDI DHILAH SEBAGAI MPP!");
           voteCount3++; break;
       case 'D':
           printf("\nANDA TELAH MENGUNDI ALIA SEBAGAI MPP!\n");
           voteCount4++; break;
       default:
           printf("\nPilihan code tiada di dalam senarai!!");
           getchar();
    }
     printf("\n\n-----------------------------------------------------------------------------------");
    printf("\nTERIMA KASIH KERANA TELAH MENGAMBIL BAHAGIAN DALAM SESI PEMILIHAN MPP 2023/2024\n");
    printf("\n-----------------------------------------------------------------------------------");
}
void voteCount(){
    printf("\n\n ###Bilangan undian MPP### ");
       printf("\n\n1. %s - %d ", cd1.cn, voteCount1);
       printf("\n2. %s - %d ", cd2.cn, voteCount2);
       printf("\n3. %s - %d ", cd3.cn, voteCount3);
       printf("\n4. %s - %d\n ", cd4.cn, voteCount4);
}
void Winner(){
    printf("\n\n #### Keputusan akhir #### \n\n");
       if(voteCount1>voteCount2 && voteCount1>voteCount3 && voteCount1>voteCount4)
          printf("\n[%s]\n\n",cd1.cn);
       else if (voteCount2>voteCount3 && voteCount2>voteCount4 && voteCount2>voteCount1)
          printf("\n[%s]\n\n",cd2.cn);
       else if(voteCount3>voteCount4 && voteCount3>voteCount2 && voteCount3>voteCount1)
          printf("\n[%s]\n\n",cd3.cn);
       else if(voteCount4>voteCount1 && voteCount4>voteCount2 && voteCount4 >voteCount3)
          printf("\n[%s]\n\n",cd4.cn);
       else
          printf("\n----- Keputusan undian seri----\n");
}
