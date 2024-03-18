# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmkhwana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 12:22:27 by tmkhwana          #+#    #+#              #
#    Updated: 2020/07/06 16:52:24 by tmkhwana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

FT_LS	=	ft_ls.a

LIBFT	=	libft/libft.a

CC = gcc

DOT_H = "./"

CFLAGS = -Wall -Wextra -Werror

SRC = 	collect_files.c print_error.c get_flags.c free_file_list.c\
		sort_file_list.c strcmp.c start_print.c print_pad.c collect_info.c\
		long_print.c print_folders.c free_info.c desc_file_sort.c asc_file_sort.c\
		f_time_sort.c valid_flags.c dir_files.c getMaxLen.c\
		start_f_print.c printTotal.c print_r_files.c m_size_sort.c m_time_sort.c f_size_sort.c\

OBJ = 	collect_files.o print_error.o get_flags.o free_file_list.o\
		sort_file_list.o strcmp.o start_print.o print_pad.o collect_info.o\
		long_print.o print_folders.o free_info.o desc_file_sort.o asc_file_sort.o\
		f_time_sort.o valid_flags.o dir_files.o getMaxLen.o\
		start_f_print.o printTotal.o print_r_files.o m_size_sort.o m_time_sort.o f_size_sort.o\



all : $(NAME)

$(NAME): $(FT_LS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) ./main.c -I$(DOT_H) $(FT_LS) $(LIBFT) 

$(FT_LS): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -c
	ar rc $(FT_LS) $(OBJ)
	ranlib $(FT_LS)

$(LIBFT):
	make -C libft

clean :
	make clean -C libft
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean : 
	make clean
	rm -f $(NAME) $(LIBFT) $(FT_LS)

re : fclean all
