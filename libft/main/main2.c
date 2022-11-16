#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <bsd/string.h>
#include <stdlib.h>
#include "../inc/libft.h"

int main()
    {
        char *c = "hey you";
        char *s = "how";
        char *r = "blue whales fly";

        printf("memset=""%p\n", memset(s, (ft_atoi(r) + 48), ft_atoi(c)));
        printf("and = %s\n", s);
        printf("ft_memset=""%p\n", ft_memset(s, (ft_atoi(r) + 48), ft_atoi(c)));
        printf("and = %s\n", s);
        printf("memcpy=""%p\n", memcpy(c, r, 2));
        printf("and = %s\n", c);
        printf("ft_memcpy=""%p\n", ft_memcpy(c, r, 2));
        printf("and=%s\n", c);
        printf("memmove=""%p\n", memmove(c, s, 3));
        printf("and=%s\n", c);
        printf("ft_memmove=""%p\n", ft_memmove(c, s, 3));
        printf("and =%s\n", c);
        printf("strlcpy=""%ld\n",strlcpy(s, r, ft_atoi(c)));
        printf("and=%s\n", s);
        printf("ft_strlcpy=""%ld\n",ft_strlcpy(s, r, ft_atoi(c)));
        printf("and =%s\n", s);
        printf("ft_strlcat=%ld\n", ft_strlcat(s, r, ft_atoi(c)));
        printf("and =%s\n", s);
        printf("strlcat=%ld\n", strlcat(s, r, ft_atoi(c)));
        printf("and =%s\n", s);
        printf("strncmp=%d\n", strncmp("qwerty", "wqerty", 2));
        printf("ft_strncmp=%d\n", ft_strncmp("qwerty", "wqerty", 2));
        printf("memchr %p\n", memchr(c, 'u', 5));
        printf("and =%s\n", c);
        printf("ft_memchr%p\n", ft_memchr(c, 'u', 5));
        printf("and =%s\n", c);
        printf("memcmp=%d\n", memcmp("qwerty", "wqerty", 2));
        printf("ft_memcmp=%d\n", ft_memcmp("qwerty", "wqerty", 2));
        printf("strnstr=%s\n", strnstr("on etait jeune a l'epoque", "jeune", 14));
        printf("ft_strnstr=%s\n", ft_strnstr("on etait jeune a l'epoque", "jeune", 14));
        printf("ft_atoi=%d\n", ft_atoi("+442"));
        printf("atoi=%d\n", atoi("+442"));
        printf("strdup=%s\n", strdup("novole bianci"));
        printf("ft_strdup=%s\n", ft_strdup("novole bianci"));
        printf("ft_substr=%s\n", ft_substr("le renard bleu saute", -3, -3));
        printf("ft_strjoin=%s\n", ft_strjoin(c, r));
        printf("ft_strtrim=%s\n", ft_strtrim(c, "you"));

    }