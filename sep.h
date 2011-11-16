/*******************
**   h
** g   d
**   b
**
** par exemple char hdb = '├';
*******************/

#if define(__unix__)
char __db = '┌';
char __bg = '┐';
char __hd = '└';
char __hg = '┘';
char __dbg = '┬';
char __hdg = '┴';
char __hdb = '├';
char __hbg = '┤';
char __dg = '─';
char __hb = '│';
char __hdbg = '┼';
#elif define(_WIN)
#endif

