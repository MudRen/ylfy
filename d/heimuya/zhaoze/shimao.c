// Room: /d/heimuya/zhaoze/shimao.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��Ŀ�Ĺˣ�ֻ������ƽ������һ��СС��Ժ����ǰ��һ����������ʱ����
��������ɽ�纮����Ҷ��Ȼ���˴�롣
LONG
);
        set("exits", ([ 
  "east" : __DIR__"shiliang1",
  "enter" : __DIR__"shimao1",
]));
    set("objects", ([
        __DIR__"npc/shusheng" : 1,
    ]));

        set("outdoors", "shimao");

        setup();
}
int valid_leave(object me, string dir)
{
        object ob=present("shu sheng", environment(me));
        if (ob && living(ob) ){
            if ( ( present("hong juan",me) ) && dir == "enter" ) {
                    say("������"+me->name()+"�ȵ�����������\n");
                    return notify_fail("�����ȵ�����λ" + RANK_D->query_respect(me) + "��ֹ����\n");
            }
        }
        return ::valid_leave(me, dir);
}

