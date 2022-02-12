# About

This is a collection of modules that I've released over the years. Most of them stand alone, or have just one or two dependencies in here, so you don't have to download this whole repo. You may find some ddoc here:http://arsdnet.net/ddoc/ or you can always ask me for help. http://dpldocs.info/


# Documentation

I know I'm pretty light on this. There's some ddocs but for the most part, I kinda expect you to use it the way I do: hoping things are logical and looking
at the source to fill in the gaps.

You can always catch me on email though: destructionator@gmail.com. That's
the most reliable way to reach me.


# Basic idea

Modules are usually independent; you don't need this whole directory
but it doesn't hurt to grab it all either.

I like to compile by just passing all the modules to the command line
at once. For example: dmd `yourapp.d` cgi.d. That's why I don't bother
with a separate arsd/ directory nor with dub packages. Passing the files
is faster to compile and easier to use!

Read more about the modules at these links (docs are still works in process):

`cgi.d` info: http://arsdnet.net/web.d/cgi.d.html

`web.d` info: http://arsdnet.net/web.d/web.d.html


# 64 Bit

Believe it or not, but I still mostly use 32 bit programs myself. I try
to keep things working on 64 bit, but don't always test it. If something
doesn't compile or work on 64 bit, email me and I'll see about fixing it.

I also tend to run a version behind bleeding-edge dmd, so sometimes things
break there too. Again, if that's a problem, just email me and I can typically
get you a fix in about an hour.

Currently included are:


# Web related

| Module | Description |
| --- | --- |
| `cgi.d` | base module for making webapps in D. Supports cgi, fastcgi, scgi, and embedded_httpd via -version=xxxx |
| `dom.d` | an xml/html DOM based on what Javascript provides in browsers |
| `web.d` | a fancier way to write web apps. Uses reflection to make functions accessible via url with minimal boilerplate in your code |
| `email.d` | gives read and write support for emails, sending via SMTP and reading mbox files |
| `web.d.php` | a PHP library meant to ease integration of php components with `web.d` apps. Gives (read) access to the session, and full access to your D ApiProviders. |
| `html.d` | functions to manipulate HTML documents, and now css and javascript with DOM functions, nested css statements, and macros for css and js. |
| `oauth.d` | Oauth 1.0 implementation with some helper functions for facebook, twitter, etc. |
| `htmltotext.d` | converts html into plain text |
| `rtud.d` | a real time update helper for HTML5 EventSource. Kinda buggy. |


# Database related

| Module | Description |
| --- | --- |
| `database.d` | main interface to databases. Includes DataObject |
| `mysql.d` | a mysql engine for `database.d` (most mature of the three). also includes some basic ORM |
| `postgres.d` | a postgres engne for database.d |
| `sqlite.d` | a sqlite engine for database.d |
| `mssql.d` | a (super crappy) mssql engine for `database.d` (uses ODBC) |
| `querygenerator.d` | a user submission for generating sql queries |


# Desktop app stuff

| Module | Description |
| --- | --- |
| `simpledisplay.d` | gives quick and easy access to a window for drawing and input. Also has some OpenGL capabilities. |
| `minigui.d` | a small widgetset built on top of `simpledisplay.d` offering buttons, checkboxes, etc. Almost done! |
| `terminal.d` | quick and easy access to a text mode console/terminal |
| `htmlwidget.d` | a very small html widget, built on simpledisplay.d |


# Game stuff

`engine.d`, `screen.d`, `audio.d` - a quick wrapper to SDL and OpenGL I used
in the pre D1 days, now updated so it compiles as both D1 and
D2 (use the -d switch to dmd)

Requires some SDL bindings.

Eventually I'll redo it.


# Reading Common Files

| Module | Description |
| --- | --- |
| `bmp.d` | basic .bmp file read/write support |
| `png.d` | provides some png read/write support |
| `jpg.d` | just reading jpg header right now |
| `csv.d` | gives read support to csv files |


# Cool stuff

| Module | Description |
| --- | --- |
| `jsvar.d` | gives a dynamic type in D similar to Javascript's var |
| `script.d` | a little script interpreter whose language is like a hybrid of D and Javascript (builds on jsvar.d) |


# Other

| Module | Description |
| --- | --- |
| `stb_truetype.d` | a port of the nice little C library `stb_truetype.h` to D for drawing text without external dependencies |
| `eventloop.d` | first draft of a generic event loop that can be reused by several libraries try it with `terminal.d` or `simpledisplay.d` with -version=with_eventloop. Only works on Linux right now. |
| `sha.d` | implementations of the SHA1 and SHA256 algorithms |
| `curl.d` | a small wrapper around the curl library |
| `http.d` | a lighterweight alternative to curl.d |
| `color.d` | a basic color struct and some HSL functions. Also includes really basic image classes on which `png.d`, `bmp.d`, and others depend, and now some quantization and dithering algorithms. |
| `characterencodings.d` | conversion to UTF8 of various encodings |


# Obsolete

| Module | Description |
| --- | --- |
| `image.d` | now merged into color.d |
| `lazypng.d` | now merged into png.d |
| `httpd.d` | old http server, use `cgi.d` with -version=embedded_httpd instead |
| `netman.d` | old network helper code, you should try `vibe.d` <http://vibed.org/> or maybe `cgi.d`'s threaded thing instead since this one is now unmaintained and poor in quality compared to vibe anyway. |
| `domconvenience.d` | now merged into dom.d |


Things I'll add when I get the time:

| Module | Description |
| --- | --- |
| `event.d` | reading Linux's /dev/event e.g. for second keyboards and usb joysticks |
| `browser.d` | a tiny browser based on htmlwidget.d |
| `wav.d` | reading and writing WAV files |
| `midi.d` | reading and writing MIDI files (I actually need to port it from C still!) |
| `simpleaudio.d` | gives minimal audio output |
| `minimal.zip` | a set of minimal D functions, works on bare metal. see: http://arsdnet.net/dcode/minimal.zip |


### Authors:

Thanks go to Nick Sabalausky, Trass3r, Stanislav Blinov, and maartenvd for input and patches.


# Newer writeup:

`audio.d`, `screen.d`, `engine.d` - my old game stuff, wrapping SDL, works in D1 and D2 (or at least did last time I tried it about a year ago). Soon to be replaced by the dependency-free `simpledisplay.d`, `simpleaudio.d`, `joystick.d` combo.

| Module | Description |
| --- | --- |
| `bmp.d`, `png.d` | read/write for bmp and image files. |
| `jpg.d` | partial read support for jpeg headers (just to get the size of the image). |
| `cgi.d` | basic module for making web apps. Includes cgi, fastcgi, scgi, and an embedded http server. Reads url encoded data, MIME data (for file uploads on the web), and has full URL parsing, among other things. |
| `characterencodings.d` | stuff for converting other strings to UTF-8. Supports about twenty other encodings based on webpage and email mining I've done in the past. Also has a lossy conversion as a catchall. |
| `color.d` | a color struct for RGBA, also does CSS color string read/writing, HSL <-> RGB, some color manipulation, alpha blending, and image base classes including palette to true color and true color to palette (quantization). |
| `csv.d` | simple csv reader, predates `std.csv` (and is a bit simpler) |
| `curl.d` | wrapper for libcurl (predates std.net.curl) |
| `database.d` | base class for RDBMS access. Also includes basic ORM and query builder in the form of DataObject and SelectBuilder. It is a simple, low-level wrapper of sql so you can manipulate it semantically more easily but you still need to understand sql to use it. (It also doesn't limit your options!) |
| `mysql.d`, `postgres.d`, `mssql.d`, `sqlite.d` | drivers for `database.d` (wrapping C libraries) |
| `dom.d` | XML and HTML parsing and manipulation, including CSS selectors and other tools that can help for implementing a browser. API inspired by modern Javascript DOM, capable of scraping tag soup web pages. |
| `email.d` | functions for reading and writing emails with MIME attachments, html and text versions, character sets. Can scrape mbox format, I used it to automatically monitor and reply to some email addresses sitting on the smtp server. |
| `english.d` | printing numbers in English |
| `eventloop.d` | an epoll based event loop for responding to and sending events. My other modules can optionally tie into it, so you can have one event loop driving files, networks, terminals, X windows, and more. |
| `html.d` | stuff for html and CSS manipulation. Includes the Css Macro Expander, which is similar to functionality offered by SASS (also available as a stand alone dub package on `code.dlang.org` btw), and a Javascript macro expander which you can use to add stuff like foreach to that language. Also has HTML sanitization based on a full parser and whitelist. |
| `htmltotext.d` | converts html to plain text so you can display it in a terminal or an email, etc. |
| `http.d` | my old standalone http client. Does NOT depend on curl. I'm in the process of replacing it with `http2.d`, which has a more flexible, asynchronous api (still dependency free, though I have to add OpenSSL and SChannel support for SSL soon). http2 provides an object that kinda works like a browser -it can understand relative links, maintain cookies, etc. |
| `joystick.d` | code for accessing XBox 360 controllers (and similar ones, like the PS1 controller via usb) on Windows and Linux. |
| `jsvar.d` | a var type similar to Javascript, usable in D. Can be used to read and write JSON with a natural syntax and other dynamic type tasks. |
| `mangle.d` | mangles a D name |
| `minigui.d` | small, dependency-free (except for `simpledisplay.d` and `color.d` but doesn't even need Phobos) widget set, using Win32 native widgets where possible, custom Xlib based ones otherwise. Still work in progress but already works for some basic forms. |
| `oauth.d` | OAuth library for client and server. I've used it with Twitter, Linked In, AWeber, Facebook, and more. Has specific functions for the Facebook Graph API, tweeting, serving oauth `1.0` requests, and doing the OAuth authorization flow. Depends on the mhash C library. |
| `querygenerator.d` | a user-contributed module for sql query generation |
| `rpc.d` | a remote procedure call library for D, making interfaces available across the network. You might prefer the apache thrift bindings or something, this is a custom job that I haven't seriously used. |
| `script.d` | a script interpeter based on jsvar.d. The script language is like a cross of D and Javascript. Made for API convenience - very very easy to embed in an application. |
| `sha.d` | implementation of SHA1 and SHA2 in pure D (well and some inline asm). |
| `simpleaudio.d` | access to WinMM on Windows and ALSA on Linux for waveform sound I/O and MIDI I/O. |
| `simpledisplay.d` | dependency-free base windowing library. Allows drawing, input, and other basic functionality. Also allows OpenGL access. |
| `sslsocket.d` | Uses OpenSSL to inherit from `std.socket.Socket` and give client SSL support. |
| `stb_truetype.d` | port of C library for writing ttf fonts to images. Has some convenience functions (but they aren't great, works, but not great) |
| `terminal.d` | I/O support for the text console. Does real time input, cellular output, getting lines with user editing, coloring, mouse input, and more. |
| `xwindows.d` | functions for working with X, beyond what `simpledisplay.d` offers. Stuff like interacting with the window manager, getting window icons, etc. I wrote it to support my D xlib taskbar. |
| `web.d` | wraps a D class in an HTTP api, with automatic url routing, view generation, argument conversion, and much more. Also includes a HTML templating system among other stuff that brings a lot of these modules together. |



There's a few other hidden gems in the files themselves, and so much more on my pipeline. Among the ones you might see added in the next month:

| Module | Description |
| --- | --- |
| `game.d` | helper functions for writing games (bringing together the display, audio, and joystick stuff). I have OpenGL texture stuff written now, almost done with the high level input api, and some math stuff that will probably be in there. |
| `model.d` | loading and displaying a 3d model format with open gl. |
| `midi.d`, `wav.d` | loading, saving, and working with midi and wav files |


(Yes, I'm writing a pair of D games again, finally! First time in a long time, but it is moving along well... and I don't need SDL this time!)
