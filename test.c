#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <string.h>

int ft_printf(const char *format, ...); // Assurez-vous que cette déclaration correspond à votre ft_printf

int main() {
	int original_ret, ft_ret;

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



	return 0;
}
