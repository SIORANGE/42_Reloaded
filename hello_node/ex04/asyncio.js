/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asyncio.js                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:51:53 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/23 19:54:34 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

try {
	const fs = require('fs');
	var lines = 0;
	let text;
	fs.readFile(process.argv[2],"utf-8", (err, date) => {
		if (err) return;
		text = date;
		for (let i = 0; text[i]; ++i) {
			if (text[i] == '\n')
				lines++;
		}
		console.log(lines);
	});
} catch (err) {}
