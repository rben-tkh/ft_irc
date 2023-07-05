/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ircserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 06:41:57 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/05/30 20:19:43 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERV_HPP
# define IRCSERV_HPP

# define CYAN "\033[1;3;36m"
# define YELLOW "\033[0;3;33m"
# define GREEN "\033[0;3;32m"
# define RED "\033[0;3;31m"
# define UNDER "\033[4m"
# define RESET "\033[0m"

# define USAGE "./ircserv <port> <password>\n"
# define ERROR -1
# define ISSPACE "\t\n\r\v\f "
# define BUFFER_SIZE 1024
# define SEND_ERROR " : Failed to send message\n"

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <exception>

# include <cstring>
# include <cstdio>
# include <cstdlib>
# include <climits>
# include <cmath>
# include <ctime>
# include <cctype>
# include <csignal>

# include <vector>
# include <map>
# include <set>
# include <queue>
# include <iterator>
# include <algorithm>
# include <utility>

# include <stdint.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <poll.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <unistd.h>
# include <errno.h>

# include <Command.hpp>
# include <Server.hpp>

extern bool	g_stop;

/*-----------------------------------UTILS-----------------------------------*/

std::vector<std::string>	splity(std::string str, const char *delim);

/*------------------------------------T^T------------------------------------*/

#endif
