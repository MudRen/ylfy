// shanxia.c By csy 98/12

inherit ROOM;
#include <ansi.h>
int get_object(object ob);
void create()
{
    set("short", HIG"����ɽ��"NOR);
    set("long", @LONG
����������ɽ��������һƬ��ţ�ֻ��Ȫ����������˼���������ɽʯ
��ᾣ���ľï�ܣ�����֮�����ࡣ�ڲ�Զ���Ĺ�ľ���У�����ԼԼ�ĺ����и�
Сɽ��(dong)��
LONG
        );

    set("item_desc", ([
           "dong" : HIB"һ���ں�����С������֪��ͨ�����\n"NOR,
    ]));

    set("outdoors","��Ĺ");

    set("exits", ([
                "northwest" : __DIR__"xiaolu3",
    ]));
    
    setup();
}

void init()
{ 
      add_action("do_zuan","zuan");
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int do_zuan(string arg,object *obj)
{
      object me=this_player();
      object *inv = deep_inventory(me); 
      mapping fam;
        if (me->is_busy() || me->is_fighting())
             return notify_fail("����æ���ģ�\n");       
        if ( arg=="dong"){
        if (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��")
             return notify_fail("�㲻�ǹ�Ĺ�ɴ��ˣ���Ҫ���ڹ�Ĺ���������ˡ�\n");
        if(me->query_temp("ride_horse"))
             return notify_fail("���������ϣ���ô��ɽ����\n");
        if ( me->query_skill("yunv-xinjing", 1) > 100 ){	
        obj = filter_array(inv,(:get_object:));
        if(sizeof(obj)){
         write ("�������Ž���ɽ�������ڱ�������̫�࣬һͷײ��ɽ���ϡ�\n");
         me->unconcious();
         me->move(__DIR__"shanxia");
         return 1;
         }         
         me->move(__DIR__"dongkou");
         message_vision(HIY"$Nһ������С���������ڣ�ֻ������ҫ�ۣ�Ũ���ѵء�\n"NOR,me);
         return 1;
         }
        return notify_fail("��ôС��ɽ��������Ľ�ȥ��\n");
       }
     return notify_fail("���������ꣿ\n");
}


