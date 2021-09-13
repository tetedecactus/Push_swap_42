/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olabrecq <olabrecq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:49:57 by olabrecq          #+#    #+#             */
/*   Updated: 2021/09/08 16:28:13 by olabrecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_stack_node
{
    int                 data;
    struct s_stack_node *prev;
    struct s_stack_node *next;
}   t_stack_node;

typedef struct s_stack
{
    t_stack_node        *head;
    t_stack_node        *tail;
    int                 size;
}   t_stack;


void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(fd, &s[i++], 1);
}

int	ft_atoi(const char *str)
{
	long			num;
	int				i;
	int				sign;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num * sign > 2147483647)
			return (-1);
		if (num * sign < -2147483648)
			return (0);
	}
	return ((long)(sign * num));
}

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9' || c == '-'));
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void       ft_putnbr(int nb)
{
    unsigned int nombre;

    if (nb < 0)
    {
        ft_putchar('-');
        nombre = -nb;
    }
    else
        nombre = nb;
    if (nombre > 9)
    {
        ft_putnbr(nombre / 10);
        nombre %= 10;
    }
    ft_putchar(nombre + '0');
}

void    error_message()
{
    ft_putstr_fd("Error\n", 2);
    exit(EXIT_FAILURE);
}

int	ft_num_of_lines(char const *s1, char c)
{
	int	lines;
	int	comp;

	lines = 0;
	comp = 0;
	if (!*s1)
		return (0);
	while (*s1)
	{
		if (*s1 == c)
			comp = 0;
		else if (comp == 0)
		{
			comp = 1;
			lines++;
		}
		s1++;
	}
	return (lines);
}

int	ft_num_of_chars(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i])
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char	**ft_array(char const *s, char **dst, char c, int l)
{
	int	i;
	int	y;
	int	k;

	i = 0;
	y = 0;
	while (s[i] && y < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		dst[y] = malloc(sizeof(char) * ft_num_of_chars(s, c, i) + 1);
		if (!dst[y])
			return (NULL);
		while (s[i] && s[i] != c)
			dst[y][k++] = s[i++];
		dst[y][k] = '\0';
		y++;
	}
	dst[y] = 0;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	int		n;

	if (s == NULL)
		return (NULL);
	n = ft_num_of_lines(s, c);
	dst = (char **)malloc(sizeof(char *) * (n + 1));
	if (!dst)
		return (NULL);
	return (ft_array(s, dst, c, n));
}

void	free_argv(char *argv[])
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}

int stack_size_calculator(int argc, char *argv[])
{
    int i;

    i = 0;
    if (argc > 2)
        i = argc - 1;
    while (argv[i])
        i++;
    return (i);    
}

int if_digit_duplicate(char *argv[], int stack_size)
{
    int i;
    int j;
    int stack_array;

    i = 0;
    while(i < stack_size)
    {
        j = i + 1;
        stack_array = ft_atoi(argv[i]);
        while (j < stack_size)
        {
            if(stack_array == ft_atoi(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int if_array_is_digit(char **argv, int stack_size)
{
    int i;
    int j;

    i = 0;
    while (i < stack_size)
    {
        j = 0;
        while (argv[i][j])
        { 
            if (!ft_isdigit(argv[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
 
void if_valid_args(char *argv[], int stack_size)
{
    if (if_digit_duplicate(argv, stack_size) || if_array_is_digit(argv, stack_size))
        error_message();
}

t_stack_node	*find_last_node(t_stack_node *node)
{
	while (node)
	{
		if (node->next == NULL)
			return (node);
		node = node->next;
	}
	return (node);
}

void  insert_end(t_stack_node **head, t_stack_node *new_head)
{
    t_stack_node *node;
    
    if (head != NULL)
    {
        if (*head != NULL)
        {
            node = find_last_node(*head);
            node->next = new_head;
            new_head->prev = node;
        }
        else
            *head = new_head;
    }
}

// ft_lstnew de la libft up grape pour double linked list
t_stack_node *new_node_init(int data)
{
    t_stack_node *new_node;

    new_node = malloc(sizeof(t_stack_node));
    if (new_node == NULL)
        return (NULL);
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return (new_node);
}

void deallocate(t_stack **tail, t_stack **head)
{
    if (*tail == NULL)
        return;
    t_stack *curr = *tail;
    while (curr->head->next != NULL)
    {
        curr->head = curr->head->next;
        free(curr->head->prev);
    }
    free(curr);
    
    *tail = NULL;
    *head = NULL;
}

int *create_array(char *argv[], int stack_size)
{
    int i;
    int *array_a;
    
    array_a = malloc(sizeof(char) * stack_size - 1);

    i = 0;
    while (i < stack_size)
    {
        array_a[i] = ft_atoi(argv[i]);
        i++;
    }
    return (array_a);
}  

void print_array(int *arr, int stack_size)
{
    int i;

    i = 0;
    while(i < stack_size)
    {
        ft_putnbr(arr[i]);
        ft_putchar(',');
        i++;
    }
    //free(arr);
    ft_putchar('\n');
} 

t_stack *init_stack(int argc, char *argv[])
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = stack_size_calculator(argc, argv);
    return (stack);
}

t_stack *create_stack(int stack_size, char *argv[], t_stack *stack)
{
    int i;
    
    i = 0;
    while (i < stack_size)
    {
        insert_end(&stack->head, new_node_init(ft_atoi(argv[i])));
        i++;
    }
    stack->tail = stack->head;
    while (stack->tail->next != NULL)
    {
        stack->tail = stack->tail->next;
    }
    return (stack);
}

void    print_stack(t_stack *stack)
{
    t_stack_node *temp;
    temp = stack->head;
    ft_putstr_fd("stack = ", 1);
    while (temp->next != NULL)
    {
        ft_putnbr((long )temp->data);
        ft_putchar(',');
        temp = temp->next;
    }
    ft_putnbr((long )temp->data);
    ft_putchar(',');
    ft_putchar('\n');
 
} 

void swap(t_stack_node *head)
{
    if (head == NULL || head->next == NULL)
        return ; 
    int temp;

    temp = head->data;
    head->data = head->next->data;
    head->next->data = temp;
}

void rotate(t_stack *stack_data)
{
    if (stack_data->size < 2)
         return ;
    t_stack_node    *next_head;
        
    next_head = stack_data->head->next;
    // shift head to bottom 
    stack_data->tail->next = stack_data->head;
    stack_data->head->prev = stack_data->tail;
    stack_data->head->next = NULL;
    stack_data->tail = stack_data->head;
    //make top_next as new head 
    stack_data->head = next_head;
    stack_data->head->prev = NULL; 
}

void r_rotate(t_stack *stack_data)
{
    if (stack_data->size < 2)
         return ;
    t_stack_node    *next_tail;
        
    next_tail = stack_data->tail->prev;
    // shift tail to head
    stack_data->head->prev = stack_data->tail;
    stack_data->tail->next = stack_data->head;
    stack_data->head->prev = NULL;
    stack_data->head = stack_data->tail;
    // make tail_next as new tail
    stack_data->tail = next_tail;
    stack_data->tail->next = NULL; 
}

void push(t_stack *stack_a, t_stack *stack_b)
{
    t_stack_node *futur_head;
    
    if (stack_a->head == NULL)
        return ; 
    futur_head = stack_a->head;
    stack_a->head =  stack_a->head->next;
    if (stack_a->head != NULL)
        stack_a->head->prev = NULL;
    futur_head->next = NULL;
    if (stack_b->head != NULL)
    {
        stack_b->head->prev = futur_head;
        futur_head->next = stack_b->head;
    }
    stack_b->head = futur_head;

}

int main(int argc, char *argv[])
{
    int free_me;
    int *arr;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_b =  malloc(sizeof(t_stack));
    free_me = 0;
    argv++;
    if (argc < 2)
        error_message();
    if (argc == 2)
    {
        argv = ft_split(argv[0], ' ');
        free_me++;
    }
    stack_a = init_stack(argc, argv);
    stack_b->head = NULL;
    //stack_a->size = stack_size_calculator(argc, argv);
    printf("stack size = %d\n", stack_a->size);
    //valid arg
    if_valid_args(argv, stack_a->size);
    //create n print array
    ft_putstr_fd("array = ", 1);
    arr = create_array(argv, stack_a->size);
    print_array(arr, stack_a->size);
    //create n print stack a & b
    stack_a = create_stack(stack_a->size, argv, stack_a);
    print_stack(stack_a);
    
    swap(stack_a->head);
    print_stack(stack_a);
    
    rotate(stack_a);
    print_stack(stack_a);
    
    r_rotate(stack_a);
    print_stack(stack_a);

    push(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);
    push(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);
    push(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);
    if (free_me)
    {
        free_argv(argv);
        printf("free\n");
    }
    //deallocate(&stack_a, &stack_b);
    printf("fin\n");
}