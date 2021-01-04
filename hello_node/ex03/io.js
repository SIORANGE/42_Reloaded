/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.js                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:51:50 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/25 03:13:56 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


const fs = require('fs');
try {
	let text = fs.readFileSync(process.argv[2]).toString();
	var lines = 0;
	for (let i = 0; text[i]; ++i) {
		if (text[i] == '\n')
			lines++;
	}
	console.log(lines);
} catch (error) {}