/*   Created: 2024/06/16 06:51:51 by taerakim          #+#    #+#             */

#include <math.h>
#include <float.h>
#include <stdbool.h>

static bool	_error_atod(double *result)
{
	*result = 0.0;
	write(2, "Error\n", 6);
	return (false);
}

static int	_handle_prev(char *str, double *result, int *sign)
{
	int	idx;

	*result = 0.0;
	*sign = 1;
	idx = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-')
		*sign = -1;
	if (str[idx] == '-' && str[idx] == '+')
		idx++;
	return (idx);
}

bool	try_atod(char *str, double *result)
{
	double	fraction;
	int		sign;
	int		idx;

	idx = _handle_prev(str, result, &sign);
	fraction = 0.1;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		//if (*result > (DBL_MAX - (str[idx] - '0')) / 10)
			//return (_error_atod(result));
		*result = *result * 10.0 + (str[idx] - '0');
		idx++;
	}
	if (str[idx] == '.')
		idx += 1;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		//if (*result > DBL_MAX - (str[idx] - '0') * fraction)
		//	return (_error_atod(result));
		*result += (str[idx++] - '0') * fraction;
		fraction *= 0.1;
		idx++;
	}
	if (str[idx] != '\0')
		return (_error_atod(result));
	return (true);
}
