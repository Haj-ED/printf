#include "main.h"

int custom_printf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    int total_printed = 0;
    char buffer[100];
     for (int i = 0; fmt[i] != '\0'; i++)
    {
        if (fmt[i] == '%')
        {
            i++;
	    if (fmt[i] == 'd' || fmt[i] == 'i')
            {
                int num = va_arg(args, int);
                int num_chars = snprintf(buffer, sizeof(buffer), "%d", num);
                total_printed += num_chars;
                printf("%s", buffer);
            }
	}
        else
        {
            putchar(fmt[i]);
            total_printed++;
        }
    }

    va_end(args);
    return total_printed;
}

int main()
{
    int num = 42;
    custom_printf("The number is: %d\n", num);

    return 0;
}
