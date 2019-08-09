/*
** EPITECH PROJECT, 2018
** init
** File description:
** init
*/

#include "../../include/struct.h"

t_input	*input_init(t_input *input)
{
	input->up = 0;
	input->left = 0;
	input->down = 0;
	input->right = 0;
	input->entrer = 0;
	input->escape = 0;
	input->space = 0;
	return (input);
}