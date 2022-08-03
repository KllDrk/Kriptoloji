#include<stdio.h>
#include<math.h>

double primeValues[2]={0,0};
int count[2] = {0,0};
char p[2][100];
double normalN,totientN;
int valueTemp2;
int valueTemp;
int k=0,d=0;
int countSelect=0,countSelect2=0,countSelect3;
bool controlTransition = false;

    char plainText[1000];
    
    char cipherText[5000];
    double cipherTextDouble[1000];
    int countCipherText[1000];
    
    char decodedText[1000];
    double decodedTextDouble[1000];
    double decodedTextDouble1[1000];

bool MainMenu();
          
void PlainTextWrite();

void RSAencryption();
       bool KeyGeneration();
            void GettingPrimeValues();
                bool arrayControl[2]={false,false};
       bool ModularN();
            double ModularValues(double,double);
       bool GeneratePublicAndPrivateKey();
            double PublicKey;
            double PrivateKey;     
            double gcd(double,double);
       bool CommonEncryption();
       
void RSAdecryption();
     bool CommonDecrytion();
     bool Decoding();

void ErrorManagement(int);
     void WordCheck();
          bool wordControl[2] = {true,true};   
     void PrimalityCheck();
          bool primality[2] = {true,true};
     void EmptyValues();
          bool emptyValue = true;
     void ControlCiphers();
          bool controlCipher = false;
     
int main(int argc, char *argv[])
{
    
    while(MainMenu()){}
    
    return 0;
}

bool MainMenu(){
    char choice[1];
    int  choiceInt;
    printf("Please Choose One of the "
           "Following.\n"
           "1-Writing PlainText\n"
           "2-Encrypting PlainText\n"
           "3-Decrypting CipherText\n"
           "4-Exiting\n"
           "Choose:");
    gets(choice);
    choiceInt = choice[0]-'0';
    switch(choiceInt){
        case 1:{
            ErrorManagement(2);
            emptyValue = true;
            PlainTextWrite();
            printf("\n\n\n");
            puts(plainText);
            printf("\n\n\n");
            break;
        }
        case 2:{
            RSAencryption();
            printf("\n\n\n");
            puts(cipherText);
            printf("\n\n\n");
            break;
        }
        case 3:{
            RSAdecryption();
            printf("\n\n\n");
            puts(decodedText);
            printf("\n\n\n");
            break;
        }
        case 4:{
            printf("Exiting the Program\n");
            return false;
            break;
        }
        default:{
            printf("You Made the Wrong "
                   "Choise. Please Try "
                   "Again.\n");
            break;
        }
    }
    return true;
}

void PlainTextWrite(){
    puts("Please Write PlainText:");
    gets(plainText);
}

void RSAencryption(){
    emptyValue = false;
    GettingPrimeValues();
    if(KeyGeneration()){
        if(ModularN()){
            if(GeneratePublicAndPrivateKey()){
                  printf("%lf-%lf\n",PublicKey,PrivateKey);
                  if(CommonEncryption()){
                   printf("successful!\n");
                   }else{
                      RSAencryption();
                   }
            }else{
                RSAencryption();
            }
        }else{
            RSAencryption();
        }
    }else{
        RSAencryption();
    }
}

void GettingPrimeValues(){
    for(int j = 0;j<2;j++){
        if(arrayControl[j] == true){
        for(int i = 0;p[j][i] != '\0';i++){
        p[j][i] ='\0';
    }
    arrayControl[j] = false;
    }
    }
    
    count[0] = 0;
    count[1] = 0;
    primeValues[0] = 0;
    primeValues[1] = 0;
    printf("Please Enter 1. Prime Number:");
    gets(p[0]);
    printf("Please Enter 2. Prime Number:");
    gets(p[1]);
    
    ErrorManagement(0);
    
    count[0] = printf("%s",p[0]);
    printf("\ncount[0]:%d\n",count[0]);
    count[1] = printf("%s",p[1]);
    printf("\ncount[1]:%d\n",count[1]);
for(int j = 0;j<2;j++)
    for(int i = 0;i<count[j];i++){
        primeValues[j] +=(int(p[j][(count[j]-1)-i] -'0')) * 
               (double)pow(10,(i));
        printf("prime values:%lf\n",primeValues[j]);
    }
    
    ErrorManagement(1);
    
    printf("1. prime values:%lf\n",primeValues[0]);
    printf("2. prime values:%lf\n",primeValues[1]);
}


bool KeyGeneration(){
        if(primality[0] == true){
            printf("1. Value is Prime Number.\n");
            if(primality[1] == true){
                printf("2. Value is Prime Number.\n");
                return true;
            }else{
                printf("2. Value is not Prime Number.\n");
                return false;
            }
        }else{
            printf("1. Value is not Prime Number.\n");
            return false;
        }
    return false;
}

bool ModularN(){
    normalN =ModularValues(primeValues[0],primeValues[1]); 
    totientN=ModularValues(primeValues[0]-1,primeValues[1]-1);
    printf("%.0lf-%.0lf\n",normalN,totientN);
    return true;
}

double ModularValues(double number1,double number2){
    return (double)(number1*number2);
}


void ErrorManagement(int ErrorId){
    switch(ErrorId){
        case 0:{
            WordCheck();
            break;
        }
        case 1:{
            PrimalityCheck();
            break;
        }
        case 2:{
            EmptyValues();
            break;
        }
        case 3:{
            ControlCiphers();
            break;
        }
        default:{
            break;
        }
    }
}

void WordCheck(){
    wordControl[0] = true;
    wordControl[1] = true;
    int IncorrectValue[2] = {0,0};
for(int j=0;j<2;j++)
    for(int i = 0;p[j][i] != '\0';i++){
        if(p[j][i]<'0' ||
           p[j][i]>'9'){
            wordControl[j] = false;
            IncorrectValue[j] = i;
        }
    }
    if(wordControl[0]){
        printf("1. Value Entered with Correct Syntax.\n");
        if(wordControl[1]){
            printf("2. Value Entered with Correct Syntax.\n");
        }else{
            printf("The %d Value is Not a Digit!\n",       
            IncorrectValue[1]+1);
            printf("Word: %c\n",p[1][IncorrectValue[1]]);
            RSAencryption();
        }
    }else{
        printf("The %d Value is Not a Digit!\n",
        IncorrectValue[0]+1);
        printf("Word: %c\n",p[0][IncorrectValue[1]]);
        RSAencryption();
    }
}

void PrimalityCheck(){
   primality[0] = true;
   primality[1] = true;
for(int j=0;j<2;j++)
   for(int i = 2;i<primeValues[j]/2;i++){
       if(fmod(primeValues[j],i) == 0){
           printf("%d Number %lf is not Prime!\n",j,
           primeValues[j]);
           primality[j] =false;
           RSAencryption();
       }
   }
}

void EmptyValues(){
    for(int i = 0;i<2;i++){
        primeValues[i] = 0;
        count[i] = 0;
        arrayControl[i] = false;
        wordControl[i] = false;
        primality[i] = false;
        for(int j = 0;j<100;j++){
             p[i][j] = '\0';
        }
    }
    normalN=0;
    totientN = 0;
    valueTemp2 = 0;
    valueTemp = 0;
    k=0;
    d=0;
    countSelect = 0;
    countSelect2 = 0;
    countSelect3 = 0;
    controlTransition = false;
    for(int i =0 ;i<1000;i++){
    plainText[i] = '\0';
    cipherTextDouble[i] = '\0';
    countCipherText[i] = '\0';
    decodedText[i] = '\0';
    decodedTextDouble[i] = '\0';
    decodedTextDouble1[i] = '\0';
    }
    for(int i = 0;i<5000;i++){
        cipherText[i] = '\0';
    }
    PublicKey = 0;
    PrivateKey = 0;     
    
}
//Bu kisim Icin Bir Sey Bulamadim :D
void ControlCiphers(){
    if(!emptyValue){
        controlCipher = true;
    }else{
        controlCipher = false;
    }
}

bool GeneratePublicAndPrivateKey(){
    double TempE =2,TempDouble1,TempDouble2;
    int TempInt,countK = 0;
    while(TempE < totientN){
        if(gcd(TempE,totientN) == 1){
            while(countK < 100){
                TempDouble1 = (totientN *countK + 1);
                TempDouble1 /= TempE;
                TempInt = TempDouble1;
                TempDouble2 = TempInt;
                //printf("%lf-%d-%lf\n",TempDouble1,TempInt,
//                TempDouble2);
                if(TempDouble1 == TempDouble2){
                       PublicKey = TempE;
                       PrivateKey = TempDouble1;
                   return true;
                   }
               else{
                   TempDouble1 = 0;
                   TempInt = 0;
                   TempDouble2 = 0;
                   countK++;
               }
            }
            countK = 0;
        }else{
            TempE++;
        }
    }
    return false;
}

double gcd(double n1,double n2){
    if(n2 != 0){
        return gcd(n2,fmod(n1,n2));
    }else{
        return n1;
    }
}

bool CommonEncryption(){
    emptyValue = false;
    int count = 0;
for(int j = 0;plainText[j] != '\0';j++){
    cipherTextDouble[j] = 1;
    count++;
    for(int i = 0; PublicKey>i;i++){
        
        cipherTextDouble[j] *= fmod(plainText[j],normalN);
        if(cipherTextDouble[j] >= normalN){
        cipherTextDouble[j]=fmod(cipherTextDouble[j],normalN);
        }
    }
    if(cipherTextDouble[j] >= normalN){
       cipherTextDouble[j]=fmod(cipherTextDouble[j],normalN);
    }
 //printf("cipherTextDouble[%d] = %lf\n",j,cipherTextDouble[j]);
}
//printf("count = %d\n",count);
for(int j =0;count>j;j++){
        valueTemp =(int)cipherTextDouble[j];
    for(int i=0;valueTemp>0;i++){
        valueTemp/=10;
        countCipherText[j]++;
    }
    //printf("countCipherText[%d]=%d\n",j,countCipherText[j]);
     
}
    valueTemp = 0;
for(int j=0;cipherTextDouble[j]!='\0';j++){
    valueTemp = (int)cipherTextDouble[j];
    for(int i=countCipherText[j]-1;i>=0;i--){
        //printf("i=%d\nvalueTemp=%d\n",i,valueTemp);
        if(countCipherText[j]%2 ==0){
            if(i%2 ==1){
            valueTemp2 += valueTemp %10;
        }else if(i%2 == 0){
                     valueTemp2 +=10*
                     (valueTemp % 10);
                     cipherText[k] = 
                     valueTemp2;
                     cipherText[k]+=33;
                     valueTemp2 = 0;
                     k++;
                 }
    valueTemp /=10;
        }else{
            
            if(i%2 ==0){
            valueTemp2 += valueTemp %10;
            if(i == 0){
                cipherText[k] =
                     valueTemp;
                     cipherText[k]+=33;
                     k++;
                     valueTemp2 = 0;
            }
        }else if(i%2 == 1){
                     valueTemp2 +=10* (valueTemp % 10);
                     cipherText[k] = valueTemp2;
                     cipherText[k]+=33;
                     valueTemp2 = 0;
                     k++;
                 }
    valueTemp /=10;
        }
    }
}
//printf("k=%d\n",k);
//for(int i=0;cipherText[i]!='\0';i++){
//    printf("cipherText[%d]=%d-%c\n",i
//           ,cipherText[i],cipherText[i]);
//}
    //printf("%s\n",cipherText);
    
for(int i=0;countCipherText[i]!='\0';i++){
    //printf("%d\n",countCipherText[i]);
    if(fmod(countCipherText[i],2) == 1){
        countSelect2 += ((int)(countCipherText[i]+1))/2;
    }else{
        countSelect2 += (int)(countCipherText[i]/2);
    }
    for(;countSelect2>countSelect;countSelect++){
       printf("%c",cipherText[countSelect]);
    }
    printf("\n");
}
    //printf("%d-%d\n",countSelect,countSelect2);
    d = count;
    return true;
    
}


void RSAdecryption(){
    if(CommonDecrytion()){
        if(Decoding()){
            printf("Successful!!!\n");
        }else{
            RSAdecryption();
        }
    }else{
        RSAdecryption();
    }
}

bool CommonDecrytion(){
    for(int i=k;i >= 0;i--){
    if(fmod(countCipherText[i],2) == 1){
        //printf("countCipher=%d\n",countCipherText[i]);
//        printf("countSelect:%d\n"
//           "countSelect2:%d\n",
//           countSelect,countSelect2);
//           printf("0-countSelect3 = %d\n",countSelect3);
        countSelect2 -= ((int)(countCipherText[i]+1))/2;
        countSelect3 = countCipherText[i] -1;
    }else{
        //printf("countCipher=%d\n",countCipherText[i]);
        countSelect2 -= (int)(countCipherText[i]/2);
        countSelect3 = countCipherText[i] -2;
    }
    //printf("1-countSelect3 = %d\n",countSelect3);
    for(;countSelect>=countSelect2;countSelect--){
       printf("%c",cipherText[countSelect]);
       decodedTextDouble[d] += ((cipherText[countSelect]-33)*
                                pow(10,countSelect3));
       countSelect3 -= 2;
       controlTransition = true;
    }
    if(controlTransition){
        //printf("decodedDoubleText[%d]:%lf",d,
        //decodedTextDouble[d]);
        printf("\n\n");
        controlTransition = false;
        d--;
    }
    
}
    return true;
}

bool Decoding(){
    int count = 0;
    //printf("PrivateKey = %lf\n",PrivateKey);
    //printf("normalN = %lf\n",normalN);
    for(int i = 0;decodedTextDouble[i]!='\0';i++){
        count++;
        decodedTextDouble1[i] = 1;
        for(int j =0;j<PrivateKey;j++){
         decodedTextDouble1[i]*= 
         fmod(decodedTextDouble[i],normalN);
        if(decodedTextDouble1[i] >= normalN){
        decodedTextDouble1[i]=
        fmod(decodedTextDouble1[i],normalN);
        }
        }
        if(decodedTextDouble1[i] >= normalN){
       decodedTextDouble1[i]=
       fmod(decodedTextDouble1[i],normalN);
    }
    decodedText[i] = decodedTextDouble1[i];
    printf("decodedTextDouble[%d] = %c\n",i,decodedText[i]);
    }
    
    return true;
}