#include<stdio.h>
#include<math.h>

    int velicinaHrpe = 12;

    int lijevi(int i){
     return (2 * i) + 1;
    }
    int desni(int i){
     return (2 * i) + 2;
    }

    int suma_lijevi=0;
    int suma_desni=0;


    void uhrpljavanje(int a[], int i){
     int l = lijevi(i), najveci;
     int r = desni(i);
     if ( (a[l] > a[i]) && (l < velicinaHrpe)){
     najveci = l;
     }
     else{
     najveci = i;
     }
     if ( (a[r] > a[najveci]) && (r < velicinaHrpe)){
     najveci = r;
     }
     if (najveci != i){
     int temp = a[i];
     a[i] = a[najveci];
     a[najveci] = temp;
     uhrpljavanje(a, najveci);
     }
    }

    void max_hrpa(int a[]){
     for(int i=(velicinaHrpe-1)/2;i>=0;i--){
     uhrpljavanje(a, i);
     }
    }

    //Napisati funkciju izracunaj
    //i - pocetni cvor, vektor
    void izracunaj(int i, int a[],int razina){
    printf("\nTrenutni cvor:%d",a[i]);
    static int lijevo = 1;
        if(i==0){
        izracunaj(lijevi(i),a,razina+1);
        printf("\nSuma s lijeve strane:%d\n",suma_lijevi);
        lijevo = 0;
        izracunaj(desni(i),a,razina+1);
        printf("\nSuma s desne strane:%d\n",suma_desni);
        return;
        }
    if (razina%2!=0){
        if (lijevo) suma_lijevi += a[i];
        else suma_desni += a[i];
    }
    
    if (lijevi(i)<velicinaHrpe)
        izracunaj(lijevi(i),a,razina+1);
    if (desni(i)<velicinaHrpe)
        izracunaj(desni(i),a,razina+1);
}


int main(){
 int arr[100];
 
 
 int n;
 scanf("%d",&n);
 
 velicinaHrpe=n;
 
 for(int i=0;i<n;i++){
     scanf("%d",&arr[i]);
 }
 
 max_hrpa(arr);
printf("Prvi broj: %d",arr[0]); 
 izracunaj(0,arr,1);
 
 if(suma_lijevi > suma_desni){
     printf("1");
 }else if(suma_desni > suma_lijevi){
     printf("-1");
 }else{
     printf("0");
 }
 printf("\n"); 
 return 0;
}
