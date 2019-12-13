// room: /d/xingxiu/cave.c
// Mei 7/12/98
inherit ROOM;
int do_use(string arg);
int do_study(string arg);
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
���ɽ�������ֲ�����ָ��ֻ�г��ڴ�͸��һ˿���ߡ�
LONG
        );
        set("exits", ([
            "out" : __DIR__"tianroad5",
]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_use", "use");
        add_action("do_study", "study");
}
int do_use(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!ob=present("fire", me))  return 0;
        if(me->query_temp("marks/��"))
         return 0;
        if( arg=="fire" ) {
             write(
             "���ȼ�˻��ۣ���������ʯ���ϻ���һ����ɮ�ֵ�ͼ����һЩ���߰����������\n"
             );
        me->set_temp("marks/��", 1);
        set("long", @LONG
ɽ������ʯ���ϻ���һ����ɮ�ֵ�ͼ����һЩ���߰����������
LONG
        );
             call_out("dest_fire",300,me,ob);
             return 1;
       }
}
int do_study(string arg)
{
        object me;
        int jing_cost;
        int skill;
        me = this_player();

        if ( !arg || ( arg != "tu" ) )
                return notify_fail("��Ҫ��ʲô��\n");

        if (!me->query_temp("marks/��")){
                tell_object(me,"����һƬ�����Ҫ��ʲô��\n");
                return 1;
        }

        if ( (int)me->query_skill("literate", 1) < 1){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        if ( (int)me->query_int() < 35){
                write("������Բ�������ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }

        jing_cost = me->query("max_jing")/10;
        if((int)me->query("jing") < jing_cost){
                write("�������ۻ����ң���ƣ�����ˡ�\n");
                return 1;
        }
        me->receive_damage("jing", jing_cost );

        message_vision("$N����������ģ��ʯ���ϵĹŹ�ͼ�����Ȼ��˼��¡�\n", me);
        
        write("�����ͼ����ĥ��һ�ض�����������\n");
        skill=(int)me->query_skill("blade", 1);
        if ( skill < 450 && random(10)>5 && skill*skill*skill/20 < me->query("combat_exp")){
                        me->improve_skill("blade", me->query_int());
                }
        return 1;
}   
void dest_fire(object me,object ob)
{
        if (!me || !ob) return;
        message("vision",HIB"����ʯ���ϵ�"+ob->name()+"ȼ���ˡ�\n"NOR,this_object());
        me->delete_temp("marks/��");
        destruct(ob);
        set("long", @LONG
���ɽ�������ֲ�����ָ��ֻ�г��ڴ�͸��һ˿���ߡ�
LONG
        );
}

