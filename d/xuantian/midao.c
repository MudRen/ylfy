// Room: /chengdu/ruin2.c
// oooc: 1998/06/26

inherit ROOM;

void create()
{
        set("short", "�����ص�");
        set("long", @LONG
�����ɵ�����ͨ���������������졣
LONG
        );



        setup();
}
void init()
{
        add_action("do_enter", "enter");
        add_action("do_climb", "climb");
}

int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="����" )
        {
                message("vision",
                        me->name() + "һ�������������˽�ȥ��\n",
                        environment(me), ({me}) );
                me->move("d/xuantian/chi");
                message("vision",
                        me->name() + "�Ӷ������˽�����\n",
                        environment(me), ({me}) );
                return 1;
        }
}     
int do_climb(string arg)
{
       
        object me=this_player();
        object ob; 
        if( (!arg) ||!((arg == "tree") || (arg == "wall")))
                return 0;
                message_vision("$Pʩչ���ڻ���ǽ���ϳ��Ṧ������������ȥ��\n\n",me);
        ob = load_object("d/xuantian/wall");
        ob = find_object("d/xuantian/wall");
        message("vision", me->query("name")+"����������������\n", ob);
        me->move("d/xuantian/wall");
        return 1;
}

