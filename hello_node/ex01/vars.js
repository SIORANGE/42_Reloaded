/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.js                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:51:44 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/26 10:29:22 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const vars = ['42', 42, new Object(42), {}, '42' == 42, void '42'];

console.log(`${vars[0]} is a ${typeof(vars[0])}.`);
console.log(`${vars[1]} is a ${typeof(vars[1])}.`);
console.log(`${vars[2]} is an ${typeof(vars[2])}.`);
console.log(`${vars[3]} is an ${typeof(vars[3])}.`);
console.log(`${vars[4]} is a ${typeof(vars[4])}.`);
console.log(`${vars[5]} is an ${typeof(vars[5])}.`);
