/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:26:58 by maherr            #+#    #+#             */
/*   Updated: 2026/10/04 13:00:00 by ahalawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc and free
#include <unistd.h> //write

void	print_grid(int grid[4][4]);
void	zero_grid(int grid[4][4]);
int		parse_input(char *str, int clues[16]);
int		solve(int grid[4][4], int clues[16], int pos);

// Before:
//left to right, 0, 1, 2, 3 first row, 4, 5, 6, 7 second row,
//cells array	 8, 9, 10, 11 third row, 12, 13, 14, 15 fourth row
// Now:
// grid[row][cell], much easier to remember
int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	clues[16];

	zero_grid(grid);
	if (argc == 2)
	{
		if (parse_input(argv[1], clues) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (solve(grid, clues, 0))
		{
			print_grid(grid);
		}
		else
		{
			write(1, "Error\n", 6);
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
