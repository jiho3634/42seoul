#include <iostream>

char    *ft_megaphone(char *av)
{
    int i;

    i = -1;
    while (av[++i])
    {
        if (av[i] >= 'a' && av[i] <= 'z')
            av[i] -= 32;
    }
    return (av);
}

int main(int ac, char **av)
{
    int i;

    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 0;    
    while (av[++i])
        std::cout << ft_megaphone(av[i]);
    std::cout << std::endl;
    return (0);
}