# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wta <wta@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/28 20:09:26 by wta               #+#    #+#              #
#    Updated: 2019/03/20 19:55:55 by williamta        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#=======================================================================  COLOR#
_GREEN		=	\033[0;32m
_WHITE		=	\033[m
_YELLOW		=	\033[0;33m
_DYELLOW	=	\x1b[33;01m
#==================================================================== VARIABLES#
NAME		=	libft.a
SRCSDIR		=	srcs
LIBFT		=	$(addprefix $(SRCSDIR)/,libft)
FT_PRINTF	=	$(addprefix $(SRCSDIR)/,ft_printf)
LIBFT_H		=	libft.h
FT_PRINTF_H	=	ft_printf.h
INCDIR		=	includes
OBJDIR		=	objs
OBJLIBFT	=	$(addprefix $(OBJDIR)/,$(SRCSLIBFT:.c=.o))
OBJPRINTF	=	$(addprefix $(OBJDIR)/,$(SRCSPRINTF:.c=.o))
CC			=	gcc 
INC			=	-I $(INCDIR)
CFLAGS		=	-Wall -Wextra -Werror
SRCSLIBFT		=															\
ft_atoi.c              ft_memmove.c           ft_strjoinfree.c				\
ft_bzero.c             ft_memset.c            ft_strlcat.c					\
ft_delnode.c           ft_pushback.c          ft_strlen.c					\
ft_intlen_base.c       ft_pushfront.c         ft_strmap.c					\
ft_isalnum.c           ft_putchar.c           ft_strmapi.c					\
ft_isalpha.c           ft_putchar_fd.c        ft_strncat.c					\
ft_isascii.c           ft_putendl.c           ft_strncmp.c					\
ft_isdigit.c           ft_putendl_fd.c        ft_strncpy.c					\
ft_isprint.c           ft_putnbr.c            ft_strndup.c					\
ft_itoa.c              ft_putnbr_fd.c         ft_strndupfree.c				\
ft_listdel.c           ft_putstr.c            ft_strnequ.c					\
ft_lstadd.c            ft_putstr_fd.c         ft_strnew.c					\
ft_lstappend.c         ft_strcat.c            ft_strnstr.c					\
ft_lstdel.c            ft_strchr.c            ft_strrchr.c					\
ft_lstdelone.c         ft_strclr.c            ft_strsplit.c					\
ft_lstiter.c           ft_strcmp.c            ft_strstr.c					\
ft_lstmap.c            ft_strcpy.c            ft_strsub.c					\
ft_lstnew.c            ft_strdel.c            ft_strtrim.c					\
ft_lstnew_mallocfree.c ft_strdup.c            ft_tolower.c					\
ft_memalloc.c          ft_strdupdel.c         ft_toupper.c					\
ft_memccpy.c           ft_strequ.c            ft_wdcpy.c					\
ft_memchr.c            ft_striter.c           ft_word_count.c				\
ft_memcmp.c            ft_striteri.c          ft_word_len.c					\
ft_memcpy.c            ft_strjoin.c											\
ft_memdel.c            ft_strjoindel.c		  get_next_line.c
SRCSPRINTF	=																\
ft_convert.c     ft_convert_hex.c ft_convert_s.c   ft_printf.c				\
ft_convert_c.c   ft_convert_o.c   ft_convert_u.c   ft_utils.c				\
ft_convert_d.c   ft_convert_p.c   ft_lst_pf.c      ft_utils2.c				\
ft_convert_f.c   ft_convert_per.c ft_parse_pf.c
#======================================================================# RULES #
all : $(NAME)
#=======================================================================# NAME #
$(NAME) : $(OBJLIBFT) $(OBJPRINTF) $(addprefix $(INCDIR)/,$(HEADER))
	@ar -rcs $(NAME) $(OBJLIBFT) $(OBJPRINTF)
	@echo "$(_GREEN)[CREATED]$(_WHITE)" $@
	@echo "Flags: $(CFLAGS)"
	@echo "All objects files are in $(_DYELLOW)obj$(_WHITE)/"
#===================================================================# MKDIROBJ #
$(OBJDIR) :
	@mkdir $@
	@echo "$(_YELLOW)[CREATED]$(_WHITE)" $@
#==================================================================# FT_PRINTF #
$(addprefix $(OBJDIR)/,%.o) : $(addprefix $(FT_PRINTF)/,%.c) | $(OBJDIR) ./includes/ft_printf.h
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 
	@echo "$(_GREEN)[OK]$(_WHITE) $@"
#======================================================================# LIBFT #
$(addprefix $(OBJDIR)/,%.o) : $(addprefix $(LIBFT)/,%.c) | $(OBJDIR) ./includes/libft.h
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< 
	@echo "$(_GREEN)[OK]$(_WHITE) $@"
#======================================================================# CLEAN #
clean :
	@/bin/rm -f $(OBJ)
	@echo "$(_DYELLOW)[DELETED]$(_WHITE)" $(OBJLIBFT) $(OBJPRINTF)
	@/bin/rm -rf $(OBJDIR)
	@echo "$(_DYELLOW)[DELETED]$(_WHITE)" $(OBJDIR)/
#=====================================================================# FCLEAN #
fclean : clean
	@/bin/rm -f	$(NAME)
	@echo "$(_DYELLOW)[DELETED]$(_WHITE)" $(NAME)
#=========================================================================# RE #
re : fclean all
#==============================================================================#
