# include <errno.h>
# include "sendmail.h"

#ifndef DAEMON
SCCSID(@(#)daemon.c	3.11		05/06/82	(w/o daemon mode));
#else

# include <sys/socket.h>
# include <net/in.h>

SCCSID(@(#)daemon.c	3.11		05/06/82	(with daemon mode));

/*
**  DAEMON.C -- routines to use when running as a daemon.
*/
/*
**  GETREQUESTS -- open mail IPC port and get requests.
**
**	Parameters:
**		none.
**
**	Returns:
**		none.
**
**	Side Effects:
**		Waits until some interesting activity occurs.  When
**		it does, a child is created to process it, and the
**		parent waits for completion.  Return from this
**		routine is always in the child.
*/

getrequests()
{
	for (;;)
	{
		register int pid;
		auto int st;
		register int port;

		/*
		**  Wait for a connection.
		*/

		while ((port = getconnection()) < 0)
		{
			syserr("getrequests: getconnection failed");
			sleep(30);
		}

		/*
		**  Create a subprocess to process the mail.
		*/

# ifdef DEBUG
		if (Debug > 1)
			printf("getrequests: forking (port = %d)\n", port);
# endif DEBUG

		pid = fork();
		if (pid < 0)
		{
			syserr("daemon: cannot fork");
			sleep(10);
			close(port);
			continue;
		}

		if (pid == 0)
		{
			/*
			**  CHILD -- return to caller.
			**	Verify calling user id if possible here.
			*/

			InChannel = fdopen(port, "r");
			OutChannel = fdopen(port, "w");
			initsys();
# ifdef DEBUG
			if (Debug > 1)
				printf("getreq: returning\n");
# endif DEBUG
			return;
		}

		/*
		**  PARENT -- wait for child to terminate.
		**	Perhaps we should allow concurrent processing?
		*/

# ifdef DEBUG
		if (Debug > 1)
		{
			sleep(2);
			printf("getreq: parent waiting\n");
		}
# endif DEBUG

		(void) wait(&st);
		close(port);
	}
}
/*
**  GETCONNECTION -- make a connection with the outside world
**
**	Parameters:
**		none.
**
**	Returns:
**		The port for mail traffic.
**
**	Side Effects:
**		Waits for a connection.
*/

struct sockaddr_in SendmailAddress = { AF_INET, IPPORT_SMTP };

getconnection()
{
	register int s;
	struct sockaddr otherend;

	/*
	**  Set up the address for the mailer.
	*/

	SendmailAddress.sin_addr.s_addr = 0;
	SendmailAddress.sin_port = IPPORT_SMTP;

	/*
	**  Try to actually open the connection.
	*/

# ifdef DEBUG
	if (Debug)
		printf("getconnection\n");
# endif DEBUG

	s = socket(SOCK_STREAM, 0, &SendmailAddress, SO_ACCEPTCONN);

# ifdef DEBUG
	if (Debug)
		printf("getconnection: %d\n", s);
# endif DEBUG
	accept(s, &otherend);

	return (s);
}
/*
**  MAKECONNECTION -- make a connection to an SMTP socket on another machine.
**
**	Parameters:
**		host -- the name of the host.
**		port -- the port number to connect to.
**		outfile -- a pointer to a place to put the outfile
**			descriptor.
**		infile -- ditto for infile.
**
**	Returns:
**		An exit code telling whether the connection could be
**			made and if not why not.
**
**	Side Effects:
**		none.
*/

makeconnection(host, port, outfile, infile)
	char *host;
	int port;
	FILE **outfile;
	FILE **infile;
{
	register int s;

	/*
	**  Set up the address for the mailer.
	*/

	if ((SendmailAddress.sin_addr.s_addr = rhost(&host)) == -1)
		return (EX_NOHOST);
	if (port == 0)
		port = IPPORT_SMTP;
	SendmailAddress.sin_port = port;

	/*
	**  Try to actually open the connection.
	*/

# ifdef DEBUG
	if (Debug)
		printf("makeconnection (%s)\n", host);
# endif DEBUG

	s = socket(SOCK_STREAM, 0, 0, 0);
	if (s < 0)
	{
		syserr("makeconnection: no socket");
		goto failure;
	}

# ifdef DEBUG
	if (Debug)
		printf("makeconnection: %d\n", s);
# endif DEBUG
	if (connect(s, &SendmailAddress) < 0)
	{
		/* failure, decide if temporary or not */
	failure:
		switch (errno)
		{
		  case EISCONN:
		  case ETIMEDOUT:
			/* there are others, I'm sure..... */
			return (EX_TEMPFAIL);

		  default:
			return (EX_UNAVAILABLE);
		}
	}

	/* connection ok, put it into canonical form */
	*outfile = fdopen(s, "w");
	*infile = fdopen(s, "r");

	return (0);
}

#endif DAEMON
