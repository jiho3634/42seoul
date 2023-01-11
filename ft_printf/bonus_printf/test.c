#include <stdio.h>

int main(void)
{
//	int				i = 0;
//	char			c = 'a';
//	char			*s = "jiho";
//	int				d = 12345;
	unsigned int	u = 12345;
//	char			*p = s;
//	int				x = 12345;


	printf("\n\n===========c test=============\n\n");
	printf("return value : %d\n\n", printf("test%d:%.c\n",++i , c));
	printf("return value : %d\n\n", printf("test%d:%-3.c\n",++i , c));
	printf("return value : %d\n\n", printf("test%d:%3.c\n",++i , c));
	//printf("return value : %d\n\n", printf("test%d:%..c\n",++i , c));
	//printf("return value : %d\n\n", printf("test%d:%.1c\n",++i , c));
	//printf("return value : %d\n\n", printf("test%d:%3.5c\n",++i , c));
	//printf("return value : %d\n\n", printf("test%d:%3.2c\n",++i , c));
	//printf("return value : %d\n\n", printf("test%d:%03.c\n",++i , c));
	//printf("return value : %d\n\n", printf("test%d:%+3.c\n",++i , c));
	//printf("return value : %d\n\n", printf("test%d:%#3.c\n",++i , c));
	//printf("return value : %d\n\n", printf("test%d:% -3.c\n",++i , c));
	
	
	printf("\n\n===========s test=============\n\n");
	printf("return value : %d\n\n", printf("test%d:%.s\n",++i , s));
	printf("return value : %d\n\n", printf("test%d:%3s\n",++i , s));
	printf("return value : %d\n\n", printf("test%d:%3.2s\n",++i , s));
	printf("return value : %d\n\n", printf("test%d:%10.2s\n",++i , s));
	printf("return value : %d\n\n", printf("test%d:%-10.2s\n",++i , s));
	printf("return value : %d\n\n", printf("test%d:%-.2s\n",++i , s));
	//printf("return value : %d\n\n", printf("test%d:%+10.2s\n",++i , s));
	//printf("return value : %d\n\n", printf("test%d:%-#10.2s\n",++i , s));
	//printf("return value : %d\n\n", printf("test%d:%-010.2s\n",++i , s));
	//printf("return value : %d\n\n", printf("test%d:% -.2s\n",++i , s));

	
	printf("\n\n===========d test=============\n\n");
	printf("return value : %d\n\n", printf("test%d:%.d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:%.3d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:%3.3d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:%10.d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:%010d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:%+010d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:%-10d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:%.10d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:%+15.10d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:% -15.10d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:%-+15.10d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:% - - -15.10d\n",++i , d));
	printf("return value : %d\n\n", printf("test%d:%-+-+15.10d\n",++i , d));
	//printf("return value : %d\n\n", printf("test%d:%#-10d\n",++i , d));

	printf("\n\n===========u test=============\n\n");
	printf("return value : %d\n\n", printf("test%d:%.u\n",++i , u));
	printf("return value : %d\n\n", printf("test%d:%.0u\n",++i , u));
	printf("return value : %d\n\n", printf("test%d:%.3u\n",++i , u));
	printf("return value : %d\n\n", printf("test%d:%.10u\n",++i , u));
	printf("return value : %d\n\n", printf("test%d:%5.10u\n",++i , u));
	printf("return value : %d\n\n", printf("test%d:%15.10u\n",++i , u));
	printf("return value : %d\n\n", printf("test%d:%-15.10u\n",++i , u));
	printf("return value : %d\n\n", printf("test%d:%015u\n",++i , u));
	//printf("return value : %d\n\n", printf("test%d:%-#15.10u\n",++i , u));
	//printf("return value : %d\n\n", printf("test%d:%-+15.10u\n",++i , u));
	//printf("return value : %d\n\n", printf("test%d:% 15.10u\n",++i , u));











	printf("\n\n===========p test=============\n\n");
	printf("return value : %d\n\n", printf("test%d:%.p\n", ++i, p));
	printf("return value : %d\n\n", printf("test%d:%20p\n", ++i, p));
	printf("return value : %d\n\n", printf("test%d:%-20p\n", ++i, p));
	//printf("return value : %d\n\n", printf("test%d:%.0p\n", ++i, p));
	//printf("return value : %d\n\n", printf("test%d:%020p\n", ++i, p));
	//printf("return value : %d\n\n", printf("test%d:%+20p\n", ++i, p));
	//printf("return value : %d\n\n", printf("test%d:%#20p\n", ++i, p));
	//printf("return value : %d\n\n", printf("test%d:% 20p\n", ++i, p));
	


	printf("\n\n===========x test=============\n\n");
	printf("return value : %d\n\n", printf("test%d:%.x\n", ++i, x));
	printf("return value : %d\n\n", printf("test%d:%.2x\n", ++i, x));
	printf("return value : %d\n\n", printf("test%d:%.10x\n", ++i, x));
	printf("return value : %d\n\n", printf("test%d:%15.10x\n", ++i, x));
	printf("return value : %d\n\n", printf("test%d:%#-15.10x\n", ++i, x));
	//printf("return value : %d\n\n", printf("test%d:% 15.10x\n", ++i, x));
	//printf("return value : %d\n\n", printf("test%d:%015.10x\n", ++i, x));
	//printf("return value : %d\n\n", printf("test%d:%+15.10x\n", ++i, x));






	printf("\n\n===========%% test=============\n\n");
	printf("return value : %d\n\n", printf("test%d:%10%\n", ++i));
	printf("return value : %d\n\n", printf("test%d:%.%\n", ++i));
	printf("return value : %d\n\n", printf("test%d:%.10%\n", ++i));
	printf("return value : %d\n\n", printf("test%d:%10.5%\n", ++i));
	printf("return value : %d\n\n", printf("test%d:%5.10%\n", ++i));
	printf("return value : %d\n\n", printf("test%d:%05%\n", ++i));
	printf("return value : %d\n\n", printf("test%d:%-5%\n", ++i));
	printf("return value : %d\n\n", printf("test%d:%+5% -> ignored \n", ++i));
	printf("return value : %d\n\n", printf("test%d:%#5% -> ignored \n", ++i));
	printf("return value : %d\n\n", printf("test%d:% 5% -> ignored \n", ++i));
	



	return (0);
}
