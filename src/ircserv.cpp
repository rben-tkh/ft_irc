/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircserv.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:32:42 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/05/30 20:19:40 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ircserv.hpp>

bool	g_stop = false;

std::vector<std::string>	splity(std::string str, const char *delim)
{
	char						*buffer;
	std::string					strCpy(str);
	std::vector<std::string>	tab;

	buffer = std::strtok(&strCpy[0], delim);
	while (buffer != NULL)
	{
		tab.push_back(buffer);
		buffer = std::strtok(NULL, delim);
	}
	return (tab);
}

static void	handle_sigint(int signum)
{
	(void)signum;
	g_stop = true;
	std::cout << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cerr << RED "Usage : " UNDER USAGE RESET;
		return (ERROR);
	}
	std::signal(SIGINT, handle_sigint);
	std::signal(SIGQUIT, SIG_IGN);
	std::signal(SIGPIPE, SIG_IGN);
	try
	{
		Server ircserv(av[1], av[2]);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}
	return (0);
}
