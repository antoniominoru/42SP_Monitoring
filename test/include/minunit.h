/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aminoru- <aminoru-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:18:23 by aminoru-          #+#    #+#             */
/*   Updated: 2022/07/31 18:12:54 by aminoru-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINUNIT_H
# define MINUNIT_H

/* file: minunit.h */
# define mu_assert(message, test) do { if (!(test)) return message; } while (0)
# define mu_run_test(test) do { char *message = test(); g_tests_run++; if (message) return message; } while (0)
extern int g_tests_run;

 #endif