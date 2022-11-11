all: printf gnl

printf: tester1printf tester2printf

tester1printf: 
		$(MAKE) -C tester1 printf | grep "Manditory" | grep -e "type_s" -e "type_d" -e  "type_x"

tester2printf:
			./ft_printf/tester2/tester d x s
		

gnl:	tester1gnl tester2gnl tester3gnl

tester1gnl: 
		mv get_next_line/ getnextline/
		$(MAKE) -C tester1 gnl
		mv getnextline/ get_next_line/

tester2gnl:
			$(MAKE) -C ./get_next_line tester2
			$(MAKE) -C ./get_next_line/tester2 m

tester3gnl:
			$(MAKE) -C ./get_next_line tester3
			$(MAKE) -C ./get_next_line/tester3

.PHONY : all gnl printf tester1gnl tester2gnl tester3gnl tester1printf tester2printf