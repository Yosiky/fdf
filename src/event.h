/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestelle <eestelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:03:54 by eestelle          #+#    #+#             */
/*   Updated: 2022/04/01 13:44:08 by eestelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# ifdef __linux__
#  define MOUSEWHEELIN	5
#  define MOUSEWHEELOUT	4
#  define KEY_ESC		65307
#  define NUM_UP		65431
#  define NUM_DOWN		65433
#  define NUM_LEFT		65430
#  define NUM_RIGHT		65432
#  define KEY_UP		65362
#  define KEY_DOWN		65364
#  define KEY_RIGHT		65363
#  define KEY_LEFT		65361
#  define W_BUTTON		119
#  define S_BUTTON		115
#  define D_BUTTON		100
#  define A_BUTTON		97
#  define P_BUTON		112
#  define I_BUTTON		105
#  define PLUS_BUTTON	61
#  define MINUS_BUTTON	45
#  define MOUSE_CORRECT	0
#  define OSX_KEY		1
# endif

# ifdef __APPLE__
#  define MOUSEWHEELIN	5
#  define MOUSEWHEELOUT	4
#  define KEY_ESC		53
#  define NUM_UP		91
#  define NUM_DOWN		84
#  define NUM_LEFT		86
#  define NUM_RIGHT		88
#  define KEY_UP		126
#  define KEY_DOWN		125
#  define KEY_LEFT		123
#  define KEY_RIGHT		124
#  define W_BUTTON		13
#  define S_BUTTON		1
#  define D_BUTTON		2
#  define A_BUTTON		0
#  define P_BUTON		35
#  define I_BUTTON		34
#  define PLUS_BUTTON	24
#  define MINUS_BUTTON	27
#  define MOUSE_CORRECT	1
#  define OSX_KEY		(-1)
# endif

#endif
