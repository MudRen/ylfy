//LUCAS 2000-6-18
// Room: book.c

inherit ROOM; 
string* books = ({
    "/clone/book/book-bamboo",
    "/clone/book/book-silk",
    "/clone/book/book-stone",
    "/clone/book/book-iron",
});
void create()
{
        set("short","书房");
        set("long",@LONG
这里是白自在的书房，一室之内，放满了各类书籍。白自在
虽然狂妄自大，但说到学问，却当真也是饱读诗书，学富五车。
这里的书架，大大小小，总有十几个吧。白自在的书童正在这为
他整理。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"weideju",   
            "south"  : __DIR__"bridge",
        ]));
        set("objects", ([  
                __DIR__"npc/su" : 1,  
                __DIR__"obj/feixue-book" : 1,  
                books[random(sizeof(books))] : 1,
                books[random(sizeof(books))] : 1,
        ]));
        setup(); 
        replace_program(ROOM);
}

