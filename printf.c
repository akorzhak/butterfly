int		ft_printf(const char *format, ...)
{
	char *s;
	char *c;
	int i;
	va_list arg;

	s = (char *)format;
	i = 0;
	va_start(arg, format);
	while (*s)
	{
		if ((ft_strchr(s, '%')) && (c = ft_strchr(s, '%')))
		{
			if (c - s > 0)
				i += write(1, s, c - s);
			i += ft_readparams(&c, arg); //%...
			s = c;
		}
	}
	va_end(arg);
	return (i + write(1, s, ft_strlen(s)));
}

int		ft_printf(const char *format, ...)
{
	char *s;
	char *c;
	int i;
	va_list arg;

	s = (char *)format;
	i = 0;
	va_start(arg, format);
	while (*s)
	{
		if (!ft_strchr(s, '%'))
		{
			i += write(1, s, ft_strlen(s));
			break ;
		}
		else if ((c = ft_strchr(s, '%'))) //if '%' is found, assign c to %...
		{
			if (c - s > 0)
				i += write(1, s, c - s);
			i += ft_readparams(&c, arg); //%...
			s = c;
		}
	}
	va_end(arg);
	return (i);
}