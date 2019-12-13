#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�ӻ���");
        set("long", @LONG
��������٢��ɽׯ���ӻ��ң���������˸��ֲ��õľ���Ʒ�����ӻ���
��һ�ǰڷ���һ��������(jia)��
LONG    );
        set("exits", ([ 
                "west" : __DIR__"hhyuan",
                "east" : __DIR__"c14-5",
        ]));
                set("item_desc", ([ 
"jia" : "�����ܷ��Ÿ�ʽ�����ı�����
һ��ֻ����һ����
        �ֽ�(jian)           ����(armor)        ����(gangzhang)
        ����(changjian)      ����(changian)     ��(zhujian)
        �̽�(duanjian)       �ֵ�(blade)        ���(zhubang)
        ��(zhujian)        

�������(na)һ������������
\n"
]));
        setup();

}

void init()
{
        add_action("do_na","na");
}

int do_na(string arg)
{
        mapping fam; 
        object me;
        me=this_player();
        if (!(fam = this_player()->query("family")) 
            || fam["family_name"] != "����Ľ��")
                return notify_fail("����Ľ�ݵ����⣬�����ǲ�������ȡ�����ģ���\n");

        if (me->query_temp("marks/��1") )
                return notify_fail("�������˱�������Ҫ���𣿣�\n");

        if (arg=="all from jia") 
                return notify_fail("����ôҪ��ô�����ѽ����ȥ��������\n");

        if (!arg) return notify_fail("��Ҫ��ʲô������\n");

        if (!"jian from jia"||!"changjian from jia"||!"duanjian from jia"
||!"zhujian from jia"||!"changbian from jian"||!"blade from jia"
||!"dao from jia"||!"armor from jia") return 0;

        if (arg=="jian from jia"){
        message_vision("$N�ӱ��������ó�һ�Ѹֽ���\n",me);
        this_player()->set_temp("marks/��1", 1);
        me = new("/d/city/obj/gangjian");
        me->move(this_player());
        return 1;
        }
        
        if (arg=="changjian from jia"){
        message_vision("$N�ӱ��������ó�һ�ѳ�����\n",me);
        this_player()->set_temp("marks/��1", 1);
        me = new("/d/city/obj/changjian");
        me->move(this_player());
        return 1;
        }

        if (arg=="duanjian from jia"){
        message_vision("$N�ӱ��������ó�һ�Ѷ̽���\n",me);
        this_player()->set_temp("marks/��1", 1);
        me = new("/d/city/obj/duanjian");
        me->move(this_player());
        return 1;
        }

        if (arg=="zhujian from jia"){
        message_vision("$N�ӱ��������ó�һ���񽣡�\n",me);
        this_player()->set_temp("marks/��1", 1);
        me = new("/d/village/obj/zhujian");
        me->move(this_player());
        return 1;
        }
        
        if (arg=="blade from jia"){
        message_vision("$N�ӱ��������ó�һ�Ѹֵ���\n",me);
        this_player()->set_temp("marks/��1", 1);
        me = new("/d/city/obj/gangdao");
        me->move(this_player());
        return 1;
        }

        if (arg=="dao from jia"){
        message_vision("$N�ӱ��������ó�һ��ľ����\n",me);
        this_player()->set_temp("marks/��1", 1);
me = new("/u/beyond/mr/obj/mudao");
        me->move(this_player());
        return 1;
        }

        if (arg=="changbian from jia"){
        message_vision("$N�ӱ��������ó�һ�����ޡ�\n",me);
        this_player()->set_temp("marks/��1", 1);
        me = new("/d/xingxiu/npc/obj/changbian");
        me->move(this_player());
        return 1;
        }
        if (arg=="armor from jia"){
        message_vision("$N�ӱ��������ó�һ�����ס�\n",me);
        this_player()->set_temp("marks/��1", 1);
        me = new("/d/city/obj/tiejia");
        me->move(this_player());
        return 1;
        }
      
        if (arg=="zhubang from jia"){
        message_vision("$N�ӱ��������ó�һ�������\n",me);
        this_player()->set_temp("marks/��1", 1);
        me = new("/d/city/obj/zhubang");
        me->move(this_player());
        return 1;
        }

        if (arg=="gangzhang from jia"){
        message_vision("$N�ӱ��������ó�һ�����ȡ�\n",me);
        this_player()->set_temp("marks/��1", 1);
        me = new("/d/city/obj/gangzhang");
        me->move(this_player());
        return 1;
        }
}
