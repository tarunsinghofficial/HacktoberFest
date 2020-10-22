#include <stdio.h>

int main() {

int time;

scanf("%d", &time);

    switch(time)

    {

        case 5:

        printf("wake up.\n");

        break;

        case 6:

        printf("take bath.\n");

        break;

        case 7:

        printf("have breakfast.\n");

        break;

        case 8:

        printf("start learning for 4 hours and stay hydrated.\n");

        case 12:

        printf("lunch time wash your hands.\n");

        default:

        printf("take a quick nap.\n");

    }

    return 0;

}
