// Room: /d/xingxiu/xxroad4.c
inherit ROOM;
void create()
{
        set("short", "С·");
        set("long", @LONG
ɽ�������･�����ƽ�������Ѿ�������������ɽ���׵�ˮ����������һ
��ɽ����
LONG
        );
        set("exits", ([
  "south" : __DIR__"xxroad4",
  "enter" : __DIR__"cangku",
  "north" : __DIR__"xxroad6",
]));
        set("objects", ([
                "/kungfu/class/xingxiu/chuchen" : 1,
        ]) );

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        //replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        object ob=present("chuchen zi", environment(me));
        myfam = (mapping)me->query("family");
        if (ob && living(ob)  && dir != "south")
        if ((!myfam || myfam["family_name"] != "������")) {
        say("������һ�Բ�������������"+me->name()+"��ǰ��\n");
                return notify_fail("������һ�Բ�����������������ǰ��\n");
        }
        return ::valid_leave(me, dir);
}
