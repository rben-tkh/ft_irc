/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 06:10:18 by rben-tkh          #+#    #+#             */
/*   Updated: 2023/05/30 20:44:38 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

# define ADMIN_USER "groot"
# define ADMIN_PASS "theboss"

# include <ircserv.hpp>

/*----------------------------------S_USER-----------------------------------*/

typedef struct s_user
{
	int					cfd;
	bool				g_oper;
	std::string			user;
	std::string			nick;
	std::string			host;
}	t_user;

/*----------------------------------S_CHAN-----------------------------------*/

typedef struct s_chan
{
	bool						mode_inv;
	bool						mode_topic;
	size_t						mode_limit;
	std::string					chan_key;
	std::string					chan_topic;
	std::vector<t_user*>		chan_users;
	std::vector<int>			chan_operators;
	std::vector<std::string>	chan_invitees;
}	t_chan;

/*----------------------------------C_COMMAND--------------------------------*/

class Command
{
	public:
										Command(void);
										Command(const Command &other);
		Command							&operator=(const Command &other);
										~Command(void);

		std::vector<pollfd>				getClients(void)const;
		std::map<int, t_user>			getUsers(void)const;
		std::map<std::string, t_chan>	getChannels(void)const;

		void	exec_command(std::vector<std::string> cmd, int i);
		void	send_code(std::string code, std::string message, int cfd);
		int		user_inchan(std::string chan, int cfd);
		bool	oper_inchan(std::string chan, int cfd);
		bool	user_invited(std::string chan, int cfd);
		void	disconnect(int i, int &cfd);
		void	oper(std::string user, std::string password, int cfd);
		void	pong(std::vector<std::string> cmd, int cfd);
		void	nick(std::vector<std::string> cmd, int cfd);
		void	privmsg(std::vector<std::string> cmd, int cfd);
		void	join(std::vector<std::string> cmd, int cfd);
		void	mode(std::vector<std::string> cmd, int cfd);
		void	part(std::vector<std::string> cmd, int cfd);
		void	topic(std::vector<std::string> cmd, int cfd);
		void	kick(std::vector<std::string> cmd, int cfd);
		void	invite(std::vector<std::string> cmd, int cfd);

	protected:
		std::vector<pollfd>				clients;
		std::map<int, t_user>			users;

	private :
		std::map<std::string, t_chan>	channels;
};

/*------------------------------------T^T------------------------------------*/

#endif
