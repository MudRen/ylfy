#include <ansi.h>
inherit ROOM;
string* books = ({
    "/clone/book/book-bamboo",
    "/clone/book/book-paper",
    "/clone/book/book-silk",
    "/clone/book/book-stone",
    "/clone/book/book-iron",
    "/clone/book/quanpu",
    "/clone/book/dujing_1",

});
void create()
{
    set("short", "С��");
    set("long", @LONG
һ��С��,ֻ��ǽ�Ϲ���������������ֻ�.�����Ҳ������
ƽʱ�ѵ�һ���ĸ��ָ������鼮.һ����òӢ���������ʿ����
��һ���ֻ�����̾��.
LONG
    );
    set("exits", ([
        "south" : __DIR__"kongdi",
    ]));
    set("objects", ([
        "/d/shenlong/npc/lu": 1,
        books[random(sizeof(books))] : 1,
        books[random(sizeof(books))] : 1,
    ]));
    set("outdoors", "shenlong");
    setup();
   replace_program(ROOM); 
}
