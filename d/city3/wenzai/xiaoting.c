//xiaoting.c
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long",@LONG
����һ��СС�Ŀ�����ǽ�Ϲ���һЩ�ֻ������������۵�����
��֮��һ������ͤ���򡷣��и�Ů�������ڴ�ɨ��������
LONG
        );
        set("exits", ([
                "south" : __DIR__"xiaoyuan",
                "up" : __DIR__"xiaolou",
        ]));
        set("objects", ([
                 __DIR__"npc/afeng" : 1,
        ]));
        set("item_desc", ([
                "����ͤ����" : "�����������������漣���ʷ��پ�����Ȼһ�ɴ�ҷ緶��\n" ,
        ]));

        setup();
}
void init()
{
        add_action("do_kneel", "kneel");
}
int do_kneel(string arg)
{
        object me,room;
        string dir;
        me = this_player();
        if ( !arg || arg=="" ) return 0;
        if( arg=="����ͤ����" ) {
                message_vision("$N�ϵع��ڡ���ͤ�����£�����ͷ���������ˡ��ذ�����ǿյġ�\n", me);
        }
        if (!( room = find_object(__DIR__"andao1")) )
               room = load_object(__DIR__"andao1");
        if ( sscanf(arg, "����ͤ���� %s", dir)==1 ) {
              if( dir=="9" || dir=="nine") {
                message_vision("$Nһ�������˾Ÿ���ͷ��ͻȻ�䣬�ذ��ɶ��ˣ�¶��һ���󶴡�\n", me);
                message_vision("$N��ǰһ�ڡ��������\n", me);
                message_vision("һ����ص��������󣬴󶴺�$N�������ˡ�\n", room);
                me->move(__DIR__"andao1");
           } else return notify_fail("����ҿ��˼���ͷ�����ʲôҲû������\n");
     } return 1;
}

