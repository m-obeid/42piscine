/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 12:18:29 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/04 13:00:00 by ahalawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_placement(int grid[4][4], int row, int col, int num);
int	check_all_views(int grid[4][4], int clues[16]);
int	solve(int grid[4][4], int clues[16], int pos);

int	try_number(int grid[4][4], int clues[16], int pos, int num)
{
	int	row;
	int	col;

	row = pos / 4;
	col = pos % 4;
	if (is_valid_placement(grid, row, col, num))
	{
		grid[row][col] = num;
		if (pos == 15)
		{
			if (check_all_views(grid, clues))
				return (1);
		}
		else if (solve(grid, clues, pos + 1))
			return (1);
		grid[row][col] = 0;
	}
	return (0);
}

int	solve(int grid[4][4], int clues[16], int pos)
{
	int	num;

	if (pos == 16)
		return (1);
	num = 1;
	while (num <= 4)
	{
		if (try_number(grid, clues, pos, num))
			return (1);
		num++;
	}
	return (0);
}
