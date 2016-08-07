# xlib
xlib is a Lua extensions library

## usage example
create a shared library, e.g.:
```
$ gcc -dynamiclib -o xlib.so xlib.c -llua
```
then in Lua:
```
xlib = require("xlib")
xlib.xsetmetatable(nil, {__index=function(t,k) return nil end})
t = {}
print(t[1][2][3])
```

## list of available functions:
* xsetmetatable - allows to set metatables for values of any type
please, note: for tables and userdata we set metatable for each object
individually, for other types the metatable for whole type
