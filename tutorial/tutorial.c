/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:04:40 by ftanon            #+#    #+#             */
/*   Updated: 2024/06/11 17:59:03 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

//////////////////////////////////////// DUP

////////// REACTIVE

// int main()
// {
// 	int fd;

// 	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
// 	dup2(fd, STDOUT_FILENO);
// 	close(fd);
// 	printf("This is printed in example.txt!\n");

// 	return (0);
// }

////////// SINGAPORE

// int main() {
//     int file = open("output.txt", O_WRONLY | O_CREAT, 0644);
//     int stdout = 1;

//     dup2(stdout, file);
//     // writing to output.txt will be redirected to stdout
//     // hence, output.txt does not contain anything
//     write(file, "example of dup2\n", 16);
//     close(file);
//     return 0;
// }

// int main() {
//     int file = open("output.txt", O_WRONLY | O_CREAT, 0644);
//     int stdout = 1;

//     dup2(file, stdout);
//     // writing to stdout will be redirected to output.txt
//     // hence, stdout does not contain anything
//     // but output.txt contains the written string
//     write(stdout, "example of dup2\n", 16); //
//     close(file);
//     return 0;
// }

////////// CODE QUOI

// int	main(void)
// {
// 	int	fd;
// 	int	fd_copy;
// 	int	nb_read;
// 	char	buf[15];

// //	Imprime le PID de notre processus pour pouvoir regarder
// //	les fd ouverts par ce processus
// 	printf("Mon PID est %d\n", getpid());
// //	Recupère un fd en ouvrant un fichier
// 	fd = open("alpha.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// //	Duplique ce fd sur le fd inutilisé
// //	le plus petit
// 	fd_copy = dup(fd);
// 	if (!fd_copy)
// 		return (1);
// //	Lit le fd ouvert
// 	nb_read = read(fd, buf, 10);
// 	if (nb_read == -1)
// 		return (1);
// 	buf[nb_read] = '\0';
// 	printf("fd %d contient : %s\n", fd, buf);
// //	Lit le fd dupliqué
// 	nb_read = read(fd_copy, buf, 10);
// 	if (nb_read == -1)
// 		return (0);
// 	buf[nb_read] = '\0';
// 	printf("fd %d contient : %s\n", fd_copy, buf);
// //	Duplique le descripteur sur l'entrée standard
// 	dup2(fd, STDIN_FILENO);
// //	Boucle infinie pour pouvoir aller voir les fd ouverts
// //	par ce processus avec ls -la /proc/PID/fd
// 	while (1)
// 		;
// }

//////////////////////////////////////// FORK

////////// CODE QUOI

// int main(void)
// {
// 	pid_t pid;

// 	printf("Fork ici.\n");
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		// Si fork renvoie -1, il y a eu une erreur !
// 		return (1);
// 	}
// 	printf("\nFork reussi !\n");
// 	if (pid == 0)
// 	{
// 		// La valeur de retour de fork
// 		// est 0, ce qui veut dire qu'on est
// 		// dans le processus fils
// 		printf("Fils : Je suis le fils, mon pid interne est %d.\n", pid);
// 	}
// 	else if (pid > 0)
// 	{
// 		// La valeur de retour de fork 
// 		// est différente de 0, ce qui veut dire
// 		// qu'on est dans le processus père
// 		printf("Pere : Je suis le pere, le pid de mon fils est %d.\n", pid);
// 	}
// 	return(0);
// }

////////// MEMORY DUPLICATED NOT SHARED

// // Routine du processus fils :
// void	routine_fils(pid_t pid, int *nb)
// {
// 	printf("Fils : Coucou! Je suis le fils. PID recu de fork = %d\n", pid);
// 	printf("Fils : Le nombre est %d\n", *nb);
// }

// // Routine du processus père :
// void	routine_pere(pid_t pid, int *nb)
// {
// 	printf("Pere : Je suis le pere. PID recu de fork = %d\n", pid);
// 	printf("Pere : Le nombre est %d\n", *nb);
// 	*nb *= 2;
// 	printf("Pere : Le nombre modifie est %d\n", *nb);
// }

// int	main(void)
// {
// 	pid_t	pid; // Stocke le retour de fork
// 	int	nb;  // Stocke un entier

// 	nb = 42;
// 	printf("Avant fork, le nombre est %d\n", nb);
// 	pid = fork(); // Création du processus fils
// 	if (pid == -1)
// 		return (EXIT_FAILURE);
// 	else if (pid == 0) // Retour de fork est 0, on est dans le fils
// 		routine_fils(pid, &nb);
// 	else if (pid > 0) // Retour de fork > 0, on est dans le père
// 		routine_pere(pid, &nb);
// 	return (EXIT_SUCCESS);
// }

////////// REACTIVE

// int main()
// {
// 	pid_t pid;

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}

// 	if (pid == 0)
// 		printf("This is the child process. (pid: %d)\n", getpid());
// 	else
// 		printf("This is the parent process. (pid: %d)\n", getpid());

// 	return (0);
// }

////////// SINGAPORE

// int main() {
//     int data = 10;
//     pid_t pid;

//     pid = fork();
//     if (pid == 0) { // if it is child process
//         data = -1;  // child process has a copy of data
//                     // hence, this change does not reflect in
//                     // variable data in the parent process
//     } else {
//       // this is parent process
//       waitpid(pid, NULL, 0); // wait till child process is finished
//       printf("data = %d\n", data); 
//     }
//     return 0;
// }

////////// LANNUR

// int main() {
// 	pid_t pid;

// 	pid = 9;
// 	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");    
// 	printf("main process (before fork). My PID is %d.\n", getpid());
// 	// Create a child process using fork()
// 	pid = fork();
// 	printf("------------------------------------\n");     
// 	printf("Hello1, I am main process (after fork). My PID is %d.\n", getpid());
// 	if (pid < 0) {
// 		// Fork failed
// 		fprintf(stderr, "Fork2 failed.\n");
// 		return 1;
// 	} else if (pid == 0) {
// 		// Child process
// 		printf("child! PID %d, child's PID %d\n", getpid(), pid);
// 	} else {
// 		// Parent process
// 		printf("parent! PID %d, child's PID %d.\n", getpid(), pid);
// 	}

//     return 0;
// }

//////////////////////////////////////// WAIT

////////// CODE QUOI PARENT PROCESS DOESN't WAIT FOR CHILD PROCESS

// int main(void)
// {
//     pid_t pid;

// 	pid = fork();
// 	if (pid == -1)
// 		return (1);
// 	if (pid == 0)
// 	{
// 		printf("Fils : Je suis le fils, mon pid interne est %d.\n", pid);
// 		sleep(1); // Attendre 1 seconde.
// 		printf("Fils : Termine !\n");
// 	}
// 	else if (pid > 0)
// 	{
// 		printf("Pere : Je suis le pere, le pid de mon fils est %d.\n", pid);
// 		printf("Pere : Termine !\n");
// 	}
// 	return (0);
// }

////////// CODE QUOI

// #ifndef CHILD_EXIT_CODE
// # define CHILD_EXIT_CODE 42
// #endif

// // Définition d'une macro pour le statut de fin
// // du fils auquel on s'attend
// #define EXPECTED_CODE 42

// // Routine du processus fils :
// void	routine_fils(pid_t pid)
// {
// 	printf("\e[36mFils : Coucou! Je suis le fils. PID recu de fork = %d\e[0m\n",
// 			pid);
// 	printf("\e[36mFils : Je sors avec le statut de fin %d.\e[0m\n",
// 			CHILD_EXIT_CODE);
// 	exit(CHILD_EXIT_CODE);
// }

// // Routine du processus pere :
// void	routine_pere(pid_t pid)
// {
// 	int	status;

// 	printf("Pere : Je suis le pere. PID recu de fork = %d\n", pid);
// 	printf("Pere : J'attends mon fils qui a le PID [%d].\n", pid);
// 	waitpid(pid, &status, 0); // Attendre le fils
// // ou   wait(&status);
// 	printf("Pere : Mon fils est sorti avec le statut %d\n", status);
// 	if (WIFEXITED(status)) // Si le fils est sorti normalement
// 	{
// 		printf("Pere : Le statut de fin de mon fils est %d\n",
// 				WEXITSTATUS(status));
// 		if (WEXITSTATUS(status) == EXPECTED_CODE)
// 			printf("Pere : C'est le statut que j'attendais !\n");
// 		else
// 			printf("Pere : Je ne m'attendais pas a ce statut-la...\n");
// 	}
// }

// int	main(void)
// {
// 	pid_t	pid; // Stocke le retour de fork

// 	pid = fork(); // Création d'un processus fils
// 	if (pid == -1)
// 		return (EXIT_FAILURE);
// 	else if (pid == 0) // Processus fils
// 		routine_fils(pid);
// 	else if (pid > 0) // Processus père
// 		routine_pere(pid);
// 	return (EXIT_SUCCESS);
// }

////////// REACTIVE

// int main(int argc, char *argv[])
// {
// 	pid_t pid;

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid == 0)
// 	{
// 		printf("I am the child process.\n");
// 		sleep(2);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		printf("I am the parent process.\n");
// 		wait(NULL);
// 		printf("Child process terminated after a 2s delay.\n");
// 	}

// 	return (EXIT_SUCCESS);
// }

//////////////////////////////////////// PIPE

//////////  developpez

	// int pipefd[2];
	// pid_t cpid;
	// char buf;
	// if (argc != 2) {
	// fprintf(stderr, "Usage: %s <string>\n", argv[0]);
	// exit(EXIT_FAILURE);
	// }
	// if (pipe(pipefd) == -1) {
	// 	perror("pipe");
	// 	exit(EXIT_FAILURE);
	// }
	// cpid = fork();
	// if (cpid == -1) {
	// 	perror("fork");
	// 	exit(EXIT_FAILURE);
	// }
	// if (cpid == 0) {    /* Le fils lit dans le tube */
	// 	close(pipefd[1]);    
	// 	while (read(pipefd[0], &buf, 1) > 0)
	// 		write(STDOUT_FILENO, &buf, 1);
	// 	write(STDOUT_FILENO, "\n", 1);
	// 	close(pipefd[0]);
	// 	_exit(EXIT_SUCCESS);
	// } else {            /* Le père écrit argv[1] dans le tube */
	// 	close(pipefd[0]);         
	// 	write(pipefd[1], argv[1], strlen(argv[1]));
	// 	close(pipefd[1]);          /* Le lecteur verra EOF */
	// 	wait(NULL);                /* Attente du fils */
	// 	exit(EXIT_SUCCESS);
	// }

////////// GEEK FOR GEEKS

// // C program to demonstrate use of fork() and pipe()

// 	// We use two pipes
// 	// First pipe to send input string from parent
// 	// Second pipe to send concatenated string from child

// 	int fd1[2]; // Used to store two ends of first pipe
// 	int fd2[2]; // Used to store two ends of second pipe

// 	char fixed_str[] = "forgeeks.org";
// 	char input_str[100];
// 	pid_t p;

// 	if (pipe(fd1) == -1) {
// 		fprintf(stderr, "Pipe Failed");
// 		return 1;
// 	}
// 	if (pipe(fd2) == -1) {
// 		fprintf(stderr, "Pipe Failed");
// 		return 1;
// 	}

// 	scanf("%s", input_str);
// 	p = fork();

// 	if (p < 0) {
// 		fprintf(stderr, "fork Failed");
// 		return 1;
// 	}

// 	// Parent process
// 	else if (p > 0) {
// 		char concat_str[100];

// 		close(fd1[0]); // Close reading end of first pipe

// 		// Write input string and close writing end of first
// 		// pipe.
// 		write(fd1[1], input_str, strlen(input_str) + 1);
// 		close(fd1[1]);

// 		// Wait for child to send a string
// 		wait(NULL);

// 		close(fd2[1]); // Close writing end of second pipe

// 		// Read string from child, print it and close
// 		// reading end.
// 		read(fd2[0], concat_str, 100);
// 		printf("Concatenated string %s\n", concat_str);
// 		close(fd2[0]);
// 	}

// 	// child process
// 	else {
// 		close(fd1[1]); // Close writing end of first pipe

// 		// Read a string using first pipe
// 		char concat_str[100];
// 		read(fd1[0], concat_str, 100);

// 		// Concatenate a fixed string with it
// 		int k = strlen(concat_str);
// 		int i;
// 		for (i = 0; i < strlen(fixed_str); i++)
// 			concat_str[k++] = fixed_str[i];

// 		concat_str[k] = '\0'; // string ends with '\0'

// 		// Close both reading ends
// 		close(fd1[0]);
// 		close(fd2[0]);

// 		// Write concatenated string and close writing end
// 		write(fd2[1], concat_str, strlen(concat_str) + 1);
// 		close(fd2[1]);

// 		exit(0);
// 	}

////////// CODEQUOI

//	Fonction utilitaire pour écrire
// void	writestr(int fd, const char *str)
// {
// 	write(fd, str, strlen(str));
// }

// //	Main
// int	main(void)
// {
// 	int	pipefd[2];  // Stocke les fd du pipe :
// 			    //  - pipefd[0] : lecture seule
// 			    //  - pipefd[1] : écriture seule
// 	pid_t	pid;	// Stocke le retour de fork
// 	char	buf;	// Stocke la lecture de read

// //	Crée un pipe. En cas d'échec on arrête tout
// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// //	Crée un processus fils
// 	pid = fork();
// 	if (pid == -1) // Echec, on arrête tout
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid == 0) // Processus fils
// 	{
// 	//	Ferme le bout d'écriture inutilisé
// 		close(pipefd[1]);
// 		writestr(STDOUT_FILENO, "Fils : Quel est le secret dans ce pipe ?\n");
// 		writestr(STDOUT_FILENO, "Fils : \"");
// 	//	Lit les caractères dans le pipe un à un
// 		while (read(pipefd[0], &buf, 1) > 0)
// 		{
// 			// Écrit le caractère lu dans la sortie standard
// 			write(STDOUT_FILENO, &buf, 1);
// 		}
// 		writestr(STDOUT_FILENO, "\"\n");
// 		writestr(STDOUT_FILENO, "Fils : Ohlala ! Je vais voir mon pere.\n");
// 	//	Ferme le bout de lecture
// 		close(pipefd[0]);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else	// Processus père
// 	{
// 	//	Ferme le bout de lecture inutilisé
// 		close(pipefd[0]);
// 		writestr(STDOUT_FILENO, "Pere : J'ecris un secret dans le pipe...\n");
// 	//	Écrit dans le bout d'écriture du pipe
// 		writestr(pipefd[1], "\e[33mJe suis ton pere mwahahaha!\e[0m");
// 	//	Ferme le bout d'ecriture (lecteur verra EOF)
// 		close(pipefd[1]);
// 	//	Attend la terminaison du fils
// 		wait(NULL);
// 		writestr(STDOUT_FILENO, "Pere : Salut mon fils !\n");
// 		exit(EXIT_SUCCESS);
// 	}
// }

////////// REACTIVE

// int main()
// {
// 	int fd[2];
// 	pid_t pid;
// 	char buffer[13];
// 	if (pipe(fd) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (pid != 0)
// 	{
// 		close(fd[0]); // close the read end of the pipe
// 		write(fd[1], "Hello parent!", 13);
// 		close(fd[1]); // close the write end of the pipe
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		close(fd[1]); // close the write end of the pipe
// 		read(fd[0], buffer, 13);
// 		close(fd[0]); // close the read end of the pipe
// 		printf("Message from child: '%s'\n", buffer);
// 		exit(EXIT_SUCCESS);
// 	}
// }

////////// SINGAPORE

// int	main()
// {
// 	int		n;
// 	int		pipefd[2];
// 	char	buf[1025];
// 	char	*data;

// 	data = "hello... this is sample data";
// 	pipe(pipefd);
// 	printf("%d\n", pipefd[0]);
// 	printf("%d\n", pipefd[1]);
// 	write(pipefd[1], data, strlen(data));
// 	n = read(pipefd[0], buf, 1024);
// 	if (n >= 0)
// 	{
// 		buf[n] = 0;
// 		printf("read from the pipe: \"%s\"\n", buf);
// 	}
// 	return (0);
// }

//////////////////////////////////////// ACCESS

////////// REACTIVE

// int main()
// {
// 	if (access("example.txt", R_OK) != -1)
// 		printf("I have permission\n");
// 	else
// 		printf("I don't have permission\n");

// 	return (0);
// }

//////////////////////////////////////// EXECVE

////////// REACTIVE

// int main()
// {
// 	char *args[3];

// 	args[0] = "ls";
// 	args[1] = "-l";
// 	args[2] = NULL;
// 	execve("/bin/ls", args, NULL);
// 	printf("This line will not be executed.\n");
// 	return (0);
// }

////////// LANNUR

// int	main(void)
// {
// 	char	*const args[] = { "ls", NULL};
// 	char	*const envp[] = { NULL };

// 	printf("PID bef %d\n", getpid());
// 	execve("/usr/bin/ls", args, envp);
// 	perror("execve");
// 	printf("PID aft %d\n", getpid());
// 	return (1);
// }

// int	main(void)
// {
// 	char	*const args[] = { "ls", NULL};
// 	char	*const envp[] = { NULL };

// 	execve("/usr/bin/ls", args, envp);
// 	perror("execve");
// 	return (1);
// }

//////////////////////////////////////// UNLINK

////////// REACTIVE

// int main()
// {
// 	if (unlink("example.txt") == 0)
// 		printf("File successfully deleted");
// 	else
// 		printf("Error deleting file");
// 	return (0);
// }

//////////////////////////////////////// 2 CHILDREN FORK

////////// STACK OVERFLOW

// int main()
// {
// 	pid_t child1;
//     pid_t child2;
//     child1 = fork();

// if (child1 == 0) {
//     printf("child 1\n");
// } else {
//     child2 = fork();

//     if (child2 == 0) {
//         printf("child 2\n");
//     } else {
//         printf("parent\n");
//     }
// }
// }

////////// CHATGPT

// int main()
// {

// 	pid_t child1, child2;

// 	child1 = fork();
// 	if (child1 == 0)
// 	{
// 		printf("First child process (PID: %d)\n", getpid());
// 		return 0;
// 	}
// 	child2 = fork();
// 	if (child2 == 0)
// 	{
// 		printf("Second child process (PID: %d)\n", getpid());
// 		return 0;
// 	}
// 	wait(NULL);
// 	wait(NULL);
// 	printf("Parent process (PID: %d) exiting\n", getpid());
// 	return 0;
// }

////////// GEEKS FOR GEEKS

// int main() 
// { 
//     // Creating first child 
//     int n1 = fork(); 
//     // Creating second child. First child 
//     // also executes this line and creates 
//     // grandchild. 
//     int n2 = fork(); 
//     if (n1 > 0 && n2 > 0) { 
//         printf("parent\n"); 
//         printf("%d %d \n", n1, n2); 
//         printf(" my id is %d \n", getpid()); 
//     } 
//     else if (n1 == 0 && n2 > 0) 
//     { 
//         printf("First child\n"); 
//         printf("%d %d \n", n1, n2); 
//         printf("my id is %d  \n", getpid()); 
//     } 
//     else if (n1 > 0 && n2 == 0) 
//     { 
//         printf("Second child\n"); 
//         printf("%d %d \n", n1, n2); 
//         printf("my id is %d  \n", getpid()); 
//     } 
//     else { 
//         printf("third child\n"); 
//         printf("%d %d \n", n1, n2); 
//         printf(" my id is %d \n", getpid()); 
//     } 
//     return 0; 
// } 

////////// CS NOTES

// int main(void) 
// {
//     // int   end[2];
//     int   status;
//     pid_t child1;
//     pid_t child2;
//     // pipe(end);
//     child1 = fork();
//     // if (child1 < 0)
//     //      return (perror("Fork: "));
//     if (child1 == 0)
//         printf("First child\n");
//     child2 = fork();
//     // if (child2 < 0)
//     //      return (perror("Fork: "));
//     if (child2 == 0)
//          printf("Second child\n"); 
//     // close(end[0]);         // this is the parent
//     // close(end[1]);         // doing nothing
//     waitpid(child1, &status, 0);  // supervising the children
//     waitpid(child2, &status, 0);  // while they finish their tasks
// 	printf("parent\n"); 
// }

//////////////////////////////////////// FILE DESCRIPTOR

// #define BUFFER_SIZE 42

/* int	main()
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		readvalue1;
	int		readvalue2;
	int		readvalue3;
	char	*buffer1;
	char	*buffer2;
	char	*buffer3;

	buffer1 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer2 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buffer3 = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fd1 = open("fichier1w.txt", O_RDONLY);
	fd2 = open("fichier2.txt", O_RDONLY);
	fd3 = open("fichier3.txt", O_RDONLY);
	fd4 = open("fichier4.txt", O_RDWR);

	readvalue3 = read(0, buffer3, BUFFER_SIZE);
	readvalue1 = read(fd2, buffer1, BUFFER_SIZE);
	write(fd4, "hello", 5);
	write(fd4, "helhel", 6);
	write(fd4, "bonbon", 6);
	write(1, "hello\n", 6);
	readvalue2 = read(fd4, buffer2, BUFFER_SIZE);
	printf("fd %d\n", fd1);
	printf("fd %d\n", fd2);
	printf("fd %d\n", fd3);
	printf("read %d\n", readvalue1);
	printf("read %s\n", buffer1);
	printf("read %d\n", readvalue2);
	printf("read %s\n", buffer2);
	printf("read %d\n", readvalue3);
	printf("read %s\n", buffer3);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);

} */