// Room: /d/xingxiu/xxh2.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ߡ�˵�Ǻ�����ʵ��Ƭ���������󣬵���ʮ���ն�
������������ͨ�����޺�������ϱ����������ܶ桪�����¶���
��������һ������(paizi)��
LONG
        );
        set("exits", ([
             "north" : __DIR__"riyuedong",
             "south" : __DIR__"xxh1",
             "northeast" : __DIR__"xxh3",
             "northwest" : __DIR__"xxh4",
        ]));
        set("valid_startroom",1);
        set("item_desc", ([
                "paizi" : "���޺����أ����¶����졣\n",
        ]));
        set("objects", ([
                "/kungfu/class/xingxiu/zhaixing" : 1,
        ]) );
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        "/clone/board/xingxiu_b"->foo();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        object ob=present("zhaixing zi", environment(me));
        if (ob && living(ob) ){
            myfam = (mapping)me->query("family");
            if ((!myfam || myfam["family_name"] != "������") && dir == "north" ) {
                    say("ժ���Ӷ�"+me->name()+"�ȵ����㲻�������ɵ��ӣ�����Դ�ү�ҵĸ��ȾͿ������\n");
                    return notify_fail("ժ���Ӻȵ����㲻�������ɵ��ӣ�����Դ�ү�ҵĸ��ȾͿ������\n");
            }
        }
        return ::valid_leave(me, dir);
}
