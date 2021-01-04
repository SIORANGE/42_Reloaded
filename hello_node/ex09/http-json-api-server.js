/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http-json-api-server.js                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktakesat <ktakesat@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 17:46:22 by ktakesat          #+#    #+#             */
/*   Updated: 2020/12/27 11:47:32 by ktakesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

if (process.argv.length != 3)
	return

const http = require('http');
const url = require('url');

try{
	const server = http.createServer((req, res) =>{

		try{
			const parsed = url.parse(req.url, true);
			var time = parsed.query['iso'];

			const date = new Date(time)
			if(isNaN(date)){
				res.end();
				return;
			}
			if(parsed.pathname == '/api/parsetime'){
				res.writeHead(200, {'Content-Type': 'application/json'});
				res.write(JSON.stringify({
					"hour":date.getUTCHours(),
					"minute":date.getUTCMinutes(),
					"second":date.getUTCSeconds()
				})+'\n')
			} else if (parsed.pathname == '/api/unixtime'){
				res.writeHead(200, {'Content-Type': 'application/json'});
				res.write(JSON.stringify({
					"unixtime":require('unix-timestamp').fromDate(date) * 1000
				})+'\n')
			} else return;
			res.end()
		}catch (error){ throw error}
	}).listen(parseInt(process.argv[2]))
	server.on('error',()=>{});
}catch (error){}