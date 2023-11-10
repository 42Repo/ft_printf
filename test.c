#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>

int ft_printf(const char *format, ...); // Assurez-vous que cette déclaration correspond à votre ft_printf

int main() {
	int original_ret, ft_ret;

	printf("-- Test --\n");
	original_ret = printf("%s", "");
	ft_ret = ft_printf("%s", "");
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Chaîne de format nulle --\n");
	original_ret = printf(NULL);
	ft_ret = ft_printf(NULL);
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Arguments manquants --\n");
	original_ret = printf("%d");
	printf("\n");
	ft_ret = ft_printf("%d");
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Longue chaîne --\n");
	char long_string[1000];
	memset(long_string, 'a', sizeof(long_string) - 1);
	long_string[sizeof(long_string) - 1] = '\0';
	original_ret = printf("%s", long_string);
	ft_ret = ft_printf("%s", long_string);
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Passer un mauvais type --\n");
	original_ret = printf("%d", "string");
	ft_ret = ft_printf("%d", "string");
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	   // Test: Impression de pointeurs non initialisés
	void *uninitialized_ptr;
	original_ret = printf("%p\n", uninitialized_ptr);
	ft_ret = ft_printf("%p\n", uninitialized_ptr);
	printf("\nOriginal printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	// Test: Utilisation de spécificateurs de format incomplets
	original_ret = printf("Incomplete specifier: % \n");
	ft_ret = ft_printf("Incomplete specifier: % \n");
	printf("\nOriginal printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	// Test: Utiliser des pointeurs de fonction avec `%p`
	original_ret = printf("%p\n", main);
	ft_ret = ft_printf("%p\n", main);
	printf("\nOriginal printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	// Test: Impression de la représentation en mémoire d'une variable
	int a = 42;
	original_ret = printf("%p\n", &a);
	ft_ret = ft_printf("%p\n", &a);
	printf("\nOriginal printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	// Test: Caractères non-ASCII avec `%c` et `%s`
	original_ret = printf("%c\n", 0x80);
	ft_ret = ft_printf("%c\n", 0x80);
	printf("\nOriginal printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	original_ret = printf("%s\n", "\xc3\xb1");
	ft_ret = ft_printf("%s\n", "\xc3\xb1");
	printf("\nOriginal printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	original_ret = printf("%|bc%");
	ft_ret = ft_printf("%|bc%");
	printf("\nOriginal printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	original_ret = printf("%|bc%\n");
	ft_ret = ft_printf("%|bc%\n");
	printf("\nOriginal printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	ft_ret = ft_printf("\n|bc%");
	original_ret = printf("\n|bc%");
	printf("\nOriginal printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	ft_ret = ft_printf("\n%m%m\n");
	original_ret = printf("\n%m\n");
	printf("Original printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	ft_ret = ft_printf("\n%5%\n");
	original_ret = printf("\n%5%\n");
	printf("Original printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	ft_ret = ft_printf(NULL);
	original_ret = printf("\n%kjg%%HGF%%5d%");
	printf("Original printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	printf("-- Test: Valeurs max et min pour les entiers --\n");
	original_ret = printf("%d %d\n", INT_MAX, INT_MIN);
	ft_ret = ft_printf("%d %d\n", INT_MAX, INT_MIN);
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Valeurs max et min pour les unsigned int --\n");
	original_ret = printf("%u %u\n", UINT_MAX, 0);
	ft_ret = ft_printf("%u %u\n", UINT_MAX, 0);
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Valeurs max et min pour les pointeurs --\n");
	int* max_ptr = (int*) UINTPTR_MAX;  // Utiliser avec précaution, pas portable et peut être dangereux
	int* min_ptr = (int*) 0;
	original_ret = printf("%p %p\n", max_ptr, min_ptr);
	ft_ret = ft_printf("%p %p\n", max_ptr, min_ptr);
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Spécificateurs de format incorrects --\n");
	original_ret = printf("%y %z\n");
	ft_ret = ft_printf("%y %z\n");
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Conversion avec les spécificateurs de format multiples --\n");
	original_ret = printf("%d %s %x %X %u %c %%\n", 42, "test", 42, 42, 42, 'A');
	ft_ret = ft_printf("%d %s %x %X %u %c %%\n", 42, "test", 42, 42, 42, 'A');
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\nw", ft_ret);

	printf("-- Test: Chaînes de format bizarres --\n");
	original_ret = printf("%s %d %10s\n", "test", 42, "aligned");
	ft_ret = ft_printf("%s %d %10s\n", "test", 42, "aligned");
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Utilisation incorrecte de pourcentage --\n");
	original_ret = printf("%%d\n");
	ft_ret = ft_printf("%%d\n");
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Spécificateurs de format mélangés avec du texte --\n");
	original_ret = printf("Ceci est un test: %d %s\n", 123, "fin");
	ft_ret = ft_printf("Ceci est un test: %d %s\n", 123, "fin");
	printf("\nOriginal printf returned: %d\n", original_ret);
	printf("ft_printf returned: %d\n\n", ft_ret);

	printf("-- Test: Valeurs limites --\n");
	original_ret = printf("%d %d %u %x %X\n", INT_MAX, INT_MIN, UINT_MAX, INT_MAX, INT_MAX);
	ft_ret = ft_printf("%d %d %u %x %X\n", INT_MAX, INT_MIN, UINT_MAX, INT_MAX, INT_MAX);
	printf("Original printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	printf("-- Test: Chaîne de format incorrecte --\n");
	original_ret = printf("%y\n");
	ft_ret = ft_printf("%y\n");
	printf("Original printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	printf("-- Test: Types incorrects pour les spécificateurs --\n");
	original_ret = printf("%d\n", "test");
	ft_ret = ft_printf("%d\n", "test");
	printf("Original printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	printf("-- Test: Spécificateurs de format incomplets --\n");
	original_ret = printf("%\n");
	ft_ret = ft_printf("%\n");
	printf("Original printf returned: %d | ft_printf returned: %d\n", original_ret, ft_ret);

	printf("-- Test: Impression de l'adresse de la fonction main --\n");
	original_ret = printf("%p\n", main);
	ft_ret = ft_printf("%p\n", main);
	printf("Original printf returned: %d | ft_printf returned: %d\n\n", original_ret, ft_ret);


// Continuez à ajouter plus de tests en suivant les principes ci-dessus...

	return 0;
}
