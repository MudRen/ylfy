// xuantian  by:pipip
inherit ROOM; 
int do_ba(string arg) ;void create()
{
        set("short", "С��");
        set("long", @LONG
�������߳��˵ص�������һ��С�������˵���
��������һ��������Ȼ�㿴��һ��޴��Բʯ�����
����ʯͷ�Ͼ�Ȼ���Ű�����Ķ̵���
LONG
        );
        set("exits", ([
              "out" : "d/xuantian/dadao",
              "enter" : "d/xuantian/pomiao",
        ]));

        setup();
}
void init()
{
            add_action("do_ba","ba");
}
void reset()
{
        ::reset();
        set("get_available" , 1);
}
int do_ba(string arg)
{
       object me,obj;
       me = this_player();
       if( !arg || arg!="����" )
              return notify_fail("��Ҫ��ʲô?\n");
       if ( query("get_available") )  {
       obj = new ("d/xuantian/obj/xblade");
       obj->move(me);
       add("get_available", -1);
message("vision",HIC"��"HIR"��������"HIC"��"HIC+":"+HIC" ��˵"HIM+me->name()+NOR HIG"���������Թ���Ū���������ɱ�������\n"NOR,users());

       }
       else
       return notify_fail("������һ�Σ�������˸��գ�ԭ�����Ѿ�����ȡ���ˡ�\n");
       return 1;
}

