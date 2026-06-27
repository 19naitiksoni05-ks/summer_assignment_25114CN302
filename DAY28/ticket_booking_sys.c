#include <stdio.h>
#include <string.h>

struct Ticket
{
    int ticketId;
    char eventName[50];
    int totalSeats;
    int availableSeats;
    float ticketPrice;
};

int main()
{
    struct Ticket t[100];
    int n, i, choice, search, found = 0, tickets;
    float bill;

    printf("Enter Number of Events: ");
    scanf("%d", &n);

    do
    {
        printf("\n========== TICKET BOOKING SYSTEM ==========\n");
        printf("1. Add Event\n");
        printf("2. Display Events\n");
        printf("3. Search Event\n");
        printf("4. Book Tickets\n");
        printf("5. Cancel Tickets\n");
        printf("6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            for (i = 0; i < n; i++)
            {

                printf("\nEvent %d\n", i + 1);

                printf("Enter Ticket ID: ");
                scanf("%d", &t[i].ticketId);

                printf("Enter Event Name: ");
                scanf("%s", t[i].eventName);

                printf("Enter Total Seats: ");
                scanf("%d", &t[i].totalSeats);

                printf("Enter Ticket Price: ");
                scanf("%f", &t[i].ticketPrice);

                t[i].availableSeats = t[i].totalSeats;
            }
            printf("\nEvents Added Successfully!\n");
            break;

        case 2:
            printf("\n------------------------------------------------------------\n");
            printf("ID\tEvent\tPrice\tAvailable\n");
            printf("------------------------------------------------------------\n");

            for (i = 0; i < n; i++)
            {
                printf("%d\t%s\t%.2f\t%d\n",
                       t[i].ticketId,
                       t[i].eventName,
                       t[i].ticketPrice,
                       t[i].availableSeats);
            }
            break;

        case 3:
            printf("Enter Ticket ID: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (t[i].ticketId == search)
                {

                    printf("\nTicket Found\n");
                    printf("ID              : %d\n", t[i].ticketId);
                    printf("Event           : %s\n", t[i].eventName);
                    printf("Ticket Price    : %.2f\n", t[i].ticketPrice);
                    printf("Available Seats : %d\n", t[i].availableSeats);

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Record Not Found!\n");

            break;

        case 4:
            printf("Enter Ticket ID: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (t[i].ticketId == search)
                {

                    printf("Enter Number of Tickets: ");
                    scanf("%d", &tickets);

                    if (tickets <= 0)
                        printf("Invalid Number of Tickets!\n");
                    else if (tickets > t[i].availableSeats)
                        printf("Seats Not Available!\n");
                    else
                    {
                        bill = tickets * t[i].ticketPrice;
                        t[i].availableSeats -= tickets;

                        printf("\nBooking Successful!\n");
                        printf("Tickets Booked : %d\n", tickets);
                        printf("Total Bill     : %.2f\n", bill);
                        printf("Seats Left     : %d\n", t[i].availableSeats);
                    }

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Record Not Found!\n");

            break;

        case 5:
            printf("Enter Ticket ID: ");
            scanf("%d", &search);

            found = 0;

            for (i = 0; i < n; i++)
            {

                if (t[i].ticketId == search)
                {

                    printf("Enter Number of Tickets to Cancel: ");
                    scanf("%d", &tickets);

                    if (tickets <= 0)
                        printf("Invalid Number!\n");
                    else if (t[i].availableSeats + tickets > t[i].totalSeats)
                        printf("Cancellation Not Possible!\n");
                    else
                    {
                        t[i].availableSeats += tickets;
                        printf("Tickets Cancelled Successfully!\n");
                        printf("Available Seats: %d\n", t[i].availableSeats);
                    }

                    found = 1;
                    break;
                }
            }

            if (found == 0)
                printf("Record Not Found!\n");

            break;

        case 6:
            printf("Thank You!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}