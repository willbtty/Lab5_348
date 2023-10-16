#include <stdio.h>
#include <stdbool.h>
void Monthly_sales_report(float sales[12])
//Print out all the sales with the according month. Hardcoded
{
    printf("Monthly Sales Report for 2022:\n");
    printf("Month\tSales\n");
    printf("January\t%.2f\n", sales[0]);
    printf("February\t%.2f\n", sales[1]);
    printf("March\t%.2f\n", sales[2]);
    printf("April\t%.2f\n", sales[3]);
    printf("May\t%.2f\n", sales[4]);
    printf("June\t%.2f\n", sales[5]);
    printf("July\t%.2f\n", sales[6]);
    printf("August\t%.2f\n", sales[7]);
    printf("September\t%.2f\n", sales[8]);
    printf("October\t%.2f\n", sales[9]);
    printf("November\t%.2f\n", sales[10]);
    printf("December\t%.2f\n", sales[11]);
}

void Sales_Summary(float sales[12])
{
    float min = sales[0];
    float max = sales[0];
    float average = 0;
    printf("Sales Summary:\n");
    for(int i = 0; i < 12; i++){ //Loops through the array of months
        if (sales[i] < min){ //Finds the minimum
            min = sales[i];
        }
        if (sales[i] > max){ //Finds the maximum
            max = sales[i];
        }
        average += sales[i]; //Adds up the sales
    }

    average = average / 12; //Divides by 12 to find the avg.
    printf("Minimum sales: %.2f\n", min); //Need to get it to print the month
    printf("Maximum sales: %.2f\n", max);
    printf("Average sales: %.2f\n", average);
}

void six_month_moving_average(float sales[12], const char *dates[])
{
    float six_month_avg[7];

    for (int j = 0; j < 7; j++){
        six_month_avg[j] = 0.0;
    }

    for (int i=0; i < 7; i++){ // Loop through 1-6 months finding the avg.
        for (int j = 0; j < 6; j++){
            six_month_avg[i] += sales[i + j];
        }
        six_month_avg[i] /= 6.0;
    }
    for (int i=0; i < 7; i++){
        if (i == 0){
        printf("January - June\t%.2f\n", six_month_avg[i]);
        }
        else if (i == 1){
            printf("Feburary - July\t%.2f\n", six_month_avg[i]);
        }
        else if (i == 2){
            printf("March - August\t%.2f\n", six_month_avg[i]);
        }
        else if (i == 3){
            printf("April - September\t%.2f\n", six_month_avg[i]);
        }
        else if (i == 4){
            printf("May - October\t%.2f\n", six_month_avg[i]);
        }
        else if ( i == 5){
            printf("June - July\t%.2f\n", six_month_avg[i]);
        }
        else if (i == 6){
            printf("July - Decemeber\t%.2f\n", six_month_avg[i]);
        }
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct {
    const char *month;
    float sale;
} SaleMonth;

void sortSales(SaleMonth salesMonths[12]) {
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11 - i; j++) {
            if (salesMonths[j].sale < salesMonths[j + 1].sale) {
                SaleMonth temp = salesMonths[j];
                salesMonths[j] = salesMonths[j + 1];
                salesMonths[j + 1] = temp;
            }
        }
    }
}


void printSortedSalesReport(SaleMonth salesMonths[12]) {
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < 12; i++) {
        printf("%-10s\t$%.2f\n", salesMonths[i].month, salesMonths[i].sale);
    }
}

int main(void)
{
    float sales[12] = {23458.01,
        40112.00,
        56011.85,
        37820.88,
        37904.67,
        60200.22,
        72400.31,
        56210.89,
        67230.84,
        68233.12,
        80950.34,
        95225.22};
    const char *months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
    };
    SaleMonth salesMonths[12];
    for (int i =0; i<12; i++){
        salesMonths[i].month = months[i];
        salesMonths[i].sale = sales[i];
    }

    Monthly_sales_report(sales);
    printf("    ");
    Sales_Summary(sales);
    printf("    ");
    printf("Six-Month Moving Average Report:\n");
    six_month_moving_average(sales, months);
    printf("    ");
    sortSales(salesMonths);
    printf("    ");
    printSortedSalesReport(salesMonths);
    return 0;
}
