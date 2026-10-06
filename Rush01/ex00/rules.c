/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 11:48:48 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/04 13:00:00 by ahalawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// these come from checks.c
// cuz there were too many functions for norminette in this file
int	check_col_up(int grid[4][4], int col, int clue);
int	check_col_down(int grid[4][4], int col, int clue);
int	check_row_left(int grid[4][4], int row, int clue);
int	check_row_right(int grid[4][4], int row, int clue);
// Checks if the row and column already have a number
// since we aren't allowed to do one number twice

int	is_valid_placement(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

// Checks all views and returns 0 if any of them are forbidden
// Otherwise 1
int	check_all_views(int grid[4][4], int clues[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (check_col_up(grid, i, clues[i]) == 0)
			return (0);
		if (check_col_down(grid, i, clues[i + 4]) == 0)
			return (0);
		if (check_row_left(grid, i, clues[i + 8]) == 0)
			return (0);
		if (check_row_right(grid, i, clues[i + 12]) == 0)
			return (0);
		i++;
	}
	return (1);
}
