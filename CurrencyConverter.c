#include<stdio.h>
#include<stdlib.h>

void converter() {
    int currency, select;
    double amount, result;

    const char *currencies[] = {"USD", "CNY", "JPY", "EUR", "HKD", "PHP"};

    printf("What's your current currency? \n");
    for (int i = 0; i < 6; i++) {
        printf("%d. %s \n", i + 1, currencies[i]);
    }
    printf("Select your currency: ");
    scanf("%d", &currency);

    if (currency < 1 || currency > 6) {
        printf("Invalid currency selection\n");
        return;
    }

    printf("Enter amount to convert: ");
    scanf("%lf", &amount);

    printf("%s to What currency? \n", currencies[currency - 1]);
    for (int i = 0; i < 6; i++) {
        if (i + 1 != currency) {
            printf("%d. %s \n", i + 1, currencies[i]);
        }
    }
    scanf("%d", &select);

    if (select < 1 || select > 6 || select == currency) {
        printf("Invalid selection\n");
        return;
    }

    switch(currency) {
        case 1: // USD
            switch(select) {
                case 2: result = amount * 6.45; break;  // USD to CNY
                case 3: result = amount * 134.0; break; // USD to JPY
                case 4: result = amount * 0.94; break;  // USD to EUR
                case 5: result = amount * 7.83; break;  // USD to HKD
                case 6: result = amount * 56.0; break;  // USD to PHP
            }
            break;
        case 2: // CNY
            switch(select) {
                case 1: result = amount / 6.45; break;  // CNY to USD
                case 3: result = amount * 20.8; break;  // CNY to JPY
                case 4: result = amount * 0.15; break;  // CNY to EUR
                case 5: result = amount * 1.22; break;  // CNY to HKD
                case 6: result = amount * 8.7; break;   // CNY to PHP
            }
            break;
        case 3: // JPY
            switch(select) {
                case 1: result = amount / 134.0; break; // JPY to USD
                case 2: result = amount / 20.8; break;  // JPY to CNY
                case 4: result = amount * 0.0070; break; // JPY to EUR
                case 5: result = amount * 0.058; break;  // JPY to HKD
                case 6: result = amount * 0.43; break;   // JPY to PHP
            }
            break;
        case 4: // EUR
            switch(select) {
                case 1: result = amount / 0.94; break;  // EUR to USD
                case 2: result = amount / 0.15; break;  // EUR to CNY
                case 3: result = amount * 142.9; break; // EUR to JPY
                case 5: result = amount * 8.6; break;   // EUR to HKD
                case 6: result = amount * 6.1; break;   // EUR to PHP
            }
            break;
        case 5: // HKD
            switch(select) {
                case 1: result = amount / 7.83; break;  // HKD to USD
                case 2: result = amount / 1.22; break;  // HKD to CNY
                case 3: result = amount * 17.24; break; // HKD to JPY
                case 4: result = amount * 0.12; break;  // HKD to EUR
                case 6: result = amount * 0.71; break;  // HKD to PHP
            }
            break;
        case 6: // PHP
            switch(select) {
                case 1: result = amount / 56.0; break;  // PHP to USD
                case 2: result = amount / 8.7; break;   // PHP to CNY
                case 3: result = amount * 2.32; break;  // PHP to JPY
                case 4: result = amount * 0.16; break;  // PHP to EUR
                case 5: result = amount * 1.42; break;  // PHP to HKD
            }
            break;
    }

    printf("%s %.2f to %s %.2f\n", currencies[currency - 1], amount, currencies[select - 1], result);
}

void help() {
    printf("Help Section:\n");
    printf("This is a currency converter that allows you to convert between different currencies.\n");
    printf("Currently supported currencies: USD, CNY, JPY, EUR, HKD, PHP.\n");
    printf("You can select the source and target currencies and enter the amount to convert.\n");
}

int main() {
    int choose;
    do {
        printf("-----------Money Currency Converter-----------\n");
        printf("Enter 1 for Currency Converter\n");
        printf("Enter 2 for help \n");
        printf("Enter 3 for exit \n");
        printf("Please choose an option: ");
        scanf("%d", &choose);

        switch(choose) {
            case 1:
                converter();
                break;
            case 2:
                help();
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid selection. Please choose again.\n");
                break;
        }
    } while (choose != 3);

    return 0;
}