int		ft_printf(const char *format, ...)
{
	char *s;
	int i;
	va_list arg;

	s = (char *)format;
	i = 0;
	va_start(arg, format);
	while (*s)
	{
		if ((ft_strchr(s, '%') && (s = ft_strchr(s, '%'))))
		{
			if (s - format > 0)
				i += write(1, format, s - format);
			i += ft_readparams(&s, arg); //%hlikkl
		}
		else
		{
			i += write(1, format, ft_strlen(format));
			break ;
		}
	}
	va_end(arg);
	return (i);
}