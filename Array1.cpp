#include <iostream>
using namespace std;
void input_usage(int daily_usage[], int day_count);
void display_usage(int daily_usage[], int day_count);
int total_usage(int daily_usage[], int day_count);
float average_usage(int daily_usage[], int day_count);
int highest_usage(int daily_usage[], int day_count);
int days_above_ten(int daily_usage[], int day_count);

int main()
{
    const int day_count = 5;
    int daily_usage[day_count];
    int menu_choice = 0;

    input_usage(daily_usage, day_count);

    do
    {
        cout << "\n\n==========Electricity Usage Menu=========";
        cout << "\n1.Display daily usage";
        cout << "\n2.Total weekly usage";
        cout << "\n3.Average daily usage";
        cout << "\n4.Highest usage";
        cout << "\n5.Count days above 10 units";
        cout << "\n6.Exit";
        cout << "\nEnter your choice: ";
        cin >> menu_choice;

        switch (menu_choice)
        {
        case 1:
            display_usage(daily_usage, day_count);
            break;
        case 2:
            cout << "Total weekly usage = " << total_usage(daily_usage, day_count);
            break;
        case 3:
            cout << "Average daily usage = " << average_usage(daily_usage, day_count);
            break;
        case 4:
            cout << "Highest usage = " << highest_usage(daily_usage, day_count);
            break;
        case 5:
            cout << "Days above 10 = " << days_above_ten(daily_usage, day_count);
            break;
        case 6:
            cout << "Exiting...Goodbye!";
            break;
        default:
            cout << "Give a number between 1 and 6.\n";
        }
    } while (menu_choice != 6);

    return 0;
}

void input_usage(int daily_usage[], int day_count)
{
    cout << "Enter electricity usage for 7 days:\n";
    for (int index = 0; index < day_count; index++)
    {
        cout << "Day " << index + 1 << " usage (units): ";
        cin >> daily_usage[index];
    }
}

void display_usage(int daily_usage[], int day_count)
{
    cout << "Daily usage: ";
    for (int index = 0; index < day_count; index++)
    {
        cout << daily_usage[index] << " ";
    }
}

int total_usage(int daily_usage[], int day_count)
{
    int total = 0;
    for (int index = 0; index < day_count; index++)
    {
        total += daily_usage[index];
    }
    return total;
}

float average_usage(int daily_usage[], int day_count)
{
    int sum_of_usage = total_usage(daily_usage, day_count);
    float average_usage = (float)sum_of_usage / day_count;
    return average_usage;
}

int highest_usage(int daily_usage[], int day_count)
{
    int highest_usage = daily_usage[0];
    for (int index = 1; index < day_count; index++)
    {
        if (daily_usage[index] > highest_usage)
        {
            highest_usage = daily_usage[index];
        }
    }
    return highest_usage;
}

int days_above_ten(int daily_usage[], int day_count)
{
    int above = 0;
    for (int index = 0; index < day_count; index++)
    {
        if (daily_usage[index] > 10)
        {
            above++;
        }
    }
    return above;
}
