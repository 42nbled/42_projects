#include "ft_nm.h"

static int state = 0;

static t_files	*arg_check(t_flags *flags, int argc, char **argv) {
	t_files	*files = NULL;

	for (int i = 1; i < argc; i++) {
		if (argv[i][0] && argv[i][0] == '-') {
			for (int y = 1; argv[i][y]; y++) {
				if (argv[i][y] == 'a')
					flags->a = 1;
				else if (argv[i][y] == 'g')
					flags->g = 1;
				else if (argv[i][y] == 'u')
					flags->u = 1;
				else if (argv[i][y] == 'r')
					flags->r = 1;
				else if (argv[i][y] == 'p')
					flags->p = 1;
				else
					return (state = 2, NULL);
			}
		}
		else {
			if (!files) {
				if (!(files = malloc(sizeof(t_files))))
					return NULL;
				files->name = argv[i];
				files->next = NULL;
			}
			else {
				t_files *tmp = files;
				while (tmp->next)
					tmp = tmp->next;
				if (!(tmp->next = malloc(sizeof(t_files))))
					return (state = 1, files);
				tmp->next->name = argv[i];
				tmp->next->next = NULL;
			}
		}
	}
	if (!files) {
		if (!(files = malloc(sizeof(t_files))))
			return NULL;
		files->name = "a.out";
		files->next = NULL;
	}
	return files;
}


static void	main_32(int fd, t_flags flags, char *executable_name) {
	t_fileinfo32	file_header;
	t_lst			name_tables = {.next=NULL, .data=NULL};

	read(fd, &file_header, sizeof(t_fileinfo32));
	for (int i=0; i < file_header.e_shnum; i++) {
		if (run_32(fd, file_header, &name_tables)) {
			state = 1;
			return ;
		}
	}

	run_32(fd, file_header, &name_tables);
	close(fd);
	if (name_tables.next)
		print_nm32(name_tables, flags, executable_name);
	else
		state = 1;
}

static void	main_64(int fd, t_flags flags, char *executable_name) {
	t_fileinfo64	file_header;
	t_lst			name_tables = {.next=NULL, .data=NULL};

	read(fd, &file_header, sizeof(t_fileinfo64));
	for (int i=0; i < file_header.e_shnum; i++) {
		if (run_64(fd, file_header, &name_tables)) {
				state = 1;
				return ;
			}
	}

	run_64(fd, file_header, &name_tables);
	close(fd);
	if (name_tables.next)
		print_nm64(name_tables, flags, executable_name);
	else
		state = 1;
}

void	clean_files(t_files *files)
{
	while (files) {
		t_files *temp = files;
		files = files->next;
		free(temp);
	}
}

int main(int argc, char **argv) {
	int				fd;
	t_eident		identifiers;
	t_flags			flags = {0};
	t_files			*files;

	if (argc == 1)
		return (printf("Usage: %s [-agurp] [file]\n", argv[0]), 1);

	if (!(files = arg_check(&flags, argc, argv)) || state) {
		if (state == 2)
			return (printf("Usage: %s [-agurp] [file]\n", argv[0]), 1);

		if (state)
			clean_files(files);

		printf("Memory error\n");
		return 1;
	}
	int nfiles = 0;
	for (t_files *tmp = files; tmp; tmp = tmp->next)
		nfiles++;
	t_files *cursor = files;
	while (cursor) {
		if ((fd = open(cursor->name, O_RDONLY)) < 0)
			return (fprintf(stderr, "Error while opening the file \'%s\'.", cursor->name), 1);

		if (nfiles != 1)
			printf("%s:\n", cursor->name);
		read(fd, &identifiers, sizeof(identifiers));

		if (identifiers.EI_CLASS == 1)
			main_32(fd, flags, cursor->name);
		else
			main_64(fd, flags, cursor->name);

		if (state)
			break ;
		t_files *temp = cursor;
		cursor = cursor->next;
		free(temp);
	}


	return (0);
}
