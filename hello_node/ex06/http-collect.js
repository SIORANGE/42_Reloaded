/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http-collect.js                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 20:09:50 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/27 11:22:01 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

if (process.argv.length != 3)
	return

try{
	var http = require('http')
	var bl = require('bl')

	http.get(process.argv[2], (res) => {
		res.pipe(bl((err, s) => {
			if (err) return;
			let contests = s.toString()
			console.log(contests.length)
			console.log(contests)
		}))
	}).on('error',()=>{})
}catch(err){}
