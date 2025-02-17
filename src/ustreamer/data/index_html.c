/*****************************************************************************
#                                                                            #
#    uStreamer - Lightweight and fast MJPEG-HTTP streamer.                   #
#                                                                            #
#    Copyright (C) 2018-2022  Maxim Devaev <mdevaev@gmail.com>               #
#                                                                            #
#    This program is free software: you can redistribute it and/or modify    #
#    it under the terms of the GNU General Public License as published by    #
#    the Free Software Foundation, either version 3 of the License, or       #
#    (at your option) any later version.                                     #
#                                                                            #
#    This program is distributed in the hope that it will be useful,         #
#    but WITHOUT ANY WARRANTY; without even the implied warranty of          #
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           #
#    GNU General Public License for more details.                            #
#                                                                            #
#    You should have received a copy of the GNU General Public License       #
#    along with this program.  If not, see <https://www.gnu.org/licenses/>.  #
#                                                                            #
*****************************************************************************/

#include "index_html.h"


const char *const US_HTML_INDEX_PAGE = " \
	<!DOCTYPE html> \
	\
	<html> \
	<head> \
		<meta charset=\"utf-8\" /> \
		<title>uStreamer</title> \
		<style>body {font-family: monospace;}</style> \
	</head> \
	\
	<body> \
		<h3>&micro;Streamer v" US_VERSION "</h3> \
		<hr> \
		<ul> \
			<li> \
				<a href=\"state\"><b>/state</b></a><br> \
				Get JSON structure with the state of the server. \
			</li> \
			<br> \
			<li> \
				<a href=\"snapshot\"><b>/snapshot</b></a><br> \
				Get a current actual image from the server. \
			</li> \
			<br> \
			<li> \
				<a href=\"stream\"><b>/stream</b></a><br> \
				Get a live stream. Query params:<br> \
				<br> \
				<ul> \
					<li> \
						<b>key=abc123</b><br> \
						The user-defined key, which is part of cookie <i>stream_client</i>, which allows<br> \
						the stream client to determine its identifier and view statistics using <a href=\"state\">/state</a>. \
					</li> \
					<br> \
					<li> \
						<b>extra_headers=1</b><br> \
						Add <i>X-UStreamer-*</i> headers to the <a href=\"stream\">/stream</a> handle \
						(like with the <a href=\"snapshot\">/snapshot</a>). \
					</li> \
					<br> \
					<li> \
						<b>advance_headers=1</b><br> \
						Enable workaround for the Chromium/Blink bug \
						<a href=\"https://bugs.chromium.org/p/chromium/issues/detail?id=527446\">#527446</a>. \
					</li> \
					<br> \
					<li> \
						<b>dual_final_frames=1</b><br> \
						Enable workaround for the Safari/WebKit bug when using option <i>--drop-same-frames</i>.<br> \
						Without this option, when the frame series is completed, WebKit-based browsers<br> \
						renders the last frame with a delay. \
					</li> \
					<br> \
					<li> \
						<b>zero_data=1</b><br> \
						Disables the actual sending of JPEG data and leaves only response headers. \
					</li> \
				</ul> \
			</li> \
			<br> \
			<li> \
				The mjpg-streamer compatibility layer:<br> \
				<br> \
				<ul> \
					<li><a href=\"?action=snapshot\">/?action=snapshot</a> as alias to the <a href=\"snapshot\">/snapshot</a>.</li> \
					<br> \
					<li><a href=\"?action=stream\">/?action=stream</a> as alias to the <a href=\"stream\">/stream</a>.</li> \
				</ul> \
			</li> \
		</ul> \
		<br> \
		<hr> \
		<a href=\"https://github.com/pikvm/ustreamer\">Sources &amp; docs</a> \
	</body> \
	</html> \
";
