/*
** Oleg Kulikov <oakulikov@yandex.ru>, 2016
** Lua extensions library
*/



#include "xlib.h"

static int l_xsetmetatable (lua_State *L) {
    int t = lua_type(L, 2);
    luaL_argcheck(L, t == LUA_TNIL || t == LUA_TTABLE, 2,
                    "nil or table expected");
    if (luaL_getmetafield(L, 1, "__metatable"))
        return luaL_error(L, "cannot change a protected metatable");
    lua_settop(L, 2);
    lua_setmetatable(L, 1);
    return 1;
}

static const struct luaL_Reg xlib [] = {
    {"xsetmetatable", l_xsetmetatable},
    {NULL, NULL}
};

int luaopen_xlib (lua_State *L) {
    luaL_newlib(L, xlib);
    return 1;
}
