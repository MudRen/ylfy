// cangjingge.c �ؾ���
// by Xiang
// 05/30/96 Marz
inherit ROOM;
string* books = ({
    "laozi1",
    "daodejing-i",
    "laozi2",
    "daodejing-i",
    "laozi8",
    "daodejing-i",
    "laozi13",
    "laozi1",
    "laozi16",
    "daodejing-i",
    "laozi18"
});
void create()
{
    set("short", "���������");
    set("long", @LONG
�����Ǹ�������㣬���䵱�ղص��̵伮�ĵط�����ǽ��һ��
��ܣ������˵��̵ĵ伮��������һ�������εĴ����ӣ�����Ҳ��
�����顣һ����ͯ���������鼮��
LONG
    );
    set("exits", ([
        "northdown" : __DIR__"fuzhen2",
        "westup" : __DIR__"fuzhen4",
    ]));
    set("objects", ([
        CLASS_D("wudang") + "/daotong" : 1,
        __DIR__"obj/"+books[random(sizeof(books))] : 1,
        __DIR__"obj/"+books[random(sizeof(books))] : 1
    ]));
    setup();
    replace_program(ROOM);
}
