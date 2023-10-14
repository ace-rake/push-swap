/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:19:24 by vdenisse          #+#    #+#             */
/*   Updated: 2023/10/14 13:05:50 by vdenisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_action_nbr(char *str)
{
	if (ft_strncmp(str, "ra\n", 3) == 0)
		return (11);
	if (ft_strncmp(str, "rb\n", 3) == 0)
		return (21);
	if (ft_strncmp(str, "rr\n", 3) == 0)
		return (31);
	if (ft_strncmp(str, "rra\n", 4) == 0)
		return (12);
	if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (22);
	if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (32);
	if (ft_strncmp(str, "pa\n", 3) == 0)
		return (13);
	if (ft_strncmp(str, "pb\n", 3) == 0)
		return (23);
	if (ft_strncmp(str, "sa\n", 3) == 0)
		return (14);
	if (ft_strncmp(str, "sb\n", 3) == 0)
		return (24);
	if (ft_strncmp(str, "ss\n", 3) == 0)
		return (34);
	return (-1);
}
#include <stdio.h>
int	ft_read_actions(t_list **actions)
{
	char	*next_line;
	int	action;

	next_line = get_next_line(STDIN_FILENO, 0);	
	while (next_line != NULL)
	{
		action = get_action_nbr(next_line); 
		if (get_macro_name(action) == NULL)
			return (1);
		ft_lstadd_back(actions, ft_lstnew(action));
		free(next_line);
		next_line = get_next_line(STDIN_FILENO, 0);
	}
	return (0);
}

void	ft_exec_action_2(int action, t_stack *stack_a[], t_stack *stack_b[])
{
	if (action == PA)
		push(stack_b, stack_a);
	if (action == PB)
		push(stack_a, stack_b);
	if (action == SA)
		swap(stack_a);
	if (action == SB)
		swap(stack_b);
	if (action == SS)
	{
		swap(stack_a);
		swap(stack_b);
	}
}

void	ft_exec_action(int action, t_stack *stack_a[], t_stack *stack_b[])
{
	if (action == RA)
		rotate(stack_a);
	if (action == RB)
		rotate(stack_b);
	if (action == RR)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (action == RRA)
		rrotate(stack_a);
	if (action == RRB)
		rrotate(stack_b);
	if (action == RRR)
	{
		rrotate(stack_a);
		rrotate(stack_b);
	}
	ft_exec_action_2(action, stack_a, stack_b);
}

int	ft_exec_all(t_stack *stack_a[], t_stack *stack_b[], t_list actions[])
{
	int	amount;
	int	iter;
	

	iter = 0;
	amount = ft_lstsize(actions);
	while (iter < amount)
	{
		ft_exec_action(actions->content, stack_a, stack_b);
	}
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_list *actions;

	stack_a = ft_init(argc - 1, argv);
	if (error_check(argc - 1, stack_a, argv))
		return (1);
	stack_b = ft_init_empty(argc - 1);
	actions = NULL;
	if (ft_read_actions(&actions) == 0)
		ft_exec_all(&stack_a, &stack_b, actions);
	if (is_done(&stack_a) && stack_b[0].active == 0)
		write(1, "OK\n", 3);
	else
		write(1, "Error\n", 6);
	free(stack_a);
	free(stack_b);
	ft_lstclear(&actions);
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_ACTION_LENGTH 3 // Adjust this as needed

char** readActions(int* numActions) 
{
    char** actions = NULL;
    *numActions = 0;

    char action[MAX_ACTION_LENGTH];
    ssize_t bytesRead;

    while ((bytesRead = read(STDIN_FILENO, action, MAX_ACTION_LENGTH)) > 0) {
        if (action[bytesRead - 1] == '\n') {
            action[bytesRead - 1] = '\0';
            bytesRead--;
        }

        actions = (char**)realloc(actions, (*numActions + 1) * sizeof(char*));
        actions[*numActions] = (char*)malloc(bytesRead);
        if (actions[*numActions] == NULL) {
            perror("Memory allocation error");
            exit(1);
        }
        strcpy(actions[*numActions], action);

        (*numActions)++;
    }

    return actions;
}

int main() {
    int numActions;
    char** actionArray = readActions(&numActions);

    if (actionArray != NULL) {
        for (int i = 0; i < numActions; i++) {
            printf("Action %d: %s\n", i, actionArray[i]);
            free(actionArray[i]); // Free each action
        }
        free(actionArray); // Free the array of actions
    }

    return 0;
}

