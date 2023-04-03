#define PRIMES_AMOUNT 166

int filter_primes(int user_guess,int list[PRIMES_AMOUNT],int length) {
	for (int i =0;i<length;++i) {
		int prime_name = list[i];
		if (user_guess == prime_name) {
			/* replace element we need to delete with the last element of the array and decriment the length */
			printf("\nWell done, removing %d from list\n",prime_name);
			list[i] = list[length-1];
			--length;
		}
}
return length;
}

int isprime (int v)
{
    int i;

    if (v < 2 || !((unsigned)v & 1))    /* 0, 1 + even > 2 are not prime */
        return 0;

    if (v == 2) return 1;

    for (i = 3; i * i <= v; i+=2)
        if (v % i == 0)
            return 0;

    return 1;
}



void primes_game() {
int primes[PRIMES_AMOUNT];
/* fill primes */
int primes_pos = 0;
for (int i=0; i<1000; ++i) {
	if (isprime(i)) {
	  primes[primes_pos] = i;
	  primes_pos++;
	}
}

char user_input[100];
int length = sizeof(primes)/sizeof(primes[0]);
int og_length = sizeof(primes)/sizeof(primes[0]);
int length_after_filter;
while ( length != 0) {
	memset(user_input,'\0',sizeof(user_input));
	get_user_guess:
	printf("\nPlease type in a prime:\n");
	fgets(user_input,sizeof(user_input),stdin);
	int user_guess = atoi(user_input);
	length_after_filter = filter_primes(user_guess,primes,length);
	if (length_after_filter == length) {
		printf(ANSI_COLOR_RED "\nNot a prime or you have said this one before\n" ANSI_COLOR_RESET);
		goto get_user_guess;
	}
	length = length_after_filter;
	printf("\nyou have done %d/%d\n",og_length-length,og_length);
}
	printf(ANSI_COLOR_GREEN "\nWell done you got all the primes!\n" ANSI_COLOR_RESET);


}

