#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	resetColor()
{
	printf("\033[0m");
}

int		ft_add_checksum(int ml, int pl, int *checksum_ft, int *checksum_sys)
{
	static int	test_id;

	// x X 의 NULL 이 조금 이상
	test_id = 1;
	printf("\033[0;35m=== END TEST-ID: %d "
			"=============================\033[0m\n",
			test_id);
	if (ml != pl)
	{
		printf("\n\033[0;31m FAILED TEST NUMBER: %d\n", test_id);
		resetColor();
	}
	*checksum_ft += ml;
	*checksum_sys += pl;
	test_id++;
	if (test_id != 44)
	{
		printf("\033[0;35m=== START TEST-ID: %d "
				"=============================\033[0m\n",
				test_id);
		printf("\033[0;34m Running test: \033[0m\n");
	}
	else
		printf("\n\nTESTS FINISHED! Let's see how you did...\n");
}

int		main()
{
	char	*testpointer;
	char	*emptystring;
	int		int1;
	int		int2;
	int		int3;
	int		int4;
	char	*test3;
	char	*test4;
	int		c_ft;
	int		c_sys;
	int		ml2;
	int		pl2;
	int		ml3;
	int		pl3;
	int		ml4;
	int		pl4;
	int		ml5;
	int		pl5;
	int		ml6;
	int		pl6;
	int		ml7;
	int		pl7;
	int		ml8;
	int		pl8;
	int		ml10;
	int		pl10;
	int		ml11;
	int		pl11;
	int		ml12;
	int		pl12;
	int		ml13;
	int		pl13;
	int		ml14;
	int		pl14;
	int		ml15;
	int		pl15;
	int		ml16;
	int		pl16;
	int		ml17;
	int		pl17;
	int		ml18;
	int		pl18;
	int		ml19;
	int		pl19;
	int		ml20;
	int		pl20;
	int		ml21;
	int		pl21;
	int		ml22;
	int		pl22;
	int		ml23;
	int		pl23;
	int		ml24;
	int		pl24;
	int		ml25;
	int		pl25;
	int		ml26;
	int		pl26;
	int		ml27;
	int		pl27;
	int		ml28;
	int		pl28;
	int		ml29;
	int		pl29;
	int		ml30;
	int		pl30;
	int		ml31;
	int		pl31;
	int		ml32;
	int		pl32;
	int		ml33;
	int		pl33;
	int		ml34;
	int		pl34;
	int		ml35;
	int		pl35;
	int		ml36;
	int		pl36;
	int		pl37;
	int		ml38;
	int		pl38;
	int		pl40;
	int		ml41;
	int		pl41;
	int		ml42;
	int		pl42;
	int		ml43;
	int		pl43;

	testpointer = NULL;
	emptystring = "";
	int1 = 0;
	int2 = 0;
	int3 = -0;
	int4 = 0;
	test3 = "TEST";
	test4 = 0;
	c_ft = 0;
	c_sys = 0;
	// Currently leaking print address (%p)
	// also leaking: %x
	int ml = ft_printf("Teasdasdasdsdst! %%%%%%%%%%%%%%%% %% %d %d %s %%%%%%%% "
						"Das ist ziemlich "
						"cool! %% %% %% test mich %u %i %p %x %s %d %p %p \n",
						int1,
						int2,
						"TEST ME",
						int3,
						int4,
						testpointer,
						int4,
						NULL,
						4,
						NULL,
						NULL);
	int pl = printf("Teasdasdasdsdst! %%%%%%%%%%%%%%%% %% %d %d %s %%%%%%%% "
					"Das ist "
					"ziemlich cool! %% %% %% test mich %u %i %p %x %s %d %p %p "
					"\n",
					int1,
					int2,
					"TEST ME",
					int3,
					int4,
					testpointer,
					int4,
					NULL,
					4,
					NULL,
					NULL);
	ft_add_checksum(ml, pl, &c_ft, &c_sys);
	ml2 = ft_printf("A %% AAA %d\n", 0);
	pl2 = printf("A %% AAA %d\n", 0);
	ft_add_checksum(ml2, pl2, &c_ft, &c_sys);
	ml3 = ft_printf("");
	pl3 = printf("");
	ft_add_checksum(ml3, pl3, &c_ft, &c_sys);
	ml4 = ft_printf("aa\n");
	pl4 = printf("aa\n");
	ft_add_checksum(ml4, pl4, &c_ft, &c_sys);
	ml5 = ft_printf("%%\n");
	pl5 = printf("%%\n");
	ft_add_checksum(ml5, pl5, &c_ft, &c_sys);
	ml6 = ft_printf("%% A %% A %% \n");
	pl6 = printf("%% A %% A %% \n");
	ft_add_checksum(ml6, pl6, &c_ft, &c_sys);
	ml7 = ft_printf("!!%d %%\n", -2147483647);
	pl7 = printf("!!%d %%\n", -2147483647);
	ft_add_checksum(ml7, pl7, &c_ft, &c_sys);
	ml8 = ft_printf("!!%d %% %s \n", -123123, emptystring);
	pl8 = printf("!!%d %% %s \n", -123123, emptystring);
	ft_add_checksum(ml8, pl8, &c_ft, &c_sys);
	int ml9 = ft_printf("!!%d %% %s %u %p \n",
						-123123,
						emptystring,
						(unsigned int)4294967295,
						emptystring);
	int pl9 = printf("!!%d %% %s %u %p \n",
						-123123,
						emptystring,
						(unsigned int)4294967295,
						emptystring);
	ft_add_checksum(ml9, pl9, &c_ft, &c_sys);
	ml10 = ft_printf("%d\n", 0);
	pl10 = printf("%d\n", 0);
	ft_add_checksum(ml10, pl10, &c_ft, &c_sys);
	ml11 = ft_printf("%d\n", -111);
	pl11 = printf("%d\n", -111);
	ft_add_checksum(ml11, pl11, &c_ft, &c_sys);
	ml12 = ft_printf("%u\n", -123123);
	pl12 = printf("%u\n", -123123);
	ft_add_checksum(ml12, pl12, &c_ft, &c_sys);
	ml13 = ft_printf("%u\n", 221474836412318);
	pl13 = printf("%u\n", 221474836412318);
	ft_add_checksum(ml13, pl13, &c_ft, &c_sys);
	ml14 = ft_printf("%u\n", NULL);
	pl14 = printf("%u\n", NULL);
	ft_add_checksum(ml14, pl14, &c_ft, &c_sys);
	ml15 = ft_printf("%x\n", 0x0);
	pl15 = printf("%x\n", 0x0);
	ft_add_checksum(ml15, pl15, &c_ft, &c_sys);
	ml16 = ft_printf("%X\n", 0x0);
	pl16 = printf("%X\n", 0x0);
	ft_add_checksum(ml16, pl16, &c_ft, &c_sys);
	ml17 = ft_printf("%p\n", 0x0);
	pl17 = printf("%p\n", 0x0);
	ft_add_checksum(ml17, pl17, &c_ft, &c_sys);
	ml18 = ft_printf("%dp\n", 0);
	pl18 = printf("%dp\n", 0);
	ft_add_checksum(ml18, pl18, &c_ft, &c_sys);
	ml19 = ft_printf("%d\n", INT_MAX);
	pl19 = printf("%d\n", INT_MAX);
	ft_add_checksum(ml19, pl19, &c_ft, &c_sys);
	ml20 = ft_printf("%d\n", INT_MIN);
	pl20 = printf("%d\n", INT_MIN);
	ft_add_checksum(ml20, pl20, &c_ft, &c_sys);
	ml21 = ft_printf("%p\n", 18446744073709551615);
	pl21 = printf("%p\n", 18446744073709551615);
	ft_add_checksum(ml21, pl21, &c_ft, &c_sys);
	ml22 = ft_printf("%x\n", -1844674407);
	pl22 = printf("%x\n", -1844674407);
	ft_add_checksum(ml22, pl22, &c_ft, &c_sys);
	ml23 = ft_printf("%x\n", 0);
	pl23 = printf("%x\n", 0);
	ft_add_checksum(ml23, pl23, &c_ft, &c_sys);
	ml24 = ft_printf("%%p\n", &emptystring);
	pl24 = printf("%%p\n", &emptystring);
	ft_add_checksum(ml24, pl24, &c_ft, &c_sys);
	ml25 = ft_printf("%%%%%%%%\n");
	pl25 = printf("%%%%%%%%\n");
	ft_add_checksum(ml25, pl25, &c_ft, &c_sys);
	ml26 = ft_printf("%u\n", LONG_MAX);
	pl26 = printf("%u\n", LONG_MAX);
	ft_add_checksum(ml26, pl26, &c_ft, &c_sys);
	ml27 = ft_printf("%u\n", LONG_MIN);
	pl27 = printf("%u\n", LONG_MIN);
	ft_add_checksum(ml27, pl27, &c_ft, &c_sys);
	ml28 = ft_printf("%p\n", LONG_MAX);
	pl28 = printf("%p\n", LONG_MAX);
	ft_add_checksum(ml28, pl28, &c_ft, &c_sys);
	ml29 = ft_printf("%p\n", LONG_MIN);
	pl29 = printf("%p\n", LONG_MIN);
	ft_add_checksum(ml29, pl29, &c_ft, &c_sys);
	ml30 = ft_printf("%X\n", LONG_MAX);
	pl30 = printf("%X\n", LONG_MAX);
	ft_add_checksum(ml30, pl30, &c_ft, &c_sys);
	ml31 = ft_printf("%x\n", LONG_MAX);
	pl31 = printf("%x\n", LONG_MAX);
	ft_add_checksum(ml31, pl31, &c_ft, &c_sys);
	ml32 = ft_printf("%x\n", LONG_MAX);
	pl32 = printf("%x\n", LONG_MAX);
	ft_add_checksum(ml32, pl32, &c_ft, &c_sys);
	ml33 = ft_printf("%%d\n", INT_MAX);
	pl33 = printf("%%d\n", INT_MAX);
	ft_add_checksum(ml33, pl33, &c_ft, &c_sys);
	ml34 = ft_printf("%%d\n", INT_MIN);
	pl34 = printf("%%d\n", INT_MIN);
	ft_add_checksum(ml34, pl34, &c_ft, &c_sys);
	ml35 = ft_printf("%x\n", INT_MIN);
	pl35 = printf("%x\n", INT_MIN);
	ft_add_checksum(ml35, pl35, &c_ft, &c_sys);
	ml36 = ft_printf("%x %d %d %d %%d \n", INT_MAX, INT_MIN, 0, -1);
	pl36 = printf("%x %d %d %d %%d \n", INT_MAX, INT_MIN, 0, -1);
	ft_add_checksum(ml36, pl36, &c_ft, &c_sys);
	int ml37 =
		ft_printf("%x %d %d %d %%d %s\n", INT_MAX, INT_MIN, 0, -1, "HELLO!");
	pl37 = printf("%x %d %d %d %%d %s\n", INT_MAX, INT_MIN, 0, -1, "HELLO!");
	ft_add_checksum(ml37, pl37, &c_ft, &c_sys);
	ml38 = ft_printf("%x %%%% %d %u %%d %s\n", 4, 4, 0, "HELLO!");
	pl38 = printf("%x %%%% %d %u %%d %s\n", 4, 4, 0, "HELLO!");
	ft_add_checksum(ml38, pl38, &c_ft, &c_sys);
	int ml39 =
		ft_printf("%x %u %%%%%%%%%%%%%%%% %%d %s\n", LONG_MAX, LONG_MAX, "HI!");
	int pl39 =
		printf("%x %u %%%%%%%%%%%%%%%% %%d %s\n", LONG_MAX, LONG_MAX, "HI!");
	ft_add_checksum(ml39, pl39, &c_ft, &c_sys);
	int ml40 =
		ft_printf("%x %d %d %d %%d %s\n", LONG_MAX, INT_MIN, 0, -1, "HELLO!");
	pl40 = printf("%x %d %d %d %%d %s\n", LONG_MAX, INT_MIN, 0, -1, "HELLO!");
	ft_add_checksum(ml40, pl40, &c_ft, &c_sys);
	ml41 = ft_printf("%x %d %d %d %%d %s\n", NULL, INT_MIN, 0, -1, "HELLO!");
	pl41 = printf("%x %d %d %d %%d %s\n", NULL, INT_MIN, 0, -1, "HELLO!");
	ft_add_checksum(ml41, pl41, &c_ft, &c_sys);
	ml42 = ft_printf("%%%% %%%%\n");
	pl42 = printf("%%%% %%%%\n");
	ft_add_checksum(ml42, pl42, &c_ft, &c_sys);
	ml43 = ft_printf("%%%% %%%% %d %%%% %%%% %%%%d\n", 1, 2);
	pl43 = printf("%%%% %%%% %d %%%% %%%% %%%%d\n", 1, 2);
	ft_add_checksum(ml43, pl43, &c_ft, &c_sys);
	printf("================================================================"
			"\n");
	if (c_sys == c_ft)
		printf("\033[0;32m ALL 44 TEST PASSED! The mandatory part should be "
				"correct.");
	else
		printf("\033[0;31m FAILED SOME TESTS. \n Scroll up and look for the "
				"output. Sorry for the stupid formatted output.");
	resetColor();
	printf("\n\n");
	// fscanf(stdin, "c"); // uncomment this and use `ps aux | grep a.out` (your
	// executable name) and then `leaks executable-pid` to find leaks in the
	// program!
	return (0);
}
