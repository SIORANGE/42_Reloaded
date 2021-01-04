/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time-server.js                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 07:58:05 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/27 11:22:43 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

if (process.argv.length != 3)
	return

const net = require('net');
require('date-utils');

try{
	var server = net.createServer((socket)=> {
		var current = new Date();
		socket.on('error',() =>{})
		socket.write(current.toFormat('YYYY-MM-DD HH24:MM') + '\n');
		socket.end();
	}).listen(parseInt(process.argv[2]));
	server.on('error',()=>{});
} catch (error){}
