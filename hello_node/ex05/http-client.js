/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http-client.js                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:17:45 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/27 11:22:10 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

if (process.argv.length != 3)
	return

try{
	require('http').get(process.argv[2], (res)=>{
		res.on('err',()=>{});
		res.setEncoding('utf8');
		res.on('data', (chunk) => {
			console.log(chunk);
		});
	}).on('error',()=>{});
}catch(err){}
