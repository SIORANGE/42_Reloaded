/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   async-http-collect.js                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 05:04:56 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/26 11:11:57 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

if (process.argv.length != 5)
	return

try{
	function collecter(arg){
		return new Promise((resolve, reject)=>{
			var http = require('http')
			var bl = require('bl')

			http.get(arg, (res) => {
				res.pipe(bl((err, s) => {
					if (err) reject(err);
					let contests = s.toString()
					console.log(contests)
					resolve();
				}))
			}).on('error',()=>{})
		})
	}

	collecter(process.argv[2])
		.then(() => {
			return collecter(process.argv[3]);
		})
		.then(() => {
			return collecter(process.argv[4]);
		})
		.catch(()=>{})
}catch(err){}
